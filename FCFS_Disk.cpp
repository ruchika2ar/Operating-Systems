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
    for(int i = 0; i < n; i++) {
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
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
        // move head to the next track in the queue
        head_movement += abs(v[i] - start);
        start = v[i];
    }
    // output number of head movements
    cout << endl << "Total number of head movements : " << head_movement << endl;
    return 0; 
}
