#include <iostream> 

/*
 *
 * 特点：
 * 1、根据不同的情况创建不同的对象。
 * 2、每个对象的方法名相同，但实现不同。
 * */
class IStrategy{
	public:
	virtual	void operate() = 0;
};

class BackDoor : public IStrategy{
	public:
		void operate(){
			std::cout << "找乔国老帮忙，让吴国太给孙权施加压力\n";
		}
};

class GivenGreenLight : public IStrategy{
	public:
		void operate(){
			std::cout << "求吴国太来绿灯，放行\n";
		}
};

class BlockEnemy : public IStrategy{
	public:
		void operate(){
			std::cout << "孙夫人断后，挡住追兵\n";
		}
};

class Context{
	public:
		Context(IStrategy *st){
			strategy = st;
		}

		void operate(){
			strategy->operate();
		}
	private:
		IStrategy* strategy;
};

int main(){
	Context *context;
	context =  new Context(new BackDoor());
	context->operate();

	context = new Context(new GivenGreenLight()); 
	context->operate();

	context = new Context(new BlockEnemy()); 
	context->operate();
}


