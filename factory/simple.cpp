#include <iostream>
/*
 * 工厂模式属于创建型模式，大致可以分为三类，简单工厂模式，工厂方法模式，抽象工厂模式。简单工厂模式，它的主要特点是需要在工厂类中做判断，从而创造相应的产品。当增加新的产品时，就需要修改工厂类。
 */

typedef enum ClassType{
	SINGCORE_A,
	SINGCORE_B,
}ClassType;

class SingCore{
	public:
		virtual ~SingCore(){}
		virtual void Show()=0;
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

		SingCore * CreateSingCore(ClassType classType){
			switch(classType){
				case SINGCORE_A:
					{
						return new SingCoreA();
					}
				case SINGCORE_B:
					{
						return new SingCoreB();
					}
			}
		}
};

int main(){
	Factory *factory = new Factory();
	factory->CreateSingCore(SINGCORE_A)->Show();
	factory->CreateSingCore(SINGCORE_B)->Show();

	delete factory;
}

/*
 *这样的设计也有缺点，就是要增加新的核类型时，就需要修改工厂类。这就违反了开放封闭原则：软件实体（类、模板、函数）可以扩展，但是不可修改。
 */
