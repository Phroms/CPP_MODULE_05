# pragma once
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &obj);
		~PresidentialPardonForm();
	protected:
		void executeAction() const; // Implementacion de la funcion virtual pura
};
