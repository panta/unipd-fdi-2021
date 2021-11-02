# uncomment to enable debug, comment to disable
DEBUG ?= y

BINARIES ?= vec3 simple scope ppm mandelbrot

CFLAGS ?= -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror
CC = gcc
CPP = cpp

ifdef DEBUG
CFLAGS += -g
else
CFLAGS += -O2
endif

all: depend $(BINARIES)

-include .depend

vec3: vec3.o
	$(CC) -o $@ $(filter %.o,$^) -lm

simple: simple.o
	$(CC) -o $@ $(filter %.o,$^) -lm

scope: scope.o
	$(CC) -o $@ $(filter %.o,$^) -lm

ppm: ppm.o
	$(CC) -o $@ $(filter %.o,$^) -lm

mandelbrot: mandelbrot.o
	$(CC) -o $@ $(filter %.o,$^) -lm

clean:
	-rm -f .depend *.o $(BINARIES)

depend :
	@rm -f .depend
	@for i in *.c; do  \
		$(CC) -MM $(CFLAGS) $$i >> .depend ; \
	done

# automatic rule to compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
