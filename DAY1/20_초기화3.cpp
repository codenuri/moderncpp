int main()
{
	// C++98 시절 초기화는 위험했습니다.
	int  n1 = 3.4;	// 에러 아니지만, 데이타 손실 발생
					// C#, java, swift 등의 대부분의 언어는 에러
					// C/C++은 되지만, 사용하지는 마세요
 	char c1 = 500;  // 오버플로우!!

	// prevent narrow - 56 page 중간부분
	int n2{ 3.4 };		// error
	char c2{ 500 };		// error

}
