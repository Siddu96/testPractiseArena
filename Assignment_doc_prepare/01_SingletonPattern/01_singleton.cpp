#include<iostream>

class Singleton
{
private:
	static Singleton* instance;
	Singleton(){}
public:
	static Singleton* getInstance(){
		if(instance == NULL){
			instance = new Singleton();
			std::cout << "Instance is created\n";
		} else {
			std::cout << "New Instance cannot be created\n";
		}
	}
};

Singleton* Singleton::instance = NULL;

int main()
{
	Singleton* obj = Singleton::getInstance();
	Singleton* obj1 = Singleton::getInstance();
	return 0;
}
