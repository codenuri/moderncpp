// tuple.h
#pragma once

template<typename ... Ts>
struct tuple
{
	static constexpr int N = 0;
};
template<typename T, typename ... Ts>
struct tuple<T, Ts...> : public tuple<Ts...>
{
	using base = tuple<Ts...>;

	T value;
	tuple() = default;
	tuple(const T& value, const Ts& ... args)
		: value(value), base(args...) {}

	static constexpr int N = base::N + 1;
};