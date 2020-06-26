#include "../include/Date.h"
#include <sstream>

Date::Date() : year(0), month(0), day(0)
{
}

void Date::set_from_string(const std::string& date){
	std::stringstream stream(date);
	char lixo;

	stream >> year;
	stream >> lixo;
	stream >> month;
	stream >> lixo;
	stream >> day;
	
}