#include <bits/stdc++.h>
using namespace std;
int main()
{
    fstream file;
    string filename = "comments.txt";
    file.open(filename.c_str());
    char ch, ch2;
    while (file.get(ch))
    {
        if (ch == '/')
        {
            file.get(ch2);
            if (ch2 == '*')
            {
                int c=0;
                while (file.get(ch))
                {
                    if(ch=='\n')
                        c++;
                    if (ch == '*' && (ch = file.get()) == '/')
                    {
                        ch = '\n';
                        break;
                    }
                }
                while(c--)
                    cout << ch;
            }
            else
                cout << ch << ch2;
        }
        else
            cout << ch;
    }
    return 0;
}
