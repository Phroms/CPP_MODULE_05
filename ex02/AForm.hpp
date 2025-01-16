# pragma once
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool 				_signed;
		int const 			_gradeToSign;
		int const 			_gradeToExecute;
		std::string 		_target;
	public:
		AForm(std::string name, int gradeToSign, int gradeToExec, std::string target);
		AForm(AForm const &obj);
		AForm &operator=(AForm const &obj);
		~AForm();
		void isGradeValid(int grade) const;
		void execute(Bureaucrat const &executor) const;

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;
		std::string getTarget() const;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	protected:
		virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &obj);
