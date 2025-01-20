# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForms.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
	bool allCorrect = true;
	Bureaucrat b1("Alice", 50);
	Bureaucrat b2("Bob", 50);
	Bureaucrat b3("Charlie", 50);
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
			b3.incrementGrade();
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
		PresidentialPardonForm ppf("The President");
		RobotomyRequestForm rrf("The Robot");
		ShrubberyCreationForm scf("The Tree");

		std::cout << "\n--- Testing PresidentialPardonForm ---\n";
		std::cout << ppf << std::endl;

		b1.signForm(ppf); // Alice deberia poder firmar
		std::cout << ppf << std::endl;
		b3.executeForm(ppf); // Charlie deberia poder ejecutar
							  
		std::cout << "\n--- Testing RobotomyRequestForm ---\n";
		std::cout << rrf << std::endl;

		b2.signForm(rrf); // Bob deberia poder firmar
		std::cout << rrf << std::endl;
		b3.executeForm(rrf); // Charlie deberia poder ejecutar
					
		std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
		std::cout << scf << std::endl;

		b4.signForm(scf); // Pedro no deberia poder firmar
		std::cout << scf << std::endl;
		b3.executeForm(scf); // Charlie deberia poder ejecutar
	}
	
	catch (std::exception &e)
	{
		std::cerr << RED"An Error ocurred: " NONE << e.what() << std::endl;
		allCorrect = false;
	}
	if (allCorrect)
	{
		std::cout << GREEN"Everything is correct" NONE << std::endl;
	}
	return 0;
}
