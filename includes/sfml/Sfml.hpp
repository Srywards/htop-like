//
// Created by julien on 20/01/18.
//

#ifndef CPP_RUSH3_SFML_HPP
#define CPP_RUSH3_SFML_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include "IMonitorDisplay.hpp"

#define HGEL 	40
#define HTXT 	15

class 			Sfml : public IMonitorDisplay
{
public:
			Sfml();
			~Sfml();
	void 		printBar(int max, int value);
	void		printTxt(std::string str);
	void 		openBox(std::string name, bool &ref);
	void 		refreshAll();
	void 		closeBox();
	void 		initColors();
	bool		wait();

private:
	sf::RenderWindow			_window;
	sf::Sprite				_sprite;
	sf::Font				_font;
	sf::Texture				_texture;
	int 					_y;
	sf::Event 				_event;
	std::vector<sf::RectangleShape> 	rect;
	std::vector<bool *>			active;
};

#endif //CPP_RUSH3_Sfml_HPP
