#include<iostream>
using namespace std;

void generate_subsequence(char *in, char *out, int i, int j) {
    // Base Case
    if(in[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    // Recursive Case
    // Include The Current Character
    out[j] = in[i];
    generate_subsequence(in, out, i + 1, j + 1);
    // Exclude The Current Character
    generate_subsequence(in, out, i + 1, j);
    
    return;
}

int main() {
    char input[] = "abc";
    char output[10];
    generate_subsequence(input, output, 0, 0);
    return 0;
}