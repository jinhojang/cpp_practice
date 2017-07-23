#include <iostream>
#include <cmath>
#include <typeinfo>

const long double PI = 3.141592653589793238L;

template<class T, class U>
auto add(T t, U u)->decltype(t + u)
{
	return t + u;
}

void test_add() 
{
	auto a = 1 + 2;
	std::cout << "type of a: " << typeid(a).name() << std::endl;
	auto b = add(1, 1.2);
	std::cout << "type of b: " << typeid(b).name() << std::endl;
	auto c = { 1, 2 };
	std::cout << "type of c: " << typeid(c).name() << std::endl;

}

auto get_func(int arg)->double(*)(double)
{
	switch (arg)
	{
	case 1: return std::fabs;
	case 2: return std::sin;
	default: return std::cos;
	}
}

void test_get_func() 
{
	auto func = get_func(1);
	std::cout << "type of func is " << typeid(func).name() << std::endl;
	std::cout << "func(-3) is " << func(-3) << std::endl;

	auto next_func = get_func(2);
	std::cout << "type of next_func is " << typeid(next_func).name() << std::endl;
	std::cout << "next_func(pi) is " << next_func(PI) << std::endl;
}

int main(int argc, char* argv) 
{
	test_add();
	test_get_func();
}