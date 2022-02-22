#include<iostream>
using namespace std;

int linear_search(int arr[], int N, int search){
    int i=0;
    for(i = 0; i<N; i++){
        if(arr[i] == search){
            return i;
        }
    }
    
    return -1;
}

//Binary Search method 1 recursion
int binary_search(int arr[], int low, int high, int search){
    int index = 0, mid;
    if(low < high){
        mid = (low + high)/2;
        if(search == arr[mid]){
            index = mid;
            return index;
        }
        else if(arr[mid]>search){
            binary_search(arr, low, mid, search);
        }
        else{
            binary_search(arr, mid+1, high, search);
        }
    }
    else if(low == high){
        if(arr[low] == search){
            return low;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}

//Binary Search method 2 loop
// int binarySearch(int arr[], int size, int element){
//     int low, mid, high;
//     low = 0;
//     high = size-1;
//     // Keep searching until low <= high
//     while(low<=high){
//         mid = (low + high)/2;
//         if(arr[mid] == element){
//             return mid;
//         }
//         if(arr[mid]<element){
//             low = mid+1;
//         }
//         else{
//             high = mid -1;
//         }
//     } 
//     return -1;
    
// }

int main(){
    int arr[100], N, search, result;
    cout<<"\nEnter the length of Array: ";
    cin>>N;

    cout<<"\nEnter the Elements of Array:\n";
    for(int i = 0;i<N;i++){
        cin>>arr[i];
    }
    
    cout<<"\nEnter the element to search in this array: ";
    cin>>search;
    cout<<"\nSearched using linear search";
    result = linear_search(arr, N, search);
    if(result == -1){
        cout<<"\nThe element is not present in array";
    }
    else{
        cout<<"\nThe element is found at index: "<<result<<endl;
    }
    
    // cout<<"\nSearched using binary search 2";
    // result = binary_search(arr, N, search);
    // if(result == -1){
    //     cout<<"\nThe element is not present in array";
    // }
    // else{
    //     cout<<"\nThe element is found at index: "<<result;
    // }
}