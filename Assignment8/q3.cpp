#include <iostream>
using namespace std;

class Char_vec
{
    int sz;
    char element[1];

public:
    static Char_vec *new_char_vec(int s);
    char &operator[](int i)
    {
        return element[i];
    }
    // ...
};
