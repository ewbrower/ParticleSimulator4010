#inlcude <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Simulation.h"

int main(int npos, double L, int nsteps)
{
clock_t start_time, end_time;
double avg_time;
  int parts, i, j, k;
  //verify valuable parameters are entered
	if (L <= 0 || npos <= 0 || nsteps <= 0)
	{
		printf("no parameters should be non-positive\n");
		return -1;
	}

  
  printf("Created simulation!\nbox length: %f\nparticles: %d\n", L, npos);

  
  start_time = clock();
  for(j = 0; j < 100; j++)
  {
	Simulation *sim;
	sim = CreateSimulation(L, npos);
	parts = CreateParticles(sim);
	WriteToFile(sim);
	for (i = 0; i < steps; i++)
	{
		
		//Calls WriteToFile function
		Update(sim);
		//printf("-- Update %d Force Summary --\n", i);
		WriteToFile(sim);
		//for(j = 0; j < npos*3; j+=3)
		//{
		//	printf("Particle %d\n", j/3);
		//	for (k = 0; k < 3; k++)
		//	{
		//		printf("%f ", sim->force_arr[j+k]);
		//	}
		//	printf("\n");
		//}
		//printf("\n");
	}
	DestroySimulation(sim);
  }
	end_time = clock();
	avg_time = ((end_time - start_time)*1000)/(CLOCKS_PER_SEC*100)
	printf("Number of particle: %d\nTime elapsed: %f\n", npos, avg_time);

	return 0;

}
