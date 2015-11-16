<<<<<<< HEAD
#inlcude <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Simulation.h"

int main(int npos, double L, int nsteps)
{
clock_t start_time, end_time;
double avg_time;
=======
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

  
>>>>>>> origin/master
  int parts, i, j, k;
  //verify valuable parameters are entered
	if (L <= 0 || npos <= 0 || nsteps <= 0)
	{
		printf("no parameters should be non-positive\n");
		return -1;
	}

<<<<<<< HEAD
  
  printf("Created simulation!\nbox length: %f\nparticles: %d\n", L, npos);
=======
  Simulation *sim;
  sim = CreateSimulation(L, npos);
//  printf("Created simulation!\nbox length: %f\nparticles: %d\n", L, npos);
>>>>>>> origin/master

  
  start_time = clock();
  for(j = 0; j < 100; j++)
  {
	Simulation *sim;
	sim = CreateSimulation(L, npos);
	parts = CreateParticles(sim);
	WriteToFile(sim);
	for (i = 0; i < steps; i++)
	{
<<<<<<< HEAD
		
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
=======
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
>>>>>>> origin/master
	}
	DestroySimulation(sim);
  }
	end_time = clock();
	avg_time = ((end_time - start_time)*1000)/(CLOCKS_PER_SEC*100)
	printf("Number of particle: %d\nTime elapsed: %f\n", npos, avg_time);

	return 0;

}
