class ISubscribers{
  public:
  virtual void notify(string msg)=0;
  virtual int getUserID()=0;
};

class Subscribers:public ISubscribers{
    int userID;
  public:
  
  Subscribers(int id){
      userID=id;
  }
  void notify(string msg){
      cout<<"This is notification for User "<<userID<<endl;
  }
  int getUserID(){
      return userID;
  }
};

class Group{
    //i have to notify all the subscribe and i should be able to subscribe and unscbcrible 
    vector<ISubscribers*>grp;
    public:
    void subscribe(ISubscribers*user){
        grp.push_back(user);
    }
    void unsubscrible(ISubscribers*user){
        cout<<"the use has been unscbcribed "<<user->getUserID()<<endl;
        grp.erase(find(grp.begin(),grp.end(),user));
    }
    void Notify(string msg){
        for(auto user:grp){
            user->notify(msg);
        }
    }
};



int main()
{
    ISubscribers*user1=new Subscribers(1);
    ISubscribers*user2=new Subscribers(2);
    ISubscribers*user3=new Subscribers(3);
    
    Group *g=new Group();
    
    g->subscribe(user1);
    g->subscribe(user2);
    g->subscribe(user3);
    
    //i will notify 
    g->Notify("this is where all 3 users are in");
    cout<<endl;
    g->unsubscrible(user2);
    cout<<endl;
    g->Notify("this is where 2 are in");
    
    //i will notify
    
    
}
