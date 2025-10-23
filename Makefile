CC = gcc
CFLAGS = -I -Wall -std=c23

mylisp: parsing.c mpc.c evaluation.c
	$(CC) -o mylisp parsing.c mpc.c evaluation.c $(CFLAGS)