#include <iostream>
#include <string>

void safe_function(const std::string &input) {
    std::string buffer = input;  
    std::cout << "Hello, " << buffer << "!" << std::endl;
}

int main() {
    std::string user_input;
    std::cout << "Enter your name: ";
    std::getline(std::cin, user_input); 
    safe_function(user_input);

    return 0;
}
