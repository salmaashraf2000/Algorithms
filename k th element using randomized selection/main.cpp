#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int partition(int a[],int l,int r){
    int n=r-l+1;
    srand(time(NULL));
    int rnd= rand()%n;
    swap(a[rnd+l],a[l]);
    int j=l+1,pivot=a[l];
    for(int i=l+1;i<=r;i++){
        if(a[i]<pivot){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[l],a[j-1]);

    return j-1;
}


int kthelement(int a[],int l,int r,int elementno){
     if(elementno>0 && elementno<=r-l+1){
        int position=partition(a,l,r);
        if(position-l==elementno-1){
            return a[position];
        }
         if(position-l>elementno-1){
            return kthelement(a,l,position-1,elementno);
        }
            return kthelement(a,position+1,r,elementno-position+l-1);

     }
     return -1;
}


int main()
{
    int a[]={48,1,6,52,4,9},sz=6,elementno=1;
    cout<<"k'th element is "<<kthelement(a,0,sz-1,elementno);
    return 0;
}
