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
    }

    void print() {
        cout << id << "          " << arrival << "          " << burst;
        cout << "            " << waiting << "            " << turn << endl;
    }
};

int main () {
    int num;
    cin >> num;
    vector<Process> v;
    // Take input for the processes
    for (int i = 1; i <= num; i++) {
        int id, arrival, burst;
        cin >> id >> arrival >> burst;
        Process pr(id, arrival, burst);
        v.push_back(pr);
    }
    // set the clock time to zero
    int clock = 0;
    for (int i = 0; i < num; i++) {
        if (clock < v[i].arrival) clock = v[i].arrival;
        // update waiting time
        v[i].waiting = clock - v[i].arrival;
        // update clock time
        clock += v[i].burst;
        // update turnaorund time
        v[i].turn = clock - v[i].arrival;
    }

    double total_waiting = 0, total_turn = 0;
    // caculate total turn around time and waiting time
    for (int i = 0; i < num; i++) {
        total_waiting += v[i].waiting;
        total_turn += v[i].turn;
    }
    // calculate average turn around time and waiting time
    double avg_waiting = total_waiting / num;
    double avg_turn = total_turn / num;

    cout << "Id   " << "   Arrival   " << "   Burst   " << "   Waiting   " << "   Turnaround   " << endl;
    for (int i = 0; i < num; i++) {
        v[i].print();
    } 

    // output average waiting time and turnaround time
    cout << "Average waiting time : " << avg_waiting << endl;
    cout << "Average turnaround time : " << avg_turn;
    return 0;

}
