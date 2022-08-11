#include <bits/stdc++.h>
using namespace std;
#include <conio.h>
#define endl "\n"
#define ll long long
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
// AFTERGLOW
//Bracket checker
int main()
{
    string str;
    cin>>str;
    stack<char> st;
    int count =0;
    for(auto x : str)
    {
        if(x == '{' || x == '[' || x == '(')
        {
            st.push(x);
        }
        else
        {
            if(st.empty())
            {
                cout<<"False\n";
                return 0;
            }
            if(x == '}')
            {
                if(st.top() != '{')
                {
                    cout<<"False\n";
                    return 0;
                }
                else
                st.pop();
            }
            if(x == ']')
            {
                if(st.top() != '[')
                {
                    cout<<"False\n";
                    return 0;
                }
                else
                st.pop();
            }
            if(x == ')')
            {
                if(st.top() != '(')
                {
                    cout<<"False\n";
                    return 0;
                }
                else
                st.pop();
            }
        }
       
    }
    cout<<"True\n";
}