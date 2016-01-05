void heapifyBottomUpMax(int i){

        while(maxQueue[parent(i)] > maxQueue[i] && parent(i) != -1){

            T temp = maxQueue[i];
            maxQueue[i] = maxQueue[parent(i)];
            maxQueue[parent(i)] = temp;
            i = parent(i);
        }
    }
    void makeHeapMin(){
        for(int i=sizeMax/2; i<sizeMax; i++)
            heapifyBottomUpMax(i);
    }