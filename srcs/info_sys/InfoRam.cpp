/*
** EPITECH PROJECT, 2018
** inforam
** File description:
** inforam hpp
*/

#include "InfoRam.hpp"
#include "Ncurses.hpp"
#include <limits.h>
#include "sys/types.h"
#include "sys/sysinfo.h"
#include <string>
#include <iomanip>
#include <sstream>

InfoRam::InfoRam()
	:	_name("RAM"),
		_enabled(true)
{
}

std::string			InfoRam::getName() 	const
{
	return _name;
}

void	InfoRam::dispValues(IMonitorDisplay &module)
{
	struct sysinfo memInfo;

	sysinfo (&memInfo);
	long long totalVirtualMem = memInfo.totalram;
	long long memoryUsed = memInfo.freeram;
	memoryUsed *= memInfo.mem_unit;
	totalVirtualMem *= memInfo.mem_unit;
	totalVirtualMem /= 1024;
	memoryUsed /= 1024;
	totalVirtualMem *= 1000;
	memoryUsed *= 1000;
	totalVirtualMem /= 10000000;
	memoryUsed /= 10000000;
	std::string a ("Total RAM (GB): ");
	std::string b ("free RAM (GB): ");
	std::ostringstream out;
	std::ostringstream out2;

    	out << std::setprecision(3) << ((float)totalVirtualMem / 100.0);
	std::string c = out.str();
	out2 << std::setprecision(3) << ((float)memoryUsed / 100.0);
	std::string d = out2.str();
	_mem = b + d;
	_total = a + c;
	module.openBox(_name, _enabled);
	if (_enabled){
		module.printTxt(_mem);
		module.printTxt(_total);
		module.printBar((int)totalVirtualMem\
		,(int)totalVirtualMem - (int)memoryUsed);
	}
	module.closeBox();
}
