#include <iostream>
#include <cstring>

void insecure_function(char *input) {
    char buffer[50];
    strcpy(buffer, input);  
    std::cout << "Hello, " << buffer << "!" << std::endl;
}

int main() {
    char user_input[100];
    std::cout << "Enter your name: ";
    gets(user_input);  
    insecure_function(user_input);

    system("ls -la");  
    return 0;
}
