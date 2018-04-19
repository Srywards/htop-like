/*
** EPITECH PROJECT, 2018
** infocpu
** File description:
** infocpu
*/

#ifndef INFOCPU_HPP_
#define INFOCPU_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <thread>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>

class 	InfoCpu	:	public IMonitorModule
{
public:
				InfoCpu();
	std::string		getName() 	const;
	void			dispValues(IMonitorDisplay &module);

private:
	const std::string	_name;
	bool			_enabled;
};

#endif
