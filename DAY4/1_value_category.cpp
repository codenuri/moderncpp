#include <string>
#include "cppmaster.h"

// value_category - 109 page

// expression 의 결과로 최종적으로 만들어지는 값이 가지는 2가지 속성
// 1. type
// 2. value category ( lvalue, xvalue, prvalue )

struct Object
{
	std::string name = "kim";
	Object() = default;
	Object(const Object&)     { std::cout << "copy\n"; }
	Object(Object&&) noexcept { std::cout << "move\n"; }
};


int main()
{
	Object obj;	// obj, 이름이 있는 사용자가 만든 객체 - lvalue
	Object{};	// 임시객체, rvalue ( prvalue)
	static_cast<Object&&>(obj); // rvalue( xvalue, eXpire value)

	static_cast<Object>(obj);	// 값 캐스팅하면
								// obj 를 복사한 임시객체가 생성됩니다.
								// "prvalue" 입니다.

	LOG_VALUE_CATEGORY(obj);
	LOG_VALUE_CATEGORY(Object{});
	LOG_VALUE_CATEGORY(static_cast<Object&&>(obj));
	LOG_VALUE_CATEGORY(std::move(obj));
	LOG_VALUE_CATEGORY(static_cast<Object>(obj));
}

// lvalue
// xvalue ( eXpire value)  : casting 등을 통해서 rvalue, ID 가 있다
//							move 되어서 expire 될것이라는 의미.
// prvalue ( pure rvalue ) : 처음부터 rvalue 이었던것, 임시객체, 리터럴(문자열제외)