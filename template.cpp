#include <iostream>

/*
 * 定义一个操作中的算法的骨架。而将一些步骤延迟到子类中，模板方法使得子类可以不改变一个算法的结构即可重新定义该算法的某些特定步骤。
 * 模板方法模式是通过把不变行为搬移到基类，去除子类中的重复代码来体现它的优势。
 */

class AbstractClass{
	public:
		~AbstractClass(){

		}
		//具体的模板方法，给出了逻辑的骨架
		void templateMethod(){
			operation1();
			operation2();
		}
		//一些抽象行为，放在子类中去实现
		virtual void operation1() = 0;
		virtual void operation2() = 0;
	protected:
		AbstractClass(){

		}
};

class ConcreteClassA : public AbstractClass{
	public:
		ConcreteClassA(){

		}
		~ConcreteClassA(){

		}
		virtual void operation1(){
			std::cout << "ConcreteClassA::operation1" << std::endl;
		}
		
		virtual void operation2(){
			std::cout << "ConcreteClassA::operation2" << std::endl;
		}
};

class ConcreteClassB : public AbstractClass{
	public:
		ConcreteClassB(){

		}
		~ConcreteClassB(){

		}
		virtual void operation1(){
			std::cout << "ConcreteClassB::operation1" << std::endl;
		}
		
		virtual void operation2(){
			std::cout << "ConcreteClassB::operation2" << std::endl;
		}
};

int main(){
	AbstractClass * pAbstract = new ConcreteClassA();
	pAbstract->templateMethod();

	pAbstract = new ConcreteClassB();
	pAbstract->templateMethod();
	return 0;
}

/*
 * 在重写了父类部分方法后，在调用从父类继承的方法，产生不同的结构，这是不是
 * 也可以理解为父类调用了子类的方法呢。修改了子类，影响了父类的结构，模板
 * 方法模式就是这样的效果。
 */
