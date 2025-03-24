#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits> 

using namespace std;

struct Process {
    int pid, arrival, burst, waiting, turnaround, completion;
};

void calculateSJF(vector<Process> &processes) {
    int n = processes.size();
    vector<bool> completed(n, false);
    int completedCount = 0, currentTime = 0;
    vector<pair<int, int>> gantt;

    cout << "\nExecuting SJF Scheduling...\n";

    while (completedCount < n) {
        int idx = -1, minBurst = INT_MAX;

        
        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival <= currentTime && processes[i].burst < minBurst) {
                minBurst = processes[i].burst;
                idx = i;
            }
        }

        if (idx == -1) {
            
            gantt.push_back({-1, 1});
            currentTime++;
        } else {
            
            processes[idx].completion = currentTime + processes[idx].burst;
            processes[idx].turnaround = processes[idx].completion - processes[idx].arrival;
            processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
            gantt.push_back({processes[idx].pid, processes[idx].burst});

            completed[idx] = true;
            completedCount++;
            currentTime = processes[idx].completion;
        }
    }

    
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    double totalTAT = 0, totalWT = 0;
    for (const auto &p : processes) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t" 
             << p.completion << "\t" << p.turnaround << "\t" << p.waiting << "\n";
        totalTAT += p.turnaround;
        totalWT += p.waiting;
    }

    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2) << (totalTAT / n) << " ms";
    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << (totalWT / n) << " ms\n";

    
    cout << "\nGantt Chart:\n";
    for (const auto &g : gantt) {
        cout << "| ";
        if (g.first == -1) cout << "Idle ";
        else cout << "P" << g.first << " ";
    }
    cout << "|\n";
}


int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter Process details (PID Arrival Burst):\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
    }

    
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
        return a.arrival < b.arrival;
    });

    calculateSJF(processes);

    return 0;
}
