#include <iostream>

using namespace std;

int main() {
    int *p;

    // Allocate an array of 10 integers
    p = new int[10];

    // Do something with p

    // Deallocate the memory, but don't set p to nullptr
    delete[] p;
	p = nullptr;

    // At this point, p is a dangling pointer because it points to a block of
    // memory that has been deallocated.
    cout << *p << endl;  // Dereferencing a dangling pointer can lead to undefined behavior

    return 0;
}

