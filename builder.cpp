#include <iostream>
#include <vector>
#include <map>
#include <string>

/*
 * 建造者模式和工厂模式非常相似。
 * 建造者模式最主要功能是基本方法的调用顺序安排，也就是这些基本方法已经实现了；而工厂方法则重点是创建，你要什么对象我创建一个对象出来，组装顺序则不关心。
 */

class CarModel{
	public:
		CarModel(){

		}
		virtual ~CarModel(){

		}
		void run(){
			int size = sequence.size();
			for(int i = 0; i < size; i++){
				std::string actionName = sequence[i];
				if (actionName == "start"){
						start();
				}else if(actionName == "stop"){
						stop();
				}else if(actionName == "alarm"){
						alarm();
				}else if(actionName == "engine boom"){
						engineBoom();
				}
			}
		}

		void setSequence(std::vector<std::string> seq){
			sequence = seq;
		}
	protected:
		virtual void start() = 0;
		virtual void stop() = 0;
		virtual void alarm() = 0;
		virtual void engineBoom() = 0;

	private:
		std::vector<std::string> sequence;
};

class BenzModel : public CarModel{
	protected:
		void alarm(){
			std::cout << "奔驰车的喇叭声音是这个样子的。。。" << std::endl;
		}
		void engineBoom(){
			std::cout << "奔驰车的引擎声音是这个样子的。。。" << std::endl;
		}
		void start(){
			std::cout << "奔驰车跑起来是这个样子的。。。" << std::endl;
		}
		void stop(){
			std::cout << "奔驰车的应该这样停车。。。" << std::endl;
		}
};

class BMWzModel : public CarModel{
	protected:
		void alarm(){
			std::cout << "宝宝车的喇叭声音是这个样子的。。。" << std::endl;
		}
		void engineBoom(){
			std::cout << "宝宝车的引擎声音是这个样子的。。。" << std::endl;
		}
		void start(){
			std::cout << "宝宝车跑起来是这个样子的。。。" << std::endl;
		}
		void stop(){
			std::cout << "宝宝车的应该这样停车。。。" << std::endl;
		}
};

class CarBuilder{
	public:
		void  setSequence(std::vector<std::string> seq) = 0;
		CarModel *getCarModel() = 0;
};

class BenzBuilder: public CarBuilder{
	public:
		CarModel *getCarModel(){
			return benz;
		}
		void  setSequence(std::vector<std::string> seq){
			benz.setSequence(seq);
		}
	private:
		BenzModel* benz = new BenzModel();
};

class BMWBuilder: public CarBuilder{
	public:
		CarModel *getCarModel(){
			return benz;
		}
		void  setSequence(std::vector<std::string> seq){
			benz.setSequence(seq);
		}
	private:
		BMWModel* benz = new BMWModel();
};

int main(){
	BenzModel* benz = new BenzModel();
	std::vector<std::string> sequence;
	sequence.push_back("engine boom");
	sequence.push_back("start");
	sequence.push_back("stop");
	benz->setSequence(sequence);
	benz->run();


}

//switch在C++里的定义
//基于整数表达式的纸允许在代码的多个部分的选择
//switch中的表达式必须是整数、字符或枚举纸
