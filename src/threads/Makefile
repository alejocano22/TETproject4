CXX=icpc
CXXFLAGS=-c -qopenmp -qopt-report=5 -xMIC-AVX512
LDFLAGS=-qopenmp

OBJECTS=main.o dna.o

dna: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o dna $(OBJECTS)

all:    dna

run:    all
	./dna

queue:  all
	echo 'cd $$PBS_O_WORKDIR ;  ./dna /home/u43411/TETproject4/datasets/ADN.txt' | qsub -l nodes=1:flat -l walltime=00:03:00 -N dnastring

clean:
	rm -f *.optrpt *.o dna *~ dnastring.*
