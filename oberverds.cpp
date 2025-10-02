#include<bits/stdc++.h>
using namespace std;

class ISubscribe{
public:
virtual void update()=0;
virtual ~ISubscribe(){};
};

class IChannel{
public:
virtual void subscribe(ISubscribe *s)=0;
virtual void unsubscribe(ISubscribe *s)=0;
virtual void notify()=0;
virtual ~IChannel(){};
};

class Channel:public IChannel{
    string name;
    vector<ISubscribe*>subscribers;
    string latestVideo;
    public:
    Channel(string name){
        this->name=name;
    }
    void subscribe(ISubscribe*s){
        if(find(subscribers.begin(),subscribers.end(),s)==subscribers.end()){
            subscribers.push_back(s);
            cout<<"Succesfully subscribed"<<endl;
        }
        else{
            cout<<"Already a Subscriber"<<endl;
        }
    }
    void unsubscribe(ISubscribe*s){
        if(find(subscribers.begin(),subscribers.end(),s)!=subscribers.end()){
            auto it=find(subscribers.begin(),subscribers.end(),s);
            subscribers.erase(it);
            cout<<"Succesfully unsubscribed"<<endl;
        }
        else{
            cout<<"Already an unSubscriber"<<endl;
        }
    }
    void notify(){
        for(auto i:subscribers){
            i->update();
        }
    }
    void uploadVideo(string  title){
        this->latestVideo=title;
        this->notify();
    }
    string latestvid(){
        return this->latestVideo;
    }
    string channelname(){
        return this->name;
    }

};

class Subscriber: public ISubscribe{
    string name;
    Channel* ch;
public:
Subscriber(string name,Channel*ch){
    this->name=name;
    this->ch=ch;
}

void update(){
    string s=ch->latestvid();
    string s2=ch->channelname();
    cout<<"hello "<<this->name<<", "<< s<<" has been uploaded by "<<s2<<endl;
}
};
int main(){

    Channel *newc=new Channel("9XM");
Subscriber *s1=new Subscriber("simarjeet",newc);
Subscriber *s2=new Subscriber("amarjeet",newc);

 newc->subscribe(s1);
 newc->subscribe(s2);
 newc->uploadVideo("chakkwein suit");
 newc->unsubscribe(s2);
 newc->uploadVideo("Parada- Jass Manak");
return 0;
}