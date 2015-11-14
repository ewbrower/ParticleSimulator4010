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
// double* SimulationNetForce(Simulation sim, int partIndex);
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



Particle* ParticleCreate(double* init_pos)
{
	Particle *p = (Particle*)malloc(sizeof(Particle));
	 p->pos = init_pos;
	return p;
}
                      
