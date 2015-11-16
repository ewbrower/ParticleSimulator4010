#ifndef SIMULATION_H
#define SIMULATION_H
#define TIMESTEP  0.0002
//#include "Particle.h"

struct particle {
	double *pos;
};

typedef struct particle Particle;

struct simulation {
	Particle *part_arr;
	double L;
	int b;
	double *force_arr;
};
typedef struct simulation Simulation;

// ***** simulation functions *****
// create simulation
Simulation* CreateSimulation(double l, int b);
// destroy a simulation
void DestroySimulation(Simulation *sim);
// update simulation to next timestep (which is known)
void Update(Simulation *sim);
// write to the xyz file
void WriteToFile(Simulation *sim, int timestep);

// ***** particle functions *****
// create a particle at a particular position
void ParticleCreate(Simulation *sim, int partInex, double* init_pos);
// generate the array of random Particles (private)
int CreateParticles(Simulation *sim);
// generate randome brownian
void GetBrownian(double *brownian);
// particle distance getter thing
double* GetParticleDistance(Simulation *sim, int partIndexA, int partIndexB);
// find net force
void SimulationNetForce(Simulation *sim);
// update position (correctly taking into account box dimensions)
double* SetPosition(Simulation *sim, int partIndex, double *pos);
// get position
void GetPosition(Simulation *sim, int partIndex, double* pos);

// ***** tests *****
int GetDistanceTest(Simulation *sim);
int ForceTest(Simulation *sim);
int StackTest(double length, int particles, int steps);
int VerifyPosition(Simulation *sim, int partIndex);
int ParticlePair();
void PrintSummary(Simulation *sim, int i);

#endif
