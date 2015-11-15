#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Simulation.h"
//#include "Particle.h"


int main(void)
{
	Simulation *sim;
	sim = CreateSimulation(12,4);
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
	pos1[1] = 3.00;
	pos1[2] = 3.00;

	pos2[0] = 2.00;
	pos2[1] = 3.00;
	pos2[2] = 3.00;

	// x2 < 2 && x1 > length - 2
	// particle 3 and particle 4
	pos3[0] = 5.25;
	pos3[1] = 5.0;
	pos3[2] = 7.00;

	pos4[0] = 5.25;
	pos4[1] = 5.00;
	pos4[2] = 7.5;

	// y1 < 2 && y2 > length - 2
	// particle 5 and particle 6
	pos5[0] = 6.75;
	pos5[1] = 0.5;
	pos5[2] = 6.75;

	pos6[0] = 6.75;
	pos6[1] = 11.5;
	pos6[2] = 6.75;

	// y2 < 2 && y1 > length - 2
	// particle 7 and particle 8
	pos7[0] = 6.75;
	pos7[1] = 12.0;
	pos7[2] = 6.75;

	pos8[0] = 6.75;
	pos8[1] = 11.0;
	pos8[2] = 6.75;

	// z1 < 2 && z2 > length - 2
	// particle 9 and particle 10
	pos9[0] = 4.6;
	pos9[1] = 4.6;
	pos9[2] = 1.0;

	pos10[0] = 3.5;
	pos10[1] = 3.5;
	pos10[2] = 11.8;

	// z2 < 2 && z1 > length - 2
	// particle 11 and particle 12
	pos11[0] = 4.6;
	pos11[1] = 4.6;
	pos11[2] = 11.09;

	pos12[0] = 4.6;
	pos12[1] = 4.6;
	pos12[2] = 1.8;

	// corners
	pos13[0] = 1.2;
	pos13[1] = 0.8;
	pos13[2] = 1.1;

	pos14[0] = 11.8;
	pos14[1] = 11.3;
	pos14[2] = 10.9;

	ParticleCreate(sim, 0, pos1);
	ParticleCreate(sim, 1, pos2);
	ParticleCreate(sim, 2, pos3);
	ParticleCreate(sim, 3, pos4);
	//ParticleCreate(sim, 4, pos5);
	//ParticleCreate(sim, 5, pos6);
	//ParticleCreate(sim, 6, pos7);
	//ParticleCreate(sim, 7, pos8);
	//ParticleCreate(sim, 8, pos9);
	//ParticleCreate(sim, 9,pos10);
	//ParticleCreate(sim,10,pos11);
	//ParticleCreate(sim,11,pos12);
	//ParticleCreate(sim,12,pos13);
	//ParticleCreate(sim,13,pos14);

	// GetDistanceTest(sim);
	ForceTest(sim);

	// printf("Position of particle 1:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[0].pos[0], sim->part_arr[0].pos[1], sim->part_arr[0].pos[2]);
	// //test set position
	// printf("Position of particle 2:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[1].pos[0], sim->part_arr[1].pos[1], sim->part_arr[1].pos[2]);	
	
	// SetPosition(sim, 0, pos3);
	
	// printf("Position of particle 1 after update:\nx: %f\ny: %f\nz: %f\n",sim->part_arr[0].pos[0], sim->part_arr[0].pos[1], sim->part_arr[0].pos[2]);

	// printf("\nGet Distance Test\n");
	// GetParticleDistance(sim, 0, 1);
	
}

void GetDistanceTest(Simulation *sim)
{
	printf("GetDistance Test\n");

	GetParticleDistance(sim, 0, 1);
	GetParticleDistance(sim, 2, 3);
	GetParticleDistance(sim, 4, 5);
	GetParticleDistance(sim, 6, 7);
	GetParticleDistance(sim, 8, 9);
	GetParticleDistance(sim,10,11);
	GetParticleDistance(sim,12,13);

}

void ForceTest(Simulation *sim)
{
	printf("Force Test\n");
	Particle* arr = sim->part_arr;
	double *force = (double*)malloc(4*sizeof(double));

	for (int i = 0; i < sim->b; i++)
	{
		printf("Particle %d\nx %f\ny %f\nz %f\n\n",i, arr[i].pos[0], arr[i].pos[1], arr[i].pos[2]);
	}
	printf("\n\n-----------------------\n\n");
	SimulationNetForce(sim);
	force = sim->force_arr;
	for (int i = 0; i < sim->b; i++)
	{
		printf("\nNet Force\nx %f\ny %f\nz %f\n", force[3*i+0], force[3*i+1], force[3*i+2]);
	}
	printf("\n\n-----------------------\n\n");
	for (int i = 0; i < sim->b; i++)
	{
		printf("Particle %d\nx %f\ny %f\nz %f\n\n",i, arr[i].pos[0], arr[i].pos[1], arr[i].pos[2]);
	}

}












