#include "dna.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void applyDna(fstream &file, int const myRank, int const nRanks){
  string firstLine;
  getline(file, firstLine);
 
  int numCols = firstLine.size();
  char resultBuffer[numCols];

  const int colPerProcess = int(double(numCols) / double(nRanks));
  int initialPosition = colPerProcess*myRank;
  vector<string> strings; 
  int totalRows = 0;

  while(true){
    file.seekp(initialPosition + totalRows*(numCols + 1));        
    char buffer[colPerProcess + 1];
    file.read(buffer, colPerProcess);

    if(!file){
      break;
    }

    buffer[colPerProcess] = 0;  
    string dna(buffer);
    strings.push_back(dna);
    totalRows++;
  } 
  int count [4][colPerProcess];
  for (int col = 0; col < colPerProcess; ++col) {
    int currentCount [4] = {};
    for (int row = 0; row < totalRows; ++row) {
      switch (strings[row][col]) {
      case 'A':
	currentCount[0]++;
	break;
      case 'C':
	currentCount[1]++;
	break;
      case 'G':
	currentCount[2]++;
	break;
      case 'T':
	currentCount[3]++;
	break;
      }     
    }
    count[0][col] = currentCount[0];
    count[1][col] = currentCount[1];
    count[2][col] = currentCount[2];
    count[3][col] = currentCount[3];
  }
  
  for (int col = 0; col < colPerProcess; col++){
    char argMax;
    int max = 0;
    for (int row = 0; row < 4; row++){
      if (count[row][col] > max){
	switch (row) {
	case 0:
	  argMax = 'A';
	  break;
	case 1:
	  argMax = 'C';
	  break;
	case 2:
	  argMax = 'G';
	  break;
	case 3:
	  argMax = 'T';
	  break;
      
	}
	max = count[row][col];
      } 
    }

    resultBuffer[initialPosition + col] = argMax;
  }
  MPI_Allgather(MPI_IN_PLACE, 0, MPI_DATATYPE_NULL, &resultBuffer[0], colPerProcess, MPI_CHAR, MPI_COMM_WORLD);
  if (myRank == 0){
    ofstream outputFile;
    outputFile.open ("result.txt");
    outputFile << resultBuffer;
    outputFile << "\n";
    outputFile.close();
    /*
    for (int i = 0; i < numCols; i++){
      cout << resultBuffer[i]; // escribir a un fichero externo
    }
    */
  }
  //  cout << endl;
}
// valorant?
