// Step1. 가변인자 템플릿 사용

template<typename ... Types>
class tuple
{

};

int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}
