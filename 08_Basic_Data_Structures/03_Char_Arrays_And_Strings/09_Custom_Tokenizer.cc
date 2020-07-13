#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char *s, char delim) {
    // Input : String And A Single Char That Acts As Delimiter
    static char *input = NULL; // So That Gets Created Only Once.
    if(s != NULL) {
        // We Are Making The First Call
        input = s;
    }
    // Base Case
    if(input == NULL) return NULL; // After Final Token Has Been Returned
    // Start Extracting Tokens And Store Them In An Array
    char *output = new char[strlen(input) + 1]; // Dynamic Array, So This Is Available After Function Call.
    int i = 0;
    for(;input[i] != '\0'; i++) {
        if(input[i] != delim) {
            output[i] = input[i];
        }
        else {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    // Corner Case
    output[i] = '\0';
    input = NULL;
    return output;
}

int main() {
    char s[100] = "Today, is a rainy, day";
    char *ptr = mystrtok(s, ' ');
    cout << ptr << endl;
    while(ptr != NULL) {
        ptr = mystrtok(NULL, ' ');
        cout << ptr << endl;
    }
    return 0;
}