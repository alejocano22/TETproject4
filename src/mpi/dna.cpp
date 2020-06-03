#include "dna.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void applyDna(ifstream &infile){
  string line;
  vector<string> strings;


  while (getline(infile, line)) {
    strings.push_back(line);
  }

  int numCols = strings[0].size() -1;
  int numRows = strings.size();
  int count [4][numCols];

  for (int col = 0; col < numCols; ++col) {
    int currentCount [4] = {};

    for (int row = 0; row < numRows; ++row) {
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
 
  for (int col = 0; col < strings[0].size(); col++){
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
    //    cout << argMax;
  }
}
// valorant?
