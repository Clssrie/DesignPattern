#include <iostream>

class Emperor{
	public:
		static Emperor* getInstance(){
			if(emperor == nullptr){
				emperor = new Emperor();
			}
			return emperor;
		}
		static void emperorInfo(){
			std::cout << "我是皇帝某某\n";
		}
	private:
		Emperor(){

		}
		static Emperor * emperor = nullptr;
};

//线程安全的
class SingletonPattern{
	public:
		static SingletonPattern *getInstance(){
			return single;
		}
	private:
		SingletonPattern(){

		}
		static SingletonPattern * single = new SingletonPattern();
};

int main(){
	Emperor *emperor1 = Emperor->getInstance(); 
	emperor1->emperorInfo();

	Emperor *emperor2 = Emperor->getInstance(); 
	emperor2->emperorInfo();
}
