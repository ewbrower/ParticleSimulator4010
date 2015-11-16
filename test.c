#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Simulation.h"
//#include "Particle.h"


int main(void)
{
	Simulation *sim;
	sim = CreateSimulation(10, 14);
	Particle *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12, *p13, *p14;
	double *pos1, *pos2, *pos3, *pos4, *pos5, *pos6, *pos7, *pos8, *pos9, *pos10, *pos11, *pos12, *pos13, *pos14;
	pos1 = (double*)malloc(3*sizeof(double));
	pos2 = (double*)malloc(3*sizeof(double));
	pos3 = (double*)malloc(3*sizeof(double));
	pos4 = (double*)malloc(3*sizeof(double));
	pos5 = (double*)malloc(3*sizeof(double));
	pos6 = (double*)malloc(3*sizeof(double));
	pos7 = (double*)malloc(3*sizeof(double));
	pos8 = (double*)malloc(3*sizeof(double));
	pos9 = (double*)malloc(3*sizeof(double));
	pos10= (double*)malloc(3*sizeof(double));
	pos11= (double*)malloc(3*sizeof(double));
	pos12= (double*)malloc(3*sizeof(double));
	pos13= (double*)malloc(3*sizeof(double));
	pos14= (double*)malloc(3*sizeof(double));

	// x1 < 2 && x2 > length - 2
	// particle 1 and particle 2
	pos1[0] = 1.00;
	pos1[1] = 1.00;
	pos1[2] = 1.00;

	pos2[0] = 1.00;
	pos2[1] = 1.00;
	pos2[2] = 9.00;

	// x2 < 2 && x1 > length - 2
	// particle 3 and particle 4
	pos3[0] = 1.0;
	pos3[1] = 9.0;
	pos3[2] = 1.0;

	pos4[0] = 9.;
	pos4[1] = 1.00;
	pos4[2] = 1.0;

	// y1 < 2 && y2 > length - 2
	// particle 5 and particle 6
	pos5[0] = 9;
	pos5[1] = 9.0;
	pos5[2] = 1.0;

	pos6[0] = 9.0;
	pos6[1] = 9.0;
	pos6[2] = 9.0;

	// y2 < 2 && y1 > length - 2
	// particle 7 and particle 8
	pos7[0] = 9.0;
	pos7[1] = 1.0;
	pos7[2] = 9.0;

	pos8[0] = 1.0;
	pos8[1] = 9.0;
	pos8[2] = 9.0;

	// z1 < 2 && z2 > length - 2
	// particle 9 and particle 10
	pos9[0] = 1.0;
	pos9[1] = 1.0;
	pos9[2] = 5.0;

	pos10[0] = 9.0;
	pos10[1] = 9.0;
	pos10[2] = 7.0;

	// z2 < 2 && z1 > length - 2
	// particle 11 and particle 12
	pos11[0] = 5.0;
	pos11[1] = 5.0;
	pos11[2] = 1.5;

	pos12[0] = 5.0;
	pos12[1] = 5.0;
	pos12[2] = 8.5;

	// corners
	pos13[0] = 5.0;
	pos13[1] = 1.0;
	pos13[2] = 2.5;

	pos14[0] = 9.0;
	pos14[1] = 1.0;
	pos14[2] = 6.0;

	// ParticleCreate(sim, 0, pos1);
	// ParticleCreate(sim, 1, pos2);
	// ParticleCreate(sim, 2, pos3);
	// ParticleCreate(sim, 3, pos4);
	// ParticleCreate(sim, 4, pos5);
	// ParticleCreate(sim, 5, pos6);
	// ParticleCreate(sim, 6, pos7);
	// ParticleCreate(sim, 7, pos8);
	// ParticleCreate(sim, 8, pos9);
	// ParticleCreate(sim, 9,pos10);
	// ParticleCreate(sim,10,pos11);
	// ParticleCreate(sim,11,pos12);
	// ParticleCreate(sim,12,pos13);
	// ParticleCreate(sim,13,pos14);

//<<<<<<< HEAD
	 //GetDistanceTest(sim);
	// ForceTest(sim);
	// StackTest(4.0, 10, 10);
	 // GetDistanceTest(sim);
	// ForceTest(sim);
	// StackTest(4.0, 10, 10);
	// StackTest(4.0, 100, 10);
<<<<<<< HEAD
	StackTest(4.0, 4, 300);
=======
	StackTest(5.0, 4, 500);
>>>>>>> origin/master
	// StackTest(10.0, 100, 10);
	// StackTest(100.0, 10, 10);
	// StackTest(100.0, 100, 10);


	// printf("Position of particle 1:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[0].pos[0], sim->part_arr[0].pos[1], sim->part_arr[0].pos[2]);
	// //test set position
	// printf("Position of particle 2:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[1].pos[0], sim->part_arr[1].pos[1], sim->part_arr[1].pos[2]);	
	
	// SetPosition(sim, 0, pos3);
	
	// printf("Position of particle 1 after update:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[0].pos[0], sim->part_arr[0].pos[1], sim->part_arr[0].pos[2]);

	// printf("\nGet Distance Test\n");
	// GetParticleDistance(sim, 0, 1);
	
	//VerifyPosition(sim, 0);

	// ParticlePair();

	//Calls WriteToFile function
	//WriteToFile(sim);
	
}

int GetDistanceTest(Simulation *sim)
{
	printf("GetDistance Test\n");

	GetParticleDistance(sim, 1, 0);
	GetParticleDistance(sim, 0, 2);
	GetParticleDistance(sim, 0, 3);
	GetParticleDistance(sim, 0, 4);
	GetParticleDistance(sim, 0, 5);
	GetParticleDistance(sim, 0, 6);
	GetParticleDistance(sim, 7, 0);
	GetParticleDistance(sim, 9, 8);
	GetParticleDistance(sim, 8, 9);
	GetParticleDistance(sim,10,11);
	GetParticleDistance(sim,10,12);
	GetParticleDistance(sim, 9,13);
	//GetParticleDistance(sim, 2, 13);

	return 0;

}

int ForceTest(Simulation *sim)
{
	printf("Force Test\n");
	Particle* arr = sim->part_arr;
	double *force = (double*)malloc(4*sizeof(double));
	int i;
	for (i = 0; i < sim->b; i++)
	{
		printf("Particle %d\nx %f\ny %f\nz %f\n\n",i, arr[i].pos[0], arr[i].pos[1], arr[i].pos[2]);
	}
	printf("\n\n-----------------------\n\n");
	SimulationNetForce(sim);
	force = sim->force_arr;
	for (i = 0; i < sim->b; i++)
	{
		printf("\nNet Force\nx %f\ny %f\nz %f\n", force[3*i+0], force[3*i+1], force[3*i+2]);
	}
	printf("\n\n-----------------------\n\n");
	for (i = 0; i < sim->b; i++)
	{
		printf("Particle %d\nx %f\ny %f\nz %f\n\n",i, arr[i].pos[0], arr[i].pos[1], arr[i].pos[2]);
	}
	
	return 0;

}

// this function takes in three parameters
// how large to make the box
// how many particles to simultaneously run
// how many steps to run on each iteration
int StackTest(double length, int particles, int steps)
{
	int parts, i, j, k;

	if (length <= 0 || particles <= 0 || steps <= 0)
	{
		printf("no params should be non-positive\n");
		return -1;
	}

	printf("\n----------------\nStack Test\n----------------\n\n");

	Simulation *sim;
	sim = CreateSimulation(length, particles);
	printf("Created simulation\nbox length: %f\nparticles: %d\n", length, particles);

	printf("sim num: %d\n\n", sim->b);

	parts = CreateParticles(sim);
	printf("Created %d particles in this simulation\n\n", parts);

	for (i = 0; i < steps; i++)
	{
		Update(sim);
		PrintSummary(sim, i);
	}

	DestroySimulation(sim);
	printf("Destroyed the simulation\n");
	return 0;
}

int VerifyPosition(Simulation *sim, int partIndex)
{
	double *function, *manual;

	Particle *part = &sim->part_arr[partIndex];

	GetPosition(sim, partIndex, function);
	manual = part->pos;

	if (function[0] != manual[0] || function[1] != manual[1] || function[2] != manual[2])
	{
		printf("Some access is broken.\n");

		printf("Position given by GetPosition:\n");
		printf("x: %f\ny: %f\nz: %f\n", function[0], function[1], function[2]);
		printf("\nPosition given by manual access\n");
		printf("x: %f\ny: %f\nz: %f\n", manual[0], manual[1], manual[2]);
		return -1;
	}

	printf("Position verified\n");
	return 0;
}

int ParticlePair()
{
	int i, j, k, particles;
	Particle *p1, *p2;
	double *pos1, *pos2;

	Simulation *sim;
	sim = CreateSimulation(10, 2);

	pos1 = (double*)malloc(3*sizeof(double));
	pos2 = (double*)malloc(3*sizeof(double));

	pos1[0] = 4.00;
	pos1[1] = 5.00;
	pos1[2] = 5.00;

	pos2[0] = 5.00;
	pos2[1] = 5.00;
	pos2[2] = 5.00;

	ParticleCreate(sim, 0, pos1);
	ParticleCreate(sim, 1, pos2);

	// there should only be two particles

	printf("Particle Pair Test\n\n");


	for (i = 0; i < 10; i++)
	{
		PrintSummary(sim, i);
		Update(sim);
	}

	printf("\n");
	DestroySimulation(sim);
	printf("Destroyed the simulation\n\n");
	return 0;

}

void PrintSummary(Simulation *sim, int i)
{
	int particles, j, k;
	particles = sim->b;
	printf("----------------- Update %d --------------------|\n", i);

	printf("----------- Particle Position Summary ---------|\n");
		for (j = 0; j < particles; j++)
		{
			printf("Particle %d\n", j);
			printf("x: %f\t", sim->part_arr[j].pos[0]);
			printf("y: %f\t", sim->part_arr[j].pos[1]);
			printf("z: %f\n", sim->part_arr[j].pos[2]);
		}
	// printf("---------------- Force Summary ----------------|\n");
	// for(j = 0; j < particles*3; j+=3)
	// {
	// 	printf("Particle %d\n", j/3);
	// 	printf("%f\t", sim->force_arr[j+0]);
	// 	printf("%f\t", sim->force_arr[j+1]);
	// 	printf("%f\n", sim->force_arr[j+2]);
	// }
	printf("-----------------------------------------------|\n\n");
}











