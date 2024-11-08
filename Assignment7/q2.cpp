#include <iostream>
using namespace std;
// changes
class Tiny
{
    char v;
    void assign(int i)
    {
        if (i & ~077)
            throw Bad_range();
        v = i;
    }

public:
    class Bad_range
    {
    };
    /* To be completed */
    Tiny(int i)
    {
        assign(i);
    }
    Tiny &operator=(int i)
    {
        assign(i);
        return *this;
    }
    Tiny operator-(Tiny &x)
    {
        return (this->v - x.v);
    }

    Tiny operator+(Tiny &x)
    {
        return (this->v + x.v);
    }

    operator int() const
    {
        return this->v;
    }

    int get_v()
    {
        return this->v;
    }
    ostream &operator<<(ostream &stream)
    {
        stream << this->get_v() << endl;
        return stream;
    }
};

/* Example of Tiny objects mixing with ints in arithmetic expressions */
int main()
{
    int i;
    Tiny c1 = 2;       // Perform range check
    Tiny c2 = 62;      // perform range check
    Tiny c3 = c2 - c1; // c3 = 60;
    std::cout << c3 << std::endl;
    Tiny c4 = c3; // no range check required
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    i = int(c1) + int(c2); // i = 64
    c1 = c1 + c2;          // range error: c1 can’t be 64
    std::cout << c1 << std::endl;
    i = c3 - 64; // i = -4
    std::cout << i << std::endl;
    c2 = c3 - 64; // range error: c2 can’t be -4
    std::cout << c2 << std::endl;
    c3 = c4; // no range check required
    std::cout << c4 << std::endl;
}