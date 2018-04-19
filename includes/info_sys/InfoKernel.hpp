//
// EPITECH PROJECT, 2018
// InfoKernel.hpp
// File description:
// InfoKernel
//

#ifndef INFOKERNEL_HPP_
#define INFOKERNEL_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class 	InfoKernel	:	public IMonitorModule
{
public:
				InfoKernel();
	std::string		getName() 	const;
	void			dispValues(IMonitorDisplay &module);

private:
	const std::string	_name;
	std::string		_osname;
	std::string		_kversion;
	bool			_enabled;
};

#endif
