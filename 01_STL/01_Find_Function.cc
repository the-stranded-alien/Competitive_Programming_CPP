#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    
    int arr[] = {1,10,11,9,100};
    int n = sizeof(arr)/sizeof(int);

    // Search - Find
    int key;
    cout << "Enter Key : ";
    cin >> key;
    auto it = find(arr, arr+n, key);
    // cout << "Address : " << it << endl;
    int index = it - arr;
    // cout << "Index : " << index << endl;

    if(index==n){
        cout << key << " Not Present" << endl;
    } else {
        cout << "Present At Index : " << index;
    }
    return 0;
}