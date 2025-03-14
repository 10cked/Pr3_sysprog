CC = gcc
CFLAGS = -Wall -Wextra -std=c11
BINDIR = bin

all: $(BINDIR) task1 task2 task3 task4

$(BINDIR):
	mkdir -p $(BINDIR)

task1: task1/task1.c
	$(CC) $(CFLAGS) task1/task1.c -o $(BINDIR)/task1

task2: task2/task2.c
	$(CC) $(CFLAGS) -o $(BINDIR)/task2 task2/task2.c

task3: task3/task3.c
	$(CC) $(CFLAGS) -o $(BINDIR)/task3 task3/task3.c

task4: task4/task4.c
	$(CC) $(CFLAGS) -o $(BINDIR)/task4 task4/task4.c -lm

clean:
	rm -rf $(BINDIR)

.PHONY: all clean task1 task2 task3 task4
