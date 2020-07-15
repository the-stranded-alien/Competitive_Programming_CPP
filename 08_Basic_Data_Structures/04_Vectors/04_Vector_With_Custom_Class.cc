#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// Given Locations Of Some Cabs {(x1, y1), (x2, y2), (x3, y3), ....... }.
// Tell There Location In Sorted Order From The Origin.

class Cab {
    public:
    string cab_name;
    int x;
    int y;
    Cab() {

    }
    Cab(string n, int x, int y) {
        cab_name = n;
        this->x = x;
        this->y = y;
    }
    int dist() {
        // Return Square Of Distance From Origin
        return ((x * x) + (y * y));
    }
};

bool compare(Cab A, Cab B) {
    int da = A.dist();
    int db = B.dist();
    if(da == db) return (A.cab_name.length() < B.cab_name.length());
    return (da < db);
}

int main() {
    int n;
    cin >> n;
    vector<Cab> v;
    for(int i = 0; i < n; i++) {
        int x, y;
        string name;
        cin >> name;
        cin >> x >> y;
        Cab temp(name, x, y);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);
    for(auto c : v) {
        cout << "Cab : " << c.cab_name << " / Dist : " << c.dist() << " / Location : " << c.x << " " << c.y << endl;
    } 
    return 0;
}