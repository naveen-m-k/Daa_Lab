#include<iostream>
#define SIZE 10
using namespace std;

class MergeSort{
    public:
    int a[SIZE];
    void getInput();
    void printArray();
    void mergesort(int[],int,int);
    void merge(int[],int,int,int);
};

void MergeSort::getInput(){
    cout<<"Before sorting"<<endl;
    for(int i=0;i<SIZE;i++){
        a[i]=rand()%100;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    mergesort(a,0,SIZE-1);
}

void MergeSort::printArray(){
    cout<<"After sorting"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void MergeSort::mergesort(int a[],int start,int end){
    int mid=0;
    if(start<end)
    {
        mid=start+((end-start)/2);
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
    }

}

void MergeSort::merge(int a[],int start,int mid, int end){
    int n1=mid-start+1;
    int n2=end-mid;
    int left_array[n1];
    int right_array[n2];
    int i=0,j=0,k=start;

    while(i<n1){
        left_array[i++]=a[k++];
    }
    k=mid+1;
    while(j<n2){
        right_array[j++]=a[k++];
    }
    i=0;
    j=0;
    k=start;
    while(i<n1&&j<n2){
        if(left_array[i]<right_array[j]){
            a[k++]=left_array[i++];
        }
        else
        {
            a[k++]=right_array[j++];
        }
    }
    while(i<n1){
         a[k++]=left_array[i++];
    }

    while(j<n2){
     a[k++]=right_array[j++];   
    }
}

int main()
{
    MergeSort m;
    m.getInput();
    m.printArray();
    
}
