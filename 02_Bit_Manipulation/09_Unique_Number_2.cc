#include<iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    
    int no;
    int xor_res = 0;
    int arr[100005];

    for (int i=0; i<n; i++){
        cin >> no;
        arr[i] = no;
        xor_res = (xor_res ^ no);
    }

    // xor_res = a ^ b
    int temp = xor_res;
    int pos = 0;
    while((temp & 1) != 1){
        pos++;
        temp = temp >> 1;
    }

    // The First Set Bit In 'xor_res'
    // is at Position 'pos'
    int mask = (1<<pos);

    // Find Those Numbers Which Contain
    // Set Bit At Position at 'pos'
    int x = 0;
    int y = 0;
    for (int i=0; i<n; i++){
        if((arr[i] & mask) > 0){
            x = x ^ arr[i];
        }
    }

    y = xor_res ^ x;

    cout << min(x, y) << " " << max(x, y) << endl;

    return 0;
}