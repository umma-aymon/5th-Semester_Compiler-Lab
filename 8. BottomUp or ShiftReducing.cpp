#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "Number of productions: " << n << endl;
    cout << endl;
    vector<pair<char, string>> gram(10);
    cout << "Productions:\n";
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        gram[i].first = s[0];
        gram[i].second = s.substr(3);
        cout << s << endl;
    }
    cout << "\nEnter input:\n";
    char input[10], stack[10];
    cin >> input;
    cout << input << endl;
    int len = strlen(input);
    int i = 0, st_pos = 0, r;
    stack[st_pos] = input[i]; //stack e input er 1st char ta nilam
    i++, st_pos++;
    cout << setw(30) << "\nStack\t\tInput\t\tAction\n";
    do
    {
        r = 1;
        while (r != 0)
        {
            cout << endl;
            for (int j = 0; j < st_pos; j++) //stack er size prjnto stack print
                cout << stack[j];
            cout << setw(8) << "\t";
            for (int j = i; j < len; j++)
                cout << input[j];
            cout << setw(9) << "\t";
            if (r == 2)
                cout << setw(7) << "Reduced";
            else
                cout << setw(7) << "Shifted";
            r = 0;
            for (int j = 0; j < st_pos; j++) //reduce krar try krbo
            {
                char ts[10];
                for (int l = 0; l < 10; l++)
                    ts[l] = '\0';
                int ts_pos = 0, l;
                for (int k = j; k < st_pos; k++) //removing first char
                {
                    ts[ts_pos] = stack[k];
                    ts_pos++;
                }
                ts[ts_pos] = '\0';
                for (int k = 0; k < n; k++)
                {
                    string tmp = gram[k].second;
                    if (ts == tmp)
                    {
                        for (l = j; l < 10; l++) //removing matched part
                            stack[l] = '\0';
                        stack[j] = gram[k].first; //non-terminal
                        st_pos = j + 1, r = 2;
                    }
                }
            }
        }
        stack[st_pos] = input[i]; //stack e abr input nilam
        i++, st_pos++;
    }
    while (strlen(stack) != 1 && st_pos != len);
    if (strlen(stack) == 1)
        printf("\n Accepted\n");
    else
        printf("\n Not Accepted");
    return 0;
}
/*
Input:
3
S->SS+
S->SS*
S->a
aaa*a++

Output:

Number of productions: 3

Productions:
S->SS+
S->SS*
S->a

Enter input:
aaa*a++

Stack		Input		Action

a       	aa*a++        	Shifted
S       	aa*a++        	Reduced
Sa       	a*a++        	Shifted
SS       	a*a++        	Reduced
SSa       	*a++        	Shifted
SSS       	*a++        	Reduced
SSS*       	a++        	Shifted
SS       	a++        	Reduced
SSa       	++        	Shifted
SSS       	++        	Reduced
SSS+       	+        	Shifted
SS       	+        	Reduced
SS+       	        	Shifted
S       	        	Reduced
 Accepted
*/
