#include<iostream>
#include<stack>
using namespace std;
bool isoperator(char a){
    if(a=='+' || a=='-' || a=='*' || a=='/')
        return true;
    return false;
}
int performoperation(char c,int a,int b){
        if(c=='*')
            return a*b;
        else if(c=='/')
            return a/b;
        else if(c=='+')            
            return a+b;
        else
            return b-a;
}

bool isnumericdigit(char a){
    if(a>='0' && a<='9')
        return true;
    return false;
}
int evaluate_postfix(string s,int a){
    stack<char>c;
    for(int i=0;i<a;i++){
        if(s[i]==' ' || s[i]==',')
            continue;
        else if(isoperator(s[i])){
            int op2=c.top();c.pop();
            int op1=c.top();c.pop();
            int result=performoperation(s[i],op2,op1);
            c.push(result);
        }
        if(isnumericdigit(s[i]))
        {
            int operand=0;
            while(i<a && isnumericdigit(s[i])){
                operand=operand*10+(s[i]-'0');
                i++;
            }
            i--;
            c.push(operand);
        }
    }
    return c.top();
}
int main(){
    string s;
    cout<<"enter a string";
    getline(cin,s);
    int result=evaluate_postfix(s,s.length());
    cout<<"the result is"<<result;
}