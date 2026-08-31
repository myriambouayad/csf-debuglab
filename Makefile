#
# Makefile for C Debug Lab
#
CC = gcc
CFLAGS = -I. -Wall -Werror -g
RM = /bin/rm
RMFLAGS = -f
SRCS =  thebomb.c

OBJS = $(SRCS:.c=.o)
PROGS = $(SRCS:.c=)

# This is the multi-executable target...
# If you type 'make' at the command line it will build
# all programs
.PHONY: all

all: $(PROGS)

$(PROGS): %: %.o Makefile
	$(CC) $< -o $@

# This line will convert any .c file to a .o file.
%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $<


# This target line will run your program
# Type 'make run' to run your program with your defuse strings from psol.txt
run:
	./thebomb < psol.txt

# Type 'make clean' up the subdirectory...
# Be Very Careful Not To Haphazzardly Make Changes!!!!!!!
clean:
	$(RM) $(RMFLAGS) $(PROGS) $(OBJS) 


