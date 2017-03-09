#include <iostream>

/*
 代理人要知道被代理人能做那些事情不能做那些事情，那就是两个人具备同一个借口
 ，代理人虽然不能干活，但是被代理人能干活*
 * */

class KindWomen{
	public:
		virtual void makeEyesWithMan() = 0;
		virtual void happyWithMan() = 0;
};

class PanJinLian: public KindWomen{
	public:
		void happyWithMan(){
			std::cout << "潘金莲在和那么人那个。。。\n";
		}

		void makeEyesWithMan(){
			std::cout << "潘金莲抛媚眼\n";
		}
};

class WangPo : public KindWomen{
	public:
		WangPo(){//默认是潘金莲的代理
			kindWomen = new PanJinLian();
		}

		WangPo(KindWomen * kind){
			kindWomen = kindWomen;
		}

		void happyWithMan(){
			kindWomen->happyWithMan();
		}

		void makeEyesWithMan(){
			kindWomen->makeEyesWithMan();
		}

	private:
		KindWomen *kindWomen;
};

int main(){
	WangPo* wangpo = new WangPo();

	wangpo->makeEyesWithMan();
	wangpo->happyWithMan();
}
