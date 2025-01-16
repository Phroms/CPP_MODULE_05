# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
						: AForm("ShrubberyCreationForm", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) 
						: AForm("ShrubberyCreationForm", 145, 137, target), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj)
						: AForm(obj), _target(obj._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
			AForm::operator=(rhs); // Llamar al operador de asignacion de la clase base
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const 
{
	std::ofstream file((getTarget() + "_shrubbery").c_str());
	if (file.is_open())
	{
		file <<	" ██████████████████████████ "
			 << " ▌                        ▐ "
			 << " ▌  ▄▄▓█████▓▄     ▄▄▓█▓▄ ▐ "
			 << " ▌ ▄▓▀▀▀██████▓▄ ▄▓█████▓▌▐ "
			 << " ▌       ▄▓███████████▓▀▀▓▐ "
			 << " ▌   ▄▓█████████▓████▓▄   ▐ "
			 << " ▌ ▄▓████▓███▓█████████▓▄ ▐ "
			 << " ▌▐▓██▓▓▀▀▓▓███████▓▓▀▓█▓▄▐ "
			 << " ▌▓▀▀    ▄▓██▓██████▓▄ ▀▓█▐ "
			 << " ▌      ▓██▓▀ ██ ▀▓██▓▄  ▀▐ "
			 << " ▌     ▄███▀ ▐█▌   ▀▓█▓▌  ▐ "
			 << " ▌    ▐▓██▓  ██▌     ▓▓█  ▐ "
			 << " ▌    ▐▓█▓  ▐██       ▀▓▌ ▐ "
			 << " ▌     ▓█▀  ██▌        ▀  ▐ "
			 << " ▌      ▀   ██▌           ▐ "
			 << " ▌         ▐██▌           ▐ "
			 << " ▌         ▐██            ▐ "
			 << " ▌         ███            ▐ "
			 << " ▌         ███            ▐ "
			 << " ▌        ▐██▌            ▐ "
			 << " ▌        ▐██▌            ▐ "
			 << " ▌        ▐██▌            ▐ "
			 << " ▌     ▄▄██████▄▄▄        ▐ "
			 << " ██████████████████████████ ";
		file.close();
	}
	else
	{
		std::cerr << "Error: could not create file " << getTarget() + "_shrubbery" << std::endl;
	}
}
