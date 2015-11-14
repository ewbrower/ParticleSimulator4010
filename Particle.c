#include "Particle.h"

struct Particle {
    double *pos;
 };

double* GetPos(Particle *p)
{
	// return an array of double
	return p->pos;
}

Particle* ParticleCreate(double* init_pos)
{
	Particle *p = malloc(sizeof(Particle));
	p->pos = init_pos;

	return p;
}
