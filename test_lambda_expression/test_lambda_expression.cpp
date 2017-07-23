#include <algorithm>
#include <iostream>
#include <ctype.h>

void test_uppercase_counter() 
{
	char s[] = "Hello World!";
	int Uppercase = 0; //modified by the lambda
					   // Uppercase: a variable defined outside of lambda which needs to be increased inside lambda
	std::for_each(s, s + sizeof(s), [&Uppercase](char c) { if (isupper(c)) Uppercase++; });
	std::cout << Uppercase << " uppercase letters in: " << s << std::endl;
}

void test_comparator()
{
	// generic lambda, operator() is a template with two parameters
	// http://stackoverflow.com/questions/5481539/what-does-t-double-ampersand-mean-in-c11
	auto glambda = [](auto a, auto&& b) { return a < b; };
	bool b = glambda(3, 3.14); // ok
	std::cout << "b = " << b << std::endl;
}


int main( int argc, char* argv )
{
	test_uppercase_counter();
	test_comparator();
}