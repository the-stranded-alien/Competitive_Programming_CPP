#include<iostream>
using namespace std;

int main() {

    int cnt[64] = {0};

    int n;
    cin >> n;
    int no;
    for(int i=0; i<n; i++){
        cin >> no;
        // Update The 'cnt' Array By Extracting Bits
        int j = 0;
        while(no > 0){
            int last_bit = (no & 1);
            cnt[j] += last_bit;
            j++;
            no = (no >> 1);
        }
    }
    // Iterate Over The Array And Do % 3.
    // Also Form The Anser By Converting 
    // Array Of 1s & 0s Into A Decimal Number.
    int p = 1;
    int ans = 0;
    for(int i=0; i<64; i++){
        cnt[i] %= 3;
        ans += (cnt[i] * p);
        p = (p << 1);
    }    

    cout << "Unique Number : " << ans << endl;

    return 0;
}