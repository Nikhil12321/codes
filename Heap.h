#ifndef Heap
#define Heap
#include<iostream>
using namespace std;
template<typename T>
class Heap{


    int size, capacity;
    T *queue;

    int left(int i){
        if(i==0)
            return 1;
        return 2*i+1;
    }
    int right(int i){
        if(i==0)
            return 2;
        return 2*i+2;
    }
    int parent(int i){
        if(i==0)
            return -1;
        return i/2;
    }

public:

    Heap(){size = 0; capacity = 0; queue = NULL;}
    Heap(T *a, int n){

        if(size == capacity)
            resize();
        for(int i=0; i<n; i++){
            if(size == capacity)
                resize();
            queue[size++] = a[i];
        }
        makeHeap();
    }
    Heap(vector<T> &a){
        int size = a.size();
        if(size == capacity)
            resize();
        for(int i=0; i<n; i++){
            if(size == capacity)
                resize();
            queue[size++] = a[i];
        }
        makeHeap();
    }
    Heap(T a){

        if(size == capacity)
            resize();
        queue[size++] = a;
    }
    void push(T a){
        if(size == capacity)
            resize();
        queue[size++] = a;
        heapifyBottomUp(size-1);
    }
    void resize(){

        int old = capacity;
        if(capacity == 0){
            queue = new T[1];  //really important, don't forget
            capacity = 1;
            return;
        }
        T temp[size];
        for(int i=0; i<size; i++){
            temp[i] = queue[i];
        }
        delete[] queue;
        capacity = size*2;
        queue = new T[capacity];
        for(int i=0; i<size; i++){
            queue[i] = temp[i];
        }
        return;
    }
    void minHeapify(int i){

        for(int i=0; i<size; i++){
            heapify(i);
        }
    }
    void heapify(int i){
        int temp = i;
        if((queue[left(i)] < queue[i]) && (left(i) < size))
            temp = left(i);
        if((queue[right(i)] < queue[temp]) && (right(i) < size))
            temp = right(i);
        if(temp!=i){
            T x;
            x = queue[temp];
            queue[temp] = queue[i];
            queue[i] = temp;
            heapify(temp);
        }
    }
    void heapifyBottomUp(int i){

        while(queue[parent(i)] > queue[i] && parent(i) != -1){

            T temp = queue[i];
            queue[i] = queue[parent(i)];
            queue[parent(i)] = temp;
            i = parent(i);
        }
    }
    void makeHeap(){
        for(int i=size/2; i<size; i++)
            heapifyBottomUp(i);
    }
    /*
    Change the getHeap function to 
    T *getHeap(){
        
        return queue;
    }
    this will return the original queue and we can make changes outside the class as well
    */
    T *getHeap(){
        T temp[size];
        for(int i=0; i<size; i++){
            temp[i] = queue[i];
        } 
        return temp;
    }
    void printHeap(){

        for(int i=0; i<size; i++)
            cout<<queue[i]<<" ";
        cout<<endl;
    }
    int getSize(){
        return size;
    }
};
#endif