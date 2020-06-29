#include<iostream>
using namespace std;

int pow(int a, int n) {
    if(n == 0) return 1;
    int subprob = pow(a, n/2);
    if(n & 1) return (a * subprob * subprob); // If n Is Odd
    else return (subprob * subprob); // If n Is Even 
}

int main() {
    int a, n;
    cin >> a >> n;
    cout << pow(a, n) << endl;
    return 0;
}