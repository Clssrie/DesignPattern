#include <iostream>
#include <string>

/*
 * 适配器模式在以下场合最适用:
 * 使用一个已经存在的类，如果它的借口和你实际要求的不一致，可以考虑使用适配器模式：
 * 要在调用者和功能提供者双发都不太容易修改的时候在使用适配器模式，而不是一有不同就使用它
 */
//class IUserInfo{
//	public:
//		virtual ~IUserInfo(){
//
//		}
//
//		virtual std::string getuserName() = 0; 
//		virtual std::string getHomeAddress() = 0;
//		virtual std::string getMobileNumber() = 0;
//		virtual std::string getOfficeTelNumber() = 0;
//		virtual std::string getJobPosition() = 0;
//		virtual std::string getHomeTelNumber() = 0;
//};
//
//class UserInfo : public IUserInfo{
//	public:
//		virtual ~UserInfo(){
//
//		}
//		std::string getHomeAddress(){
//			std::string address = "这里是员工的家庭住址..";
//			std::cout << "这里是员工的家庭住址..." << '\n';
//			return address;
//		}
//
//		std::string getHomeTelNumber(){
//			std::string telnumber = "员工的家庭电话是。。";
//			std::cout << telnumber << std::endl;
//			return telnumber;
//		}
//
//		std::string getJobPosition(){
//			std::string position = "这个人的职位是BOSS...";
//			std::cout << position << '\n';
//			return position;
//		}
//
//		std::string getMobileNumber(){
//			std::string number = "这个人的手机号是000.。。";
//			std::cout << number << '\n';
//			return number;
//		}
//
//		std::string getOfficeTelNumber(){
//			std::string officenumber = "办公室电话是000.。。";
//			std::cout << officenumber << '\n';
//			return officenumber;
//		}
//
//		std::string getOfficeTelNumber(){
//			std::string name= "姓名叫做.。。";
//			std::cout << name << '\n';
//			return name;
//		}
//};
//
//类适配器
class Target{
	public:
		virtual void Request(){
			std::cout << "Target::Request" <<'\n'; 
		}
};

class Adaptee{
	public:
		void SpecificRequest(){
			std::cout << "Adaptee::SpecoficRequest" << '\n';
		}
};

class Adapter : public Target, Adaptee{
	public:
		void Request(){
			Adaptee::SpecificRequest();
		}
};

//对象适配器
class OOTarget{
	public:
		OOTarget(){

		}
		virtual ~OOTarget(){

		}
		virtual void Request(){
			std::cout << "Target::Request" << std::endl;
		}
};

class OOAdaptee{
	public:
		void SpecificRequest(){
			std::cout << "Adaptee::SpecificRequest" << '\n';
		}
};

class OOAdapter : public OOTarget{
	public:
		OOAdater():m_Adaptee(new Adaptee){

		}

		~Adapter(){
			if (m_Adaptee != NULL){
				delete m_Adaptee;
				m_Adaptee = NULL;
			}
		}

		void Request(){
			m_Adaptee->SpecificRequest();
		}

	private:
		Adaptee *m_Adaptee;

};

int main(){
	Target *targetObj = new Adapter();
	targetObj->Request();

	delete targetObj;
	targetObj = NULL;

	return 0;
}
