int main()
{
	// C/C++98 초기화의 문제점
	// => 아래 코드가 에러가 아니다
	int  n1 = 3.4;  // C/C++ 을 제외한 대부분의 언어는 에러.. 
	char c1 = 500;  // 오버플로우 발생.. 데이타 손실

	// prevent narrow - 56 page 
	// => {} 초기화는 데이타 손실이 발생하는 표기는 에러
	int n2{ 3.4 };		// error
	char c2{ 500 };		// error

	int n3 = { 3.4 }; // error

}
