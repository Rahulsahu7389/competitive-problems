#include<bits/stdc++.h>
using namespace std;

int fen[N];

void update(int i , int add){
    while(i<N){
        fen[i] += add;
        i += (i &(-i));
    }
}

int sum(int i){
    int s =0;
    while(i>0){
        s += fen[i];
        i = i - (i &(-i));
    }
    return s;
}

int main(){
    
    return 0;
}