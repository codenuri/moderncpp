#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// 인자가 2개인 setter
	/*
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}

	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	*/
	// 인자가 2개이상인 setter의 경우는 위처럼 직접 만들지 말고
	// T&& 를 사용하는 것이 좋습니다.

	template<typename T1, typename T2>
	// T1, T2가 string과 호환되지않은 타입이면 사용하지 않을께 가 필요 
	// => enable_if 기술.. 내일 
	void set(T1&& n, T2&& a)
	{
		name    = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// 생성자도 결국 "setter" 입니다.
	// 아래 코드는 move지원 안됩니다.
//	People(const std::string& n, const std::string& a)
//		: name(n), address(a) {}
	
	template<typename T1, typename T2>
	People(T1&& n, T2&& a)
		: name(std::forward<T1>(n)), address(std::forward<T2>(a))
	{
	}
};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p(name, std::move(addr));
	p.set(name, addr);
	p.set(std::move(name), addr);
	p.set(name, std::move(addr));
	p.set(std::move(name), std::move(addr));

	std::pair<int, double> p(1, 3.4);
}

/*
template <class _Other1, class _Other2,
	enable_if_t<conjunction_v<is_constructible<_Ty1, _Other1>, is_constructible<_Ty2, _Other2>>, int> = 0>
constexpr explicit(!conjunction_v<is_convertible<_Other1, _Ty1>, is_convertible<_Other2, _Ty2>>)
	
	pair(_Other1&& _Val1, _Other2&& _Val2) noexcept    (	is_nothrow_constructible_v<_Ty1, _Other1>&& is_nothrow_constructible_v<_Ty2, _Other2>) // strengthened
	
	: first(_STD forward<_Other1>(_Val1)), second(_STD forward<_Other2>(_Val2)) {
}
*/





