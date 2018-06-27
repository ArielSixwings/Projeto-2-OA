IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -g

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = In_OutPuts.h ArvoreB.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = In_OutPuts.o Main.o ArvoreB.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: Trabalho2

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Trabalho2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -g
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 