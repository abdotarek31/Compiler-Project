#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_TOKEN_LENGTH 100

using namespace std;

char token[MAX_TOKEN_LENGTH];

int isKeyword(string token) {
    string keywords[32] = { "auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for",
                             "goto", "if", "int", "long", "register", "return", "short",
                             "signed", "sizeof", "static", "struct", "switch", "typedef",
                             "union", "unsigned", "void", "volatile", "while"
    };
    int i, flag = 0;

    for (i = 0; i < 32; ++i) {
        if (keywords[i] == token) {
            flag = 1;
            break;
        }
    }

    return flag;
}

int main() {
    char ch;
    int i, j = 0;

    ifstream input_file("input.txt");

    if (!input_file) {
        cout << "Error: Cannot open file" << endl;
        return 1;
    }

    while (input_file.get(ch)) {
        if (isalnum(ch)) {
            token[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            token[j] = '\0';
            j = 0;

            if (isKeyword(token) == 1) {
                cout << token << " is a keyword" << endl;
            }
            else {
                cout << token << " is an identifier" << endl;
            }
        }
    }

    input_file.close();

    return 0;
}
