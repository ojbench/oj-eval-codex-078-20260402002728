#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
    // Default constructor
    Evil() : st(0), ed(0), val(0), data(nullptr) {
        data = new int[1];
        data[0] = 0;
    }

    // Parameterized constructor
    Evil(int st_, int ed_, int val_) : st(st_), ed(ed_), val(val_), data(nullptr) {
        int len = (ed >= st) ? (ed - st + 1) : 1;
        if (ed < st) {
            // Normalize to a single element buffer if invalid range
            st = ed = st_;
        }
        data = new int[len];
        for (int i = 0; i < len; ++i) data[i] = 0;
    }

    // Copy constructor
    Evil(const Evil &other) : st(other.st), ed(other.ed), val(other.val), data(nullptr) {
        int len = (ed >= st) ? (ed - st + 1) : 1;
        data = new int[len];
        for (int i = 0; i < len; ++i) data[i] = other.data ? other.data[i] : 0;
    }

    // Assignment operator
    Evil& operator=(const Evil &other) {
        if (this == &other) return *this;
        int newLen = (other.ed >= other.st) ? (other.ed - other.st + 1) : 1;
        int *newData = new int[newLen];
        for (int i = 0; i < newLen; ++i) newData[i] = other.data ? other.data[i] : 0;
        delete[] data;
        st = other.st; ed = other.ed; val = other.val;
        data = newData;
        return *this;
    }

    // Subscript operator: returns reference to stored variable.
    int & operator[](int i) {
        if (st <= i && i <= ed) {
            return data[i - st];
        }
        // If out of range, return first element (st day)
        return data[0];
    }

    // Prefix ++ : increment val
    Evil& operator++() {
        ++val;
        return *this;
    }

    // Postfix ++ : increment val, return old value
    Evil operator++(int) {
        Evil tmp(*this);
        ++val;
        return tmp;
    }

    // Output operator
    friend ostream& operator<<(ostream &os, const Evil &e) {
        os << e.val << " ";
        int len = (e.ed >= e.st) ? (e.ed - e.st + 1) : 1;
        for (int i = 0; i < len; ++i) {
            os << e.data[i] << " ";
        }
        os << "\n";
        return os;
    }

    void Print(){
        cout << val << " ";
        int len = (ed >= st) ? (ed - st + 1) : 1;
        for(int i = 0; i < len; ++i)
            cout << data[i] <<" ";
        cout << endl;
    }

    // Destructor
    ~Evil(){
        delete[] data;
        data = nullptr;
    }
};

#endif//EVIL_HPP
