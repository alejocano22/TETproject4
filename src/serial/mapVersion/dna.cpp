#include "dna.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void applyDna(ifstream &infile){
  string line;
  vector<string> strings;
  vector<map<char, int> > count;
  
  while (getline(infile, line)) {
    strings.push_back(line);
  }

  char resultBuffer[strings[0].size()];
  cout << strings[0].size() << endl;
  for (int col = 0; col < strings[0].size(); ++col) {
    map<char, int> currentCount;
    for (int row = 0; row < strings.size(); ++row) {
      currentCount[strings[row][col]]++;
    }
    count.push_back(currentCount);
  }

  for (int row = 0; row < count.size(); row++) {
    char argMax;
    char max = 0;
    for (map<char, int>::iterator it = count[row].begin();
	 it != count[row].end(); ++it) {
      if (it->second > max) {
	argMax = it->first;
	max = it->second;
      }
    }
    resultBuffer[row] = argMax;
    //    cout << argMax;
  }
  ofstream outputFile;
  outputFile.open ("result.txt");
  outputFile << resultBuffer;
  outputFile << "\n";
  outputFile.close();
}
