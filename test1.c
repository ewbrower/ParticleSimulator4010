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
	double *pos1, *pos2;
	pos1 = (double*)malloc(3*sizeof(double));
	pos2 = (double*)malloc(3*sizeof(double));
	pos1[0] = 1.78;
	pos1[1] = 2.43;
	pos1[2] = 3.01;
	pos2[0] = 13.23;
	pos2[1] = 14.8;
	pos2[2] = 11.99;
	
	p1 = (Particle*)ParticleCreate(pos1);
	p2 = ParticleCreate(pos2);

	sim->part_arr[0] = *p1;
	sim->part_arr[1] = *p2;

	printf("Position of particle 1:\nx: %f\ny:%f\nz: %f\n",sim->part_arr[0].pos[0], sim->part_arr[0].pos[1], sim->part_arr[0].pos[2]);
	//test set position
	

	
}
