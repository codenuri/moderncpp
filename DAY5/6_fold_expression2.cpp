#include <iostream>

// #1. unary  right fold : (args + ...)	    => E1+(E2+(E3+(E4+E5)))		 
// #2. binary right fold : (args + ... + 0) => E1+(E2+(E3+(E4+(E5+0))))  
// #3. unary  left fold  : (... + args)	    => (((E1+E2)+E3)+E4)+E5		 
// #4. binary left fold  : (0 + ... + args) => ((((0+E1)+E2)+E3)+E4)+E5  


template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// 핵심 : fold expression  도 "pack 이름" 뿐 아니라 
	//		 "pack 을 사용하는 패턴" 도 적용가능
	
	(printv(args), ...);  // 이항연산자가 뭘까요 ?

}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



