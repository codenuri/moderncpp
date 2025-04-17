#include <string>
#include <optional>
class Holder
{
public:
	std::string data = "hello";

//	std::string& get_data() { return data; } // A

	std::string&  get_data() &  { return data; }				// B
	std::string&& get_data() && { return std::move(data); } // C
};

int main()
{
	Holder h = Holder{}; // 임시객체이므로 move, 최적화하면 호출 제거됨

	std::string s = Holder{}.data; // 임시객체의 이름있는 멤버데이타도
									// rvalue 이므로 move

	std::string s = Holder{}.get_data();	// A만 있다면 반환값이 참조! lvalue
											// move 가 아닌 copy
								// => B,C 로 해결


	std::optional<int> opt(10);

//	int n = *opt;  // 이 원리가
//	int n = opt.operator*(); // 이 코드인데
							// 이 함수가 위처럼 되어 있습니다.

}