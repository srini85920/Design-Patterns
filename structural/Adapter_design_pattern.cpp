#include <bits/stdc++.h>
using namespace std;

//target format
class JSON{
    
    public:
    virtual string json(string msg)=0;
};
class XML{
    public:
    string xml(string msg){
        return "<xml>"+msg+"</xml>";
    }
};
class XMLtoJSON:public JSON{
    XML*xmlProvider;
    
    public:
    XMLtoJSON(XML*x):xmlProvider(x){}
    
    string json(string msg){
        string xmlMsg=xmlProvider->xml(msg);
        string newMsg="{ "+xmlMsg+" }";
        return newMsg;
    }
    
};

int main()
{
    
   XML*x=new XML();
   JSON*file=new XMLtoJSON(x);
   cout<<file->json("what is the msg")<<endl;
}
