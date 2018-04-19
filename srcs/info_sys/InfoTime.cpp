/*
** EPITECH PROJECT, 2018
** infotime
** File description:
** infotime cpp
*/

#include "InfoTime.hpp"

InfoTime::InfoTime()
	:	_name("Date"),
		_enabled(true)
{
}

std::string			InfoTime::getName() 	const
{
	return _name;
}

void	InfoTime::dispValues(IMonitorDisplay &module)
{
	time_t now;
	char *date;
	time_t lol = time(&now);
	date = ctime(&lol);
	std::string a ("");
	std::string b (date);
	_date = a + b;
	module.openBox(_name, _enabled);
	if (_enabled){
		module.printTxt(_date);
	}
	module.closeBox();
}
