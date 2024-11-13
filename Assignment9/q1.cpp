#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

/* A file descriptor type */
class fileRA{
 
  public:
  fstream fd;
  int pos;
  fileRA(string name)
  {
    fd.open(name, ios::in|ios::out);
  }
  fileRA &operator[](int i)
  {
    fd.seekp(i);//set the put pointer to ith position
    pos=i;
    return *this;    
  }
 
  int get_size()
  {
  string c;
    int count;
    while(getline(fd,c))
    {
      count +=c.length();
    }
    return count;
  }

  operator char() const
  {
    fd.seekg(pos);
    char c=fd.get();
    return c;
  }
  
  fileRA &operator=(char c)
  {
    fd.seekp(pos);
    fd.put(c);
    return *this;
  }
  
};
ostream& operator<<(ostream &os, const fileRA &f)
  {
    os<<f.(fd.peek())<<endl;
    return os;
  }
  
  
int main()
{
  /* Opens the file in read and write mode */
  fileRA fobj("Test.txt");
  //std::cout << fobj[2];
  //fobj[4] = 'A'; // random writing to file
  /* print the contents of the file */
  cout<<fobj.get_size();
  for(unsigned int i=0;i<fobj.get_size();i++)
    std::cout << fobj[i];
  //char c = fobj[1]; // implicit conversion to char
  //std::cout << "Char is = " << c << std::endl;
}

//seekg
//seekp
