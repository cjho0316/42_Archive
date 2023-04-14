#include "Harl.hpp"

void Harl::debug(void){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::stfu(void){
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complainSwitch(std::string str){
	void (Harl::*fp[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std:: string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int idx = -1;

	for(int i = 0; i < 4 ; i++){
		if (level_arr[i] == str){
			idx = i;
			break ;
		}
	}

	switch(idx) {
		case 0: (this->*fp[0])();
		case 1: (this->*fp[1])();
		case 2: (this->*fp[2])();
		case 3: (this->*fp[3])(); break;
		default: (this->Harl::stfu)();
	}
}


