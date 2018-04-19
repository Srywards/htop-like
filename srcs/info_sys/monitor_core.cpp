/*
** EPITECH PROJECT, 2018
** monitor_core
** File description:
** monitor_core cpp
*/

#include "monitor_core.hpp"
#include "Ncurses.hpp"

monitor_core::monitor_core()
	: display(true), _name("Core "), tymeMem(time(NULL) - 1)
{
	mem = new std::vector<unsigned int>;
}

monitor_core::~monitor_core()
{
	delete mem;
}

std::string monitor_core::getName() const
{
	return _name;
}

void	getProcessPercentage(std::string tmp, std::vector<unsigned int> &arr)
{
	std::istringstream	nom(tmp);
	std::string word;
	unsigned int	nb = 0;
	unsigned int	sum = 0;

	nom >> word;
	for (unsigned int i = 0; i < 7; i++) {
		nom >> word;
		if (i < 3)
			sum += atoi(word.c_str());
		nb += atoi(word.c_str());
	}
	arr.push_back(nb);
	arr.push_back(sum);
}

void	monitor_core::dispValues(IMonitorDisplay &module)
{
	unsigned int nthreads = std::thread::hardware_concurrency() + 1;
	std::string tmp;
	std::ifstream path("/proc/stat");
	std::vector<unsigned int> arr;

	module.openBox("Monitor Core", display);
	if (time(NULL) - tymeMem > 1) {
		for (unsigned int i = 0; i < nthreads; i++) {
			getline(path, tmp);
			getProcessPercentage(tmp, arr);
		}
		path.close();
		if (mem->size() == 0) {
			*mem = arr;
			tymeMem = time(NULL);
			return;
		}
		double nb;
		values.clear();
		for (unsigned int i = 0; i / 2 < nthreads && display; i += 2) {
			if (i == 0)
				module.printTxt("Core :");
			else
				module.printTxt(
					"Core " + std::to_string(i / 2) +
					" :");
			nb = (double) (arr[i + 1] - (*mem)[i + 1])
			     / (double) (arr[i] - (*mem)[i]) * 100;
			values.push_back((unsigned int)nb);
			module.printBar(100, (int) nb);
		}
		*mem = arr;
		tymeMem = time(NULL);
	}
	else
		for (unsigned int i = 0; i < values.size(); i++) {
			if (i == 0)
				module.printTxt("Core :");
			else
				module.printTxt(
					"Core " + std::to_string(i) +
					" :");
			module.printBar(100, (int) values[i]);
		}
	module.closeBox();
	/*usleep(500000);
	std::vector<unsigned int> arr2;
	path.open("/proc/stat");
	for (unsigned int i = 0; i < nthreads; i++) {
		getline(path, tmp);
		getProcessPercentage(tmp, arr2);
	}
	path.close();
	double	nb;
	module.openBox("Monitor Core", display);
	for (unsigned int i = 0; i / 2 < nthreads && display; i += 2) {
		if (i == 0)
			module.printTxt("Core :");
		else
			module.printTxt("Core " + std::to_string(i / 2) + " :");
		nb = (double)(arr2[i + 1] - arr[i + 1])
			/ (double)(arr2[i] - arr[i]) * 100;
		module.printBar(100, (int)nb);
	}
	module.closeBox();*/
}
