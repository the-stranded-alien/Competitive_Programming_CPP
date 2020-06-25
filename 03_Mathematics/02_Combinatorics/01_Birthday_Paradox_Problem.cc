#include<iostream>
using namespace std;

// Birthday Paradox Problem
// What Is The Minimum Number Of People That Should Be
// Present In A Hall So That There's N % Chance Of Two
// People Having The Same Birthday ?

int main(){
    // X Denotes The Probability Of 2 People Having Same B'day.
    float x = 1.0;

    int people = 0;

    float num = 365;
    float denom = 365;

    float p;
    cin >> p;

    if(p==1.0){
        cout << "Minimum No. Of People : " << 366;
        return 0;
    }

    while(x > 1 - p) {
        // 'x' Is Less Than The Threshold
        x = x*(num/denom);
        num--;
        people++;
        // cout << "People : " << people << " And x : " << x << endl;
    }

    cout << "Minimum No. Of People : " << people << endl;

    return 0;
}