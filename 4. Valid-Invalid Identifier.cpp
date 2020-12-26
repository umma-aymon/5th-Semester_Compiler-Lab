#include <bits/stdc++.h>
using namespace std;
bool isKeyword(string s2) {
    string keywords[32] = {"auto", "break", "case", "char", "const", "continue", "default",
                           "do", "double", "else", "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return", "short", "signed",
                           "sizeof", "static", "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"};
    //for(auto el:keywords)
    // if(el==s2)
    for (int i = 0; i < 32; i++)
        if (keywords[i] == s2)
            return true;
    return false;
}

int main() {
    string s;
    while (cin >> s) {
        bool flag = false;
        if (isKeyword(s))
            cout << s << " is an invalid identifier.\n";
        else if (isalpha(s[0]) || s[0] == '_') {
            for (int i = 1; i < s.size(); i++)  {
                if (s[i] == '_')
                    continue;
                if (!isalnum(s[i])) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cout << s << " is an invalid identifier.\n";
            else
                cout << s << " is a valid identifier.\n";
        }
        else
            cout << s << " is an invalid identifier.\n";
    }
    return 0;
}
