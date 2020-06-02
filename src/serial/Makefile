CXX=icpc
CXXFLAGS=-c -qopenmp
LDFLAGS=-qopenmp

OBJECTS=main.o

dna: $(OBJECTS)
        $(CXX) $(LDFLAGS) -o dna $(OBJECTS)

all:    dna

run:    all
        ./dna

queue:  all
        echo 'cd $$PBS_O_WORKDIR ; ./dna' | qsub -l nodes=1:flat -l walltime=00:05:00 -N dnastring

clean:
        rm -f *.optrpt *.o dna *~ dnastring.*
