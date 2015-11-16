#include "Simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[])
{

  if( argc != 3 )
   {
      printf("Incorrect Number of Arguments Supplied \n");
      exit(0);
   }

  //formatting the command parameters
  int npos = atoi(argv[1]);
  double L = atof(argv[2]);
  int nsteps = atoi(argv[3]);

  
  int parts, i, j, k;
  //verify valuable parameters are entered
	if (L <= 0 || npos <= 0 || nsteps <= 0)
	{
		printf("no parameters should be non-positive\n");
		return -1;
	}

  Simulation *sim;
  sim = CreateSimulation(L, npos);
//  printf("Created simulation!\nbox length: %f\nparticles: %d\n", L, npos);

  parts = CreateParticles(sim);

  for (i = 0; i < steps; i++)
	{
    WriteToFile(sim); //Calls WriteToFile function
		Update(sim);
	//	printf("-- Update %d Force Summary --\n", i);
		for(j = 0; j < npos*3; j+=3)
		{
		//	printf("Particle %d\n", j/3);
			for (k = 0; k < 3; k++)
			{
		//		printf("%f ", sim->force_arr[j+k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;

}
