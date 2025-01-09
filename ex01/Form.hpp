# pragma once
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>
# include <string>

# define RED \033[91m
# define YELLOW \033[92m
# define GREEN \033[93m
# define CYAN \033[96m
# define NONE \033[0m

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool 				_signed;
		int const 			_gradeToSign;
		int const 			_gradeToExecute;
	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(Form const &obj);
		Form &operator=(Form const &obj);
		void isGradeValid(int grade) const;

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;

		void beSigned(Bureaucrat const &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &out, Form const &obj);
