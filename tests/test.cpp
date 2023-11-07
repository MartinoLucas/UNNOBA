#include <iostream>

void test(int*& ptr) {
    ptr = new int();
    std::cout << ptr << std::endl;
}

int main() {
    int* ptr = nullptr;
    std::cout << ptr << std::endl;
    test(ptr);
    std::cout << ptr;
}