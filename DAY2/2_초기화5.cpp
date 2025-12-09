#include <vector>
#include <string>
#include <memory>

// 인자는 const& 가 좋지만 설명을 위한 코드
void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	// 아래 코드에 대해서 생각해 보세요
	hoo("hello");	// 자연스러운 코드.. 되야 합니다.
					// 지금 됩니다.
	std::string s1("hello");	// ok
	std::string s2 = "hello";	// ok
								// string(const char*) 생성자는 explicit 아님

	goo(10);	// 논리적이지 않습니다. 에러 나와야 합니다.
				// 지금. 에러
	std::vector<int> v1(10);  // ok. 크기가 10인 vector
	std::vector<int> v2 = 10; // error.
								// vector(int) 생성자는 explicit 라는 의미

	// 즉, 어떤 클래스 설계시, 인자가 한개인 생성자를 만들고 있다면
	// => explicit 를 붙일지 말지를 반드시 고려하세요
	// => 위 처럼 함수 인자인 경우로 놓고 생각하면 됩니다.

	// 요즘은 explicit 를 붙이는 것이 더 권장됨.
	// => 편리함 보다는 안전성이 중시
	// => C++ 표준 스마트 포인터의 생성자는 모두 explicit
	std::shared_ptr<int> sp1 = new int; // error
	std::shared_ptr<int> sp2( new int); // ok. 
}





