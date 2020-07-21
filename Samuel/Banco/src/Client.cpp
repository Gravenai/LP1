#include "../include/Client.hpp"

int Client::quantClient;

Client::Client(std::string name){
	this->name = name;
	this->quantClient++;
}

std::string Client::getName(){
	return name;
}

void Client::setName(std::string name){
	this->name = name;
}

Bank Client::getAgency(){
	return agency;
}

void Client::setAgency(Bank bank){
	this->agency = bank;
}