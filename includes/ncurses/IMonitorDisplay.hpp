//
// EPITECH PROJECT, 2018
// IMonitorDisplay.hpp
// File description:
// IMonitorDisplay
//

#ifndef IDISPLAY
#define IDISPLAY

#include <iostream>

class 			IMonitorDisplay
{
public:
	virtual void	printBar(int max, int value) = 0;
	virtual void	printTxt(std::string str) = 0;
	virtual void	openBox(std::string name, bool &ref) = 0;
	virtual void	refreshAll() = 0;
	virtual void	closeBox() = 0;
	virtual void	initColors() = 0;
	virtual bool	wait() = 0;
};

#endif
