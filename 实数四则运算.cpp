#include<bits/stdc++.h>
using namespace std;
int main()
{
    char op;
    string s1, s2;
    cin >> s1 >> op >> s2;
    double d1, d2;
    stringstream ss;
    ss << s1;
    ss >> d1;
    ss.clear();
    ss << s2;
    ss >> d2;
    ss.clear();
    if(op == '+' || op == '-' || op == '*' || op == '/')
    {
        if(op == '/' && d2 == 0)
        {
            cout << "Wrong input!" << endl;
        }
        else
        {
            double ans;
            switch (op)
            {
            case '+':
                ans = d1 + d2;
                break;
            case '-':
                ans = d1 - d2;
                break;
            case '*':
                ans = d1 * d2;
                break;
            case '/':
                ans = d1 / d2;
                break;
            }
            cout << fixed << setprecision(2) << ans << endl;
        }
    }
    else
    {
        cout << "Wrong input!" << endl;
    }
    return 0;
}