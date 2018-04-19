//
// EPITECH PROJECT, 2018
// InfoTime.hpp
// File description:
// InfoTime
//

#ifndef INFOTIME_HPP_
#define INFOTIME_HPP_
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Ncurses.hpp"
#include <iostream>
#include <time.h>


class 	InfoTime	:	public IMonitorModule
{
public:
				InfoTime();
	std::string		getName() 	const;
	void			dispValues(IMonitorDisplay &module);

private:
	const std::string	_name;
	std::string		_date;
	std::string		_time;
	bool			_enabled;
};

#endif
