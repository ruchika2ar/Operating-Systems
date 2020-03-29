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
    // take input for number of processes
    cin >> num;
    vector<Process> v;
    for (int i = 1; i <= num; i++) {
        int id, arrival, burst;
        cin >> id >> arrival >> burst;
        Process pr(id, arrival, burst);
        v.push_back(pr);
    }
    int clock = 0;
    vector<Process> end;
    while (v.size() > 0) {
        int min = -1;
        // find process with minimum burst time
        for (int i = 0; i < v.size(); i++) {
            if (v[i].arrival <= clock && (min == -1 || v[i].burst < v[min].burst)) min = i;
        }
        if (min == -1) clock = v[0].arrival;
        else {
            Process cur = v[min];
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
    // calculate total turn around time and waiting time
    double total_waiting = 0, total_turn = 0;
    for (int i = 0; i < num; i++) {
        total_waiting += end[i].waiting;
        total_turn += end[i].turn;
    }
    // calculate average turn around time and waiting time
    double avg_waiting = total_waiting / num;
    double avg_turn = total_turn / num;

    cout << "Id   " << "   Arrival   " << "   Burst   " << "   Waiting   " << "   Turnaround   " << endl;
    for (int i = 0; i < num; i++) {
        end[i].print();
    } 
    
    // output average waiting time and turnaround time
    cout << "Average waiting time : " << avg_waiting << endl;
    cout << "Average turnaround time : " << avg_turn;
    return 0;

}
