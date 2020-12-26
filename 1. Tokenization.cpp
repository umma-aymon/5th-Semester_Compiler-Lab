#include <bits/stdc++.h>
using namespace std;
bool isKeyword(string s2)
{
    string keywords[32] = {"auto", "break", "case", "char", "const", "continue", "default",
                           "do", "double", "else", "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return", "short", "signed",
                           "sizeof", "static", "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"
                          };
    //for(auto el:keywords)
    // if(el==s2)
    for (int i = 0; i < 32; i++)
        if (keywords[i] == s2)
            return true;
    return false;
}
bool isIdentifier(string s)
{
    if (isalpha(s[0]) || s[0] == '_')
    {
        for (int i = 1; i < s.size(); i++)
            if (!isalnum(s[i]))
                return false;
        return true;
    }
    else
        return false;
}
int isInteger(string str)
{
    int d = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            return 2;
        if (int(str[i]) >= 48 && int(str[i]) <= 57)
            d = 1;
    }
    return d;
}
int main()
{
    string op = "+-*/%=";
    fstream file;
    string filename = "file.txt";
    file.open(filename.c_str());
    string s, s2;
    while (getline(file, s))
    {
        for (int k = 0; k < s.length(); k++)
        {
            if (op.find(s[k]) != string::npos)
                cout << s[k] << " is operator\n";
            else if (isalnum(s[k]) || s[k] == '.')
                s2 += s[k];
            else if ((s[k] == ' ' || s[k] == '\n') && s2.length() > 0)
            {
                if (isKeyword(s2))
                    cout << s2 << " is a keyword\n";
                else if (isIdentifier(s2))
                    cout << s2 << " is an identifier\n";
                else if (isInteger(s2) == 1)
                    cout << s2 << " is an integer\n";
                else if (isInteger(s2) == 2)
                    cout << s2 << " is a real number\n";
                else
                    cout << s2 << " is not a valid identifier\n";
                s2.clear();
            }
        }
    }
    return 0;
}
