#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
std::string read_file_contents(const std::string& filename);

int main(int argc, char *argv[]) {
    bool isdoubleSlash = false;
    int ret_val = 0;
    // Disable output buffering
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    if (argc < 3) {
        std::cerr << "Usage: ./your_program tokenize <filename>" << std::endl;
        return 1;
    }

    const std::string command = argv[1];

    if (command == "tokenize") {
        std::string file_contents = read_file_contents(argv[2]);
        
        // if (!file_contents.empty()) {
        //     std::cerr << "Scanner not implemented" << std::endl;
        //     return 1;
        //}
        for (size_t i = 0; i < file_contents.size() && !isdoubleSlash; ++i) {
            char c = file_contents[i];
            switch (c) {
                case ' ': // 忽略空格
                case '\t': // 忽略Tab
                case '\n': // 忽略换行
                    break;
                case '/':
                    if ((i + 1 < file_contents.size() && file_contents[i + 1] != '/') || i + 1 == file_contents.size()) {
                        std::cout << "SLASH / null" << std::endl;
                    }else{
                        isdoubleSlash = true;
                    }
                    break;
                case '>':
                    if (i + 1 < file_contents.size() && file_contents[i + 1] == '=') {
                        std::cout << "GREATER_EQUAL >= null" << std::endl;
                        ++i;    
                    } else {
                        std::cout <<"GREATER > null" << std::endl;
                    }                 
                    break;
                case '<':
                    if (i + 1 < file_contents.size() && file_contents[i + 1] == '=') {
                        std::cout << "LESS_EQUAL <= null" << std::endl;
                        ++i;    
                    } else {
                        std::cout <<"LESS < null" << std::endl;
                    }                 
                    break;
                case '!':
                    if (i + 1 < file_contents.size() && file_contents[i + 1] == '=') {
                        std::cout << "BANG_EQUAL != null" << std::endl;
                        ++i;    
                    } else {
                        std::cout <<"BANG ! null" << std::endl;
                    }                 
                    break;
                case '=':
                    if (i + 1 < file_contents.size() && file_contents[i + 1] == '=') {
                        std::cout << "EQUAL_EQUAL == null" << std::endl;
                        ++i; 
                    } else {
                        std::cout << "EQUAL = null" << std::endl;
                    }
                    break;
                case '(': 
                    std::cout << "LEFT_PAREN ( null" << std::endl; 
                    break;
                case ')': 
                    std::cout << "RIGHT_PAREN ) null" << std::endl; 
                    break;
                case '{':
                    std::cout << "LEFT_BRACE { null" << std::endl; 
                    break;
                case '}': 
                    std::cout << "RIGHT_BRACE } null" << std::endl; 
                    break;
                case ',':
                    std::cout << "COMMA , null" << std::endl;
                    break;
                case '.':
                    std::cout << "DOT . null" << std::endl;
                    break;
                case '-':
                    std::cout << "MINUS - null" << std::endl;
                    break;
                case '+':
                    std::cout << "PLUS + null" << std::endl;
                    break;
                case ';':
                    std::cout << "SEMICOLON ; null" << std::endl;
                    break;
                case '*':
                    std::cout << "STAR * null" << std::endl;
                    break;
                default:
                    // Ignore other characters for now.
                    std::cerr << "[line " << 1 << "] " << "Error: Unexpected character: " << c << std::endl;
                    ret_val = 65;
                    break;
            }
        }
        std::cout << "EOF  null" << std::endl; // Placeholder, remove this line when implementing the scanner 
        return ret_val;
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}

std::string read_file_contents(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        std::exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
