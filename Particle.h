#ifndef PARTICLE_H
#define PARTICLE_H


typedef struct Particle Particle;

// get position returns an array of three double
double* GetPosition(Particle *p);

Particle* ParticleCreate(double* init_pos);
// Brownian returns an array of three doubles of Brownian displacement
// double* GetBrownian();
#endif
