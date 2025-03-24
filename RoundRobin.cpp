#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <climits>
#include <algorithm>  

using namespace std;

struct Process {
    int pid, arrival, burst, remaining, completion, waiting, turnaround;
};

void calculateRoundRobin(vector<Process>& processes, int quantum) {
    int n = processes.size();
    queue<int> q;
    vector<bool> visited(n, false);
    vector<pair<int, int>> gantt;

    int time = 0, completed = 0;
    for (auto& p : processes) p.remaining = p.burst;

    
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        if (processes[idx].arrival > time) {
            gantt.push_back({-1, processes[idx].arrival - time});
            time = processes[idx].arrival;
        }

        int execTime = min(quantum, processes[idx].remaining);
        gantt.push_back({processes[idx].pid, execTime});
        time += execTime;
        processes[idx].remaining -= execTime;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && processes[i].arrival <= time) {
                q.push(i);
                visited[i] = true;
            }
        }

        if (processes[idx].remaining > 0) {
            q.push(idx);
        } else {
            processes[idx].completion = time;
            completed++;
        }

        if (q.empty() && completed < n) {
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    
    double totalTAT = 0, totalWT = 0;
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto& p : processes) {
        p.turnaround = p.completion - p.arrival;
        p.waiting = p.turnaround - p.burst;
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t" << p.completion << "\t" << p.turnaround << "\t" << p.waiting << "\n";
        totalTAT += p.turnaround;
        totalWT += p.waiting;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << totalTAT / n << " ms";
    cout << "\nAverage Waiting Time: " << totalWT / n << " ms\n";

    // Print Gantt Chart
    cout << "\nGantt Chart:\n";
    for (auto& g : gantt) {
        cout << "| ";
        if (g.first == -1) cout << "Idle ";
        else cout << "P" << g.first << " ";
    }
    cout << "|\n";
}

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);

    cout << "Enter process details (PID Arrival Burst):\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    calculateRoundRobin(processes, quantum);
    return 0;
}
