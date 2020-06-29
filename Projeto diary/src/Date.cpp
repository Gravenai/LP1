#include "../include/Date.h"
#include <sstream>

Date::Date() : year(0), month(0), day(0)
{
}

void Date::set_from_string(const std::string& date){
	std::stringstream stream(date);
	char lixo;

	stream >> day;
	stream >> lixo;
	stream >> month;
	stream >> lixo;
	stream >> year;
	
}

std::string Date::to_string(){
	std::stringstream stream;

	if (day < 10){
		stream << '0';
	}
	stream << day;
	stream << '/';
	if (month < 10){
		stream << '0';
	}

	stream << month;
	stream << '/';
	stream << year;
	return stream.str();
}