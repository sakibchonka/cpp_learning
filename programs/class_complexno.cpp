#include<bits/stdc++.h>
using namespace std;

class ComplexNumber{
    int R;
    int I;
    public:
    ComplexNumber(int r, int i):R(r),I(i){

    }
    void add(ComplexNumber C2){
        R = R+C2.R;
        I = I+C2.I;
    }
    void multiply(ComplexNumber C2){
        int a = R * (C2.R);
        int b = R * (C2.I);
        int c = I * (C2.R);
        int d = I * (C2.I)*-1;
        R = a+d;
        I = b+c;
    }
    void display(){
        cout<<R<<" + "<<" i"<<I;
    }
};

int main() {
    ComplexNumber C1(1,4);
    ComplexNumber C2(5,1);
    //C1.add(C2);
    C1.multiply(C2);
    C1.display();
	return 0;
}