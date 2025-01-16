# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
					: AForm("RobotomyRequestForm", 75, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
					: AForm("RobotomyRequestForm", 75, 45, target) 
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj)
					: AForm(obj) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs); // Llamar al operator de asignacion de la clase base
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Bzzzz... Bzzz... (driling noises)" << std::endl;

	if (rand() % 2)
	{
		std::cout << getTarget() << " has been successfully robotomized! " << std::endl;
	}
	else
	{
		std::cout << "The robotomy failed on " << getTarget() << "!" << std::endl;
	}
}
