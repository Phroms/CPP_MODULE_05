# include "AForm.hpp"
# include "Bureaucrat.hpp"

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
		Form f1("Formulario 1", 49, 50);  // Nombre del formulario, grado requerido para firmar, grado requerido para ejecutar
		//std::cout << f1 << std::endl;

		b1.signForm(f1); // Alice deberia poder firmar
		std::cout << f1 << std::endl;

		Form f2("Formulario 2", 49, 50);
		b3.signForm(f2); // Charlie no deberia poder firmar
		std::cout << f2 << std::endl;
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


/* EJEMPLOS 

Ejemplo 1:

si yo tengo un burocrata Alice de grado 50 y un grado para firmar de 60 y un grado para ejecutar es de 100

entonces ese burocrata podra firmar sin problema

Ejemplo 2:

si yo tengo un burocrata de grado 10 y un grado para firmar 5 y un grado para ejecutar 20

entonces ese burocrata no podra firmar

Ejemplo 3:

si yo tengo un burocrata de grado 70 y un grado para firmar de 80 y un grado para ejecutar de 10

entonces ese burocrata no podra firmar, mas no puede ejecutarlo

Ejemplo 1:

    Burócrata: Alice, grado 50
    Grado para firmar: 60
    Grado para ejecutar: 100

Alice podrá firmar sin problema porque su grado (50) es menor que el requerido para firmar (60).

Ejemplo 2:

    Burócrata: grado 10
    Grado para firmar: 5
    Grado para ejecutar: 20

El burócrata no podrá firmar porque su grado (10) es mayor que el requerido para firmar (5).

Ejemplo 3:

    Burócrata: grado 70
    Grado para firmar: 80
    Grado para ejecutar: 10

El burócrata podrá firmar porque su grado (70) es menor que el requerido para firmar (80),
pero no podrá ejecutar el formulario porque su grado (70) es mayor que el requerido 
para ejecutar (10).

*/
