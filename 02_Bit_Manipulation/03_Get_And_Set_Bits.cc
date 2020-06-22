# include<iostream>
using namespace std;

int getBit(int n, int i){
    int mask = (1<<i);
    int bit = (n & mask) > 0 ? 1:0;
    return bit;
}

int setBit(int n, int i){
    int mask = (1<<i);
    int ans = n|mask;
    return ans;
}

int main() {
    
    int n;
    int i;
    cout << "\nEnter N : ";
    cin >> n;
    cout << "Enter i : ";
    cin >> i;
    cout << "i-th Bit Is : " << getBit(n,i);
    cout << "\nNumber After Setting i-th Bit : " << setBit(n,i);

    return 0;
}