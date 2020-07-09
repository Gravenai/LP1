#ifndef CAR_H
#define CAR_H

#include <string>
#include "Motor.hpp"

class Car{
	public:
		int static quantCar;
		std::string tipo;
	    std::string placa;
	    int numPortas;
	    std::string cor;
	    int velocidade;
	    Motor motor;

	    Car();
	    Car(std::string cor);

	    void acelerar(int velocidade);
	    void freiar(int velocidade);
	    void darPartida();

};

#endif