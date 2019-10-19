#include<bits/stdc++.h>
using namespace std;

int partition(int* arr,int low,int high){
    int i=low-1,temp;
    int pivot = arr[high];
    for(int j=low;j<high;j++){
        if (arr[j] <= pivot){
            i = i+1;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j] = temp;} }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high] = temp;
    return (i+1); }

void quickSort(int* arr,int low,int high) {
    if (low < high){
        int pi = partition(arr,low,high);
        quickSort(arr, low, pi-1) ;
        quickSort(arr, pi+1, high); }}

int main(int argc, char **argv)
{
    int n,arr[10],sarr[10],k,small=-99,start,end,t,z,y;
    cout<<"\n Enter array size: ";
    cin>>n;
    cout<<"\n Enter the array elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\nEnter the no. of test cases: ";
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"\n Enter the start and end indices: ";
        cin>>start>>end;
        cout<<"Enter the value of k: ";
        cin>>k;
        int arr2[end-start+1];
        for(z=start-1,y=0;z<=end-1;z++,y++)
            arr2[y]=arr[z];
        quickSort(arr2,0,y);
        cout<<"\nThe kth smallest element is "<<arr2[k-1];
    }
    return 0;
}

