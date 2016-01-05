#include<iostream>

using namespace std;

void buildHeap(int *a, int i);
void heapify(int *a, int n, int i);
void heapSort(int *a, int n);
void printArray(int *a, int n);
int left(int i);
int right(int i);
int parent(int i);
void printArray(int *a, int n);
void swap(int *a, int i, int j);


void heapSort(int *a, int n){

    int size = n;
    //loop only for leaf nodes
    for(int i=n/2; i<n; i++)
        buildHeap(a, i);
    printArray(a, n);
    int i=0;

    while(n>1){


        swap(a, 0, n-1);
        //if extra space cannot be used, we make a max heapify to build an ascending array at the end since 
        //the largest element will be added at the end every time
        n--;            
        heapify(a, n, 0);
         
    }

    printArray(a, size);

    
}


//bottom up
void buildHeap(int *a, int i){

    while((a[parent(i)] < a[i]) && parent(i) != -1){
 
        swap(a, parent(i), i);
        i = parent(i);
    }

}

//top down
void heapify(int *a, int n, int i){


    int temp = i;
    
    if((a[left(i)] > a[i]) && (left(i) < n)){
            temp = left(i);
    }
    if((a[right(i)] > a[temp]) && (right(i) < n)){
            temp = right(i);
    }
    if(temp!=i){
        swap(a, temp, i);
        heapify(a, n, temp);
    }

}


void printArray(int *a, int n){


    for(int i=0; i<n; i++){

        cout<<a[i]<<" ";
    }

    cout<<endl;
    return;
}

int left(int i){

    if(i==0)
        return 1;
    return 2*i + 1;
}

int right(int i){

    if(i==0)
        return 2;
    return 2*i + 2;
}

int parent(int i){

    if(i==0)
        return -1;
    return i/2;
}

void swap(int *a, int i, int j){

    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main(){


    int n, i, x;

    cin>>n;
    
    int a[n];
    
    for(i=0; i<n; i++){


        cin>>x;
        a[i] = x;

    }

    heapSort(a, n);
}