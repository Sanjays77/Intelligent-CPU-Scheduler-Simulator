// SJF

#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, burstTime, waitingTime, turnaroundTime;
};

bool compare(Process a, Process b) {
    return a.burstTime < b.burstTime; // Sort by burst time (Shortest First)
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    Process p[n];
    
    cout << "Enter Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "P" << p[i].id << ": ";
        cin >> p[i].burstTime;
    }
    
    // Step 1: Sort processes by burst time
    sort(p, p + n, compare);

    // Step 2: Calculate waiting time
    p[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    // Step 3: Calculate turnaround time
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
    }

    // Step 4: Display results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t" << p[i].burstTime << "\t\t"
             << p[i].waitingTime << "\t\t" << p[i].turnaroundTime << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWaitingTime / n;
    cout << "\nAverage Turnaround Time: " << totalTurnaroundTime / n << endl;

    return 0;
}
