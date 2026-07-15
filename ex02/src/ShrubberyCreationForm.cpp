#include "ShrubberyCreationForm.hpp"

std::string tree0 = "#                a&                                  \n";
std::string tree1 = "#              8&@&                                  \n";
std::string tree2 = "#       &8@8 8&  8@|                                 \n";
std::string tree3 = "#    &&@@&%#@%_|@@&&@#       @=&                     \n";
std::string tree4 = "#   &#@# #%##  ;&@8#  %@    @% &%                    \n";
std::string tree5 = "#     @  %  #&  8%~|       @%@%@&#                  \n";
std::string tree6 = "#                  |;;         # %                   \n";
std::string tree7 = "#                     \\        @ 8 %@%#             \n";
std::string tree8 = "#                      |~     =;@ __8%               \n";
std::string tree9 = "#                      =|   ~_=___  %&#              \n";
std::string tree10  = "#                      || /~         % #             \n";
std::string tree11 = "#                      |//           &               \n";
std::string tree12 ="#                      |=                            \n";
std::string tree13 = "#                      ~|                            \n";
std::string tree14 = "#                      ;|                            \n";
std::string tree15 = "#       .---.        ./||\\.    .-.";

std::string tree[] = {tree0, tree1, tree2, tree3, tree4, tree5, tree6, tree7, tree8, tree9, tree10, tree11, tree12, tree13, tree14, tree15};

//Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
    std::cout << "Shrubery Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int signgrade, int execgrade) : AForm(name, signgrade, execgrade)
{
    if(signgrade < 1 || execgrade < 1)
            throw GradeTooHighException();
    else if(signgrade > 146 || execgrade > 137)
        throw GradeTooLowException();
    create_file(name);
    std::cout << "Shrubbery Atributes constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    std::cout << "Shrubbery Copy constructor called" << std::endl;
    (void) other;
}
// Destructors
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery Destructor called" << std::endl;
}

// Overload Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "Shrubbery Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Public Methods
void    ShrubberyCreationForm::create_file(std::string name)
{
    std::ofstream wFile(name.c_str());
	if(wFile.good() == false)
	{
		std::cout << "Error opening " << name << "\n";
		return;
	}
    for(int i = 0; i < 16; i++)
    {
        wFile << tree[i];
    }
    wFile.close();
}

// Getters

// Setters



