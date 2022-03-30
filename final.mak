a.out:final.o c_final.o
	gcc final.o c_final.o
final.o:final.c final.h
	gcc -c final.c
c_final.o:c_final.c final.h
	gcc -c c_final.c