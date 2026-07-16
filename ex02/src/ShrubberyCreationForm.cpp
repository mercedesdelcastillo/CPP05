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
std::string tree15 = "#       .---.        ./||\\.    .-.\n\n";

std::string tree[] = {tree0, tree1, tree2, tree3, tree4, tree5, tree6, tree7, tree8, tree9, tree10, tree11, tree12, tree13, tree14, tree15};

//Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
    std::cout << "A Shrubbery Default Form was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int signgrade, int execgrade) : AForm(name, signgrade, execgrade)
{
    if(signgrade < 1 || execgrade < 1)
        throw GradeTooHighException();
    else if(signgrade > 145 || execgrade > 137)
        throw GradeTooLowException();
    std::cout << "Shrubbery with Atributes Form was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "Shrubbery Copy constructor called" << std::endl;
}
// Destructors
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery Destructor called" << std::endl;
}

// Overload Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "Not a good idea, but the Shrubbery Forms are a bit equal now" << std::endl;
    if(this != &other)
    {
        this->setSigned(other.getSigned());
    }
    return (*this);
}

// Public Methods
void    ShrubberyCreationForm::action(std::string target)
{
    target.append("_shrubbery");
    std::ofstream wFile;
    wFile.open(target.c_str(), std::ios_base::app);
    if(wFile.good() == false)
    {
        std::cout << "Error opening " << target << "\n";
        return;
    }  
    for(int i = 0; i < 16; i++)
    {
        wFile << tree[i];
    }
    wFile.close();
    std::cout << "A tree was planted" << std::endl;
}

// Getters

// Setters



