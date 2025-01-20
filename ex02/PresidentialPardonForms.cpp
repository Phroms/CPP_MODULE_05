# include "PresidentialPardonForms.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
						: AForm("PresidentialPardonForm", 25, 5, "") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
						: AForm("PresidentialPardonForm", 25, 5, target) 
{
	srand(time(NULL));
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj)
						: AForm(obj) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
