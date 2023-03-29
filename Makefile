Main: Main.c
	$(CC) Main.c headers/ProcessManager.c headers/InputParser.c -o Main -Wall -Wextra -pedantic -std=c99 && trap '$(RM) Main' EXIT; ./Main
	$(RM) Main
