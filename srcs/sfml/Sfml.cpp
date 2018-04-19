//
// EPITECH PROJECT, 2018
// sfml
// File description:
// sfml
//

#include "Sfml.hpp"
 	Sfml::Sfml()
	:	_window(sf::VideoMode(960, 1080), "Rush 3")
{
    	sf::Sprite sprite;
	sf::Texture texture;
	if (!texture.loadFromFile("srcs/space.png"))
		exit(84);
	_texture = texture;
	_sprite = sprite;
	 sf::Font font;
	if (!font.loadFromFile("srcs/arial.ttf"))
		exit(84);
	_sprite.setTexture(_texture);
	_font = font;
	_y = 1;
}

Sfml::~Sfml()
{

}
void 		Sfml::printBar(int max, int value)
{
	float 	w = (float)value / (float)max * 480.0;
	int 	wi = (int)w;
	sf::RectangleShape r(sf::Vector2f(480, HGEL / 2));
	sf::RectangleShape bar(sf::Vector2f((int)wi, HGEL / 2));
	bar.setFillColor(sf::Color(255, 0, 0));
	r.setFillColor(sf::Color(100, 100, 100));
	bar.setPosition(480 - 480 / 2, (_y * (HGEL / 2)) - (HGEL / 2));
	r.setPosition(480 - (480 / 2), (_y * (HGEL / 2)) - (HGEL / 2));
	_window.draw(r);
	_window.draw(bar);

	_y++;
}
void		Sfml::printTxt(std::string str)
{
	sf::Text text(str, _font, HTXT);
	text.setPosition(480 - 	text.getLocalBounds().width / 2,\
	(_y * (HGEL / 2)) - (HGEL / 2));
	sf::RectangleShape r(sf::Vector2f(480, HGEL / 2));
	r.setFillColor(sf::Color(150, 150, 150));
	r.setPosition(480 - (480 / 2), (_y * (HGEL / 2)) - (HGEL / 2));
	_window.draw(r);
	_window.draw(text);
	_y++;
}
void 		Sfml::openBox(std::string name, bool &ref)
{
	sf::Text titre(name, _font, HTXT);
	titre.setPosition(480 - titre.getLocalBounds().width / 2,\
	(_y * (HGEL / 2)) - (HGEL / 2));
	sf::RectangleShape r(sf::Vector2f(480, HGEL / 2));
	r.setFillColor(sf::Color(200, 100, 100));
	r.setPosition(480 - (480 / 2), (_y * (HGEL / 2)) - (HGEL / 2));
	_window.draw(r);
	_window.draw(titre);
	active.push_back(&ref);
	_y++;
}
void 		Sfml::refreshAll()
{
	_window.clear();
	_window.draw(_sprite);
	std::string	str = "";
}
void 		Sfml::closeBox()
{
	sf::RectangleShape r(sf::Vector2f(480, HGEL / 2));
	r.setFillColor(sf::Color(200, 100, 100));
	r.setPosition(480 - (480 / 2), (_y * (HGEL / 2)) - (HGEL / 2));
	_window.draw(r);
	_y+= 2;
}
void 		Sfml::initColors()
{

}
bool		Sfml::wait()
{
	_y = 1;
	rect.clear();

	if (_window.isOpen()){

	    sf::Event _event;
	     if (_window.pollEvent(_event)){

		     int 		nb = 0;
		     int 		r = sf::Event::KeyReleased;
		     nb = ((_event.type == r) && (_event.key.code == sf::Keyboard::A)) ? 1 : nb;
		     nb = ((_event.type == r) && (_event.key.code == sf::Keyboard::Z)) ? 2 : nb;
		     nb = ((_event.type == r) && (_event.key.code == sf::Keyboard::E)) ? 3 : nb;
		     nb = ((_event.type == r) && (_event.key.code == sf::Keyboard::R)) ? 4 : nb;
		     nb = ((_event.type == r) && (_event.key.code == sf::Keyboard::T)) ? 5 : nb;
		     nb = ((_event.type == r) && (_event.key.code == sf::Keyboard::Y)) ? 6 : nb;
		     nb = ((_event.type == r) && (_event.key.code == sf::Keyboard::U)) ? 7 : nb;
		     if (nb > 0) {
			     if (nb - 1 < (int)active.size()) {
				     *active[nb - 1] = !(*active[nb - 1]);

			     }
		     }

	     if (_event.key.code == sf::Keyboard::Escape ||\
		     _event.type == sf::Event::Closed){
			_window.close();
			exit(0);
			}
	     }
	     active.clear();

	    _window.display();
	}
	return true;
}
