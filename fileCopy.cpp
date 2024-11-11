//file copy char by char
#include<iostream>
#include<fstream>
using namespace std;


int main()
{
  ifstream inFile("f1.txt", ios::in);//opening the input file
  ofstream outFile("f1_copy.txt", ios::out|ios::trunc);//creating the output file
  if(outFile.fail())//checking the fail state
  {
    cout<<"Cannot open the output file."<<endl;
  }
  
  char c;
  while(inFile.get(c))
  {
    outFile<<c;
  }
  return 0;
}
//even if the input file is not present the program runs and creates an empty output file 
