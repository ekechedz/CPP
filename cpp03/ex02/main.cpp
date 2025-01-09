/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:48:52 by ekechedz          #+#    #+#             */
/*   Updated: 2025/01/09 14:48:55 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Default Constructor Test ===" << std::endl;
	ClapTrap clapDefault;
	ScavTrap scavDefault;
	FragTrap fragDefault;

	std::cout << "\n=== Parameterized Constructor Test ===" << std::endl;
	ClapTrap clapParam("Clappy");
	ScavTrap scavParam("Scavvy");
	FragTrap fragParam("Fraggy");

	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	ClapTrap clapCopy(clapParam);
	ScavTrap scavCopy(scavParam);
	FragTrap fragCopy(fragParam);

	std::cout << "\n=== Copy Assignment Test ===" << std::endl;
	ClapTrap clapAssigned;
	ScavTrap scavAssigned;
	FragTrap fragAssigned;
	clapAssigned = clapParam;
	scavAssigned = scavParam;
	fragAssigned = fragParam;

	std::cout << "\n=== Testing Special Functionalities ===" << std::endl;
	fragParam.highFivesGuys();
	scavParam.guardGate();

	std::cout << "\n=== Destruction Test ===" << std::endl;
	return 0;
}
