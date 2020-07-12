#include <iostream>

using namespace std;

int Max=0;

int IndexOfMax(int a[],int l,int r){
   if(l==r){
    return l;
   }else{
     int m=(l+r)/2;
      int ind1=IndexOfMax(a,l,m);
      int ind2=IndexOfMax(a,m+1,r);
      if(a[ind1]>a[ind2]){
        return ind1;
      }else{
        return ind2;
      }
   }
}

int main()
{
    int a[]={9,1,6,0,4,89},sz=6;
    cout<<IndexOfMax(a,0,sz-1);
    return 0;
}


///b- outout index of largest element from left
///c- T(n)=2(T(n/2))+1 O(n)
///d- same but brute force avoids overhead recursive calls
