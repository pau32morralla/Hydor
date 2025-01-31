#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <optional>
#include <string>

enum TokenType {
    TKN_PLUS, TKN_MINUS, TKN_STAR, TKN_SLASH,

    TKN_NUMBER
};

class Token {
    public:
        TokenType type;
        const char* lexeme;
        int length;
        int line;
};

std::optional<std::string> readFile(char* path);
std::optional<std::vector<Token>> makeTokens(const std::string& source);

int main(int argc, char** argv){
    std::optional<std::string> optSource = readFile(argv[1]);
    if(!optSource){
        return 1;
    }
    std::string source = optSource.value();

    std::optional<std::vector<Token>> optTokens = makeTokens(source);
    if(!optSource){
        return 1;
    }
    std::vector<Token> tokens = optTokens.value();

    return 0;
}

std::optional<std::string> readFile(char* path){
    std::ifstream file(path);

    if(!file.is_open()){
        std::cerr << "Error opening the file " << path << std::endl;
    	return std::nullopt;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string contents = buffer.str();

    file.close();
    return contents;
}

std::optional<std::vector<Token>> makeTokens(const std::string& source){
    std::vector<Token> tokens;

    for(unsigned long long i; i < source.length(); i++){
        char current_char = source.at(i);

        switch (current_char){
            case 'a':
                /* code */
                break;
        
            default:
                std::cerr << "Illegal character" << current_char;
                return std::nullopt;
        }
    }

    return tokens;
}
