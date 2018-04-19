/*
** EPITECH PROJECT, 2018
** infocpu
** File description:
** infocpu
*/

#include "InfoCpu.hpp"
#include "Ncurses.hpp"

InfoCpu::InfoCpu()
	:	_name(""),
		_enabled(true)
{}

std::string			InfoCpu::getName() 	const
{
	return _name;
}

void	InfoCpu::dispValues(IMonitorDisplay &module)
{
	std::string tmp;
	std::string word;
	std::string toaff;
	std::ifstream path("/proc/cpuinfo");

	for (int i = 0; i < 5; i++)
		getline(path, tmp);
	path.close();
	std::istringstream	nom(tmp);
	for (int j = 0; j < 4; j++)
		nom >> word;
	for (int k = 0; k < 5; k++) {
		nom >> word;
		toaff += word;
	}
	module.openBox("Cpu Infos", _enabled);
	if (_enabled)
		module.printTxt(toaff);
	module.closeBox();
}
