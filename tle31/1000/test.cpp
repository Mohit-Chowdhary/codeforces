#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
void printType(T) {
    cout << __PRETTY_FUNCTION__ << endl;
}

int main() {
    auto a = {1,2};
    auto b(a);
    auto c = int{1};
    cout << __cplusplus << endl;

    printType(a);
    printType(b);
    printType(c);
}