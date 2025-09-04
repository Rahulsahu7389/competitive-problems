#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct Process
{
    int pid;
    int burst;
    int arrival;
    int completion;
    int turnaround;
    int waiting;
}P;

bool custom(P a , P b){
    if(a.arrival)
    return (a.arrival < b.arrival);
}


int main(){
    int n = 4;

    vector<P> arr(n);
    cout<<"enter data now : "<<endl;
    int t=1;
   
    do
    {
        cout<<"enter the arrival time for p"<<t<<" ";
        cin>>arr[t-1].arrival;
       
        cout<<"enter the burst time for p"<<t<<" ";
        cin>>arr[t-1].burst;
        arr[t-1].pid = t;
        t++;
    } while (t<=n);


    sort(arr.begin(),arr.end(),custom);

    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if(time<arr[i].arrival){
            time = arr[i].arrival;
        }
        time += arr[i].burst;
        arr[i].completion = time;
        arr[i].turnaround = arr[i].completion - arr[i].arrival;
        arr[i].waiting = arr[i].turnaround - arr[i].burst;
        
    }


    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].pid << "\t" << arr[i].arrival << "\t" << arr[i].burst << "\t"
             << arr[i].completion << "\t" << arr[i].turnaround << "\t" << arr[i].waiting << "\n";
    }
    
    
    
    
    
    


    return 0;
}