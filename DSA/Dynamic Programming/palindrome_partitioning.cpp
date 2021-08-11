#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string input, int start, int end) { 
    while (start < end) { 
        if (input[start] != input[end]) 
            return false; 
        start++; 
        end--; 
    } 
    return true; 
}

int palPart(string s,int i,int j){
    if(isPalindrome(s,i,j))
        return 0;
    int res = INT_MAX;
    for(int k=i;k<j;k++){
        res = min(res, 1 + palPart(s,i,k)+palPart(s,k+1,j));
    }
    return res;
}

int main(){
    string s = "eeee";
    	
    cout<<palPart(s,0,s.length()-1);

    return 0;   
}