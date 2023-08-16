#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
bool arepair(char start,char end){
    if(start=='(' && end==')')
        return true;
    else if(start=='{' && end=='}')
        return true;
    else if(start=='[' && end==']')
        return true;
    else
        return false;
    
}
bool check_parentheses(char *c,int n){
    stack<char>s1;
    for(int i=0;i<n;i++){
        if(c[i]=='[' || c[i]=='{'|| c[i]=='('){
            s1.push(c[i]);
        }
        else if(c[i]==']' || c[i]=='}'|| c[i]==')'){
            if(s1.empty() || !arepair(s1.top(),c[i])){
                return false;
            }
            else
                s1.pop();
        }
    }
    return s1.empty()? true:false;
}
int main(){
    char s[50];
    cout<<"enter a string:";
    gets(s);
    if(check_parentheses(s,strlen(s))){
        cout<<"nice parentheses"<<endl;
    }
    else
        cout<<"hagu"<<endl;
}