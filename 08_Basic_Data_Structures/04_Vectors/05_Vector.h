class Vector {
    int cs; // Current Size
    int ms; // Maximum Size
    int *arr; // Pointer To Dynamic Array
public:
    Vector() {
        cs = 0;
        ms = 1;
        arr = new int[ms];
    }
    void push_back(const int d) {
        if(cs == ms) {
            // If Array Is Full
            int *oldArray = arr;
            arr = new int[2 * ms];
            ms = 2 * ms;
            for(int i = 0; i < ms; i++) arr[i] = oldArray[i];
            delete [] oldArray; // Clear Old Memory
        }
        arr[cs] = d;
        cs++;
    }
    void pop_back() {
        cs--;
    }
    int front() const {
        return arr[0];
    }
    int back() const {
        return arr[cs - 1];
    }
    bool empty() const {
        return (cs == 0);
    }
    int capacity() const {
        return ms;
    }
    int at(const int i) {
        return arr[i];
    }
    int size() const {
        return cs;
    }
    // Operator Overloading
    int operator[](const int i) {
        return arr[i];
    }
};