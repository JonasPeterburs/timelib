CC = gcc
CFLAGS  = -g -Werror
TARGET = timelib

all: timelib

timelib: main.o timelib.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o timelib.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

timelib.o: timelib.c timelib.h
	$(CC) $(CFLAGS) -c timelib.c
