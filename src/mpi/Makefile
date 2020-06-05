CXX=mpiicpc
CXXFLAGS=-c -qopenmp -qopt-report=5 -xMIC-AVX512
LDFLAGS=-qopenmp -lmemkind

OBJECTS=main.o dna.o

dna: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o dna $(OBJECTS)

all:    dna

run:    all
	./dna

queue:  all
	echo 'cd $$PBS_O_WORKDIR ; mpirun -machinefile $$PBS_NODEFILE ./dna /home/u42508/TETproject4/datasets/ADN.txt' | qsub -l nodes=4:flat -l walltime=00:03:00 -N dnastring

clean:
	rm -f *.optrpt *.o dna *~ dnastring.*
