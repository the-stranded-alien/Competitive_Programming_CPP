#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100005];
    int result = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        result = (result ^ arr[i]);
    }
    int temp = result;
    int pos = 0; // Position Of First Set Bit
    while((temp & 1) != 1){
        pos++;
        temp = temp >> 1;
    }

    int mask = (1 << pos);

    int num1 = 0;
    int num2 = 0;
    for(int i = 0; i < n; i++) {
        if((arr[i] & mask) > 0) {
            num1 = num1 ^ arr[i];
        }
    }
    num2 = result ^ num1;
    cout << min(num1, num2) << " " << max(num1, num2) << endl;
    return 0;
}