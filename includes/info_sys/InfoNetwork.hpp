//
// EPITECH PROJECT, 2018
// InfoNetwork.hpp
// File description:
// InfoNetwork
//

#ifndef INFONETWORK_HPP_
#define INFONETWORK_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

class 	InfoNetwork	:	public IMonitorModule
{
public:
	InfoNetwork();
	~InfoNetwork();
	std::string		getName() 	const;
	void			dispValues(IMonitorDisplay &module);

private:
	const std::string	_name;
	std::string		_ip;
	int 			_second;
	int 			_packets;
	bool			_enabled;
	int 			_nb;
	std::vector<unsigned int>	*lastSpeedUp;
	std::vector<unsigned int>	*lastSpeedDown;
};

#endif
