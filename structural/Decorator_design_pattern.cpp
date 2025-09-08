#include <bits/stdc++.h>
using namespace std;
//base 
class ICoffee{
    public:
    virtual string type()=0;
    virtual double price()=0;
    virtual ~ICoffee(){}
};
//concrete class
class SimpleCoffee:public ICoffee{
    public:
    string type(){
        return "Simple Coffee";
    }
    double price(){
        return 20.0;
    }
};

//base Decorator
class Decorator:public ICoffee{
    protected:
    ICoffee*coffee;
    
    public:
    Decorator(ICoffee*c){
        coffee=c;
    }

};


//concrete Decorators
class Milk:public Decorator{
    public:
    Milk(ICoffee*c): Decorator(c){
       
    }
    string type(){
        return coffee->type()+" with Milk";
    }
    double price(){
        return coffee->price()+30.0;
    }
};
class WhipCream:public Decorator{
    public:
    WhipCream(ICoffee*c): Decorator(c){
       
    }
    string type(){
        return coffee->type()+" with WhipCream";
    }
    double price(){
        return coffee->price()+50.0;
    }
};

int main()
{
    ICoffee*c1=new SimpleCoffee();
    cout<<c1->type()<<" and the Price is "<<c1->price()<<endl;
    ICoffee*c2=new WhipCream(new SimpleCoffee());
    cout<<c2->type()<<" and the Price is "<<c2->price()<<endl;
    ICoffee*c3=new Milk(new SimpleCoffee());
    cout<<c3->type()<<" and the Price is "<<c3->price()<<endl;
}
