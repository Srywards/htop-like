#include "InfoNetwork.hpp"
#include "Ncurses.hpp"
#include "InfoNetwork.hpp"

InfoNetwork::InfoNetwork()
	:	_name("Network"),
		_enabled(true)
{
	_second = (int)time(NULL);
	_packets = 0;
	_nb = 0;
}

InfoNetwork::~InfoNetwork()
{
}

std::string			InfoNetwork::getName() 	const
{
	return _name;
}

void	InfoNetwork::dispValues(IMonitorDisplay &module)
{
	std::ifstream	file("/proc/net/dev");
	std::string	line;
	std::string	word;
	std::istringstream	stream;
	double		speedUp = 0;
	double		speedDown = 0;

	module.openBox(_name, _enabled);
	std::getline(file, line);
	std::getline(file, line);
	for (int i = 0; _enabled && std::getline(file, line); i++) {
		stream.str(line);
		stream >> word;
		module.printTxt(word);
		stream.clear();
		stream >> word;
		speedDown = (double)atoi(word.c_str()) / 1000000.0;
		for (int i = 0; i < 8; i++)
			stream >> word;
		speedUp = (double)atoi(word.c_str()) / 1000000.0;
		_second = time(NULL);
			module.printTxt(std::to_string(speedDown)
					+ "Mb-down  "
					+ std::to_string(speedUp) +
						"Mb-up");
	}
	module.closeBox();
	file.close();
}
