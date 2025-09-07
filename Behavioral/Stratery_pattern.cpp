
class IPayment{
    public:
    virtual void pay(int amt)=0;
};

class UPI:public IPayment{
    public:
    void pay(int amt){
        cout<<"Amount "<<amt<<" is been debited from UPI"<<endl;
    }
};

class CreditCard:public IPayment{
    public:
    void pay(int amt){
        cout<<"Amount "<<amt<<" is been debited from Net Banking"<<endl;
    }
};

class PaymentService{
    IPayment*method;
    public:
    PaymentService(IPayment*m){
        method=m;
    }  
    void setMethod(IPayment*m){
        method=m;
    }
    void debit(int amt){
        method->pay(amt);
    }
};

int main()
{
    IPayment*method1=new CreditCard();
    IPayment*method2=new UPI();
    PaymentService*p1=new PaymentService(method1);
    p1->debit(500);
    
    PaymentService*p2=new PaymentService(method2);
    p2->debit(200);
    p2->debit(400);
    
    p1->debit(300);
    p2->setMethod(method1);
    cout<<"P2s method is changed to p1"<<endl;
    p2->debit(1000);
    
}

