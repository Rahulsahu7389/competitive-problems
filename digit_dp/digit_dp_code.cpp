#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[20][2][20];//index,tight(0 or 1),cnt of 3 in that

ll digitdp(string &s, ll idx,ll bound,ll cnt){
    if(idx==s.length()){
        return cnt;
    }
    if(dp[idx][bound][cnt]!=-1){
        return dp[idx][bound][cnt];
    }
    ll limit = (bound == 1)?(s[idx]-'0'):9;//it is constrained so max to second part of digit
    ll ans = 0;
    for (ll i = 0; i <=limit; i++)//iterating through number of digits
    {
        ll updatecnt = cnt + ((i==3)?1:0);
        ans += digitdp(s,idx+1,(bound&(s[idx]-'0' == i) ),updatecnt);//here s[idx] = 4 so i can go upto that 4 only
    }
    return dp[idx][bound][cnt] = ans;
    
}

void solve(){
    //count the number of 3 in number from l ,r
    ll l,r;
    cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    string ri = to_string(r);
    ll rval = digitdp(ri,0LL,1,0LL);//string ,index,tight,cnt
    string li = to_string(l-1);
     memset(dp,-1,sizeof(dp));
    ll lval = digitdp(li,0LL,1,0LL);//string ,index,tight,cnt

    cout<<(rval - lval)<<endl;

}

int main(){
    solve();
    return 0;
}