#include <iostream>
#include <vector>
using namespace std;

class Process {
public:
    // process id
    int id;
    // arrival time
    int arrival;
    //burst time
    int burst;
    // remainig execution time
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
    int num;
    cin >> num;
    vector<Process> v;
    // take input for all processes
    for (int i = 1; i <= num; i++) {
        int id, arrival, burst;
        cin >> id >> arrival >> burst;
        Process pr(id, arrival, burst);
        v.push_back(pr);
    }
    // set clock time to zero
    int clock = 0;
    vector<Process> end;
    while (v.size() > 0) {
        int min = -1;
        // find the process with least remaing execution time
        for (int i = 0; i < v.size(); i++) {
            if (v[i].arrival <= clock && (min == -1 || v[i].rem < v[min].rem)) min = i;
        }
        if (min == -1) clock++;
        else {
            v[min].rem--;
            clock++;
            // if remaing time is zero, remove the process from the queue
            if (v[min].rem == 0) {
                // update turnaround time
                v[min].turn = clock - v[min].arrival;
                // update waiting time
                v[min].waiting = clock - v[min].burst - v[min].arrival;
                end.push_back(v[min]);
                v.erase(v.begin() + min);
            }
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
