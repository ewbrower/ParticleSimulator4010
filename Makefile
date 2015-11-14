tester: Simulation.c test.c Simulation.h
	gcc -lm -o tester Simulation.c test.c
debug: Simulation.c test.c Simulation.h
	gcc -g -lm -o tester Simulation.c test.c
clean: 
	rm -f *.o tester
