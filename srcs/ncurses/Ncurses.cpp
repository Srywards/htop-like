/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** ncurses
*/

#include "../../includes/ncurses/Ncurses.hpp"
#include "../../includes/info_sys/IMonitorModule.hpp"
#include <stdio.h>
#include <stdlib.h>

void		Ncurses::initColors()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
}

Ncurses::Ncurses():
	x(0), y(0)
{
	initscr();
	if(has_colors() == FALSE) {
		endwin();
		std::cerr << "Your terminal does not support color\n";
		exit(1);
	}
	timeout(100);
	curs_set(0);
	start_color();
	initColors();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}

Ncurses::~Ncurses()
{
	endwin();
}

/*void		Ncurses::printBox(int sx, int sy)
{
	(void)sx;
	(void)sy;
}*/

void 		Ncurses::refreshAll()
{
	x = 0;
	y = 0;
	active.clear();
}

void 		Ncurses::openBox(std::string name, bool &ref)
{
	int	sx = (BOXSIZE - name.size()) / 2;
	int	i = x;

	for (; i < x + sx; i++) {
		mvprintw(y, i, "-");
	}
	mvprintw(y, i, name.c_str());
	i += name.size();
	for (; (unsigned int)i < x + (sx * 2) + name.size(); i++) {
		mvprintw(y, i, "-");
	}
	if (name.size() % 2 != 0)
		mvprintw(y, i, "-");
	y++;
	active.push_back(&ref);
	refresh();
}

void		Ncurses::printTxt(std::string str)
{
	int 	i = x + 1;
	int	sx = (BOXSIZE - str.size()) / 2;

	mvprintw(y, x, "|");
	for (; i < x + sx; i++) {
		mvprintw(y, i, " ");
	}
	mvprintw(y, i, str.c_str());
	i += str.size();
	for (; (unsigned int)i < x + (sx * 2) + str.size() - 1; i++) {
		mvprintw(y, i, " ");
	}
	if (str.size() % 2 != 0) {
		mvprintw(y, i, " ");
		i++;
	}
	mvprintw(y, i, "|");
	refresh();
	y++;
}

void 		Ncurses::closeBox()
{
	for (int i = x; i < x + BOXSIZE; i++) {
		mvprintw(y, i, "-");
	}
	y += 2;
	refresh();
}

void		Ncurses::printBar(int max, int value)
{
	int 	i;

	value = value * (BOXSIZE - 4) / max;
	mvprintw(y, x, "|[");
	for (i = x + 2; i < x + BOXSIZE - 2; i++) {
		if (i < x + value) {
			attron(COLOR_PAIR(1));
			mvprintw(y, i, "|");
			attroff(COLOR_PAIR(1));
		} else
			mvprintw(y, i, " ");
	}
	mvprintw(y, i, "]|");
	refresh();
	y++;
}

bool		is_correctNumber(char c)
{
	if (c <= '7' && c >= '1')
		return true;
	return false;
}

bool		Ncurses::wait()
{
	std::string	str = "";
	int 		nb;

	str += getch();
	if (str[0] > 0 && is_correctNumber(str[0])) {
		nb = atoi(str.c_str());
		if (nb - 1 < (int)active.size()) {
			*active[nb - 1] = !(*active[nb - 1]);
			clear();
		}
//		mvprintw(0, 60, "%d", active[nb - 1]);
	}
	if (str[0] == 'q')
		return false;
	return true;
}
