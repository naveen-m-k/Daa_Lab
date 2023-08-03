#include<iostream>
#define SIZE 10
using namespace std;

class QuickSort{
    public:
    int a[SIZE];
    int partition(int[],int,int);
    void quickSort(int[],int,int);
    void getInput();
    void printArray();
};

void QuickSort::getInput(){
    cout<<"Before sorting : "<<endl;
    for(int i=0;i<SIZE;i++){
        a[i]=rand()%100;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quickSort(a,0,SIZE-1);
}

void QuickSort::printArray(){
    cout<<"After sorting : "<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void QuickSort::quickSort(int a[],int start,int end){
    int pivot_index=0;
    if(start<end){
         pivot_index=partition(a,start,end);
         quickSort(a,start,pivot_index-1);
         quickSort(a,pivot_index+1,end);
    }
}

int QuickSort::partition(int a[], int start, int end) {
    int pivot = a[start]; 
    int i = start + 1; 

    for (int j = start + 1; j <= end; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[start], a[i - 1]);

    return i - 1;
}


int main(){
    QuickSort q;
    q.getInput();
    q.printArray();
}

//time complexity 
//best:omega(nlogn)
//avg:theta(nlogn)
//worst:theta(n^2)
