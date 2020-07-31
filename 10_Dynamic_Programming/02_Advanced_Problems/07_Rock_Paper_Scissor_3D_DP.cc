#include<iostream>
#include<iomanip>
using namespace std;

double dp[105][105][105];

void set_dp() {
    for(int i = 0; i <= 102; i++) {
        for(int j = 0; j <= 102; j++) {
            for(int k = 0; k <= 102; k++) {
                dp[i][j][k] = -1.0;
            }
        }
    }
}

// Probability That Rock Survives
double rock_survives(int r, int s, int p) {
    // Base Cases
    if(r == 0 || s == 0) return 0.0;
    if(p == 0) return 1.0;
    // Recursive Cases
    if(dp[r][s][p] != -1.0) return dp[r][s][p]; // Look Up
    double tot = ((r * s) + (r * p) + (s * p));
    double ret = 0.0;
    ret += (rock_survives((r - 1), s, p) * ((r * p) / tot)); // Paper Kills Rock
    ret += (rock_survives(r, (s - 1), p) * ((r * s) / tot)); // Rock Kills Scissor
    ret += (rock_survives(r, s, (p - 1)) * ((s * p) / tot)); // Scissors Kills Paper
    return (dp[r][s][p] = ret);
}

// Probability That Scissor Survives
double scissor_survives(int r, int s, int p) {
    // Base Cases
    if(p == 0 || s == 0) return 0.0;
    if(r == 0) return 1.0;
    // Recursive Cases
    if(dp[r][s][p] != -1.0) return dp[r][s][p]; // Look Up
    double tot = ((r * s) + (r * p) + (s * p));
    double ret = 0.0;
    ret += (scissor_survives((r - 1), s, p) * ((r * p) / tot)); // Paper Kills Rock
    ret += (scissor_survives(r, (s - 1), p) * ((r * s) / tot)); // Rock Kills Scissor
    ret += (scissor_survives(r, s, (p - 1)) * ((s * p) / tot)); // Scissors Kills Paper
    return (dp[r][s][p] = ret);
}

// Probability That Paper Survives
double paper_survives(int r, int s, int p) {
    // Base Cases
    if(p == 0 || r == 0) return 0.0;
    if(s == 0) return 1.0;
    // Recursive Cases
    if(dp[r][s][p] != -1.0) return dp[r][s][p]; // Look Up
    double tot = ((r * s) + (r * p) + (s * p));
    double ret = 0.0;
    ret += (paper_survives((r - 1), s, p) * ((r * p) / tot)); // Paper Kills Rock
    ret += (paper_survives(r, (s - 1), p) * ((r * s) / tot)); // Rock Kills Scissor
    ret += (paper_survives(r, s, (p - 1)) * ((s * p) / tot)); // Scissors Kills Paper
    return (dp[r][s][p] = ret);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int r, s, p;
        cin >> r >> s >> p;
        set_dp();
        double rock = rock_survives(r, s, p);
        set_dp();
        double scissor = scissor_survives(r, s, p);
        set_dp();
        double paper = paper_survives(r, s, p);
        cout << fixed << setprecision(9) << rock << " " << scissor << " " << paper << endl;
    }
    return 0;
}