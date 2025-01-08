# include "Bureaucrat.hpp"
#include <cstdlib>

int main()
{
	try
	{
		Bureaucrat b1("Alice", 50);
		Bureaucrat b2("Bob", 1);
		Bureaucrat b3("Charlie", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;


		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl; // Esto deberia lanzar una exception
		b3.decrementGrade();
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b4("Invalid123", 100); // Esto deberia lanzar una exception
	}

	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b5("David", 0); // Esto deberia lanzar una exception
	}

	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b6("Eve", 151); // Esto deberia lanzar una exception
	}

	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
