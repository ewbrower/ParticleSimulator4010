tester: Simulation.c test1.c Simulation.h
	gcc -lm -o tester Simulation.c test1.c
debug: Simulation.c test1.c Simulation.h
	gcc -o -g -lm tester Simulation.c test1.c
clean: 
	rm -f *.o tester
