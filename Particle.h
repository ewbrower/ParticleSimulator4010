#ifndef PARTICLE_H
#define PARTICLE_H

// Eric will do all three of these particle functions
// (because they are easy and he's choosing)
//
// get position returns an array of three double
double* GetPosition(int partIndex);

// set position
int SetPosition(Simulation sim, int partIndex, int x, int y, int z);

// Brownian returns an array of three doubles of Brownian displacement
double* GetBrownian();

#endif