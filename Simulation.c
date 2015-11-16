#include "Simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
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
	
	sim->b = b;
	sim->L = l;
	sim->part_arr = (Particle*)malloc(b*sizeof(Particle));
	sim->force_arr = (double*)malloc(3*b*sizeof(double));

	return sim;
}
// generate the array of random Particles (private)
int CreateParticles(Simulation *sim)
{
	int i;
	double x, y, z;
	srand(time(NULL));

	for (i = 0; i < sim->b; i++)
	{
		double L = sim->L;
		sim->part_arr[i].pos= (double*)malloc(3*sizeof(double));
		x = (L*rand())/(double)RAND_MAX; // random
		y = (L*rand())/(double)RAND_MAX; // random
		z = (L*rand())/(double)RAND_MAX; // random
		sim->part_arr[i].pos[0] = x;
		sim->part_arr[i].pos[1] = y;
		sim->part_arr[i].pos[2] = z;
	}

	return sim->b;
}

//
// // update simulation to next timestep (which is known)
 void Update(Simulation *sim)
{
	srand(time(NULL));
	double *newPos, *oldPos, *brownian, *netForce;
	newPos = (double*)malloc(3*sizeof(double));
	oldPos = (double*)malloc(3*sizeof(double));
	brownian = (double*)malloc(3*sizeof(double));
	netForce = (double*)malloc(3*sizeof(double));
	int i, j;
	SimulationNetForce(sim);
	for (i = 0; i < sim->b; i++)
	{
		GetPosition(sim, i, oldPos);
		GetBrownian(brownian);
		for (j = 0; j < 3; j++)
		{
		netForce[j] = sim->force_arr[3*i+j];
		
		newPos[j] = netForce[j]*TIMESTEP + brownian[j]+oldPos[j];	
		}
		
		SetPosition(sim, i, newPos);
					
	}
	free(newPos);
	free(oldPos);
	free(brownian);
	free(netForce);
}
// // particle distance getter thing
// double GetParticleDistance(Simulation sim, int partIndexA, int partIndexB);
// // find net force
void SimulationNetForce(Simulation *sim)
{
	double *netForce = (double*)malloc(3*sizeof(double));
	double *dist = (double*)malloc(4*sizeof(double));
	double Fmag, Fscale;
	
	int i, j;
	for (i = 0; i < sim->b; i++)
	{
		netForce[0] = 0.0;
		netForce[1] = 0.0;
		netForce[2] = 0.0;
		for (j = 0; j < sim->b; j++)
		{
			
			dist = GetParticleDistance(sim, i, j);
			if (i != j)
			{if (dist[3] < 2)
			{
				Fmag = 125*(2-dist[3]);
				Fscale = Fmag/dist[3];
				netForce[0] += Fscale*dist[0];
				netForce[1] += Fscale*dist[1];
				netForce[2] += Fscale*dist[2];						
		}} 	
		}
		sim->force_arr[3*i] = netForce[0];
		sim->force_arr[3*i+1] = netForce[1];
		sim->force_arr[3*i+2] = netForce[2];
		
		//sim->force_arr[3*j] = -1*netForce[0];
		//sim->force_arr[3*j+1] = -1*netForce[1];
		//sim->force_arr[3*j+2] = -1*netForce[2];
	}
	free(netForce);
	free(dist);
}
// // check if in box update position to correct one
double* SetPosition(Simulation *sim, int partIndex, double *pos)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if(pos[i] < 0)
		{
			pos[i] = sim->L + pos[i];
		}
	}

	//Make sure new position is in LxLxL box
	pos[0] = fmod(pos[0],sim->L);
	pos[1] = fmod(pos[1],sim->L);
	pos[2] = fmod(pos[2],sim->L);
	
	//Assigns updated position to particle
	//sim->part_arr[partIndex].pos = pos;
	sim->part_arr[partIndex].pos[0] = pos[0];
	sim->part_arr[partIndex].pos[1] = pos[1];
	sim->part_arr[partIndex].pos[2] = pos[2];
	//PARTICLE INDICIES START AT ZERO
	//
	return sim->part_arr[partIndex].pos;
}
//
// // write to the xyz file
void WriteToFile(Simulation *sim)
{
	Particle* arr = sim->part_arr; //grabs particle positions


	//convert timestep count to char
	char timeS[10];
	sprintf(timeS, "%f", TIMESTEP);

	double pos[3];
	char writeLine[] = "time_step_number\n";
	int i;
	int numParticles = sim->b; //pulls the number of particles
	double particlePoints[3];

	FILE *fp;
	fp = fopen("traj.xyz", "wb"); //open file to write information in


		//writes the coordinates of the particle

		fprintf(fp, "%d\n", numParticles); //write number of particles
		fprintf(fp, "%s", writeLine); //writes "time_step_number"
		for (i = 0; i < numParticles; i++) { //loop to get all the particles positions and write them
	  	GetPosition(sim, i, pos);
			fprintf(fp, "0 ");
			fprintf(fp, "%0.3f ", arr[i].pos[0]);
			fprintf(fp, "%0.3f ", arr[i].pos[1]);
			fprintf(fp, "%0.3f\n", arr[i].pos[2]);

	}

	fclose(fp);
}


void GetBrownian(double* brownian)
{
	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		brownian[i] = 0;
		for (j = 0; j < 12; j++)
		{
			brownian[i] += rand()/(double)RAND_MAX;
		}
		brownian[i] -= 6;
		brownian[i] =brownian[i]* sqrt(2*(double)TIMESTEP);
	}	
}
void GetPosition(Simulation *sim, int partIndex, double* pos)
{
	pos[0] = sim->part_arr[partIndex].pos[0];
	pos[1] = sim->part_arr[partIndex].pos[1];
	pos[2] = sim->part_arr[partIndex].pos[2];
}
double* GetParticleDistance(Simulation *sim, int partIndexA, int partIndexB)
{
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

	//printf("Particle %d:\nx: %f\ny: %f\nz: %f\n", partIndexA, x1, y1, z1);
	//printf("Particle %d:\nx: %f\ny: %f\nz: %f\n", partIndexB, x2, y2, z2);

	double *dVector = malloc(4*sizeof(double));

	dVector[0] = (x1-x2);
	dVector[1] = (y1-y2);
	dVector[2] = (z1-z2);

	dVector[3] = sqrt(dVector[0]*dVector[0] + dVector[1]*dVector[1] + dVector[2]*dVector[2]);

	if (x1 < 2 && x2 > length - 2)
	{
		// printf("x1 < 2 && x2 > length - 2\n");
		double tempX1 = length + x1;
		double tempDist = sqrt((tempX1-x2)*(tempX1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));

		if (tempDist < dVector[3])
		{
			x1 = tempX1;
			dVector[0] = (tempX1-x2);
			dVector[3] = tempDist;
		}
	}
	if (x2 < 2 && x1 > length - 2)
	{
		// printf("x2 < 2 && x1 > length - 2\n");
		double tempX2 = length + x2;
		double tempDist = sqrt((x1-tempX2)*(x1-tempX2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));

		if (tempDist < dVector[3])
		{
			x2 = tempX2;
			dVector[0] = (x1-tempX2);
			dVector[3] = tempDist;
		}
	}
	if (y1 < 2 && y2 > length - 2)
	{
		// printf("y1 < 2 && y2 > length - 2\n");
		double tempY1 = length + y1;
		double tempDist = sqrt((x1-x2)*(x1-x2) + (tempY1-y2)*(tempY1-y2) + (z1-z2)*(z1-z2));

		if (tempDist < dVector[3])
		{
			y1 = tempY1;
			dVector[1] = (tempY1-y2);
			dVector[3] = tempDist;
		}
	}
	if (y2 < 2 && y1 > length - 2)
	{
		// printf("y2 < 2 && y1 > length - 2\n");
		double tempY2 = length + y2;
		double tempDist = sqrt((x1-x2)*(x1-x2) + (y1-tempY2)*(y1-tempY2) + (z1-z2)*(z1-z2));

		if (tempDist < dVector[3])
		{
			y2 = tempY2;
			dVector[1] = (y1-tempY2);
			dVector[3] = tempDist;
		}
	}
	if (z1 < 2 && z2 > length - 2)
	{
		// printf("z1 < 2 && z2 > length - 2\n");
		double tempZ1 = length + z1;
		double tempDist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (tempZ1-z2)*(tempZ1-z2));

		if (tempDist < dVector[3])
		{
			z1 = tempZ1;
			dVector[2] = (tempZ1-z2);
			dVector[3] = tempDist;
		}
	}
	if (z2 < 2 && z1 > length - 2)
	{
		// printf("z2 < 2 && z1 > length - 2\n");
		double tempZ2 = length + z2;
		double tempDist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-tempZ2)*(z1-tempZ2));

		if (tempDist < dVector[3])
		{
			z2 = tempZ2;
			dVector[2] = (z1-tempZ2);
			dVector[3] = tempDist;
		}
	}

	// check for all combinations
	//if (x1 < 2)
	//	x1 = length + x1;
	//if (x2 < 2)
	//	x2 = length + x1;
	//if (y1 < 2)
	//	y1 = length + y1;
	//if (y2 < 2)
	//	y2 = length + y2;
	//if (z1 < 2)
	//	z1 = length + z1;
	//if (z2 < 2)
	//	z2 = length + z2;

	//double edgeDist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
	//if (edgeDist < dVector[3])
	//{
	//	dVector[3] = edgeDist;
	//}
	// doesn't take care of every overlap case

	//printf("Diplacement: \nx: %f\ny: %f\nz: %f\n", dVector[0], dVector[1], dVector[2]);
	//printf("Total Distance: %f\n\n", dVector[3]);
	return dVector;
}

void ParticleCreate(Simulation *sim, int partIndex, double* init_pos)
{
	Particle *p = (Particle*)malloc(sizeof(Particle));
	sim->part_arr[partIndex] = *p;
	double* pos = (double*)malloc(3*sizeof(double));
	sim->part_arr[partIndex].pos = pos;
	SetPosition(sim, partIndex, init_pos);
}

void DestroySimulation(Simulation *sim)
{
	int i;
	// for (i = 0; i < sim->b; i++)
	// {
	// 	Particle *p = &sim->part_arr[i];
	// 	free(p);
	// }
	free(sim);
}
                      








