#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

/* A file descriptor type */
class fileRA
{
  fstream fd;
  int pos;

public:
  fileRA(const char *name)
  {
    fd.open(name, ios::in | ios::out);
  }
  fileRA &operator[](int i)
  {
    // fd.seekg(i); // set the put pointer to ith position
    this->pos = i;
    return *this;
  }

  int get_size()
  {

    char ch;
    int count;

    while (!fd.eof())
    {
      fd.get(ch);
      if (ch != '\n')
      {
        count++;
        // cout << "count: " << count << endl;
      }
    }

    // cout << "count: " << count << endl;
    fd.seekg(pos);
    return count;
  }

  operator char()
  {
    fd.seekg(pos);
    char c = fd.get();
    if (!fd)
    {
      cerr << "Error: Seek failed at position " << pos << endl;
      exit(1);
    }
    return c;
  }

  fileRA &operator=(char c)
  {
    fd.seekp(pos);
    // fd.put(c);
    fd << c;
    if (!fd)
    {
      cerr << "Error: Seek failed at position " << pos << endl;
      exit(1);
    }
    return *this;
  }
  // ostream &operator<<(ostream &os)
  // {
  //   // os << (char)fd.get() << endl;
  //   // return os;

  //   fd.seekg(pos);
  //   char c = fd.get();
  //   os << c;
  //   return os;
  // }
};
// ostream &operator<<(ostream &os, const fileRA &f)
// {
//   os << f.(fd.peek()) << endl;
//   return os;
// }

int main()
{
  /* Opens the file in read and write mode */
  fileRA fobj("Test.txt");
  // std::cout << fobj.get_size();
  fobj[4] = 'A'; // random writing to file
  /* print the contents of the file */
  //  for (unsigned int i = 0; i < fobj.get_size(); i++)
  //    std::cout << fobj[i];
  char c = fobj[1]; // implicit conversion to char
  std::cout << "Char is = " << c << std::endl;
}
