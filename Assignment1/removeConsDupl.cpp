#include <iostream>
using namespace std;
void removeConsDupl(string &s,int size,int i){
    if(i==size-1)return;
    if(s[i]==s[i+1]){
        s.erase(s.begin()+i);
        removeConsDupl(s,s.size(),i);
        return;
    }
    removeConsDupl(s,s.size(),i+1);
    return;
}
int main() {
    string s;
    cin>>s;
    removeConsDupl(s,s.size(),0);
    cout<<s;
}



