# include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec)
		: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
			throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
			throw GradeTooLowException();
}

Form &Form::operator=(Form const &obj)
{
	if (this != &obj)
		_signed = obj._signed;
	return *this;
}

Form::Form(Form const &obj)
		: _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
}

void Form::isGradeValid(int grade) const
{
	if (grade < 1)
			throw GradeTooLowException();
	if (grade > 150)
			throw GradeTooHighException();
}

char const *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

char const *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::string Form::getName() const
{
	return _name;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool Form::isSigned() const
{
	return _signed;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
			throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return out;
}
