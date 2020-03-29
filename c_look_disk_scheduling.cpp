#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    cout << "Enter queue: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int start;
    cout << "Enter starting position of head: ";
    cin >> start;
    cout << endl;
    int head_movement = 0;
    cout << "Order of I/O requests serviced: ";
    // Assuming the head is moving towards track 0;
    while (v.size() > 0) {
        bool exists = false;
        int min = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > start) {
                if (min == -1 || v[i] < v[min]) {
                    min = i;
                    exists = true;
                }
            }
        }
        if(!exists) break;
        cout << v[min] << " ";
        head_movement += v[min] - start;
        start = v[min];
        v.erase(v.begin() + min);
    }
    int minimum = v[0];
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < minimum) minimum = v[i];
    }
    head_movement += start - minimum;
    start = minimum;
    while (v.size() > 0) {
        bool exists = false;
        int min = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > start) {
                if (min == -1 || v[i] < v[min]) {
                    min = i;
                    exists = true;
                }
            }
        }
        if(!exists) break;
        cout << v[min] << " ";
        head_movement += v[min] - start;
        start = v[min];
        v.erase(v.begin() + min);
    }
    cout << endl << "Total number of head movements : " << head_movement << endl;
    return 0;
}
