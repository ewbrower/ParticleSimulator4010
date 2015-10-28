#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle {
    double x;
    double y;
    double z;

    double xSpeed;
    double ySpeed;
    double zSpeed;
};

// get position
double GetX(struct Particle);
double GetY(struct Particle);
double GetZ(struct Particle);

// get direction
double GetXSpeed(struct Particle);
double GetYSpeed(struct Particle);
double GetZSpeed(struct Particle);

// update particle position
void UpdatePosition(int timestep);

#endif