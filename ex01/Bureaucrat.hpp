# pragma once
# include <iostream>
# include <string>
# include <cctype>
# include <stdexcept>
# include <filesystem>
# include <exception>// es para el throw
# include <cstdlib>

# define RED "\033[91m"
# define YELLOW "\033[93m"
# define GREEN "\033[92m"
# define BLUE "\033[94m"
# define NONE "\033[0m"

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int digit);
		Bureaucrat(Bureaucrat const &rhs);
		Bureaucrat &operator=(Bureaucrat const &rhs);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		// Los metodos what es un metodo virtual que se hereda de la clase exception
		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};

		class InvalidNameException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
};

// Declaracion del operador de insercion de flujo
std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs);


