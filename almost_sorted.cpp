#include<iostream>
#include<vector>
#include<queue>


using namespace std;


//make different heaps for different set of k numbers 

int *almostSorted(std::vector<int> numbers, int k){


    vector<priority_queue<int> > v;
    int n = numbers.size();
    int j=0;
    int i,max, save;
    int arr[n];


    while(j<n){


        priority_queue<int> q;
        for(i=j; (i<j+k) && (i<n); i++){

            q.push(numbers[i]);
        }
        
        j = j+k;
        v.push_back(q);
    }

    int pos = n-1;


//pick the first number of the heap having the maximum element(max heap = priority queue) and put it behind the array
    while(!v.empty()){


        max = -111;
        for(i=0; i<v.size(); i++){


            if(v[i].top() > max)
            {

                max = v[i].top();
                save = i;
            }
        }

        arr[pos] = max;
        v[save].pop();
        if(v[save].size() == 0)
            v.erase(v.begin() + save);
        pos--;

    }

    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;


}

int main(){


    std::vector<int> v;
    int n, i, a, k;

    cin>>n>>k;

    for(i=0; i<n; i++){

        cin>>a;
        v.push_back(a);
    }


    int *ans = almostSorted(v, k);
}