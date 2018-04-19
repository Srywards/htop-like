/*
** EPITECH PROJECT, 2018
** infoname
** File description:
** infoname hpp
*/

#include "InfoName.hpp"
#include "Ncurses.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

InfoName::InfoName()
	:	_name("User & PC name"),
		_enabled(true)
{
	char hostname[1025];
	char username[1025];
	hostname[0] = '\0';
	username[0] = '\0';
	gethostname(hostname,1025);
	getlogin_r(username, 1025);
	std::string	h (hostname);
	std::string	u (username);
	_hostname = h;
	_username = u;
}

std::string			InfoName::getName() 	const
{
	return _name;
}

void	InfoName::dispValues(IMonitorDisplay &module)
{
	char hostname[1025];
	char username[1025];
	hostname[0] = '\0';
	username[0] = '\0';
	gethostname(hostname,1025);
	getlogin_r(username, 1025);
	std::string	h (hostname);
	std::string	u (username);
	_hostname = h;
	_username = u;
	module.openBox(_name, _enabled);
	if (_enabled){
		module.printTxt(_hostname);
		module.printTxt(_username);
	}
	module.closeBox();
}
