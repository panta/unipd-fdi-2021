# uncomment to enable debug, comment to disable
DEBUG ?= y

BINARIES ?= any-v1 any-v2 any-v3

CFLAGS ?= -std=c99 -Wall -Wextra -pedantic -Wstrict-prototypes -Wconversion -Werror
CC = gcc
CPP = cpp

ifdef DEBUG
CFLAGS += -g
else
CFLAGS += -O2
endif

all: depend $(BINARIES)

-include .depend

clean:
	-rm -f .depend *.o $(BINARIES)
	@-rm -rf *.dSYM

depend :
	@rm -f .depend
	@for i in *.c; do  \
		$(CC) -MM $(CFLAGS) $$i >> .depend ; \
	done

# automatic rule to compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# automatic rule to compile .c files directly into executable files
%: %.c
	$(CC) $(CFLAGS) -o $@ $< -lm
