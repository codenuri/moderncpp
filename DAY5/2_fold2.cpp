#include <iostream>

// #1. unary  right fold : (args + ...)	    => E1+(E2+(E3+(E4+E5)))		 
// #2. binary right fold : (args + ... + 0) => E1+(E2+(E3+(E4+(E5+0))))  
// #3. unary  left fold  : (... + args)	    => (((E1+E2)+E3)+E4)+E5		 
// #4. binary left fold  : (0 + ... + args) => ((((0+E1)+E2)+E3)+E4)+E5  


// 핵심 
// 1. pack 의 이름 뿐 아니라 pack 을 사용하는 표현식 자체를 사용 가능

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// #1
//	( printv(args) , ... );
	// args       op ...		=> unary right fold
	// printv(1), (printv(2), (printv(3), ( ... )))))

	// #2
	// (std::cout << ... << args);
	//초기값    op ... op pack	=> binary left fold
	// (((std::cout<< e1) << e2 ) << e3

	// #3
	((std::cout << args << " ") , ...);
	// pack 을 사용하는 패턴     op ...
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



