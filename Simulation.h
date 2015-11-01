#ifndef SIMULATION_H
#define SIMULATION_H
#define TIMESTEP = 0.0002

struct Simulation;
typedef Simulation Simulation;

// Eric will handle these functions
//
// create simulation
Simulation* CreateSimulation(double l, int b);
// generate the array of random Particles (private)
int CreateParticles(Simulation sim);

// Cameron will do the particle functions as per each iteration
// 
// update simulation to next timestep (which is known)
void Update(Simulation sim);
// particle distance getter thing
double GetParticleDistance(Simulation sim, int partIndexA, int partIndexB);
// find net force
double* SimulationNetForce(Simulation sim, int partIndex);
// check if in box
double* SimulationInBox(Simulation sim, int partIndex);

// Abi will handle properly writing the output to xyz files
//
// write to the xyz file
void WriteToFile(Simulation sim);

#endif