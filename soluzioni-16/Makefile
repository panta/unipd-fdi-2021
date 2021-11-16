# uncomment to enable debug, comment to disable
DEBUG ?= y

BINARIES ?= e16-1 e16-2 e16-3 e16-4 e16-5 e16-6 e17-1 e17-2 e17-3 e17-4 e17-5

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

e16-2: e16-2.o
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
