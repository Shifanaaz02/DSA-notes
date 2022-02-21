#include<iostream>
using namespace std;
//Display
void display(int arr[],int N){
    cout<<"\nEntered Array is: ";
    for(int i = 0;i<N;i++){
        cout<<arr[i]<<" ";
    }
}

//Sequence matter
int sorted_insertion(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1;
    }
    for(int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    
    return 1;
}
//Sequence doesn't matter
int unsorted_insertion(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1;
    }
    arr[size] = arr[index]; 
    arr[index] = element;
    
    return 1;
}

//Sequence matter
void sorted_deletion(int arr[], int size, int index){
    for(int i=index; i < size; i++){
        arr[i] = arr[i+1];
    }
}

//Sequence doesn't matter
void unsorted_deletion(int arr[], int size, int index){
    arr[index] = arr[size-1];
}

int main(){
    int arr[100], N, result, index, element;
    cout<<"\nEnter the length of Array: ";
    cin>>N;
    //Traversing
    cout<<"\nEnter the Elements of Array:\n";
    for(int i = 0;i<N;i++){
        cin>>arr[i];
    }
    display(arr,N);
    cout<<"\nEnter element to be inserted: ";
    cin>>element;
    cout<<"\nEnter index where u want to insert element:";
    cin>>index;
    result = sorted_insertion(arr, N, element, 100, index);
    if(result == -1){
        cout<<"\nNo more space to insert";
    }
    else{
        cout<<"\nInserted Successfully";
        N+=1;
        display(arr,N);
    }
    result = unsorted_insertion(arr, N, element, 100, index);
    if(result == -1){
        cout<<"\nNo more space to insert";
    }
    else{
        cout<<"\nInserted Successfully\n";
        N+=1;
        display(arr,N);
    }
    cout<<"\nEnter the index of element to be deleted: ";
    cin>>index;
    sorted_deletion(arr,N,index);
    N-=1;
    display(arr,N);

    cout<<"\nEnter the index of element to be deleted: ";
    cin>>index;
    unsorted_deletion(arr,N,index);
    N-=1;
    display(arr,N);
    
    
}