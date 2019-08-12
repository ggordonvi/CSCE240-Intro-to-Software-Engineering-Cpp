CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

CAL = $(CC) $(FLAGS) -o  # compile, assemble, link
CA = $(CC) $(FLAGS) -c  # compile, assemble, do not link

01hw : main.o
	$(CAL) $@ $^
01arrays.o : main.cc
	$(CA) $^

all : 01hw
	@echo All apps made

clean:
	rm main.o 01hw
