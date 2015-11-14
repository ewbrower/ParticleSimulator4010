#include "Simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "Particle.h"

//struct simulation {
//	Particle *part_arr;
//	double L;
	
//};
//typedef struct Simulation Simulation;

//struct particle {
//	double *pos;
//};
//typedef struct particle Particle;

Simulation* CreateSimulation(double l, int b)
{
	Simulation *sim = (Simulation*)malloc(sizeof(Simulation));

	sim->L = l;
	sim->part_arr = (Particle*)malloc(b*sizeof(double));
	
	return sim;
}
// // generate the array of random Particles (private)
// int CreateParticles(Simulation sim);
//
// // update simulation to next timestep (which is known)
// void Update(Simulation sim);
// // particle distance getter thing
// double GetParticleDistance(Simulation sim, int partIndexA, int partIndexB);
// // find net force
double* SimulationNetForce(Simulation *sim, int partIndex)
{
	double *netForce = (double*)malloc(3*sizeof(double));
	double *dist = (double*)malloc(4*sizeof(double));
	double Fmag, Fscale;
	
	int i, j;
	for (i = 0; i < sim->b; i++)
	{
		for (j = 0; j < sim->b; j++)
		{
			if (j !=i)
			{
				dist = GetParticleDistance(sim, i, j);
				if (dist[3] < 2)
				{
					Fmag = 125*(2-dist[3]);
					Fscale = Fmag/dist[3];
					//netForce[0] += 
						
				} 
			}	
		}
	}
	free(netForce);
}
// // check if in box update position to correct one
double* SetPosition(Simulation *sim, int partIndex, double *pos)
{
	//Make sure new position is in LxLxL box
	pos[0] = fmod(pos[0],sim->L);
	pos[1] = fmod(pos[1],sim->L);
	pos[2] = fmod(pos[2],sim->L);
	
	//Assigns updated position to particle
	sim->part_arr[partIndex].pos = pos;
	//PARTICLE INDICIES START AT ZERO
	//
	return sim->part_arr[partIndex].pos;
}
//
// // write to the xyz file
// void WriteToFile(Simulation sim);

double* GetParticleDistance(Simulation *sim, int partIndexA, int partIndexB)
{
	printf("\n");
	// get the vals
	double length = sim->L;
	Particle *partA = &sim->part_arr[partIndexA];
	Particle *partB = &sim->part_arr[partIndexB];
	double x1 = partA->pos[0];
	double y1 = partA->pos[1];
	double z1 = partA->pos[2];
	double x2 = partB->pos[0];
	double y2 = partB->pos[1];
	double z2 = partB->pos[2];

	printf("Particle %d:\nx: %f\ny: %f\nz: %f\n", partIndexA, x1, y1, z1);
	printf("Particle %d:\nx: %f\ny: %f\nz: %f\n", partIndexB, x2, y2, z2);

	double *dVector = malloc(4*sizeof(double));

	dVector[0] = (x1-x2)*(x1-x2);
	dVector[1] = (y1-y2)*(y1-y2);
	dVector[2] = (z1-z2)*(z1-z2);

	dVector[3] = sqrt(dVector[0] + dVector[1] + dVector[2]);

	if (x1 < 2 && x2 > length - 2)
	{
		printf("x1 < 2 && x2 > length - 2\n");
		double tempX1 = length + x1;
		double tempDist = sqrt((tempX1-x2)*(tempX1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));

		if (tempDist < dVector[3])
		{
			dVector[0] = (tempX1-x2)*(tempX1-x2);
			dVector[3] = tempDist;
		}
	}
	else if (x2 < 2 && x1 > length - 2)
	{
		printf("x2 < 2 && x1 > length - 2\n");
		double tempX2 = length + x2;
		double tempDist = sqrt((x1-tempX2)*(x1-tempX2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));

		if (tempDist < dVector[3])
		{
			dVector[0] = (x1-tempX2)*(x1-tempX2);
			dVector[3] = tempDist;
		}
	}
	else if (y1 < 2 && y2 > length - 2)
	{
		printf("y1 < 2 && y2 > length - 2\n");
		double tempY1 = length + y1;
		double tempDist = sqrt((x1-x2)*(x1-x2) + (tempY1-y2)*(tempY1-y2) + (z1-z2)*(z1-z2));

		if (tempDist < dVector[3])
		{
			dVector[1] = (tempY1-y2)*(tempY1-y2);
			dVector[3] = tempDist;
		}
	}
	else if (y2 < 2 && y1 > length - 2)
	{
		printf("y2 < 2 && y1 > length - 2\n");
		double tempY2 = length + y2;
		double tempDist = sqrt((x1-x2)*(x1-x2) + (y1-tempY2)*(y1-tempY2) + (z1-z2)*(z1-z2));

		if (tempDist < dVector[3])
		{
			dVector[1] = (y1-tempY2)*(y1-tempY2);
			dVector[3] = tempDist;
		}
	}
	else if (z1 < 2 && z2 > length - 2)
	{
		printf("z1 < 2 && z2 > length - 2\n");
		double tempZ1 = length + z1;
		double tempDist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (tempZ1-z2)*(tempZ1-z2));

		if (tempDist < dVector[3])
		{
			dVector[2] = (tempZ1-z2)*(tempZ1-z2);
			dVector[3] = tempDist;
		}
	}
	else if (z2 < 2 && z1 > length - 2)
	{
		printf("z2 < 2 && z1 > length - 2\n");
		double tempZ2 = length + z2;
		double tempDist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-tempZ2)*(z1-tempZ2));

		if (tempDist < dVector[3])
		{
			dVector[2] = (z1-tempZ2)*(z1-tempZ2);
			dVector[3] = tempDist;
		}
	}

	// check for all combinations
	if (x1 < 2)
		x1 = length + x1;
	if (x2 < 2)
		x2 = length + x1;
	if (y1 < 2)
		y1 = length + y1;
	if (y2 < 2)
		y2 = length + y2;
	if (z1 < 2)
		z1 = length + z1;
	if (z2 < 2)
		z2 = length + z2;

	double edgeDist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
	if (edgeDist < dVector[3])
	{
		dVector[3] = edgeDist;
	}
	// doesn't take care of every overlap case

	printf("Distance: %f\n", dVector[3]);

	return dVector;
}

void ParticleCreate(Simulation *sim, int partIndex, double* init_pos)
{
	Particle *p = (Particle*)malloc(sizeof(Particle));
	sim->part_arr[partIndex] = *p;
	SetPosition(sim, partIndex, init_pos);
}
                      
