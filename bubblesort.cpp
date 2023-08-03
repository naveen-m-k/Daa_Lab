#include<iostream>
#define SIZE 10
using namespace std;

class BubbleSort{
    public:
    int a[SIZE];
    void getInput();
    void sort();
    void printArray();
};

void BubbleSort::getInput(){
    cout<<"Before sorting : \n";
    for(int i=0;i<SIZE;i++){
        a[i]=rand()%100;
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void BubbleSort::printArray(){
    cout<<"After sorting : \n";
    for(int i=0;i<SIZE;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void BubbleSort::sort(){
    for(int i=0;i<SIZE-1;i++)
    {
        for(int j=i+1;j<SIZE;j++){
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}

int main()
{
    BubbleSort b;
    b.getInput();
    b.sort();
    b.printArray();
}
