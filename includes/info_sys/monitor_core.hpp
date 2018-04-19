/*
** EPITECH PROJECT, 2018
** monitor_core
** File description:
** monitor_core hpp
*/

#ifndef MONITOR_CORE_HPP_
#define MONITOR_CORE_HPP_

#include "IMonitorModule.hpp"
#include <thread>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>

class	monitor_core : public IMonitorModule
{
public:
	monitor_core();
	~monitor_core();
	std::string	getName() const;
	void		dispValues(IMonitorDisplay &module);
private:
	bool	display;
	const std::string _name;
	std::vector<unsigned int>	*mem;
	std::vector<unsigned int>	values;
	unsigned int		tymeMem;
};

#endif
