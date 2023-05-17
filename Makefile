Main: Main.c
	$(CC) Main.c ProcessManager.c InputParser.c Errors.c -o Main -D_XOPEN_SOURCE=600 -Wall -Wextra -pedantic -std=c99 && trap '$(RM) Main' EXIT; ./Main
	$(RM) Main
