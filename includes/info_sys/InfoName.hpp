//
// EPITECH PROJECT, 2018
// InfoName.hpp
// File description:
// InfoName
//

#ifndef INFONAME_HPP_
#define INFONAME_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class 	InfoName	:	public IMonitorModule
{
public:
				InfoName();
	std::string		getName() 	const;
	void			dispValues(IMonitorDisplay &module);

private:
	const std::string	_name;
	std::string		_hostname;
	std::string		_username;
	bool			_enabled;
};

#endif
