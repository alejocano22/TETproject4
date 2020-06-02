
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void usage(const char *name)
{
    cerr << "Usage: " << name << " <dataset>.txt" << endl;
    exit(0);
}

int main(int argc, char const *argv[]) {
      if (argc != 2)
    {
        usage(argv[0]);
    }

    ifstream infile(argv[1]);
    string line;

    vector<string> strings;
    vector<map<char, int>> count;
   
    while (getline(infile, line)) {
        strings.push_back(line);
    }
   
    for (int col = 0; col < strings[0].size() -1; ++col) {     
        map<char, int> currentCount; 
        for (int row = 0; row < strings.size(); ++row) {
            currentCount[strings[row][col]]++;
        }
        count.push_back(currentCount);

    }
   
    for (int row = 0;  row < count.size(); row++){
        char argMax; 
        char max = 0;
        for (map<char,int>::iterator it=count[row].begin(); it != count[row].end(); ++it){        
            if (it->second > max){
                argMax = it->first;
                max = it->second;
            }
        }
        cout << argMax;    
    }
    
    return 0;
}