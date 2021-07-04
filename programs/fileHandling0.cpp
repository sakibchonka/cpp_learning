#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream fp;
    fp.open("hello.txt");
    string name;
    int age;
    fp>>name>>age;
    cout<<name<<age;
    return 0;
}