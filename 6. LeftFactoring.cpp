#include <bits/stdc++.h>
using namespace std;
vector<pair<char, string> > gram(10);
int main()
{
    int n, i, j, k;
    cout << "No of production: ";
    cin >> n;
    cout << n << endl;
    string s;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        gram[i].first = s[0];
        gram[i].second = s.substr(3);
    }
    for (i = 0; i < n; i++)
    {
        string s1[10];
        int p = 0, pos = 1;
        for (j = 0; j < gram[i].second.length(); j++)
            if (gram[i].second[j] == '|')
            {
                s1[pos] = gram[i].second.substr(p, j - p);
                pos++;
                p = j + 1;
            }
        if (pos == 1)
            cout << gram[i].first << "->" << gram[i].second << endl;
        else if (s1[1][0] != s1[2][0])
            cout << gram[i].first << "->" << gram[i].second << endl;
        else
        {
            s1[pos] = gram[i].second.substr(p);
            cout << gram[i].first << "->";
            for (k = 0; k < s1[1].length(); k++)
            {
                if (s1[1][k] == s1[2][k])
                    cout << s1[1][k];
                else
                    break;
            }
            cout << gram[i].first << "\'|" << s1[3] << endl;
            pos = k;
            cout << gram[i].first << "\'->";
            for (k = pos; k < s1[1].length(); k++)
                cout << s1[1][k];
            if (pos == s1[1].length())
                printf("$");
            printf("|");
            for (k = pos; k < s1[2].length(); k++)
                cout << s1[2][k];
            if (pos == s1[2].length())
                printf("$");
            printf("\n");
        }
    }
    return 0;
}
/*
Input:
enter no of production: 2
S->iEtS|iEtSes|a
E->b
Output:
S->iEtSS'|a
S'->$|es
E->b*/
