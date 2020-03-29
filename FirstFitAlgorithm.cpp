#include <iostream>
#include <vector>
using namespace std;

int main() {
    // take input for number of memory blocks and number of I/O operations
    int num_blocks, num_processes;
    cout << "Enter number of blocks and processes : ";
    cin >> num_blocks >> num_processes;
    vector<int> memory(num_blocks, 0);
    vector<int> process(num_processes, 0);
    cout << "Enter block sizes : ";
    // take input for memory block sizes
    for (int i = 0; i < num_blocks; i++) {
        cin >> memory[i];
    }
    // take input for process memory sizes
    cout << "Enter process memory sizes: ";
    for (int i = 0; i < num_processes; i++) {
        cin >> process[i];
    }

    for (int i = 0; i < process.size(); i++) {
        int fits = -1;
        // find the first process that is large enough to store the current process
        for (int ix = 0; ix < memory.size(); ix++) {
            if (memory[ix] >= process[i]) {
                fits = ix;
                break;
            }
        }
        // if no process is found, print could not allocate memory
        if (fits == -1) cout << endl << "Cannot Allocate memory to process of size: " << process[i] << endl << endl;
        else {
            // remove process from queue
            cout << endl << "Process : " << process[i] << " Memory block : " << memory[fits] << endl;
            memory.erase(memory.begin() + fits);
        }
    }
    return 0;
}
