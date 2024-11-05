int main()
{
	int x[3] = { 1,2,3 };

	// auto 와 decltype 의 차이점 #1

	decltype(x[0]) d = x[0];	// int& d = x[0]
	
	auto a = x[0];				// int a = x[0] 


	// 타입 추론과 배열이름
	
	decltype(x) d1;
	
	auto a1 = x;
	
	auto& a2 = x;

	
}

