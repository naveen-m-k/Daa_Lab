#include<iostream>
#define SIZE 10
using namespace std;

class SelectionSort{
    public:
    int a[SIZE];
    int min;
    void printArray();
    void getInput();
    void sort();
};

void SelectionSort::getInput(){
    cout<<"Before sorting : " <<endl;
    for(int i=0;i<SIZE;i++)
    {
        a[i]=rand()%100;
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}


void SelectionSort::sort(){

    for(int i=0;i<SIZE;i++)
    {
        min=i;
        for(int j=i+1;j<SIZE;j++)
        {
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(a[min],a[i]);
    }
}
void SelectionSort::printArray(){
    cout<<"After sorting : " <<endl;
    for(int i=0;i<SIZE;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}


int main()
{
    SelectionSort s;
    s.getInput();
    s.sort();
    s.printArray();
}

//time complexity 
//best:omega(n^2)
//avg:theta(n^2)
//worst:theta(n^2)
