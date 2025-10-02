#include<bits/stdc++.h>
using namespace std;
//interface 
class sortingStrategy{
    private:
    public:
   virtual void sort()=0;
};
//concrete classes


//bubble sort
class bubbleSort: public sortingStrategy{
    public:
   void sort() {cout<<"this is bubble sort"<<endl;}
};

// merge sort
class mergeSort: public sortingStrategy{
    public:
  void sort() { cout<<"this is merge sort"<<endl;}
};

//selection sort
class selectionSort: public sortingStrategy{
    public:
    void sort(){
    cout<<"this is selection sort"<<endl;
    }
};
//context 
class coding_operation{
    public:
    sortingStrategy * ss1;
    coding_operation(sortingStrategy * ss1){
        cout<<"i am constructing"<<endl;
this->ss1=ss1;
    }
    void dosort(){
        cout<<"dosort here"<<endl;
        ss1->sort();}
};
int main(){
    coding_operation *ctx=new coding_operation(ss1);
    ctx->dosort();

}