#include <string>
#include <iostream>

// 임시객체의 어려움을 보여주는 예제

// Max 를 만들어 봅시다.
// 1. 인자는 "복사본"을 제거하기 위해 const std::string& 로!
// 2. 리턴용 임시객체도 제거하기 위해 const std::string& 
const std::string& Max(const std::string& a, const std::string& b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";

//	std::string s3 = Max(s1, s2); 
					// 리턴으로 돌아온것은 복사본이 아닌 s2 인데
					// 그것을 s3에 복사
					// std::string s3 = s2 의 의미

	const std::string& ret = Max(s1, s2);
					// ret 는 결국 s2 의 별명!

	// 질문, 아래 코드 안전할까요 ?
	const std::string& ret2 = Max(std::string{ "A" }, std::string{ "B" });

	// ret2 사용해도 될까요?
}

// cppreference.com 에서 std::max 검색