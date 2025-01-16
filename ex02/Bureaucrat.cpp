# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{}

bool isValidName(std::string name)
{
	if (name.empty())
			return false;
	for (size_t i = 0; i < name.length(); i++)
	{
		if (std::isdigit(name[i]))
				return false;
	}
	return true;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
			: _name(name), _grade(grade)
{
	if (!isValidName(name))
			throw InvalidNameException();
	if (grade < 1)
			throw GradeTooHighException();
	if (grade > 150)
			throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
			: _name(rhs._name), _grade(rhs._grade)
{
	if (!isValidName(rhs._name))
			throw InvalidNameException();
	if (_grade < 1)
			throw GradeTooHighException();
	if (_grade > 150)
			throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		if (!isValidName(rhs._name))
				throw InvalidNameException();
		if (rhs._grade < 1)
				throw GradeTooHighException();
		if (rhs._grade > 150)
				throw GradeTooLowException();
		_grade = rhs._grade;
	}
	return *this;
}

// Implimentacion de los metodos what() para las excepciones

// Los metodos what se implementan para cada clase de excepcion. Estos metodos devuelven el error especifico
char const *Bureaucrat::InvalidNameException::what() const throw()
{
	return RED "Invalid name.";
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return YELLOW "Grade is too low!";
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return YELLOW "Grade is too high!";
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
			throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
			throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::executeGrade()
{
	if (_grade < 1)
		throw GradeTooLowException();
	if (_grade > 150)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BLUE << _name << GREEN << " signed: " << WHITE << form.getName() << NONE << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BLUE << _name << RED << " couldn't sign " << WHITE << form.getName() << YELLOW << " because " << NONE << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return out;
}

