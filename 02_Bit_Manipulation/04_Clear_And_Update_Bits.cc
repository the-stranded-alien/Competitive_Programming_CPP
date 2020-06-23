# include<iostream>
using namespace std;

void clearBit(int &n, int i){
    int mask = ~(1<<i);
    n = (n & mask);
}

void updateBit(int &n, int i, int v){
    int clr_mask = ~(1<<i);
    int cleared_n = (n&clr_mask);
    int mask = (v << i);
    n = (cleared_n|mask);
}

int main() {
    
    int n;
    int i;
    cout << "\nEnter N : ";
    cin >> n;
    cout << "Enter i : ";
    cin >> i;
    clearBit(n,i);
    cout << "Number After Clearing i-th Bit : " << n;
    
    int i2;
    int v;
    cout << "\nEnter i And v To Udate : ";
    cin >> i2 >> v;
    updateBit(n, i2, v);
    cout << "Number After Updating i-th Bit : " << n;

    return 0;
}