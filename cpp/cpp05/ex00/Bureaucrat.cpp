#include "Bureaucrat.hpp"

// Canonical form
Bureaucrat::Bureaucrat( void ) : _name("bureaucrat_instance"), _grade(DEFAULT_GRADE) {
	std::cout << GREEN << "[ Bureaucrat ]: Default constructor called";
	std::cout << RESET_COLOR << std::endl;
}

	// Constructor by parameter
Bureaucrat::Bureaucrat( const std::string& name, int grade )
			: _name(name), _grade(NO_GRADE) {
	std::cout << GREEN << "[ Bureaucrat ]: constructor by parameter called";
	std::cout << RESET_COLOR << std::endl;
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	else if (grade > 150) throw Bureaucrat::GradeTooLowException();
	else _grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other.getName() + "_copy") {
	std::cout << GREEN << "[ Bureaucrat ]: Copy Constructor called";
	std::cout << RESET_COLOR << std::endl;
	*this=(other);
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	std::cout << GREEN << "[ Bureaucrat ]: Copy Assignment called";
	std::cout << RESET_COLOR << std::endl;
	if (this != &other) {
		_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << GREEN << "[ Bureaucrat ]: Default destructor called";
	std::cout << RESET_COLOR << std::endl;
}

// methods
void	Bureaucrat::incrementGrade( void ) {
	_grade--;
	if (_grade < 1) throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade( void ) {
	_grade++;
	if (_grade > 150) throw Bureaucrat::GradeTooLowException();
}

// Exceptions Bureaucrat's methods
const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException";
}

// getters
const std::string&	Bureaucrat::getName( void ) const {
	return _name;
}

int	Bureaucrat::getGrade( void ) const {
	return _grade;
}

// overload insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat) {
	os << Bureaucrat.getName() << ", bureaucrat _grade " << Bureaucrat.getGrade();
	return os;
}
