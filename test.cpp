#include <iostream>
#include <cstring>

void unsafe_copy() {
    char buffer[10];
    strcpy(buffer, "This is a long string!"); // strcpy without length chck
    std::cout << "Buffer contents: " << buffer << std::endl;
}

int main() {
    unsafe_copy();
    return 0;
}
