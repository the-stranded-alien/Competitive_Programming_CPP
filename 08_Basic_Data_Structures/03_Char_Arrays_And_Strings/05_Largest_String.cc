#include<iostream>
#include<cstring>
using namespace std;

// Print The Largest String And Its Length

int main() {
    int n;
    cin >> n;
    char a[1000];
    cin.get(); // To Deal With Extra "Enter"
    char largest[1000];
    int len = 0;
    int largest_len = 0;
    for(int i = 0; i < n; i++) {
        cin.getline(a, 1000);
        len = strlen(a);
        if(len > largest_len) {
            largest_len = len;
            strcpy(largest, a);
        }
    }
    cout << "Largest String : " << largest << " With Length : " << largest_len << endl;
    return 0;
}