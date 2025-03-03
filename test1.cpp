#include <iostream>
#include <cstdlib>

void unsafe_system_call() {
    char command[50];
    std::cout << "Enter command to run: ";
    std::cin >> command;
    system(command);  // com from sys
}

int main() {
    unsafe_system_call();
    return 0;
}
