#include <fstream> 
#include <iostream> 
#include <string>

using namespace std; 

int main(){
  fstream file("/home/u42508/TETproject4/datasets/ejemplo.txt", ios::out|ios::in); 
  if(!file.is_open()){
    cout << "error";
  }else{
    int rank = 1;
    int totalRank = 4;
    int lon = 9;
    int steps = (lon-1) / 4;
    int row = 90;

    cout << file.tellg() << endl;
    file.seekp(steps*rank + row*lon);
    cout << file.tellg() << endl;
    char A[3]; 
    file.read(A, 2);
    if (!file){
      cout << "Termine de leer" << endl;
    }
    A[2] = 0;  
    // Output the contents read from the file and close it  
    cout << A << endl; 

  }
  return 0;      
}
