Main: Main.c
	$(CC) Main.c -o Main -Wall -Wextra -pedantic -std=c99 && trap '$(RM) Main' EXIT; ./Main
	$(RM) Main
