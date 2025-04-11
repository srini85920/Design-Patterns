#include<bits/stdc++.h>
using namespace std;
class ISubscribers{
	public:
		virtual void notify(string msg)=0;
		
};
class Subscribers:public ISubscribers{
	private:
		int userid;
	public:
		Subscribers(int id){
			userid=id;
		}
		void notify(string msg){
			cout<<"User with userid "<<userid<<" Recieved the msg "<<msg<<endl;
		}
};
class Groups{
	private:
		vector<ISubscribers*>users;
	public:
		void subscribe(ISubscribers*u){
			users.push_back(u);
		}	
		void unsubscribe(){
			if(!users.empty())users.pop_back();
		}
		void notify(string msg){
			for(int i=0;i<users.size();i++){
				users[i]->notify(msg);
			}
		}
};
int main(){
	Groups*grp=new Groups();
	Subscribers*user1=new Subscribers(1);
	Subscribers*user2=new Subscribers(2);
	Subscribers*user3=new Subscribers(3);
	grp->subscribe(user1);
	grp->subscribe(user2);
	grp->notify("hello");
	grp->unsubscribe();
	grp->subscribe(user3);
	grp->notify("hello again");
}
