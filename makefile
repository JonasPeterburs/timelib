prog: main.o timelib.o
  gcc -o prog main.o timelib.o
  
main.o: main.c
  gcc -c main.c
  
timelib.o: timelib.c
  gcc -c timelib.c
