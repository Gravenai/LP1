#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

	struct Time {
		int hou;
		int min;
		int sec;

		std::string toString();
	};

	struct Date{
		int year;
		int mont;
		int day;

		std::string toString();
	};

	struct Message{
		Date date;
		Time time;
		std::string content;

		int compareDateMessages(const Message &message);
		/*  Retorne 1 para caso essa menssagem seja mais nova
			Retorne 0 para caso as mensagens tenham datas iguais
			Retorne -1 para caso essa mensagem seja mais velha
		*/
		std::string toString();
	}

	struct Diary{
		std::vector<Message>;

		std::vector<Message> getAllMessages();
		std::vector<Message> findByDate(Date date);
		//Mensagens entre um data inicial e uma final
		std::vector<Message> findByMarge(Date initial_date, Date final_date, Time initial_time, Time final_time);
		Message addMessage(const Message &message);
		void removeMessage(int id);
		void removeMessage(Date date, Time time);
		Date getLastDate();

		//Não tenho certeza da necessidade da função abaixo
		//std::string toString();
	};

	struct Output{

		void printMessages(vector<Message>);
		void printUse();
		void printError();
		void printOther(std::string);
	};

#endif