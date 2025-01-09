/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:46:23 by ekechedz          #+#    #+#             */
/*   Updated: 2025/01/09 14:46:24 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");

	clap.attack("Target1");
	clap.takeDamage(3);
	clap.beRepaired(2);

	ClapTrap copyClap = clap;
	copyClap.attack("Target2");

	ClapTrap assignedClap("Assigned");
	assignedClap = clap;
	assignedClap.takeDamage(15);

	return 0;
}
