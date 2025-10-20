CC = gcc
CFLAGS = -I -Wall -std=c23

mylisp: main.c 
	$(CC) -o mylisp main.c $(CFLAGS)