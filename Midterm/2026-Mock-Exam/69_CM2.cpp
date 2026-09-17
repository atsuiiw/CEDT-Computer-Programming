#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// n_a to base 10
int convert(string s,int a){
    int res = 0;
    int multiplier = 1;
    for(int i=s.size()-1;i>=0;i--){
        char x = s[i];
        if(i!=s.size()-1 && x=='&'){
            char z = s[i+1];
            if(isdigit(z)) multiplier = z-'0';
            else multiplier = z-'A' + 10;
        }
        else if('0' <= x && x<='9'){
            res += pow(a,s.size()-i-1) * (x-'0');
        }
        else if('A' <= x && x<='Z'){
            res += pow(a,s.size()-i-1) * (x-'A' + 10);
        }
    }
    return res * multiplier;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    string X,Y;
    int a,b;

    // a and b is the base number
    char opr; cin>>X>>a>>Y>>b>>opr;

    int resA = convert(X,a);
    int resB = convert(Y,b);

    if(opr=='+') cout<<resA+resB;
    else if(opr=='-') cout<<resA-resB;
    else if(opr=='*') cout<<resA*resB;
    else cout<<resA/resB;
    return 0;
}

/*
ZZZ 36
36^2 * 35 
36^1 * 35
1 * 35
(31296 + 36 + 1) * 35

*/