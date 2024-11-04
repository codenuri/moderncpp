#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	// 아래 코드중 에러를 찾아 보세요.

	hoo("hello"); // ok. 논리적으로 맞습니다.
				  // 그래서 에러 아닙니다.
				  // std::string s = "hello" 가 된다는 의미

	std::string s1("hello");  // ok
	std::string s2 = "hello"; // ok
							// std::string(const char*) 생성자는
							// explicit 가 아니라는 의미.

	goo(10); // 논리적으로 맞지 않습니다.
			 // 그래서 에러!!!
			 // std::vector<int> v = 10 는 에러라는 의미.
		
	std::vector<int> v1(10);   // ok
	std::vector<int> v2 = 10;  // error
							   // std::vector(int) 생성자는
						       // explicit 라는 의미. 






}





