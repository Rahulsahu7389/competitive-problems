#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[100005];
ll seg[4*100005];//this is the segment tree

//here idx - segment tree ka kon sa node hai btata and low and high are the range in the array
void build(ll idx , ll low , ll high){//this will build the segment tree for getting the max
    if(low == high){
        seg[idx] = a[low];//only single range like pointing in the array
        return;
    }
    ll mid = (low  + high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);//dono child ka max lelo
}

//l and r the query indices jo chaiye
ll querynolazy(ll idx, ll low , ll high , ll l , ll r){
    if(low>=l && high<=r){//completely lies
        return seg[idx];//vo node ki value
    }
    if(high<l || low>r) return -1e15;//if does not overlap at all
    //partial overlap
    ll mid = (low + high)/2;

    ll left = querynolazy(2*idx+1,low,mid,l,r);
    ll right = querynolazy(2*idx+2,mid+1,high,l,r);
    return max(left,right);
    

}

void solve(){
    ll n;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    build(0,0,n-1);//start from root and take 0 to n-1 from array
    ll ans = querynolazy(0,0,n-1,0,3);
    cout<<ans<<endl;
    
}

int main(){
    solve();
    return 0;
}