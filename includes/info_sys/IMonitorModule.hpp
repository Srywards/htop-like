//
// EPITECH PROJECT, 2018
// IMonitorModule.hpp
// File description:
// IMonitorModule
//

#ifndef IMODULE_H_
#define IMODULE_H_

#include "IMonitorDisplay.hpp"
#include <iostream>

class 				IMonitorModule
{
public:
	virtual std::string	getName()	const = 0;
	virtual void	dispValues(IMonitorDisplay &module) = 0;

};

#endif
