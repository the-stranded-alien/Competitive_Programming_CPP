#include<iostream>
using namespace std;

void generate_strings(char *in, char *out, int i, int j) {
    // Base Case
    if(in[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    // Recursive Case
    // Case 1 -> One Digit At A Time
    if(in[i] == '0') { 
        // Case Handling '0' In Input. If We Have 0 At Current
        // Position We Need Not Take Case Of Two Digits.
        generate_strings(in, out, i + 1, j);
        return;
    }
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    generate_strings(in, out, i + 1, j + 1);
    // Case 2 -> Two Digits At A Time
    if(in[i + 1] != '\0') {
        int secondDigit = in[i + 1] - '0';
        int num = (digit * 10) + secondDigit;
        if(num <= 26) {
            ch = num + 'A' - 1;
            out[j] = ch;
            generate_strings(in, out, i + 2, j + 1); 
        }
    }
    return;
}

int main() {
    char in[100]; // Digits
    cin >> in;
    char out[100];
    generate_strings(in, out, 0, 0);
    return 0;
}