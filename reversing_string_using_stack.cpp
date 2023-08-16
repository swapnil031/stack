#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
void reverse(char *s,int n){
    stack<char>s1;
    for(int i=0;i<n;i++){
        s1.push(s[i]);
    }
    for(int i=0;i<n;i++){
        s[i]=s1.top();
        s1.pop();
    }
}
int main(){
    char s[51];
    cout<<"enter a string: ";
    gets(s);
    reverse(s,strlen(s));
    cout<<"the reversed string is "<<s;
}