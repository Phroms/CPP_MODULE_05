# pragma once
# include <iostream>
# include <string>
# include <cctype>
# include <stdexcept> // es para el throw

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
		std::ostream &operator<<(std::ostream &out);

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
