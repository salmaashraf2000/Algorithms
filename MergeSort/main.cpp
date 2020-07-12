#include <iostream>

using namespace std;


void merge(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m,i,j,k;
    int L[n1+2],R[n2+2];
    for(i=0;i<n1;i++){
        L[i]=a[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=a[m+1+j];
    }
    k=l;
    i=0;
    j=0;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            a[k++]=L[i++];
        }else{
          a[k++]=R[j++];
        }
    }
    while(i<n1){
        a[k++]=L[i++];
    }
    while(j<n2){
        a[k++]=R[j++];
    }

}

void mergesort(int a[],int l,int r){
   if(l<r){
    int m=(l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
   }
}

int main()
{
    int a[]={2,8,1,6,3,10,9},sz=7;
    mergesort(a,0,sz-1);
    for(int i=0;i<sz;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
