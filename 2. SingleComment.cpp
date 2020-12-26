#include <bits/stdc++.h>
using namespace std;
int main() {
    fstream file;
    string filename = "read.txt";
    file.open(filename.c_str());
    string s, s2;
    while (getline(file, s)) {
        if (s[0] != '/' && s[1] != '/')  {
            if (s.find('/') != string::npos) {
                int in= s.find('/');
                if(s[in+1]=='/')
                    s.erase(in,s.length()-in);
                cout<<s<<endl;
            }
            else
                cout << s << endl;
        }
    }
    return 0;
}
//input-read.txt
