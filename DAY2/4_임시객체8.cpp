#include <string>
#include <iostream>

// String class
// => std::string 모든 기능을 물려 받고
// => std::string 생성자도 물려 받는데.. 
// => 소멸자만 추가해서 "객체 파괴시 로깅"
struct String : public std::string
{
	using std::string::basic_string;

	~String()
	{
		std::cout << "~String() [\"" << data() << " \"]\n";
	}
};

const String& f1(const String& s) { return s; }

const String& f2()
{
	String s = "abc";
	return s;
}
String f3()
{
	String s = "abc";
	return s;
}

int main()
{
//	const String& s = String("abc");
//	const String& s = f1(String("abc"));
//	const String& s = f2();

//	for (auto e : String("abc")) // 안전
	for (auto e : f3() ) // 안전
	{
		std::cout << e << std::endl;
	}
	std::cout << "-----------------\n";
}





// git 에서   임시객체8.cpp 받아보세요