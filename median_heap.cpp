#include<iostream>

using namespace std;

template<typename T>
class Heap{


    int size, capacity;
    int sizeMin, sizeMax, capacityMin, capacityMax;
    T *queue;
    T *minQueue;
    T *maxQueue;

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
    void heapifyMin(int i){
        int temp = i;
        if((minQueue[left(i)] < minQueue[i]) && (left(i) < sizeMin))
            temp = left(i);
        if((minQueue[right(i)] < minQueue[temp]) && (right(i) < sizeMin))
            temp = right(i);
        if(temp!=i){
            T x;
            x = minQueue[temp];
            minQueue[temp] = minQueue[i];
            minQueue[i] = temp;
            heapifyMin(temp);
        }
    }
    void heapifyMax(int i){
        int temp = i;
        if((maxQueue[left(i)] > maxQueue[i]) && (left(i) < sizeMax))
            temp = left(i);
        if((maxQueue[right(i)] > maxQueue[temp]) && (right(i) < sizeMax))
            temp = right(i);
        if(temp!=i){
            T x;
            x = maxQueue[temp];
            maxQueue[temp] = maxQueue[i];
            maxQueue[i] = temp;
            heapifyMax(temp);
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
    void heapifyBottomUpMin(int i){

        while(minQueue[parent(i)] > minQueue[i] && parent(i) != -1){

            T temp = minQueue[i];
            minQueue[i] = minQueue[parent(i)];
            minQueue[parent(i)] = temp;
            i = parent(i);
            cout<<"coming ";
            printMinHeap();
        }
        //cout<<"done heapifying"<<endl;
    }
    void makeHeapMin(){
        for(int i=sizeMin/2; i<sizeMin; i++)
            heapifyBottomUpMin(i);
    }
    void heapifyBottomUpMax(int i){

        while(maxQueue[parent(i)] < maxQueue[i] && parent(i) != -1){

            T temp = maxQueue[i];
            maxQueue[i] = maxQueue[parent(i)];
            maxQueue[parent(i)] = temp;
            i = parent(i);
        }
    }
    void makeHeapMax(){
        for(int i=sizeMax/2; i<sizeMax; i++)
            heapifyBottomUpMax(i);
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
    void resizeMin(){
        int old = capacityMin;
        if(capacityMin == 0){
            minQueue = new T[1];  //really important, don't forget
            capacityMin = 1;
            return;
        }
        T temp[sizeMin];
        for(int i=0; i<sizeMin; i++){
            temp[i] = minQueue[i];
        }
        delete[] minQueue;
        capacityMin = sizeMin*2;
        minQueue = new T[capacityMin];
        for(int i=0; i<sizeMin; i++){
            minQueue[i] = temp[i];
        }
        //cout<<"doneresizing"<<endl;
        return;
    }
    void resizeMax(){
        int old = capacityMax;
        if(capacityMax == 0){
            maxQueue = new T[1];  //really important, don't forget
            capacityMax = 1;
            return;
        }
        T temp[sizeMax];
        for(int i=0; i<sizeMax; i++){
            temp[i] = maxQueue[i];
        }
        delete[] maxQueue;
        capacityMax = sizeMax*2;
        maxQueue = new T[capacityMax];
        for(int i=0; i<sizeMax; i++){
            maxQueue[i] = temp[i];
        }
        return;
    }
public:

    Heap(){size = 0; capacity = 0; queue = NULL; minQueue = NULL; maxQueue = NULL; capacityMin=0; capacityMax = 0;
        sizeMin=0; sizeMax=0;}
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
    Heap(T a){

        if(size == capacity){
            resize();
            resizeMin();
        }
        queue[size++] = a;
        minQueue[sizeMin++] = a;
    }
    void push(T a){
        if(size == capacity)
            resize();
        queue[size++] = a;
        heapifyBottomUp(size-1);
        //cout<<"done1"<<endl;
        pushMinMax(a);
    }
    void pushMin(T a){
        if(sizeMin == capacityMin)
            resizeMin();
        minQueue[sizeMin++] = a;
        heapifyBottomUpMin(sizeMin-1);
        //cout<<"done final"<<endl;
    }
    void pushMax(T a){
        if(sizeMax == capacityMax)
            resizeMax();
        maxQueue[sizeMax++] = a;
        
        heapifyBottomUpMax(sizeMax-1);
        
    }
    void pushMinMax(T a){
        if(sizeMin == 0){
            //cout<<"done2"<<endl;
            pushMin(a);
            //cout<<"done5"<<endl;
            return;
        }
        if(mintop() > a){
            if(sizeMax == sizeMin){
                T temp = maxtop();
                maxpop();
                pushMin(temp);
                pushMax(a);
                cout<<"on "<<a<<endl;
                printMinHeap();
                printMaxHeap();
            }
            else{
                pushMax(a);
                cout<<"on "<<a<<endl;
                printMinHeap();
                printMaxHeap();
            }
        }
        else{
            if(sizeMin > sizeMax){
                T temp = mintop();
                minpop();
                pushMax(temp);
                pushMin(a);
                cout<<"on "<<a<<endl;
                printMinHeap();
                printMaxHeap();
            }
            else{
                pushMin(a);
                cout<<"on "<<a<<endl;
                printMinHeap();
                printMaxHeap();
            }
        }
    }
    /*
    Change the getHeap function to 
    T *getHeap(){
        
        return queue;
    }
    this will return the original queue and we can make changes outside the class as well
    */
    T *getHeap(){
        T *temp;
        temp = new T[size];
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
    void printMinHeap(){

        for(int i=0; i<sizeMin; i++)
            cout<<minQueue[i]<<" ";
        cout<<endl;
    }
    void printMaxHeap(){

        for(int i=0; i<sizeMax; i++)
            cout<<maxQueue[i]<<" ";
        cout<<endl;
    }
    int getSize(){
        return size;
    }
    T top(){
        return queue[0];
    }
    void pop(){
        queue[0] = queue[size-1];
        heapify(0);
        --size;
    }
    T mintop(){
        return minQueue[0];
    }
    void minpop(){
        minQueue[0] = minQueue[sizeMin-1];
        heapifyMin(0);
        --sizeMin;
    }
    T maxtop(){
        return maxQueue[0];
    }
    void maxpop(){
        maxQueue[0] = maxQueue[sizeMax-1];
        heapifyMax(0);
        --sizeMax;
    }
    void printMedian(){

        if(size%2==0){
            cout<<maxtop()<<" "<<mintop();
        }
        else
            cout<<mintop();
        cout<<endl;
    }
};
int main(){


    Heap<int> a;
    int n;
    cin>>n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        a.push(x);
    }
    /*
    int * temp = a.getHeap();
    for(int i=0;i<a.getSize();i++)
        cout<<temp[i]<<" ";
        */
    a.printMedian();
}