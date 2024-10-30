#include <iostream>

using namespace std;

class myvector
{
    int *p;            // base pointer of the vector
    unsigned int size; // size of the vector
    bool shallow;      // flag indicating whether this is a shallow copy
    unsigned int *ref_count; // reference count for shared memory

public:
    /* create an empty vector */
    myvector()
    {
        p = nullptr;
        size = 0;
        shallow = false;
        ref_count = new unsigned int(1); // Initialize reference count
    }

    /* create a vector of length size initialized to 0 */
    myvector(unsigned int n)
    {
        shallow = false;
        size = n;
        p = new int[size];
        ref_count = new unsigned int(1); // Initialize reference count
        for (int i = 0; i < size; i++)
        {
            p[i] = 0;
        }
    }

    /* copy constructor */
    myvector(myvector &v, bool shallow = true)
    {
        this->shallow = shallow;
        size = v.get_size();
        if (shallow) // shallow copy
        {
            p = v.get_ptr();
            ref_count = v.ref_count; // Point to the same reference count
            (*ref_count)++; // Increment reference count
        }
        else // deep copy
        {
            p = new int[this->size];
            for (int i = 0; i < this->size; i++)
            {
                p[i] = (v.get_ptr())[i]; // copying the elements
            }
            ref_count = new unsigned int(1); // New ref count for deep copy
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

    /* update the element at index i with val */
    void update(unsigned int i, int val)
    {

        p[i] = val;
    }

    /* destructor */
    ~myvector()
    {
        if (ref_count && --(*ref_count) == 0) // Decrease ref count
        {
            delete[] p; // Delete the allocated memory
            delete ref_count; // Delete the reference count
        }
    }
};

int main()
{
    myvector x(7); // create a vector of size 7 initialized to 0
    for (unsigned int i = 0; i < 7; i++)
        x.update(i, 10 + 5 * i);

    myvector v{x}; // shallow copy
    v.update(1, 100);
    x.print();

    myvector y{x, false}; // deep copy
    y.update(1, 200);
    x.print();

    return 0;
}

