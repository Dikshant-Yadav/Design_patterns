#include <bits/stdc++.h>
using namespace std;
class singleton {
private:

// we declared the only object that will exist in singleton class
static singleton*onlyobject;


//constructor called only inside the class 

singleton(){
    cout<<"singleton constructor called"<<endl;
}

 // Delete copy constructor and assignment operator to prevent copying
    singleton(const singleton&) = delete;
    singleton& operator=(const singleton&) = delete;
public:
// a static int to understand the working of static if you don't know , not related to singleton
static int onlyint;

    // we made a class to make object if doesn't made earlier else return that same object
   static singleton*getsingleton(){
        if(onlyobject==nullptr){
            onlyobject=new singleton();
        }
        return onlyobject;
    }

    // some random fuction for testing 
    void doingsomething(){
        cout<<"singleton is doing something"<<endl;
        cout<<onlyint++<<endl;
    }

};
// we init the only object that will exist in singleton class
singleton*singleton::onlyobject=nullptr;
//init int to 0
int singleton::onlyint=0;


int main() {
    // trying to make 2 different objects
    singleton*object1=singleton::getsingleton();
    singleton*object2=singleton::getsingleton();

//calling functions with 2 objects we made
    object1->doingsomething();
    object2->doingsomething();

    //checking whether the 2 objects are same of different
    cout<<"are these two objects same "<<(object1==object2)<<endl;  //cout value 1 as only one object is there they point same object

    delete object1;  // or delete object2 (both point to same memory)

    return 0;
}
