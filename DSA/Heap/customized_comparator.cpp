#include<bits/stdc++.h>
using namespace std;

struct Person{
    int age;
    float height;
    Person(int a,float h){
        age = a;
        height = h;
    }
};

struct myComp{
    bool operator()(Person const &p1,Person const &p2){
       return  p1.age>p2.age;
    }
};

int main(){
    priority_queue<Person,vector<Person>,myComp> pq;
    pq.push(Person(10,5.8));
    pq.push(Person(12,5.9));
    pq.push(Person(15,6.0));

    while(pq.empty()==false){
        cout<<pq.top().age<<" ";
        pq.pop();
    }
}