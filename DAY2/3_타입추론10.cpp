
// auto 와 decltype 추론 차이

int main()
{
	int x[3] = { 1,2,3 };

	auto a = x[0];		// int
	decltype(x[0]) d; 	// int&

	// decltype : id 외에 다른 연산자가 있다면
	// => lvalue 인지 rvalue 인지까지 고려해서 타입결정
}

