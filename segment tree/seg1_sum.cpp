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
    seg[idx] = seg[2*idx+1]+seg[2*idx+2];//dono child ka max lelo
}

//l and r the query indices jo chaiye
ll querynolazy(ll idx, ll low , ll high , ll l , ll r){
    if(low>=l && high<=r){//completely lies
        return seg[idx];//vo node ki value
    }
    if(high<l || low>r) return 0;//if does not overlap at all
    //partial overlap
    ll mid = (low + high)/2;

    ll left = querynolazy(2*idx+1,low,mid,l,r);
    ll right = querynolazy(2*idx+2,mid+1,high,l,r);
    return left + right;
    

}

void pointUpdatesnolazy(ll idx, ll low , ll high , ll ind,ll val){//update at ind to val in original array(assume actual me to tree me hota)
    if(low==high){//leaf node
        seg[idx] += val;//leaf node me add ho rha
        return;
    }
    ll mid = (low + high)/2;
    if(ind>=low && ind<=mid){
        //lies in the left half
        pointUpdatesnolazy(2*idx+1,low,mid,ind,val);
    }
    else{
        pointUpdatesnolazy(2*idx+2,mid+1,high,ind,val);
    }
    //at last when you backtrack you have updated one node so uske upar bhi to update krna hai
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];


}

void solve(){
    ll n;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    build(0,0,n-1);//start from root and take 0 to n-1 from array
    pointUpdatesnolazy(0,0,n-1,1,1);
    // ll ans = querynolazy(0,0,n-1,0,3);
    ll ans = querynolazy(0,0,n-1,1,1);
    cout<<ans<<endl;
    
}

int main(){
    solve();
    return 0;
}