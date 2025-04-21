// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main()
{
    int n = 3;                 // Number of processes
    int arrival[] = {2, 3, 4}; // Arrival times
    int burst[] = {4, 6, 8};   // Burst times
    int completion[3], turnaround[3], waiting[3];

    int time = 0;

    
    for (int i = 0; i < n; i++)
    {
        if (time < arrival[i])
            time = arrival[i]; 

        completion[i] = time + burst[i];            
        turnaround[i] = completion[i] - arrival[i]; 
        waiting[i] = turnaround[i] - burst[i];      

        time = completion[i]; 
    }

    // Output Table
    cout << "PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << completion[i] << "\t\t" << turnaround[i] << "\t\t" << waiting[i] << endl;
    }

    return 0;
}
