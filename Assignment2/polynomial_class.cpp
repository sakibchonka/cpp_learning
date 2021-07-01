#include<bits/stdc++.h>
using namespace std;
class Polynomial{
    public:
    int* poly_no;
    int capacity;

    //Default Constructor
    Polynomial(){
        this->poly_no = new int[6];
        this->capacity = 5;
    }

    //Paramaterized constructor
    Polynomial(int capacity){
        this->poly_no = new int[capacity+1];
        this->capacity = capacity;
    }

    //copy constructor
    Polynomial(Polynomial const &P){
        int *P_res = new int[P.capacity+1];
        for(int i=0;i<P.capacity;i++)
            P_res[i]=P.poly_no[i];
        this->poly_no = P_res;
        this->capacity = P.capacity;
    }

    //set coefficient function
    void setCoefficient(int deg, int coef){
        if(deg>capacity){
            int new_cap = deg;
            int *newdeg = new int[new_cap+1];
            //copying from original to new 
            for(int i=0;i<=capacity;i++){
                newdeg[i]=poly_no[i];
            }
            this->poly_no = newdeg;
            this->capacity = new_cap;
            poly_no[deg]=coef;
        }else{
            poly_no[deg] = coef;
        }
    }

    //overload + operator
    Polynomial operator +(Polynomial const &P){
        int max_cap = max(capacity,P.capacity);
        Polynomial P_res(max_cap);

        for(int i=0;i<=max_cap;i++){
            if(i<=capacity && i<=P.capacity)
                P_res.poly_no[i]=this->poly_no[i]+P.poly_no[i];
            else if(i<=capacity)
                P_res.poly_no[i]=this->poly_no[i];
            else 
                P_res.poly_no[i]=P.poly_no[i];
        }
        return P_res;
    }

    //overload - operator
    Polynomial operator -(Polynomial const &P){
        int max_cap = max(capacity,P.capacity);
        Polynomial P_res(max_cap);

        for(int i=0;i<=max_cap;i++){
            if(i<=capacity && i<=P.capacity)
                P_res.poly_no[i]=this->poly_no[i]-P.poly_no[i];
            else if(i<=capacity)
                P_res.poly_no[i]=this->poly_no[i];
            else 
                P_res.poly_no[i]=P.poly_no[i];
        }
        return P_res;
    }

    //overload * operator
    Polynomial operator *(Polynomial const &P){
        int max_cap = this->capacity+P.capacity;
        Polynomial P_res(max_cap);

        for(int i=0;i<=this->capacity;i++){
            for(int j=0;j<=P.capacity;j++){
                P_res.poly_no[i+j]+=poly_no[i]*P.poly_no[j];
            }
        }
        return P_res;
    }

    //overload = operator
    void operator =(Polynomial const &P){
        int *P_res = new int[P.capacity+1];
        for(int i=0;i<P.capacity;i++)
            P_res[i]=P.poly_no[i];
        this->poly_no = P_res;
        this->capacity = P.capacity;
    }

    //print function
    void print(){
        for(int i=0;i<capacity;i++){
            if(poly_no[i]!=0)
                cout<<poly_no[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }

};

int main(){
    int N,M,C;
    cin>>N;
    int *degree_1 = new int[N];
    int *coeff_1 = new int[N];
    for(int i=0;i<N;i++) cin>>degree_1[i];
    for(int i=0;i<N;i++) cin>>coeff_1[i];
    Polynomial poly_1;
    for(int i=0;i<N;i++)
        poly_1.setCoefficient(degree_1[i],coeff_1[i]);

    cin>>M;
    int *degree_2= new int[M];
    int *coeff_2 = new int[M];
    for(int i=0;i<M;i++) cin>>degree_2[i];
    for(int i=0;i<M;i++) cin>>coeff_2[i];
    Polynomial poly_2;
    for(int i=0;i<M;i++)
        poly_2.setCoefficient(degree_2[i],coeff_2[i]);

    cin>>C;
    switch(C){ 
        //sum
        case 1:
        {
            Polynomial res = poly_1+poly_2;
            res.print();
            break;
        }
        //subtract
        case 2:
        {
            Polynomial res = poly_1+poly_2;
            res.print();
            break;
        }
        //multiply
        case 3:
        {
            Polynomial res = poly_1*poly_2;
            res.print();
            break;
        }
        //assignment operator
        case 4:
        {
            Polynomial poly_3(poly_1);
            if(poly_3.poly_no == poly_1.poly_no){
                cout<<"false"<<endl;
            }
            else{
                cout<<"true"<<endl;
            }
            break;
        }

        //copy constructor
        case 5:
        {
            Polynomial poly_4(poly_1);
            if(poly_4.poly_no == poly_1.poly_no){
                cout<<"false"<<endl;
            }
            else{
                cout<<"true"<<endl;
            }
            break;
        }

    }
    return 0;
}