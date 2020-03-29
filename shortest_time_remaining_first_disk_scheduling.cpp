#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
        // take input for number of operations
    int n;
    cin >> n;
    vector<int> v(n);
    cout << "Enter queue: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
        // enter the starting position of head
    int start;
    cout << "Enter starting position of head: ";
    cin >> start;
    cout << endl;
        // intiliase number of head movements to zero
    int head_movement = 0;
    cout << "Order of I/O requests serviced: ";
    while (v.size() > 0) {
        int min = 0;
        // find the track which is closest to the current track
        for (int i = 0; i < v.size(); i++) {
            if (abs(v[i] - start) < abs(v[min] - start)) {
                min = i;
            }
        }
        cout << v[min] << " ";
        // move head to the track which is closest to the current track
        head_movement += abs(v[min] - start);
        // update current track position
        start = v[min];
        v.erase(v.begin() + min);
    }
        // output number of head movements
    cout << endl << "Total number of head movements : " << head_movement << endl;
    return 0;
}
