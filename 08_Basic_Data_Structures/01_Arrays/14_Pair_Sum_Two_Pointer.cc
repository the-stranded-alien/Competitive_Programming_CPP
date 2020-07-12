#include<iostream>
using namespace std;

int main() {
    int a[] = {1,3,5,7,10,11,12,13};
    int s = 16;
    int i = 0;
    int j = (sizeof(a) / sizeof(int)) - 1;
    while(i < j) {
        int cur_sum = a[i] + a[j];
        if(cur_sum > s) j--;
        else if(cur_sum < s) i++;
        else {
            cout << a[i] << " And " << a[j] << endl;
            i++;
            j--;
        }
    }    
    return 0;
}