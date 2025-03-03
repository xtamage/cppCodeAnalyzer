#include <fstream>
#include <regex>
#include <iostream>
#include <vector>

void analyze_code(const std::string &file_name){
    std::ifstream file(file_name);
    if(!file){
        std::cerr << "Error occured. File cannot be opened" << std::endl;
        return;
    }


std::regex danger_patterns[] = {


    std::regex(R"(strcpy\s*\()"),
    std::regex(R"(gets\s*\()"),
    std::regex(R"(sprintf\s*\()"),
    std::regex(R"(system\s*\()"),
    std::regex(R"(malloc\s*\()"),
    std::regex(R"(new\s)")
};


std::vector<std::pair<int, std::string>> issues;
std::string line;
int line_num = 0;

while(std::getline(file, line)){
    line_num++;
    for(const auto &pattern : danger_patterns){
        if(std::regex_search(line, pattern)){
            issues.push_back({line_num, line});
        }
    }
}
file.close();


if(issues.empty()){
    std::cout << "No vulnerabilities found.\n";

}else{
    std::cout << "Vulnerabilities found:\n";
    for(const auto &issue : issues){
        std::cout << "LIne " << issue.first << ": " << issue.second << std::endl;
    }

}
}
int main(int argc, char *argv[]){
    if(argc != 2){
        std::cerr << "Please enter the correct arguments.\n";
        std::cout << "Using: " << argv[0] << " (filename.cpp)\n";
        return 1;

    }
    analyze_code(argv[1]);
    return 0;

}