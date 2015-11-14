#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Simulation.h"
//#include "Particle.h"


int main(void)
{
	Simulation *sim;
	sim = CreateSimulation(12,2);
	Particle *p1, *p2;
	double *pos1, *pos2, *pos3;
	pos1 = (double*)malloc(3*sizeof(double));
	pos2 = (double*)malloc(3*sizeof(double));
	pos3 = (double*)malloc(3*sizeof(double));

	pos1[0] = 1.78;
	pos1[1] = 2.43;
	pos1[2] = 3.01;

	pos2[0] = 13.23;
	pos2[1] = 14.8;
	pos2[2] = 11.99;

	pos3[0] = 11.0;
	pos3[1] = 12.0;
	pos3[2] = 14.0;
	
	ParticleCreate(sim, 0, pos1);
	ParticleCreate(sim, 1, pos2);

	printf("Position of particle 1:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[0].pos[0], sim->part_arr[0].pos[1], sim->part_arr[0].pos[2]);
	//test set position
	printf("Position of particle 2:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[1].pos[0], sim->part_arr[1].pos[1], sim->part_arr[1].pos[2]);	
	
	SetPosition(sim, 0, pos3);
	
	printf("Position of particle 1 after update:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[0].pos[0], sim->part_arr[0].pos[1], sim->part_arr[0].pos[2]);

	printf("\nGet Distance Test\n");
	GetParticleDistance(sim, 0, 1);
	
}
