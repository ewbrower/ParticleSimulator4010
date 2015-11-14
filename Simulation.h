#ifndef SIMULATION_H
#define SIMULATION_H
#define TIMESTEP = 0.0002
//#include "Particle.h"

struct particle {
	double *pos;
};

typedef struct particle Particle;

struct simulation {
	Particle *part_arr;
	double L;
	int b;
};
typedef struct simulation Simulation;
// create simulation
Simulation* CreateSimulation(double l, int b);
// // generate the array of random Particles (private)
// int CreateParticles(Simulation sim);
//
// // update simulation to next timestep (which is known)
// void Update(Simulation sim);
// // particle distance getter thing
double GetParticleDistance(Simulation *sim, int partIndexA, int partIndexB);
// // find net force
double* SimulationNetForce(Simulation sim, int partIndex);
// // check if in box update position to correct one
 double* SetPosition(Simulation *sim, int partIndex, double *pos);
//
// // write to the xyz file
// void WriteToFile(Simulation sim);
//
//
void ParticleCreate(Simulation *sim, int partInex, double* init_pos);
void GetDistanceTest();
#endif
