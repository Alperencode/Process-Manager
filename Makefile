Main: Main.c
	$(CC) Main.c ProcessManager.c InputParser.c Errors.c -o Main -Wall -Wextra -pedantic -std=c99 && trap '$(RM) Main' EXIT; ./Main
	$(RM) Main
