#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int pid;       
    int arrival;    
    int burst;      
    int start;      
    int finish;     
    int waiting;    
    int turnaround; 
};

void calculateFCFS(vector<Process> &processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    int time = 0;
    vector<pair<int, int>> gantt;

    for (auto &p : processes) {
        if (time < p.arrival) {
            gantt.push_back({-1, p.arrival - time}); // Idle Time
            time = p.arrival;
        }
        p.start = time;
        p.waiting = time - p.arrival;
        time += p.burst;
        p.finish = time;
        p.turnaround = p.finish - p.arrival;
        gantt.push_back({p.pid, p.burst});
    }

    cout << "\nGantt Chart:\n";
    cout << " ";
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

    calculateFCFS(processes);
    displayResults(processes);

    return 0;
}
