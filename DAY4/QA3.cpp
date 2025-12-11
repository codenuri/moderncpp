class Point
{
public:
	// 변환 연산자함수 : 객체가 다른 타입으로 변환되려고 할때 호출.
	// 특징 : 함수 이름에 반환 타입 포함. 별도의 반환 타입 표기 안함.
	operator int()
	{
		return 10;
	}
};

int main()
{
	Point pt;

	int n = pt; // Point => int 변환이 필요 하다.
				// "pt.operator int()" 라는 약속된 함수 호출
}