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
	echo 'cd $$PBS_O_WORKDIR ;  ./dna /home/u42508/TETproject4/datasets/example2.txt' | qsub -l nodes=1:flat -l walltime=00:10:00 -N dnastring

clean:
	rm -f *.optrpt *.o dna *~ dnastring.*
