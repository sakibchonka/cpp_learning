#include<bits/stdc++.h>
using namespace std;

struct Mystack{
    int *arr;
    int top;
    int capacity;
    Mystack(int c){
        capacity = c;
        arr = new int[capacity];
        top = -1;
    }
    void push(int e){
        if(top == capacity-1){
            cout<<"overflow";
            return;
        }
        top++;
        arr[top] = e;
    }
    int pop(){
        if(top == -1){
            cout<<"underflow";
            return -1;
        }
        int ret = arr[top];
        top--;
        return ret;
    }
    bool isEmpty(){
        return (top==-1);
    }
    int size(){
        return top+1;
    }
    int peek(){
        return arr[top];
    }
};

int main(){
    Mystack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
  
}