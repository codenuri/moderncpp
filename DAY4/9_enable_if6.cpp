#include <iostream>
#include <string>
#include <vector>

class People
{
private:
	std::string name;
	int age;

public:
	// 방법 #1. 2개의 함수 사용
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n) { name = std::move(n); }


	// 방법 #2. T&& 사용.
	template<typename T>
	void set_name(T&& n)
	{
		name = std::forward<T>(n);	
	}

};

int main()
{
	People p;

	p.set_name(3.4);				
				// name = 3.4(double) 의 코드에서 에러
}








