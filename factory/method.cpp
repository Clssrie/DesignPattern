#include <iostream>

/*
 * 所谓工厂方法模式，是指定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method工厂方法模式使一个类的实例化延迟到其子类。
 */

class SingCore{
	public:
		virtual ~SingCore(){

		}
		virtual void Show() = 0;
};

class SingCoreA : public SingCore{
	public:
		virtual ~SingCoreA(){

		}
		void Show(){
			std::cout << "SingCore A..." << '\n';
		}
};

class SingCoreB : public SingCore{
	public:
		virtual ~SingCoreB(){

		}
		void Show(){
			std::cout << "SingCore B..." << '\n';
		}
};

class Factory{
	public:
		virtual ~Factory(){

		}

		virtual SingCore * CreateSingCore() = 0;
};

class FactoryA : public Factory{
	public:
		virtual ~FactoryA(){

		}

		SingCoreA* CreateSingCore(){
			return new SingCoreA();
		}
};

class FactoryB : public Factory{
	public:
		virtual ~FactoryB(){

		}

		SingCoreB* CreateSingCore(){
			return new SingCoreB();
		}
};

int main(){
	Factory *factoryA = new FactoryA();
	factoryA->CreateSingCore()->Show();

	Factory *factoryB = new FactoryB();
	factoryB->CreateSingCore()->Show();

	return 0;
}
