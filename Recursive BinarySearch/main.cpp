#include <iostream>

using namespace std;

int BinarySearch(int a[],int l,int h,int number){
   if(l<=h){
      int mid=(l+h)/2;
      if(a[mid]==number){
        return 1;
      }
      if(a[mid]>number){
        return BinarySearch(a,l,mid-1,number);
      }else{
        return BinarySearch(a,mid+1,h,number);
      }
   }
   return 0;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10},sz=10,number=0;
    if(BinarySearch(a,0,sz-1,number)){
        cout<<"number found\n";
    }else{
        cout<<"number not found\n";
    }
    return 0;
}
