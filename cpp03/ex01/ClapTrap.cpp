/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:48:06 by ekechedz          #+#    #+#             */
/*   Updated: 2025/01/09 14:48:07 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " has been constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap copy constructor called!" << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

// Member Functions
void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	hitPoints = (amount >= hitPoints) ? 0 : (hitPoints - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points!" << std::endl;
	hitPoints += amount;
}
