#include <iostream>
#include <cctype>
using namespace std;

bool isKeyword(string word) {
    return word == "int" || word == "float" || word == "return";
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=';
}

bool isDelimiter(char ch) {
    return ch == ';' || ch == '(' || ch == ')';
}

int main() {
    string code = "int x = 10 + 20;";

    string token = "";
    for (int i = 0; i < code.size(); i++) {
        char ch = code[i];

        if (isalnum(ch)) {
            token += ch;
        } else {
            if (!token.empty()) {
                if (isKeyword(token))
                    cout << "[KEYWORD] " << token << endl;
                else if (isdigit(token[0]))
                    cout << "[NUMBER] " << token << endl;
                else
                    cout << "[IDENTIFIER] " << token << endl;
                token = "";
            }

            if (isOperator(ch))
                cout << "[OPERATOR] " << ch << endl;
            else if (isDelimiter(ch))
                cout << "[DELIMITER] " << ch << endl;
        }
    }

    return 0;
}