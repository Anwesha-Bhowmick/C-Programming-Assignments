//file copy char by char
#include<iostream>
#include<fstream>
using namespace std;


int main()
{
  int sum=0;
  ifstream inFile("f1.txt", ios::in);//opening the input file
  if(inFile.fail())//checking the fail state
  {
    cout<<"Cannot open the output file."<<endl;
  }
  
  char c;
  while(inFile.get(c))
  {
    sum=sum + int(c);
  }
  cout<<"total = "<<sum<<endl;
  return 0;
}
//even if the input file is not present the program runs and creates an empty output file 
