#include <iostream>
#include <iomanip>      // std::setw
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> stringmap;

stringmap merge(stringmap a, stringmap b) {
	stringmap temp(a); 
	temp.insert(b.begin(), b.end()); 
	return temp;
}

int test_constructor()
{
	// constructing unordered_maps
	std::cout << "testing constructor...." << std::endl;
	stringmap first;                                                         // empty
	stringmap second({ { "apple", "red" },{ "lemon", "yellow" } });       // init list
	stringmap third({ { "orange", "orange" },{ "strawberry", "red" } });  // init list
	stringmap fourth(second);                                              // copy
	stringmap fifth(merge(third, fourth));                                // move
	stringmap sixth(fifth.begin(), fifth.end());                           // range

	std::cout << "sixth contains:" << std::endl;
	for (auto& x : sixth) std::cout << std::setw(10) << x.first << " :"
		<< std::setw(10) << x.second << std::endl;
	std::cout << std::endl;
	return 0;
}

int test_empty_method()
{
	//empty
	std::cout << "testing empty method...." << std::endl;
	std::unordered_map<int, int> first;
	std::unordered_map<int, int> second = { { 1,10 }, { 2,20 }, { 3,30 } };
	std::cout << "first " << ( first.empty() ? "is empty" : "is not empty" ) << std::endl;
	std::cout << "second " << ( second.empty() ? "is empty" : "is not empty" ) << std::endl;
	std::cout << std::endl;
	return 0;
}

int main( int argc, char *argv[] )
{
	test_constructor();
	test_empty_method();
	return 0;
}