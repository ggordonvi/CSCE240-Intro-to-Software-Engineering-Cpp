CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # produce debugging information

LINK = $(CC) $(FLAGS) -o

COMPILE = $(CC) $(FLAGS) -c

01 : complex.o test.o
	$(LINK) $@ $^

complex.o : complex.cc complex.h
	$(COMPILE) $<

test.o : test.cc test.h complex.h
	$(COMPILE) $<

clean:
	@rm *.o 01
