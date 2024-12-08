#include "ICharacter.hpp"
#include "utils.hpp"

/* ICharacter::~ICharacter( void ) {
	print("[ ICharacter ]: Destructor Called", GREEN);
} */

/* Canonical form of Character */
Character::Character( void ) : name("DefaultCharacterName") {
	print("[ Character ]: Default Constructor Called", GREEN);
	for (size_t i = 0; i < AMATERIA_SLOTS; i++)
		slots[i] = NULL;
}

Character::Character( const Character& other ) : name("DefaultCharacterName") {
	print("[ Character ]: Copy Constructor Called", GREEN);
	for (size_t i = 0; i < AMATERIA_SLOTS; i++)
		slots[i] = NULL;
	*this=(other);
}

Character&	Character::operator=( const Character& other ) {
	print("[ Character ]: Copy Assignment Called", GREEN);
	if (this != &other) {
		this->name = other.getName();
		// to be test this copy, should be deep one.
		for (size_t i = 0; other.slots[i] != NULL; i++)
		{
			if (this->slots[i] != NULL)
				delete slots[i];
			this->slots[i] = other.slots[i];
		}
	}
	return *this;
}

Character::~Character( void ) {
	print("[ Character ]: Default destructor called", GREEN);
	// free resources.
	for (size_t i = 0; i < AMATERIA_SLOTS; i++)
	{
		if (slots[i])
			delete slots[i];
	}
}

Character::Character( std::string const &_name ) : name(_name) {
	print("[ Character ]: Constructor by parameter called", GREEN);
}

/* Interface */


std::string const&	Character::getName( void ) const {
	return name;
}

void	Character::equip( AMateria *m ) {
	size_t	i = 0;

	for (; i < AMATERIA_SLOTS; i++)
	{
		if (slots[i] == NULL)
			break ;
	}
	if (i == AMATERIA_SLOTS)
	{
		print("No slot left", RED);
		return ;
	}
	slots[i] = m;
}

void	Character::unequip( int idx ) {
	// save the address on the main.
	slots[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target ) {
	if (idx >= AMATERIA_SLOTS)
	{
		print("No slot at this index", RED);
		return ;
	}
	slots[idx]->use( target );
}