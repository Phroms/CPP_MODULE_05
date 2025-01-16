# pragma once
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;
	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string const &target);
			ShrubberyCreationForm(ShrubberyCreationForm const &obj);
			ShrubberyCreationForm &operator=(ShrubberyCreationForm const &obj);
			~ShrubberyCreationForm();
	protected:
			void executeAction() const; 
};
