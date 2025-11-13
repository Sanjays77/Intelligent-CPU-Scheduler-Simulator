INT 331 TEST  CA 1

# Intelligent-CPU-Scheduler-Simulator
CSE 316 project

The Intelligent CPU Scheduler Simulator is a C++ based project designed to simulate and analyze various CPU scheduling algorithms like FCFS, SJF, Priority, and Round Robin. The project includes real-time Gantt chart visualization and performance metrics like average waiting time and turnaround time.

FEATURES :

Supports four key CPU scheduling algorithms:

First Come First Serve (FCFS)

Shortest Job First (SJF)

Priority Scheduling

Round Robin (RR)

CALCULATES:

Waiting Time (WT)

Turnaround Time (TAT)

Real-time ASCII Gantt Chart visualization

Modular and expandable C++ codebase

Version control and collaboration via GitHub

Technologies Used

Programming Language: C++

Libraries: Standard Template Library (STL)

Tools:

GitHub for version control and collaboration

VS Code / Code::Blocks for development

🔧 How to Run

g++ simulator.cpp -o simulator
./simulator

 Example Input (Interactive Mode)

Enter number of processes: 4
Enter Process details: PID ArrivalTime BurstTime Priority
1 0 8 3
2 1 4 1
3 2 9 2
4 3 5 4

Choose the algorithm:

1. FCFS
2. SJF
3. Priority
4. Round Robin

 Sample Gantt Chart Output

Gantt Chart:
 --------------------------------
|  P1   |  P2   |  P3   |  P4   |
 --------------------------------
0       8       12      21      26

 Performance Metrics (Example)

Algorithm

Avg. Waiting Time

Avg. Turnaround Time

FCFS

8.25 ms

14.75 ms

SJF

5.50 ms

12.25 ms

Priority

7.00 ms

13.00 ms

Round Robin (Q=3)

6.75 ms

12.75 ms

 Future Scope

Add GUI-based Gantt Chart visualization

Integrate preemptive versions of SJF and Priority

Machine Learning integration for predictive CPU scheduling

Energy-efficient scheduling algorithms

   Contributors

S SANJAY

MUHAMMED JAISH

THURAKA MAHENDRA


    References

Silberschatz, A., Galvin, P.B., Gagne, G., Operating System Concepts, 8th Edition

Milan Milenkovic, Operating System Concepts and Design, McGraw-Hill

Sukanya Suranauwarat, CPU Scheduling Algorithm Simulator, ASEE/IEEE
