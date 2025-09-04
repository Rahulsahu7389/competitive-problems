#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Process
{
    int pid;
    int burst;
    int priority;
    int arrival;
    int completion;
    int turnaround;
    int waiting;
}P;

bool custom(P a , P b){
    // if(a.arrival == b.arrival){
    //     return (a.priority < b.priority);
    // }
    return (a.arrival<b.arrival);
}

int main(){
    int n;
    cout<<"enter the no of processes: ";
    cin>>n;

    vector<P> a(n);
    vector<int> vis(n,-1);
    for (int i = 0; i < n; i++)
    {
        a[i].pid = i+1;
        cout<<"enter the arrival of p"<<(i+1)<<":";
        cin>>a[i].arrival;
        cout<<"enter the burst time of p"<<(i+1)<<":";
        cin>>a[i].burst;
        cout<<"enter the priority of p"<<(i+1)<<":";
        cin>>a[i].priority;
    }

    sort(a.begin(),a.end(),custom);
    int time =0;
    int completed = 0;
    while (completed<n)
    {
        
        int maxPriority = INT_MAX;
        int p = -1;
        for (int j = 0; j < n; j++)
        {
            if(vis[j]==-1 && a[j].arrival<=time){
                if(a[j].priority<maxPriority ){
                    p = j+1;
                    maxPriority = a[j].priority;
                    
                }

            }
        }
        if(p == -1){
            cout<<"idle\n";
            time++;
        }
        else{

            
            time += a[p-1].burst;
            vis[p-1] = 1;
            a[p-1].completion = time;
            a[p-1].turnaround = a[p-1].completion - a[p-1].arrival;
            a[p-1].waiting = a[p-1].turnaround - a[p-1].burst;
            completed++;
            cout<<completed<<endl;
        }
        


    }

    cout << "\nPRIO\tPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout <<a[i].priority<<"\t"<< a[i].pid << "\t" << a[i].arrival << "\t" << a[i].burst << "\t"
             << a[i].completion << "\t" << a[i].turnaround << "\t" << a[i].waiting << "\n";
    }



    

    return 0;
}