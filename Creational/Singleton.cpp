#include <bits/stdc++.h>
using namespace std;

class Logger{
    
    static int cnt;
    //constuctor
    Logger(){
        cnt++;
    }
 
    static Logger* instance;
    //deleting the copy constructor and assignment operator
    Logger(const Logger&)=delete;
    //l1 is there ,Logger *l1=l2;
    Logger &operator=(const Logger &)=delete;
    //Logger *l2=new Logger(*l1)
  public: 
    static Logger* getInstance();
    
    static int getCnt();
    
    void logg(string msg);
};

int Logger::cnt=0;

Logger* Logger::instance=NULL;

Logger*Logger::getInstance(){
    if(instance==NULL) instance=new Logger();
    return instance;
}

int Logger::getCnt(){
    return cnt;
}

void Logger::logg(string msg){
    cout<<"msg is "<<msg<<endl;
}
int main()
{
    Logger*l1=Logger::getInstance();
    Logger*l2=Logger::getInstance();
    
    l1->logg("Hello world");
    l2->logg("this is me ");
    
    cout<<"Counter is "<<Logger::getCnt()<<endl;
    cout<<(l1==l2)<<endl;
    
}

//output of the file is

Hello world
this is me 
Counter is 1
1
