#include <bits/stdc++.h>
using namespace std;

//factory 
class IDebit{
    public:
    virtual void debit()=0;
};

class UPI:public IDebit{
    public:
    void debit(){
        cout<<"UPI payement"<<endl;
    }
};

class NetBanking:public IDebit{
    public:
    void debit(){
        cout<<"Net Banking payement"<<endl;
    }
};

class CreditCard:public IDebit{
    public:
    void debit(){
        cout<<"Credit card payement"<<endl;
    }
};

class PayLater:public IDebit{
    public:
    void debit(){
        cout<<"Paylater payement"<<endl;
    }
};

class factory{
  public:
  static IDebit*fetchPaymentMethod(string type){
      if(type=="UPI")return new UPI();
      else if(type=="Paylater")return new PayLater();
      else if(type=="CreditCard")return new CreditCard();
      return new NetBanking();
  }
};

int main()
{
    IDebit*p1=factory::fetchPaymentMethod("UPI");
    p1->debit();
    
    IDebit*p2=factory::fetchPaymentMethod("Paylater");
    p2->debit();
    
    IDebit*p3=factory::fetchPaymentMethod("anything");
    p3->debit();
}
