void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main					chronometry						hoo(int&&)
// hoo(10) ================================================> ok
// chronometry(10) =====> int&& arg = 10
//						  arg 는 lvalue 
//						  hoo(arg) ===================> error. arg 는 lvalue
//						rvalue 를 받으면서 lvalue로 변경
//						  hoo(static_cast<int&&>(arg) =======> ok

template<typename F> void chronometry(F f, int&& arg)
{
//	f(arg); // error

	// main ===> chronometry 로 보낼때는 rvalue(10) 였는데.. 
	// "int&& arg = 10" 으로 받으면서 arg 가 lvalue 가 되었다.
	// forwarding 할때는 다시 rvalue 로 변경해서 전달
	f(static_cast<int&&>(arg));
}

int main()
{
	hoo(10); 

	chronometry(hoo, 10); 
	
}





