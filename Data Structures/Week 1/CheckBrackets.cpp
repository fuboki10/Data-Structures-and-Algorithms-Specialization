#include <iostream>
#include <string>
#include <stack>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(next,position + 1);
        }

        if (next == ')' || next == ']' || next == '}') {
            Bracket brac;
            if (!opening_brackets_stack.empty()) {
                brac = opening_brackets_stack.pop();
                if (!brac.Matchc(next)) {
                    cout << position + 1 << endl;
                    return 0;
                }
            }
            else {
                cout << position + 1 << endl;
                return 0;
            }
    }
    if (opening_brackets_stack.empty()) {
        cout << "Success\n";
    }
    else
    {
        cout << opening_brackets_stack.pop().position << endl;
    }
    // Printing answer, write your code here

    return 0;
}
