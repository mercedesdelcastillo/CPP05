#!/bin/bash

hppPath="./"
cppPath="./"

mkdir -p $hppPath $cppPath

for class in "$@"
do
    capClass="$(tr '[:lower:]' '[:upper:]' <<< ${class:0:1})${class:1}"
    fcapClass="$(tr '[:lower:]' '[:upper:]' <<< ${class})"
    hpp="$hppPath$capClass".hpp
    cpp="$cppPath$capClass".cpp
    # HPP
    rm -f $hpp && touch $hpp
    cat > $hpp << EOL
#ifndef ${fcapClass}_HPP
# define ${fcapClass}_HPP
# include <iostream>

class $capClass
{
    public:
    //Constructors
        $capClass(void);
        $capClass(const $capClass& other);

    //Destructors
        ~$capClass();

    //Overload Operators
        $capClass &operator=(const $capClass &other);
    
    //Public Methods
    
    //Setters

    //Getters
        
};

#endif

EOL

    # CPP
    rm -f $cpp && touch $cpp
    cat > $cpp << EOL
#include "$capClass.hpp"

//Constructors
$capClass::$capClass(void)
{
    std::cout << "Default constructor called" << std::endl;
}

$capClass::$capClass(const $capClass &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
}
// Destructors
$capClass::~$capClass(void)
{
    std::cout << "Destructor called" << std::endl;
}

// Overload Operators
$capClass &$capClass::operator=(const $capClass &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Public Methods

// Getters

// Setters



EOL
done

printf "\n$# classes created:\n\n"
for class in "$@"
do
    echo "$capClass.hpp/.cpp"
done