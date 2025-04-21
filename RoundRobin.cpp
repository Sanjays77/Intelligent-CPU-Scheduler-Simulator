#include <iostream>
using namespace std;

struct Process {
    int id, burstTime, remainingTime, waitingTime, turnaroundTime;
};

int main() {
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter Burst Time for P" << p[i].id << ": ";
        cin >> p[i].burstTime;
        p[i].remainingTime = p[i].burstTime;
        p[i].waitingTime = 0;
    }

    int time = 0, completed = 0;
    while (completed < n) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (p[i].remainingTime > 0) {
                done = false;
                if (p[i].remainingTime > timeQuantum) {
                    time += timeQuantum;
                    p[i].remainingTime -= timeQuantum;
                } else {
                    time += p[i].remainingTime;
                    p[i].waitingTime = time - p[i].burstTime;
                    p[i].turnaroundTime = time;
                    p[i].remainingTime = 0;
                    completed++;
                }
            }
        }
        if (done) break;
    }

    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
        cout << "P" << p[i].id << "\t" << p[i].burstTime << "\t\t"
             << p[i].waitingTime << "\t\t" << p[i].turnaroundTime << endl;
    }

    cout << "\nAverage Waiting Time: " << (totalWaitingTime / n);
    cout << "\nAverage Turnaround Time: " << (totalTurnaroundTime / n) << endl;

    return 0;
}
