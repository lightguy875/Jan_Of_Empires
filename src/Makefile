IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs
TESTFLAGS= -l gtest -l pthread -ftest-coverage -fprofile-arcs
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = Necromancer.hpp Bloco.hpp Recurso.hpp Pilar.hpp  
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Necromancer.o Bloco.o Recurso.o Pilar.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tests:  $(OBJ)
	$(CC) -o $@ Teste.cpp $^ $(TESTFLAGS)

.PHONY: clean

run: 
	./tests

# cov: 
# 	gcov obj/codeline_counter.

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ tests obj/*.* *.gcda *.gcno *.gcov

