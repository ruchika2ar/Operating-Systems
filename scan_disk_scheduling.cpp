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
    int num_tracks;
    cout << "Enter number of tracks :";
    cin >> num_tracks;
        // intiliase number of head movements to zero
    int head_movement = 0;
    cout << "Order of I/O requests serviced: ";
    // Assuming the head is moving towards track 0;
    for(int cur = start; cur >= 0; cur--) {
        for(int i = 0; i < v.size(); i++) {
            // check if there is a operation with track number equal to current track
            if(v[i] == cur) {
                // update number of head movements
                head_movement += start - v[i];
                // update position of current track
                start = v[i];
                cout << v[i] << " ";
                // remove the executed operation from the queue
                v.erase(v.begin() + i);
                break;
            }
        }
    }
    // move the head till track 0
    head_movement += start - 0;
    start = 0;
    // move head from track zero till the track of the operation with the highest track number
    for(int cur = 0; cur < num_tracks && v.size() > 0; cur++) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == cur) {
                 // update number of head movements
                head_movement += v[i] - start;
                // update position of current track
                start = v[i];             
                cout << v[i] << " ";
                // remove the executed operation from the queue
                v.erase(v.begin() + i);
                break;
            }
        }
    }
        // output number of head movements
    cout << endl << "Total number of head movements : " << head_movement << endl;
    return 0;
}
