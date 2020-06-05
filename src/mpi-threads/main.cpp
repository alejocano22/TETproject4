#include <omp.h>
#include <mpi.h>
#include <cmath>
#include "dna.h"
#include <iostream>
#define P float

const int nTrials = 10;
const int skipTrials = 3;  // Skip first iteration as warm-up

using namespace std;

double Stats(double &x, double &dx) {
  x /= (double)(nTrials - skipTrials);
  dx = sqrt(dx / double(nTrials - skipTrials) - x * x);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s {file}\n", argv[0]);
    exit(1);
  }

  MPI_Init(&argc, &argv);
  int myRank, nRanks;
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
  MPI_Comm_size(MPI_COMM_WORLD, &nRanks);

  if (myRank == 0) {
    printf("\033[1m%5s %15s\n", "Step", "Time, ms");
    fflush(stdout);
  }

  double t, dt;

  for (int iTrial = 1; iTrial <= nTrials; iTrial++) {
    fstream file(argv[1]);
    if(!file.is_open()){
      cout << "Error leyendo el fichero" << endl;
      exit(1);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    const double t0 = omp_get_wtime();
    applyDna(file, myRank, nRanks);
    MPI_Barrier(MPI_COMM_WORLD);
    const double t1 = omp_get_wtime();
    
    const double ts = t1 - t0;      // time in seconds
    const double tms = ts * 1.0e3;  // time in milliseconds
    
    if (iTrial > skipTrials) {  // Collect statistics
      t += tms;
      dt += tms * tms;
    }
    

    // Output performance
    if (myRank == 0) {
      printf("%5d %15.3f %s\n", iTrial, tms,
	     (iTrial <= skipTrials ? "*" : ""));
      fflush(stdout);
    }
  }
  if (myRank == 0){
    Stats(t, dt);
    printf("-----------------------------------------------------\n");
    printf(
	   "\033[1m%s\033[0m\n%8s   \033[42m%8.1f+-%.1f\033[0m\n",
	   "Average performance:", "", t, dt);
    printf("-----------------------------------------------------\n");
    printf("* - warm-up, not included in average\n\n");
  }
  MPI_Finalize();
  return 0;
}
