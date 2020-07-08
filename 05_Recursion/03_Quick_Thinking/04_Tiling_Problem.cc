#include<iostream>
using namespace std;

// Place The Tiles On Wall Of Size Of 4 x N. Tiles Are Of
// Size (1, 4) and (4, 1). In How Many Ways Can Wall Be Build ?

int buildWall(int n) {
    if(n <= 3) return 1;
    return (buildWall(n - 1) + buildWall(n - 4));
}

int main() {
    int N;
    cin >> N;
    cout << buildWall(N) << endl;
    return 0;
}