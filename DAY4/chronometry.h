// stopwatch.h

#pragma once

#include <iostream>
#include <chrono>	// C++ǥ�� �ð� ���̺귯��

class stop_watch
{
	std::chrono::system_clock::time_point start;
	bool log_at_finish;
public:
	stop_watch(bool b = false) : log_at_finish(b) { start = std::chrono::system_clock::now(); }
	~stop_watch() { if (log_at_finish) log(); }

	std::chrono::duration<double> stop()
	{
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	void log()
	{
		std::cout << stop().count() << " seconds." << std::endl;;
	}
};

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	stop_watch sw(true);

	// �Ʒ� ó�� �ϸ� f �� �Ϲ� �Լ� �϶��� �����մϴ�
	// ��� �Լ���� ����!!
	//return f(std::forward<T>(arg)...);

	// �Ʒ� ó�� �ϸ� �Ϲ� �Լ� �� �ƴ϶� ��� �Լ�, ���� ǥ����, �Լ���ü ��� ���
	return std::invoke(f, std::forward<T>(arg)...);
}