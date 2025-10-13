#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> rank,parent,sizes;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        sizes.resize(n+1,0);
        for (int i = 0; i <=n; i++)
        {
            parent[i] = i;
        }
        
    }
    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);//this assignment makes it compression
    }
    void unionByRank(int u,int v){
        int ulti_u = findPar(u);
        int ulti_v = findPar(v);
        if(ulti_u == ulti_v){
            return ;//dont do anything
        }
        if(rank[ulti_u] < rank[ulti_v]){
            parent[ulti_u] = ulti_v;
        }
        else if(rank[ulti_u] > rank[ulti_v]){
            parent[ulti_v] = ulti_u;
        }
        else{
            parent[ulti_v] = ulti_u;//you can do otherwise also
            rank[ulti_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulti_u = findPar(u);
        int ulti_v = findPar(v);
        if(ulti_u == ulti_v) return;
        if(sizes[ulti_u]<sizes[ulti_v]){
            parent[ulti_u] = ulti_v;
            sizes[ulti_v]  += sizes[ulti_u];
        }
        else{
            parent[ulti_v] = ulti_u;
            sizes[ulti_u] += sizes[ulti_v];
        }
    }

};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    //checking if 3 and 7 belongs to same component or not
    if(ds.findPar(3) == ds.findPar(7)){
        cout<<"same\n";
    }
    else{
        cout<<"NOt same\n";
    }
    ds.unionBySize(3,7);
    if(ds.findPar(3) == ds.findPar(7)){
        cout<<"same\n";
    }
    else{
        cout<<"NOt same\n";
    }

    return 0;
}