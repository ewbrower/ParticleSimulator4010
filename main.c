#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Simulation.h"
#include <math.h>
#include <string.h>


int main(int argc, char *argv[])
{

    if( argc != 4 )
    {
      printf("Incorrect Number of Arguments Supplied \n");
      exit(0);
    }

    clock_t start_time, end_time;
    double avg_time;
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

  
    printf("Created simulation!\nbox length: %f\nparticles: %d\n", L, npos);
    
    start_time = clock();
    // for(j = 0; j < 100; j++)
    // {
        Simulation *sim;
        sim = CreateSimulation(L, npos);
        parts = CreateParticles(sim);
        WriteToFile(sim, 0.0);
        for (i = 0; i < nsteps; i++)
        {
        	//Calls WriteToFile function
        	Update(sim);
        	//printf("-- Update %d Force Summary --\n", i);
        	WriteToFile(sim, i+1.0);
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
    // }
	end_time = clock();
	avg_time = (((double)end_time - (double)start_time)*1000)/(CLOCKS_PER_SEC*100);
	printf("Number of particle: %d\nAvg Time elapsed: %f milliseconds\n", npos, avg_time);

	return 0;

}
