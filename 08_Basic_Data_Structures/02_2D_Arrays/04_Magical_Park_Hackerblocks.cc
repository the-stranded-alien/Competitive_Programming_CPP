#include<iostream>
using namespace std;

// Piyush and Magical Park (Hackerblocks)
// Piyush is lost in a magical park which contains N rows and M columns.In order to get
// out of park safely and return home, he needs atleast K amount of strength.Given a N
// by M pattern, your task is to find weather Piyush can ever escape the park.
// Piyush enters the park with strength S. The park is filled with some obstacles denoted
// by ‘.’ , some magical beans denoted by ‘*’ and some blockades denoted as ‘#’. If he
// encounters an obstacle (.) , strength decreases by 2. If he encounters a magic bean (' * ')
// , his strength increases by 5. Piyush can only walk row wise, so he starts from left of a
// row and moves towards right and he does this for every row. However when he encounters
// a blockade (#) , he cannot go any further in his current row and simply jumps to the start
// of a new line without losing any strength. Piyush requires a strength of 1 for every step.
// His strength should always be greater than K while traversing or else Piyush will get lost.
// Assume that Piyush can shift immediately from last of one row to the start of next one
// without loss of any strength, help out Piyush to escape the park. His escape is successful
// if he is able to return home with atleast K strength.

void magical_park(char a[][100], int m, int n, int k, int s) {
    bool success = true; // Piyush Can Get Out Of The Park
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char ch = a[i][j];
            if(s < k) {
                success = false;
                break;
            }
            if(ch == '*') s += 5;
            else if(ch == '.') s -= 2;
            else break;
            // We Also Loose 1 Point When We Move Right Except For The Last Column
            if(j != (n - 1)) s--;
        }
    }
    if(success) {
        cout << "Yes" << endl;
        cout << s << endl;
    } else cout << "No" << endl;
    return;
}

int main() {
    int m, n, k, s;
    cin >> m >> n >> k >> s;
    char park[100][100];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> park[i][j];
    }
    magical_park(park, m, n, k, s);
    return 0;
}