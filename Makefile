tester: Simulation.c test.c Simulation.h
	gcc -lm -o tester Simulation.c test.c
debug: Simulation.c test.c Simulation.h
	gcc -g -lm -o tester Simulation.c test.c
clean: 
	rm -f *.o tester
main: Simulation.c Simulation.h main.c
	gcc -lm -o bd Simulation.c main.c