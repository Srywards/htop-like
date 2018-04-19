/*
** EPITECH PROJECT, 2018
** infokernel
** File description:
** infokernel hpp
*/

#include "InfoKernel.hpp"
#include "Ncurses.hpp"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>


InfoKernel::InfoKernel()
	:	_name("Operating System"),
		_enabled(true)
{
struct utsname u;
uname(&u);
std::string a ("OS :");
std::string b (u.sysname);
std::string c ("Kernel version : ");
std::string d (u.release);

_osname = a + b;
_kversion = c + d;
}

std::string			InfoKernel::getName() 	const
{
	return _name;
}

void	InfoKernel::dispValues(IMonitorDisplay &module)
{
	module.openBox(_name, _enabled);
	if (_enabled){
		module.printTxt(_osname);
		module.printTxt(_kversion);
	}
	module.closeBox();
}
