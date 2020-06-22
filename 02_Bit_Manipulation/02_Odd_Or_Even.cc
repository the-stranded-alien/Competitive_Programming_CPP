# include<iostream>
using namespace std;

bool isOdd(int n){
    return (n&1);
}

// if ( N & 1 ) == 1 => N is Odd
// if ( N & 1 ) == 0 => N is Even

int main() {

    int n1 = 5;
    int n2 = 8;

    cout << "Is " << n1 << " Odd : " << isOdd(n1) << endl;
    cout << "Is " << n2 << " Odd : " << isOdd(n2) << endl;

    return 0;
}