#Makefile for "	Cadastro de Animais em um Petshop" C++ application
#Created by Thais Lins 28/10/2016

PROG = petfera
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11
OBJS = main.o funcionario.o animal.o animalsilvestre.o

all: petfera

petfera: main.o funcionario.o animal.o animalsilvestre.o 
	$(CC) main.o funcionario.o animal.o animalsilvestre.o -o pf

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

funcionario.o: funcionario.cpp
	       $(CC) $(CPPFLAGS) -c funcionario.cpp

animal.o: animal.cpp
	  $(CC) $(CPPFLAGS) -c animal.cpp

animalsilvestre.o: animalsilvestre.cpp
		   $(CC) $(CPPFLAGS) -c animalsilvestre.cpp

clean:
	rm -rf *o $(OBJS) 	



