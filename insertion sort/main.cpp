#include <iostream>

using namespace std;

void insertionsort(int a[],int sz){
    int cmp,j;
    for(int i=1;i<sz;i++){
        cmp=a[i];
        j=i-1;
        while(j>=0 && cmp<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=cmp;
    }
}


/*void insertionsort(int a[],int sz){
    int j;
    for(int i=1;i<sz;i++){
        j=i-1;
        while(j>=0 && a[j+1]<a[j]){
            swap(a[j+1],a[j]);
            j--;
        }
    }
}*/



int main()
{
    int a[]={8,1,6,2,3,11,0,3},sz=8;
    insertionsort(a,8);
    for(int i=0;i<sz;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
