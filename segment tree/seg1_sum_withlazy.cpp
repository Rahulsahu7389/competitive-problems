#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[100005];
ll seg[4*100005];//this is the segment tree
ll lazy[4*100005];//this is the replica of segment tree

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
////////////query with lazy
void checklazy(ll idx, ll low , ll high){
    if(lazy[idx]!=0){//chekcing at node so use idx
        seg[idx] += (high - low +1)*lazy[idx];
        if(low!=high){
            //not the leaf node so propagate the value
            lazy[idx*2 +1] += lazy[idx];
            lazy[idx*2 +2] += lazy[idx];
        }
        lazy[idx]  =0;
    }
}

void rangeUpdatelazy(ll idx, ll low , ll high , ll l,ll r,ll val){//update at from l to r to val in original array(assume actual me to tree me hota)
    checklazy(idx,low,high);
    if(high<l || low>r) return;//completely outside

    // if completely lies so update that one only and update lazy to child
    if(l<=low && high<=r){
        seg[idx] += (high - low +1)*val;
        if(low!=high){
            lazy[idx*2 +1] +=val;
            lazy[idx*2 +2] += val;
        }
        return;
    }
    //partial overlap
    ll mid = (low + high)/2;
    rangeUpdatelazy(2*idx+1,low,mid,l,r,val);
    rangeUpdatelazy(2*idx+2,mid+1,high,l,r,val);
    seg[idx] = seg[idx*2 +1] + seg[2*idx+2];

}

ll querywithlazy(ll idx, ll low , ll high , ll l , ll r){
    checklazy(idx,low,high);//udpate the pending work
    //outside range
    if(high<l || low>r) return 0;
    
    //complete overlap
    if(l<=low && high<=r){
        return seg[idx];
    }
    
    ll mid = (low + high)/2;
    ll left = querywithlazy(2*idx+1,low,mid,l,r);
    ll right = querywithlazy(2*idx+2,mid+1,high,l,r);
    return left + right;

}

void solve(){
    ll n;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    build(0,0,n-1);//start from root and take 0 to n-1 from array
    rangeUpdatelazy(0,0,n-1,0,0,2);
    rangeUpdatelazy(0,0,n-1,1,1,1);
    // ll ans = querynolazy(0,0,n-1,0,3);
    ll val1 = querywithlazy(0,0,n-1,0,0);
    ll val2 = querywithlazy(0,0,n-1,1,1);
    cout<<val1<<" "<<val2<<endl;
    
}

int main(){
    solve();
    return 0;
}