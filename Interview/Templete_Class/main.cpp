#include <iostream>
#include <cstdlib>

template <typename T> void foo(T &val)
{
	std::cout << (T(0) < val) - ( T(0) > val) << "\n";
}

int main()
{
	int z = 98;
	foo<int>(z);
	double zf = 0.000000000000;
	foo<double>(zf);
	return(EXIT_SUCCESS);
}