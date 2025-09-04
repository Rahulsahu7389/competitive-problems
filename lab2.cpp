// #include<iostream>
// #include<algorithm>
// using namespace std;

// typedef struct Process
// {
//     int pid;
//     int burst;
//     int arrival;
//     int completion;
//     int turnaround;
//     int waiting;
// }P;

// bool custom(P a , P b){
//     if(a.arrival == b.arrival){
//         return (a.burst<b.burst);
//     }
//     return (a.arrival<b.arrival);
// }

// int main(){
//     int n = 3;
//     P arr[3];

//     int t = 1;
//     do
//     {
//         cout<<"enter the arrival time for p"<<t<<" ";
//         cin>>arr[t-1].arrival;
       
//         cout<<"enter the burst time for p"<<t<<" ";
//         cin>>arr[t-1].burst;
//         arr[t-1].pid = t;
//         t++;
//     } while (t<=n);

//     sort(arr,arr+n,custom);

//     int time = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if(time < arr[i].arrival){
//             time = arr[i].arrival;
//         }
//         time += arr[i].burst;
//         arr[i].completion = time;
//         arr[i].turnaround = arr[i].completion - arr[i].arrival;
//         arr[i].waiting = arr[i].turnaround - arr[i].burst;
//     }

//     cout<<"PID\tAT\tBT\tCT\tTT\tWT"<<endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i].pid<<"\t"<<arr[i].arrival<<"\t"<<arr[i].burst<<"\t"<<arr[i].completion<<"\t"<<arr[i].turnaround<<"\t"<<arr[i].waiting<<endl;
//     }
    
    

    

//     return 0;
// }

#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Process
{
    int pid;
    int burst;
    // int priority;
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
                if(a[j].burst<maxPriority ){
                    p = j+1;
                    maxPriority = a[j].burst;
                    
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

    cout << "\tPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << a[i].pid << "\t" << a[i].arrival << "\t" << a[i].burst << "\t"
             << a[i].completion << "\t" << a[i].turnaround << "\t" << a[i].waiting << "\n";
    }


    vector<pair<int,int>> g(n);
    for (int i = 0; i < n; i++)
    {
        g[i] = {a[i].completion , a[i].pid};
    }
    sort(g.begin(),g.end());
    for(auto val:g){
        cout<<val.second<<"\t";
    }
    cout<<endl;
    for(auto val:g){
        cout<<val.first<<"\t";
    }
    



    

    return 0;
}