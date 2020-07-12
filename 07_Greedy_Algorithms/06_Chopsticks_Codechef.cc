#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// Chopsticks (TACHSTCK) - Codeforces
// Actually, the two sticks in a pair of chopsticks need not be of the same length.
// A pair of sticks can be used to eat as long as the difference in their length is at most D.
// The Chef has N sticks in which the ith stick is L[i] units long. A stick can't be part of
// more than one pair of chopsticks. Help the Chef in pairing up the sticks to form the maximum
// number of usable pairs of chopsticks.

int main() {
    int N, D;
    cin >> N >> D;
    int chopsticks[100005];
    for(int i = 0; i < N; i++) cin >> chopsticks[i];
    sort(chopsticks, chopsticks + N);
    int pairs = 0;
    for(int idx = 0; idx < (N - 1); idx++) {
        if(abs(chopsticks[idx] - chopsticks[idx + 1]) <= D) {
            pairs++;
            idx++;
        }
    }
    cout << pairs << endl;
    return 0;
}