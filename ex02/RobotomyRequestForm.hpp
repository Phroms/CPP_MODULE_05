# pragma once
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib> // Para rand() y srand()
# include <ctime> // Para time()

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	protected:
		void executeAction() const;
};
