#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define MOD 1000000007

// Working Out (Codeforces - 429-B)
// Summer is coming! It's time for Iahub and Iahubina to work out, as they both want to look
// hot at the beach. The gym where they go is a matrix a with n lines and m columns.
// Let number a[i][j] represents the calories burned by performing workout at the cell
// of gym in the i-th line and the j-th column. Iahub starts with workout located at line 1
// and column 1. He needs to finish with workout a[n][m]. After finishing workout a[i][j],
// he can go to workout a[i + 1][j] or a[i][j + 1]. Similarly, Iahubina starts with workout
// a[n][1] and she needs to finish with workout a[1][m]. After finishing workout from cell
// a[i][j], she goes to either a[i][j + 1] or a[i - 1][j]. There is one additional condition
// for their training. They have to meet in exactly one cell of gym. At that cell, none of
// them will work out. They will talk about fast exponentiation (pretty odd small talk)
// and then both of them will move to the next workout. If a workout was done by either
// Iahub or Iahubina, it counts as total gain. Please plan a workout for Iahub and Iahubina
// such as total gain to be as big as possible. Note, that Iahub and Iahubina can perform
// workouts with different speed, so the number of cells that they use to reach meet cell
// may differs.

const int NN = 1005;
int boy_start[NN][NN];
int boy_end[NN][NN];
int girl_start[NN][NN];
int girl_end[NN][NN];
int calorie[NN][NN];

int maxCalories(int M, int N) {
    // Building boy_start[][] Table In Bottom Up Fashion.
    // Here boy_start[i][j] --> The Max Calories That Can Be Burnt If The Boy
    // Start From (1, 1) And Goes Upto (i, j).
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            boy_start[i][j] = (calorie[i][j] + max(boy_start[i - 1][j], boy_start[i][j - 1]));
        }
    }
    // Building girl_start[][] Table In Bottom Up Fashion.
    // Here girl_start[i][j] --> The Max Calories That Can Be Burnt If The Girl
    // Starts From (M, 1) And Goes Up To (i, j).
    for(int i = M; i >= 1; i--) {
        for(int j = 1; j <= N; j++) {
            girl_start[i][j] = (calorie[i][j] + max(girl_start[i + 1][j], girl_start[i][j - 1]));
        }
    }
    // Building boy_end[][] Table In Bottom Up Fashion Which Specifies The Journey From End To Start.
    // Here boy_end[i][j] --> The Max Calories That Can Be Burnt If The Boy
    // Starts From End i.e. (M, N) And Comes Back To (i, j).
    for(int i = M; i >= 1; i--) {
        for(int j = N; j >= 1; j--) {
            boy_end[i][j] = (calorie[i][j] + max(boy_end[i + 1][j], boy_end[i][j + 1]));
        }
    }
    // Building girl_end[][] Table In Bottom Up Fashion Which Specifies The Journey From End To Start.
    // Here girl_end[i][j] --> The Max Calorie That Can Be Burnt If The Girl
    // Starts From End i.e. (M, N) And Comes Back To (i, j).
    for(int i = 1; i <= M; i++) {
        for(int j = N; j >= 1; j--) {
            girl_end[i][j] = (calorie[i][j] + max(girl_end[i - 1][j], girl_end[i][j + 1]));
        }
    }
    // Iterate Over All The Possible Meeting Points i.e. Between (2, 2) To (M - 1, N - 1)
    // Consider This Point As The Actual Meeting Point And Calculate The Max Possible Answer.
    int ans = 0;
    for(int i = 2; i < M; i++) {
        for(int j = 2; j < N; j++) {
            int ans1 = (boy_start[i][j - 1] + boy_end[i][j + 1] + girl_start[i + 1][j] + girl_end[i - 1][j]);
            int ans2 = (boy_start[i - 1][j] + boy_end[i + 1][j] + girl_start[i][j - 1] + girl_end[i][j + 1]);
            ans = max(ans, max(ans1, ans2)); 
        }
    }
    return ans;
}

int main() {
    memset(boy_start, 0, sizeof(boy_start));
    memset(boy_end, 0, sizeof(boy_end));
    memset(girl_start, 0, sizeof(girl_start));
    memset(girl_end, 0, sizeof(girl_end));
    memset(calorie, 0, sizeof(calorie));
    int M, N;
    cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> calorie[i][j];
        }
    }
    cout << maxCalories(M, N) << endl;
    return 0;
}