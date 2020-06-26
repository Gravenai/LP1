#include "../include/Time.h"
#include <sstream>

Time::Time() : hour(0), minute(0), second(0){

}

void Time::set_from_string(const std::string& time){
	std::stringstream stream(time);
	char lixo;

	stream >> hour;
	stream >> lixo;
	stream >> minute;
	stream >> lixo;
	stream >> second;

}