#include<iostream>
#include<cstring>
using namespace std;

// BALIFE - Load Balancing (SPOJ)
// SuperComputer Inc. have built a super-fast computer server consisting of N hyper-scalar
// lightning-fast processors Beta 007. These processors are numbered from 1 to N and are
// used to process independent jobs. Every new incoming job is assigned to an arbitrary
// processor. Sometimes, a processor may be assigned too many jobs while other processors
// have a relatively light load (or even wait idly). In that case, the whole system undergoes
// rebalancing. Rebalancing proceeds in rounds. In each round, every processor can transfer
// at most one job to each of its neighbors on the bus. Neighbors of the processor i are the
// processors i-1 and i+1 (processors 1 and N have only one neighbor each, 2 and N-1
// respectively). The goal of rebalancing is to achieve that all processors have the same
// number of jobs. Given the number of jobs initially assigned to each processor, you are
// asked to determine the minimal number of rounds needed to achieve the state when every
// processor has the same number of jobs, or to determine that such rebalancing is not possible.

int main() {
    int arr[200000];
    int n;
    while(1) {
        // Take Input Current Test Case
        memset(arr, 0, sizeof arr);
        int max_load = 0;
        int load = 0;
        cin >> n;
        // Stop Taking Input If N == -1
        if(n == -1) break;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            load += arr[i];
        }
        if(load % n != 0) {
            cout << -1 << endl;
            continue;
        }
        // Find The Load That Is To Be Divided Equally
        load = (load / n);
        // Greedy Step
        int diff = 0;
        for(int i = 0; i < n; i++) {
            // Find The Difference Between Final Load
            // To Be Assigned And Current Loads
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout << max_load << endl;
    }
    return 0;
}