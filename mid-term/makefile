CC = gcc

FLAGS = -c -g -Wall

LFLAGS = -labs -lgraph -lfdr

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

PROGRAM = main

LIBS = -L../lib/implementation

INCLUDES = -I../lib/include


all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS) $(INCLUDES) $(LIBS) $(LFLAGS)


.c.o: $(SRCS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)

clean:
	find . -type f | xargs touch
	rm -rf core $(PROGRAM) $(OBJS) *~
