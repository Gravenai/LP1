#include "../include/Car.hpp"

Car::Car(){
	this->cor = cor;
	quantCar++;
}
Car::Car(std::string cor){
	this->cor = cor;
	quantCar++;
}

void Car::acelerar(int velocidade){
	this->velocidade += velocidade;
}
void Car::freiar(int velocidade){
	this->velocidade -= velocidade;
}
void Car::darPartida(){
	motor.darPartida();
}
