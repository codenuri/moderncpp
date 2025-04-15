// prevent narrow - 56 page 중간부분

int main()
{
	// C++98 스타일 초기화
	int  n1 = 3.4;	// 데이타 손실있지만 ok.
					// C/C++ 을 제외한 대부분의 언어는 에러!

	char c1 = 500;	// 오버 플로우 발생하지만 ok

	// C++11 의 중괄호 초기화는 데이타손실이나 오버플로우 발생시
	// 컴파일 에러
	int n2{ 3.4 };  // error
	char c2{ 500 }; // error

	int n3 = { 3.4 }; // error


	// 안전성 : {} 초기화가 좋습니다.
	// 가독성 : 초보자등을 고려하면 C++98 스타일이 보기 좋습니다.

}