#include "../include/Diary.h"


std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { 
    return format_current_date("%d/%m/%Y"); }

std::string get_current_time() {
    return format_current_date("%H:%M:%S"); }

// ---------------------------------------------------------------------------------------------------------------

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];

    load();
    
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if (messages_size >= messages_capacity) {
        return;
    }

    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());

    messages[messages_size] = m;
    messages_size++;

    if (messages_size >= messages_capacity){
        updateCapacity();
    }

}

void Diary::write()
{   

    std::ofstream outputFile(filename);
    Date pointerDate = messages[0].date;

    outputFile << "# " << messages[0].date.to_string() << "\n";
    for (int i = 0; i < messages_size; i++){
        if (messages[i].date.to_string() == pointerDate.to_string()){
            outputFile << "- " << messages[i].time.to_string() << " " << messages[i].content << "\n";
        } else {

            outputFile << "\n" << "# " << messages[i].date.to_string() << "\n" 
            << "- " << messages[i].time.to_string() << " " << messages[i].content << "\n";
            pointerDate = messages[i].date;
        }
        
    }
    // gravar as mensagens no disco
}

void Diary::load(){
    std::ifstream readFile(filename);
    std::string line;
    int number = 0;

    Time auxTime;
    Date auxDate;
    char aux;
    std::string auxContent;

    while (getline(readFile, line)){
        std::stringstream stream(line);

        stream >> aux;
        if (aux == '#'){
            auxDate.set_from_string(line.substr(2,11));

        } else if (aux == '-') {
            if (line.length() != 0){
                stream >> auxContent;
                auxTime.set_from_string(auxContent);
                stream >> auxContent;
                
                auxContent = line.substr(11, line.length() - 1);
                
                Message m;
                m.content = auxContent;
                m.time = auxTime;
                m.date = auxDate;
                messages[messages_size] = m;
                messages_size++;
                if (messages_size >= messages_capacity){
                       updateCapacity();
                }
            }
        }
    }
}

void Diary::updateCapacity(){
    
    messages_capacity = messages_capacity * 2;
    Message *m = new Message[messages_capacity];
    for (int i = 0; i < messages_size; i++){
        m[i] = messages[i];
    }
    delete[] messages;
    messages = m;
    
}
