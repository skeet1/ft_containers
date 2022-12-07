// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    
    vector<int> v(3, 10);
    /*
	for (size_t i = 0; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    
    cout << v.size() << "\n";
    cout << v.max_size() << "\n";
	*/
	cout << v.front() << endl;
	//cout << v.back() << endl;
    return 0;
}
