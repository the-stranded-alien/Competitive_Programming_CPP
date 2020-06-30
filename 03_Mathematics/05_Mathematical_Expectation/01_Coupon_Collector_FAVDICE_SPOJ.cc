#include<iostream>
#include<iomanip>
using namespace std;

// FAVDICE - Favourite Dice (SPOJ)
// BuggyD loves to carry his favorite die around. Perhaps you wonder
// why it's his favorite? Well, his die is magical and can be transformed
// into an N-sided unbiased die with the push of a button. Now BuggyD wants
// to learn more about his die, so he raises a question:
// What is the expected number of throws of his die while it has N sides
// so that each number is rolled at least once?

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        double ans = 0;
        for(int i = 1; i <= n; i++) ans += (n / (i * 1.0));
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}