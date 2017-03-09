#include <iostream>

/*
 * 我们能见到的大部分抽象工厂模式都是这样的：它的里面是一堆工厂方法，每个工厂方法返回某种类型的对象。
 * 如果说抽象工厂中的工厂是一个实际的工厂的话，那么工厂方法中的工厂更像现实中工厂的一条生产线。
 */

class SingleCore{
	public:
		virtual void Show() const = 0;
};

class SingleCoreA: public SingleCore{
	public:
		void Show()const{
			std::cout << "SingleCore A" << '\n';
		}
};

class SingleCoreB: public SingleCore{
	public:
		void Show()const{
			std::cout << "SingleCore B" << '\n';
		}
};

class MultiCore{
	public:
		virtual void Show() const = 0;
};

class MultiCoreA : public MultiCore{
	public:
		void Show() const{
			std::cout << "Multi Core A" << '\n';
		}
};

class MultiCoreB : public MultiCore{
	public:
		void Show() const{
			std::cout << "Multi Core B" << '\n';
		}
};

class Factory{
	public:
		virtual SingleCore * CreateSingleCore() = 0;
		virtual MultiCore * CreateMultiCore() = 0;
};

class FactoryA : public Factory{
	public:
	SingleCore* CreateSingleCore(){
		return new SingleCoreA();
	}
	MultiCore* CreateMultiCore(){
		return new MultiCoreA();
	}
};

class FactoryB: public Factory{
	public:
	SingleCore* CreateSingleCore(){
		return new SingleCoreB();
	}
	MultiCore* CreateMultiCore(){
		return new MultiCoreB();
	}
};

int main(){
	FactoryA *factoryA = new FactoryA();
	factoryA->CreateSingleCore()->Show();
	factoryA->CreateMultiCore()->Show();

	FactoryB *factoryB = new FactoryB();
	factoryB->CreateSingleCore()->Show();
	factoryB->CreateMultiCore()->Show();
}
