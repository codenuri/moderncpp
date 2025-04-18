// 7_가변인자템플릿1 - 225 page



// 가변인자 클래스 템플릿
template<typename ... Types> class tuple 
{
};

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, double> t2;	// Types : int, double
}