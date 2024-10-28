#include <iostream>

using namespace std;

class myvector
{
    int *p;            // base pointer of the vector
    unsigned int size; // size of the vector
    bool shallow;
    // flag indicating whether this is a shallow copy of another myvector
public:
    /*create an empty vector */
    myvector()
    {
        p = nullptr;
        size = 0;
        // shallow=true;
    }
    /* create a vector of length size initialized to 0 */
    myvector(unsigned int n)
    {
        size = n;
        p = new int[size];
    }
    /*copy constructor. Can be shallow or deep depending on the option */
    myvector(myvector &v, bool shallow = true)
    {
        if (shallow)
        {
            this->shallow = v.is_shallow();
            size = v.get_size();
            p = v.get_ptr();
        }
        else
        {
            this->shallow = v.is_shallow();
            size = v.get_size();
            p = new int[this->size];
            for (int i = 0; i < this->size; i++)
            {
                p[i] = (v.get_ptr())[i]; // copying the elements
            }
        }
    }
    /* return the base pointer to the vector */
    int *get_ptr() const
    {
        return this->p;
    }
    /* return the size of the vector */
    unsigned int get_size() const
    {
        return this->size;
    }
    /* Return the shallow flag */
    bool is_shallow() const
    {
        return this->shallow;
    }
    /*update the element at index i with val*/
    void update(unsigned int i, int val)
    {
        p[i] = val;
    }
    /*return the element at index i*/
    int get(unsigned int i) const
    {
        return p[i];
    }
    /*print the vector contents in the console */
    void print() const
    {
        int *temp = this->get_ptr(); // pointing to the the base address of the vector
        for (int i = 0; i < this->get_size(); i++)
        {
            cout << temp[i] << "  ";
        }
        cout << "\n";
    }
    /*Expand the vector and insert a new value at the end.*/
    void push_back(int val)
    {
        myvector temp(*this, true);        // copy of the object
        this->size = this->size + 1;       // incrementing the size of the original object
        this->p = new int[this->size + 1]; // new vector
        for (int i = 0; i < temp.size; i++)
            this->p[i] = temp.p[i]; // copying the elements into the new vector
        this->p[this->size - 1] = val;
    }
    ~myvector()
    {
        delete p; // deallocation
    }
};

int main()
{
    myvector x(7); /*create a vector of size 7 initialized all to 0 */
    for (unsigned int i = 0; i < 7; i++)
        x.update(i, 10 + 5 * i);
    myvector v{x}; // shallow copy
    v.update(1, 100);
    v.print();
    // print the contents of x and verify that x has also changed on updating v.
    x.print();
    myvector y{x, false}; // deep copy
    y.update(1, 200);
    y.print();
    // print the contents of x and verify that x has NOT changed on updating y.
    x.print();
    // push_back 500 on y and verify
    y.push_back(500);
    y.print();
    return 0;
}