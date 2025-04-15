#include <vector>
#include <string>
#include <memory>
// call by value 보다는 const & 가 좋지만
// => explicit 설명을 위한 예제!!
void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello");	// 되야 합니다. 현재 잘됩니다.
					// std::string s = "hello" 가 된다는 것
	// 따라서 아래 2줄 모두 가능합니다.
	std::string s1("hello");
	std::string s2 = "hello";	// std::string(const char*) 생성자는
								// explicit 가 아니라는 의미


	goo(10);	// 안되야 합니다. 현재 안됩니다.
				// std::vector<int> v = 10 이 안된다는 것
		
	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error.
								// std::vector(int) 생성자는
								// "explicit" 라는 의미!
	



	


}





