#include <iostream>

using namespace std;
int sz=6;


int LargestElementPosition(int a[],int pos,int mx,int mxpos){
   if(pos>sz-1){
     return mxpos;
   }else{
     int current=a[pos];
     if(current>mx){
        mxpos=pos;
        mx=current;
     }
   LargestElementPosition(a,++pos,mx,mxpos);
   }

}

int main()
{
    int arr[]={66,2,4,66,9,199};
    cout<<LargestElementPosition(arr,0,arr[0],0)+1;
    return 0;
}
