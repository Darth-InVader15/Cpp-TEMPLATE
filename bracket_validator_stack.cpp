#include <bits/stdc++.h>
using namespace std;
#include <conio.h>
#define endl "\n"
#define ll long long
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

//Bracket checker
int main()
{
    string str;
    cin>>str;
    stack<char> st;
    //int count =0;
    for(auto x : str)
    {
        //INPUT ANY OPEN BRACKET IN THE STACK
        if(x == '{' || x == '[' || x == '(')
        {
            st.push(x);
        }
        else
        {
            //ELSE CHECK WHETHER THE LAST OPENED BRACKET IN THE STACK MATCHES THE CURRENT CLOSING BRACKET
            //ALSO CHECK WHETHER THE STACK IS EMPTY OR NOT IN THE BEGINNING, IN CASE THE I/P IS LIKE ')'
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
    //CHECK WHETHER THE STACK IS EMPTY TO AVOID EDGE CASES LIKE '(){}('
    if(st.size()==0)
    cout<<"True\n";
    else 
    cout<<"False\n";
}