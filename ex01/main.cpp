# include "Form.hpp"
# include "Bureaucrat.hpp"

int main()
{
	bool allCorrect = true;
	Bureaucrat b1("Alice", 50);
	Bureaucrat b2("Bob", 50);
	Bureaucrat b3("Charlie", 49);
	Bureaucrat b4("Pedro", 150);

	try
	{


		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;

		try
		{
			b1.incrementGrade();
			std::cout << BLUE << b1 << NONE << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED"Error with " BLUE << b1.getName() << ": " << e.what() << std::endl;
			allCorrect = false;
		}

		try
		{
			b2.incrementGrade();
			std::cout << BLUE << b2 << NONE << std::endl; // Esto deberia lanzar una exception
		}
		catch (std::exception &e)
		{
			std::cerr << RED"Error with " BLUE << b2.getName() << ": " << e.what() << std::endl;
			allCorrect = false;
		}

		try
		{
			b3.decrementGrade();
			std::cout << BLUE << b3 << NONE << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED"Error with " BLUE << b3.getName() << ": " << e.what() << std::endl;
			allCorrect = false;
		}

		try
		{
			b4.decrementGrade();
			std::cout << BLUE << b4 << NONE <<std::endl; // Esto deberia lanzar una exception
		}
		catch (std::exception &e)
		{
			std::cerr << RED"Error with " BLUE << b4.getName() << ": " << e.what() << std::endl;
			allCorrect = false;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << RED"An Error ocurred: " NONE << e.what() << std::endl;
		allCorrect = false;
	}

	try
	{
		Bureaucrat b4("Invalid123", 100); // Esto deberia lanzar una exception
	}

	catch (std::exception &e)
	{
		std::cerr << RED"Error creating b4: " NONE << e.what() << std::endl;
		allCorrect = false;
	}

	try
	{
		Bureaucrat b5("David", 0); // Esto deberia lanzar una exception
	}

	catch (std::exception &e)
	{
		std::cerr << RED"Error creating b5: " NONE << e.what() << std::endl;
		allCorrect = false;
	}

	try
	{
		Bureaucrat b6("Eve", 151); // Esto deberia lanzar una exception
	}

	catch (std::exception &e)
	{
		std::cerr << RED"Error creating b6: " NONE << e.what() << std::endl;
		allCorrect = false;
	}

	// Pruebas para la clase Form
	try
	{
		Form f1("Form1", 50, 100);
		//std::cout << f1 << std::endl;

		b1.signForm(f1); // Alice deberia poder firmar
		std::cout << f1 << std::endl;

		Form f2("Form2", 1, 1);
		b3.signForm(f2); // Charlie no deberia poder firmar
		std::cout << f2 << std::endl;
	}
	
	catch (std::exception &e)
	{
		std::cerr << RED"An Error ocurred: :" NONE << e.what() << std::endl;
		allCorrect = false;
	}
	if (allCorrect)
	{
		std::cout << GREEN"Everything is correct" NONE << std::endl;
	}
	return 0;
}

