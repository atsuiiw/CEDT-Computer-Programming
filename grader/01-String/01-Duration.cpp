#include<iostream>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(0);
    int h1,m1,s1,h2,m2,s2;
    std::cin>>h1>>m1>>s1>>h2>>m2>>s2;
    int st = h1 * 60 * 60 + m1 * 60 + s1;
    int en = h2 * 60 * 60 + m2 * 60 + s2;
    int final = (24*60*60) + (en-st);
    final%=(24*60*60);
    std::cout<<final/3600<<":"<<(final%3600)/60<<":"<<final%60;
    return 0;
}