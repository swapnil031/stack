#include<iostream>
using namespace std;
#define max 5
class stack{
    int a[max];
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
};
int main()
{
    stack s1;
    s1.pop();
    s1.push(5);s1.display();
    s1.push(10);s1.display();
    //s1.pop();s1.display();
    s1.push(20);s1.display();
    s1.push(20);
    s1.push(20);
    s1.push(20);s1.display();
}