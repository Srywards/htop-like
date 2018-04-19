/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "Ncurses.hpp"
#include "Sfml.hpp"
#include "InfoName.hpp"
#include "monitor_core.hpp"
#include "InfoKernel.hpp"
#include "InfoTime.hpp"
#include "InfoRam.hpp"
#include "InfoCpu.hpp"
#include "InfoRam.hpp"
#include "InfoNetwork.hpp"

int	main(int ac, char **av)
{
	Sfml			sfml;
	Ncurses 		ncurse;
 	InfoName 		lol;
	InfoTime 		t;
	InfoRam 		r;
	InfoCpu 		c;
	InfoKernel		k;
	monitor_core		co;
	InfoNetwork 		n;
	IMonitorDisplay 	*disp;
	std::string 		s("");

	if (av && av[0] && av[1])
		s = av[1];
	if (ac > 1 && av && av[0] && av[1] && s == "graphical")
		disp = new Sfml();
	else
		disp = new Ncurses();

	bool	cont = true;
	while (cont)
 	{
		disp->refreshAll();
		lol.dispValues(*disp);
		t.dispValues(*disp);
		r.dispValues(*disp);
		k.dispValues(*disp);
		c.dispValues(*disp);
		co.dispValues(*disp);
		n.dispValues(*disp);
		cont = disp->wait();
 	}
 	return 0;
}
