# include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExec, std::string target)
		: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec), _target(target)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
			throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
			throw GradeTooLowException();
}

AForm &AForm::operator=(AForm const &obj)
{
	if (this != &obj)
		_signed = obj._signed;
	return *this;
}

AForm::AForm(AForm const &obj)
		: _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
}

void AForm::isGradeValid(int grade) const
{
	if (grade < 1)
			throw GradeTooHighException();
	if (grade > 150)
			throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &execute) const
{
	if (!_signed)
			throw FormNotSignedException();
	if (execute.getGrade() > _gradeToExecute)
			throw GradeTooLowException();
	executeAction();
}

char const *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

char const *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

char const *AForm::FormNotSignedException::what() const throw()
{
	return "Unsigned Form";
}

std::string AForm::getName() const
{
	return _name;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool AForm::isSigned() const
{
	return _signed;
}

std::string AForm::getTarget() const
{
	return _target;
}

AForm::~AForm(){}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
			throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return out;
}
