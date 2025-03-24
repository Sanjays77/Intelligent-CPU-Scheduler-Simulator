#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

struct Process {
    int pid, arrival, burst, start, finish, waiting, turnaround;
    bool completed = false;
};

void calculateSJF(vector<Process> &processes) {
    int n = processes.size();
    int time = 0, completed = 0;
    vector<pair<int, int>> gantt;

    while (completed < n) {
        int idx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival <= time && processes[i].burst < minBurst) {
                minBurst = processes[i].burst;
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx].start = time;
            processes[idx].waiting = time - processes[idx].arrival;
            time += processes[idx].burst;
            processes[idx].finish = time;
            processes[idx].turnaround = processes[idx].finish - processes[idx].arrival;
            processes[idx].completed = true;
            completed++;
            gantt.push_back({processes[idx].pid, processes[idx].burst});
        } else {
            gantt.push_back({-1, 1});
            time++;
        }
    }

    cout << "\nGantt Chart:\n ";
    for (auto &g : gantt) cout << "--------";
    cout << "\n|";
    for (auto &g : gantt) {
        if (g.first == -1) cout << "  Idle  |";
        else cout << "  P" << g.first << "   |";
    }
    cout << "\n ";
    for (auto &g : gantt) cout << "--------";
    cout << "\n";

    int current = 0;
    cout << current;
    for (auto &g : gantt) {
        current += g.second;
        cout << setw(8) << current;
    }
    cout << "\n";
}

void displayResults(vector<Process> &processes) {
    double totalWT = 0, totalTAT = 0;
    cout << "\nPID\tAT\tBT\tWT\tTAT\n";
    for (auto &p : processes) {
        cout << "P" << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.waiting << "\t" << p.turnaround << "\n";
        totalWT += p.waiting;
        totalTAT += p.turnaround;
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << totalWT / processes.size() << " ms";
    cout << "\nAverage Turnaround Time: " << totalTAT / processes.size() << " ms\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter PID, Arrival Time, and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
    }

    calculateSJF(processes);
    displayResults(processes);

    return 0;
}
