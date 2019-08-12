CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o

COMPILE = $(CC) $(FLAGS) -c

all: 01

01 : main.o complex.o
	$(LINK) $@ $^

main.o : main.cc main.h
	$(COMPILE) $<

complex.o : complex.cc complex.h
	$(COMPILE) $<

clean:
	@rm main.o complex.o 