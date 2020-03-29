#include <iostream>
#include <vector>
using namespace std;


class Process {
public:
    // process id
    int id;
    // arrival time
    int arrival;
    // burst time
    int burst;
    // remaining execution time
    int rem;
    // waiting time
    int waiting;
    // turnaround time
    int turn;

    Process (int ID, int Arrival, int Burst) {
        id = ID;
        arrival = Arrival;
        burst = Burst;
        waiting = 0;
        turn = 0;
        rem = burst;
    }

    void print() {
        cout << id << "          " << arrival << "          " << burst;
        cout << "            " << waiting << "            " << turn << endl;
    }
};

int main () {
    // take input for number of processes
    int num;
    cin >> num;
    // take input for time quantum value
    int time_quantum;
    cin >> time_quantum;
    vector<Process> v;
    // take input for processes
    for (int i = 1; i <= num; i++) {
        int id, arrival, burst;
        cin >> id >> arrival >> burst;
        Process pr(id, arrival, burst);
        v.push_back(pr);
    }
    // set clock value to zero
    int clock = 0;
    vector<Process> end;
    // while there are processes in the queue, execute
    while (v.size() > 0) {
        // updated stores if a process was updated
        bool updated = false;
        int i = 0;
        while (i < v.size()) {
            if (v[i].arrival <= clock) {
                updated = true;
                // if remaining execution time is greater than or equal to time quantum
                // add one time quantum to clock and reduce one time quantum rom remaining time of process
                if (v[i].rem >= time_quantum) {
                    clock += time_quantum;
                    v[i].rem -= time_quantum;
                } else {
                    // else set remaing time to zero and update clock
                    clock += v[i].rem;
                    v[i].rem = 0;
                }
                // if process execution is complete
                if (v[i].rem == 0) {
                    // update turnaround time and waiting time
                    v[i].turn = clock - v[i].arrival;
                    v[i].waiting = clock - v[i].burst - v[i].arrival;
                    end.push_back(v[i]);
                    // remov process from queue
                    v.erase(v.begin() + i);
                } else i++;
            } else i++;
        }
        // if no process wa updated or executed, increment clock time by 1 unit
        if (!updated) clock++;
    }
    // calculate total waiting time and turnaround time
    double total_waiting = 0, total_turn = 0;
    for (int i = 0; i < num; i++) {
        total_waiting += end[i].waiting;
        total_turn += end[i].turn;
    }
    // calculate average waiting time and turnaround time
    double avg_waiting = total_waiting / num;
    double avg_turn = total_turn / num;

    cout << "Id   " << "   Arrival   " << "   Burst   " << "   Waiting   " << "   Turnaround   " << endl;
    for (int i = 0; i < num; i++) {
        end[i].print();
    }
    // output average turnarond time and waiting time
    cout << "Average waiting time : " << avg_waiting << endl;
    cout << "Average turnaround time : " << avg_turn;
    return 0;

}
