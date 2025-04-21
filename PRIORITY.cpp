#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, burstTime, priority, waitingTime, turnaroundTime;
};

// Function to sort by priority (ascending order)
bool compare(Process a, Process b) {
    return a.priority < b.priority;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    cout << "Enter Burst Time and Priority for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "P" << p[i].id << " Burst Time: ";
        cin >> p[i].burstTime;
        cout << "P" << p[i].id << " Priority: ";
        cin >> p[i].priority;
    }

    // Step 1: Sort by priority
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
    cout << "\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t" << p[i].burstTime << "\t\t"
             << p[i].priority << "\t\t" << p[i].waitingTime << "\t\t"
             << p[i].turnaroundTime << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWaitingTime / n;
    cout << "\nAverage Turnaround Time: " << totalTurnaroundTime / n << endl;

    return 0;
}
