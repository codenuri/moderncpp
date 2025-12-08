
class Cursor
{
private:
	Cursor() {}

public:
	static Cursor& instance()
	{
		static Cursor instance;
		return instance;
	}
	// 싱글톤 패턴을 사용하려면 "복사 생성과 대입 연산"을 막아야 합니다.
	// 컴파일러에게 자동생성할수 없도록
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete; // 복사 생성자를 삭제시
												// 대입도 삭제하는 것이 관련
};

int main()
{
	// GUI 환경에서 커서 는 오직 한개만 존재 합니다.
	//Cursor c1;
	//Cursor c2; // error. 생성자가 private

	Cursor& c1 = Cursor::instance();
	Cursor& c2 = Cursor::instance();

	Cursor c3(c1); // 이렇게 만드는 것도 막아야 합니다.
}