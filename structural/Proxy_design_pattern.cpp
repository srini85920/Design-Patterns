#include <bits/stdc++.h>
using namespace std;
class IImage{
    public:
    virtual void display()=0;
};
class RealImage:public IImage{
    string file;
    public:
    RealImage(string filename):file(filename){
        cout<<"loading  file "<<file<<endl;
    }
    void display(){
        cout<<"Displaying image "<<file<<endl;
    }
};
class Proxy:public IImage{
    string file;
    RealImage*rm;
    public:
    Proxy(string filename):file(filename),rm(NULL){
        
    }
    void display(){
        if(rm==NULL)rm=new RealImage(file);
        rm->display();
    }
};

int main()
{
   IImage*img=new Proxy("newPhoto.jpg");
   cout<<"IMage is loading"<<endl;
   img->display();
   
   img->display();
}
