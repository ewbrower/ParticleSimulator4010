int main(int npos, double L, int nsteps)
{

  int parts, i, j, k;
  //verify valuable parameters are entered
	if (L <= 0 || npos <= 0 || nsteps <= 0)
	{
		printf("no parameters should be non-positive\n");
		return -1;
	}

  Simulation *sim;
  sim = CreateSimulation(L, npos);
  printf("Created simulation!\nbox length: %f\nparticles: %d\n", L, npos);

  parts = CreateParticles(sim);

  for (i = 0; i < steps; i++)
	{
    WriteToFile(sim); //Calls WriteToFile function
    SimulationNetForce(sim);
		Update(sim);
		printf("-- Update %d Force Summary --\n", i);
		for(j = 0; j < npos*3; j+=3)
		{
			printf("Particle %d\n", j/3);
			for (k = 0; k < 3; k++)
			{
				printf("%f ", sim->force_arr[j+k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;

}
