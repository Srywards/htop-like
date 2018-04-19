//
// Created by julien on 20/01/18.
//

#ifndef CPP_RUSH3_NCURSES_HPP
#define CPP_RUSH3_NCURSES_HPP

#include <curses.h>
#include <iostream>
#include <vector>
#include "IMonitorDisplay.hpp"

#define BOXSIZE 40

class 			Ncurses : public IMonitorDisplay
{
public:
	Ncurses();
	~Ncurses();
	void 		printBar(int max, int value);
	void		printTxt(std::string str);
	void 		openBox(std::string name, bool &ref);
	void 		refreshAll();
	void 		closeBox();
	void 		initColors();
	bool		wait();

private:
	int 		x;
	int 		y;
	std::vector<bool *>	active;
};

#endif //CPP_RUSH3_NCURSES_HPP
