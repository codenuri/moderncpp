// 149
int main()
{
	int v1 = 0, v2 = 0;

	// 캡쳐의 다양한 모양

	auto f1 = [v1, &v2](int a) {  };  // v1은 값 캡쳐, v2는 참조 캡쳐
	auto f2 = [&v1, v2](int a) {  };

	auto f3 = [=](int a) {  };	// main 의 모든 지역변수를 값 캡쳐
	auto f4 = [&](int a) {  };  // main 의 모든 지역변수를 참조 캡쳐

	auto f5 = [=, &v2](int a) {  }; // 모든 지역변수를 값, 단, v2만 참조
	auto f6 = [&, v2](int a)  {  };
	auto f7 = [&, &v2](int a) {  }; // error. mode가 다른 경우만 표기

	
	// int x = v1; 처럼 v1의 이름을 x로 변경해서 사용(값 캡쳐)
	// int& y = v2 처럼 해서 y 이름으로 사용
	auto f8 = [x = v1, &y = v2](int a) { x, y };
}




