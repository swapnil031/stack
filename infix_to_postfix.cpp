#include<iostream>
#include<stack>
using namespace std;
bool isoperand(char c)
{
    if(c>='a' && c<='z')
        return true;
    return false;
}
bool isoperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c== '$')
        return true;
    return false;
}
int precedence(char x)
{
    if(x=='*' || x=='/')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    else
        return -1;
}

string infix_to_postfix(string c,int n)
{
stack<char>s;
string postfix=" ";
for(int i=0;i<n;i++){
    if(isoperand(c[i])){
        postfix+=c[i];
    }
    else if(isoperator(c[i])){
        while(!s.empty() && precedence(s.top())>=precedence(c[i])){
            postfix+=s.top();
            s.pop();
        }
        s.push(c[i]);
    }
}
while(!s.empty())
{
    postfix+=s.top();
    s.pop();
}
return postfix;
}
int main()
{
    string s;
    cout<<"enter an infix expression ";
    getline(cin,s);
    string result=infix_to_postfix(s,s.length());
    cout<<"the result is "<<result;
}