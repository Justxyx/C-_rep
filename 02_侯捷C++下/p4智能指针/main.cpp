#include <iostream>
using namespace std;

template<class T>
class p{
private:
    T* px;
public:
    T& operator* () const{
        return *px;
    }
    T* operator->() const{
        return px;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
