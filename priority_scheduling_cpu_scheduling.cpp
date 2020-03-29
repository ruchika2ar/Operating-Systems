#include <iostream>
#include <vector>
using namespace std;


class Process {
public:
    // priority of the process
    // lower number suggests higher priority
    int priority;
    // arrival time
    int arrival;
    // burst time
    int burst;
    // waiting time
    int waiting;
    // turnaround time
    int turn;

    Process (int p, int Arrival, int Burst) {
        priority = p;
        arrival = Arrival;
        burst = Burst;
        waiting = 0;
        turn = 0;
    }

    void print() {
        cout << priority << "               " << arrival << "          " << burst;
        cout << "            " << waiting << "            " << turn << endl;
    }
};

int main () {
    // take input for number of processes
    int num;
    cin >> num;
    vector<Process> v;
    // take input for processes
    for (int i = 1; i <= num; i++) {
        int p, arrival, burst;
        cin >> p >> arrival >> burst;
        Process pr(p, arrival, burst);
        v.push_back(pr);
    }
    // initialise clock to zero
    int clock = 0;
    vector<Process> end;
    // while there are processes in the queue
    while (v.size() > 0) {
        int min = -1;
        // find the process with the highest priority
        for (int i = 0; i < v.size(); i++) {
            if (v[i].arrival <= clock && (min == -1 || v[i].priority < v[min].priority)) min = i;
        }
        // if no porcess is found with current clock time as the arrival time, update clock time
        if (min == -1) clock = v[0].arrival;
        else {
            Process cur = v[min];
            // remove porcess from the queue
            v.erase(v.begin() + min);
            // update waiting time
            cur.waiting = clock - cur.arrival;
            // update clock time
            clock = clock + cur.burst;
            // update turnaround time
            cur.turn = clock - cur.arrival;
            end.push_back(cur);
        }
    }
    // calculate total waiting time and turn around time
    double total_waiting = 0, total_turn = 0;
    for (int i = 0; i < num; i++) {
        total_waiting += end[i].waiting;
        total_turn += end[i].turn;
    }
    // ca;cu;ate average waiting time and turnaround time
    double avg_waiting = total_waiting / num;
    double avg_turn = total_turn / num;

    cout << "Priority   " << "   Arrival   " << "   Burst   " << "   Waiting   " << "   Turnaround   " << endl;
    for (int i = 0; i < num; i++) {
        end[i].print();
    } 
    // output average waiting time and turnaround time
    cout << "Average waiting time : " << avg_waiting << endl;
    cout << "Average turnaround time : " << avg_turn;
    return 0;

}
