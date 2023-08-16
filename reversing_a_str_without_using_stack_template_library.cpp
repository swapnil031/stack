#include<iostream>
#include<cstring>
using namespace std;
#define max 6
class stack{
    char a[max];
    int top;
public:
        stack(){
            top=-1;
        }
        void push(int x){
            if(top==max-1){
                cout<<"overflow"<<endl;
            }
            else{
                a[++top]=x;
            }
        }
        void pop(){
            if(top==-1){
                cout<<"no elements to pop"<<endl;
            }
            else
                top--;
        }
        bool isempty(){
            if(top==-1)
                return true;
            return false;    
        }
        int top1(){
            return a[top];
        }
        void display(){
            cout<<"the elements are ";
            for(int i=0;i<=top;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        void reverse(char *c,int n){
                for(int i=0;i<n;i++){
                    push(c[i]);
                }
                for(int i=0;i<n;i++){
                    c[i]=top1();
                    pop();
                }
        }
};
int main(){
    stack s1;
    char c[51];
    cout<<"enter a string";
    //getline(cin,c);
    gets(c);
    s1.reverse(c,strlen(c));
    cout<<"the reversed string is "<<c;
}