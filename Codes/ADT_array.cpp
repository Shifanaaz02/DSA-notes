#include<iostream>
using namespace std;

class myArray
{
        
    public:
    int total_size;         //size of array
    int used_size;          //this no. of elements to be used
    int *ptr;               //points first element

};

//Function which points to usize and tsize of class

void createArray(myArray * a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).total_size = uSize;
    // (*a).ptr = new int[tSize * sizeof(int)];
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr =NULL;
    a->ptr = new int[tSize];      //memory of ptr is dynamically allocated with tsize as size
}

//Display arrays

void show(myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        cout<<(a->ptr)[i]<<endl;
    }
}

//Takes input to element of arrays

void setVal(myArray *a){
    int n;
    for(int i=0; i < a->used_size; i++)
    {
        cout<<"Enter element "<<i<<": ";
        cin>>n;
        (a->ptr)[i] = n;
    }
}

int main(){
    myArray marks;                  //object of class myArray
    createArray(&marks, 10, 3);
    cout<<sizeof(marks);            //2 integers are also added here of public
    cout<<"\nWe are running setVal now: \n";
    setVal(&marks);                 //address
    cout<<"\nWe are running show now: \n";
    show(&marks);
    cout<<"\nWe are running show now: \n";
    insert(&marks, 34, 1);
    cout<<"\nWe are running show now: \n";
    show(&marks);
    return 0;
}