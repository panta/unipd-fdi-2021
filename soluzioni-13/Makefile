# uncomment to enable debug, comment to disable
DEBUG ?= y

BINARIES ?= e1 e2-v1 e2-v2 e3 e4 e5 e6 e7 e8 e9 e10 e11

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

e6: e6.o
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
