int main()    
{
	int n = 0;
	int x[3] = { 1,2,3 };

	// auto 와 decltype 의 차이점 #1

	decltype(x[0]) d = x[0];	// int& d = x[0]
	
	auto a = x[0];				// int a = x[0] 


	// 타입 추론과 배열이름
	// x의 타입 : int[3]

	decltype(x) d1;	// int d1[3]	즉, decltype(배열)의 결과는 배열
	
	auto a1 = x;	// #1. auto 를 x와 동일타입인 int[3] 로 결정했다면
					// => int a1[3] = x; 의 코드 생성인데, error
					// 
					// #2. auto 를 포인터로 결정하면
					// => int* a1 = x;  의 코드 생성인데, 에러 아님. 
					
					// 답은 2번. 배열을 auto 값으로 가리키면 "포인터"로추론
	
	auto& a2 = x;	// auto : int[3]    a2 : auto&,  int(&a2)[3]
					// => int(&a2)[3] = x  의 코드. 에러 아님.
					// 따라서 이 경우 auto 는 int[3]

	// 정리
	auto a3 = x;  // auto : int*		배열이 포인터로 바뀌게되는 현상
				  //					"decay" 라고 합니다.
	auto& a4 = x; // auto : int[3]	
}

