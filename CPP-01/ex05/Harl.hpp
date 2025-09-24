#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	// Type de pointeur vers fonction membre
	typedef void (Harl::*HarlFunctionPtr)(void);

	// Tableau de paires (niveau, pointeur)
	static			HarlFunctionPtr levels[];
	static const	std::string 	levelNames[];

public:
	Harl();
	void complain(std::string level);
};

#endif