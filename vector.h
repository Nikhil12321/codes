#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;
template<typename T>
class Vector {
    int s,c;
    T * ptr;
    static int x;
    void doubleitup() {
        c = c == 0? 1 : 2 * c;
        T * temp = new T[c];
        for (int i = 0; i < c/2; i++) {
            temp[i] = ptr[i];
        }
        delete ptr;
        ptr = temp;
    }
    public:
    Vector() : s(0), c(0), ptr(0) {}
    Vector(int size, const T & init) : c(size), s(size), ptr(0) {
        ptr = new T[c];
        for (int i = 0; i < s; i++) {
            ptr[i] = init;
        }
    }
    Vector(const Vector & B) : s(B.s), c(B.c) {
        ptr = new T[c];
        for (int i = 0; i < s; i++) {
            ptr[i] = B.ptr[i];
        }
    }
    Vector & operator=(const Vector & B) {
        if (ptr) delete ptr;
        s = B.s;
        c = B.c;
        ptr = new T[c];
        for (int i = 0; i < s; i++) {
            ptr[i] = B.ptr[i];
        }
        return *this;
    }
    Vector & operator+=(const Vector & B) {
        for (int i = 0; i < B.s ; i++) {
            push_back(B.ptr[i]);
        }
        return *this;
    }
    Vector & operator+=(const T & el) {
        x++;
        push_back(el);
        return * this;
    }
    static int getX() {
        return x;
    }
    const Vector operator+(const Vector & B) const {
        Vector temp = *this;
        temp+=B;
        return temp;
    }
    ~Vector() {
        delete ptr;
    }
    void push_back(const T & el) {
        if (s == c) {
            doubleitup();
        }
        ptr[s] = el;
        s++;
    }
    void insertAtK(const T & el, int k) {
        if (k > s) {
            throw "Invalid index";
        }
        if( s == c) {
            doubleitup();
        }
        for(int i = s-1; i >= k; i--) {
            ptr[i+1] = ptr[i];
        }
        ptr[k] = el;
        s++;
    }
    T At(int index) const {
        if (index >= s || index < 0) {
            throw "Invalid Index";
        }
        return ptr[index];
    }
    T & operator[](int index) {
        if (index >= s || index < 0) {
            throw "Invalid Index";
        }
        return ptr[index];
    }
    const T & operator[](int) const;
    int size() {
        return s;
    }
    template<typename V>
    friend ostream & operator<<(ostream &, const Vector<V> &);
};
template<typename V>
const V & Vector<V>::operator[](int index) const {
    if (index >= s || index < 0) {
        throw "Invalid Index";
    }
    return ptr[index];
}
template<typename T>
ostream & operator<<(ostream & out, const Vector<T> & B) {
    for (int i = 0; i < B.s; i++) {
        out << B.ptr[i] << " ";
    }
    return out;
}
template<typename T>
int Vector<T>::x = 5;
#endif
