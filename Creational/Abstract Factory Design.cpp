#include<iostream>
using namespace std;
class Pizza{
	public:
	virtual void make()=0;
};
class Drink{
	public:
	virtual void pour()=0;
};
class DominosPizza:public Pizza{
	public:
	void make(){
		cout<<"This is Dominos Pizza"<<endl;
	}
};
class PizzaHutPizza:public Pizza{
	public:
	void make(){
		cout<<"This is PizzaHut Pizza"<<endl;
	}
};
class DominosDrink:public Drink{
	public:
	void pour(){
		cout<<"this is Dominos Spl drink"<<endl;
	}
};
class PizzaHutDrink:public Drink{
	public:
	void pour(){
		cout<<"this is PizzaHut spl Drink"<<endl;
	}
};

class BrandFactory{
	public:
	virtual Pizza*createPizza()=0;
	virtual Drink*createDrink()=0;
};

class DominosFactory:public BrandFactory{
	public:
	Pizza* createPizza() { return new DominosPizza(); }
    Drink* createDrink() { return new DominosDrink(); }
};
class PizzaHutFactory:public BrandFactory{
	public:
	Pizza* createPizza()  { return new PizzaHutPizza(); }
    Drink* createDrink() { return new PizzaHutDrink(); }
};
int main(){
	BrandFactory*brand=new DominosFactory;
	Pizza*pizza=brand->createPizza();
	Drink*drink=brand->createDrink();
	pizza->make();
	drink->pour();
	
}
