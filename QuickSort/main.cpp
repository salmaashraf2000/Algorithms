#include <iostream>
#include <ctime>
using namespace std;

int cnt=0;

///pivot is fist element in given array if array already sorted O(n power 2)
/*int partition(int a[],int low,int high){
    //cnt+=(high-low);
    int pivot=a[low];
    int i=low+1,j;
    for(j=low+1;j<=high;j++){
        if(a[j]<pivot){
            int temp;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    int temp=a[low];
    a[low]=a[i-1];
    a[i-1]=temp;
    return i-1;
}*/

///pivot determined using random O(nlog n)
/*int partition(int a[],int low,int high){
    srand(time(NULL));
    int random= low+rand()%(high-low);
    int t=a[random];
    a[random]=a[low];
    a[low]=t;
    int pivot=a[low];
    int i=low+1,j;
    for(j=low+1;j<=high;j++){
        if(a[j]<pivot){
            int temp;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    int temp=a[low];
    a[low]=a[i-1];
    a[i-1]=temp;
    return i-1;
}*/


///pivot is last element in given array if array already sorted O(n power 2)
int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low,j;
    for(j=low;j<high;j++){
        if(a[j]<pivot){
            int temp;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    int temp=a[high];
    a[high]=a[i];
    a[i]=temp;
    return i;
}

void Quicksort(int a[],int low,int high){
    if(low<high){
        int pivot=partition(a,low,high);
        Quicksort(a,low,pivot-1);
        Quicksort(a,pivot+1,high);

    }
}

int main()
{
    //int a[10009];
    int a[]={10,9,7,5,8,1};
    Quicksort(a,0,5);
    for(int i=0;i<6;i++){
        //cin>>a[i];
        cout<<a[i]<<" ";
    }
    //Quicksort(a,0,10000);
    //cout<<cnt<<endl;
    return 0;
}

