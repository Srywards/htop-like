//
// EPITECH PROJECT, 2018
// InfoRam.hpp
// File description:
// InfoRam
//

#ifndef INFORAM_HPP_
#define INFORAM_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class 	InfoRam	:	public IMonitorModule
{
public:
				InfoRam();
	std::string		getName() 	const;
	void			dispValues(IMonitorDisplay &module);

private:
	const std::string	_name;
	std::string		_mem;
	std::string		_total;
	bool			_enabled;
};

#endif
