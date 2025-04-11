#include<iostream>
using namespace std;
class Vehicle{
	public:
	virtual void getVehicle()=0;
		
};
class Car:public Vehicle{
	public:
	void getVehicle(){
		cout<<"The vehicle is Car"<<endl;
	}
};
class Truck:public Vehicle{
	public:
	void getVehicle(){
		cout<<"the Truck has been created"<<endl;
	}
};
class Bike:public Vehicle{
	public:
	void getVehicle(){
		cout<<"The vehicle is Bike"<<endl;
	}
};
class Factory{
	Vehicle*vehicle;
	string type;
	public:
	Factory(string t){
		type=t;
	}
	Vehicle*getSpecific(){
		if(type=="car")vehicle=new Car();
		else if(type=="bike")vehicle=new Bike();
		else vehicle =new Truck();
		return vehicle;
	}
};
int main(){
	//Vehicle*vehicle;
	cout<<"Enter the type of Vehicle :";
	string vehicle_type;
	cin>>vehicle_type;
	Factory f(vehicle_type);
	Vehicle*vehicle=f.getSpecific();
	vehicle->getVehicle();
}
