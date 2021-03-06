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

Diary::Diary() : messages_size(0), messages_capacity(10)
{
    updateConfig();
    load();
    
}

Diary::~Diary()
{
    
}

void Diary::add(const std::string& message)
{

    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());

    messages.push_back(m);
    messages_size++;

}

void Diary::write()
{   

    std::ofstream outputFile(path);
    Date pointerDate = messages[0].date;

    outputFile << "# " << messages[0].date.to_string() << "\n";
    for (size_t i = 0; i < messages_size; i++){
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

std::vector<std::string> Diary::list(std::string formatSend){
    std::vector<std::string> auxVector;
    for (size_t i = 0; i < messages_size; ++i) {
        std::stringstream streamRead(formatSend);
        std::stringstream streamOutput;
        char aux;
        while(aux = streamRead.get(), streamRead){

            if (aux == '%'){
                streamRead >> aux;
                switch (aux){
                    case 'd':
                        streamOutput << messages[i].date.to_string();
                    break;
                    case 't':
                        streamOutput << messages[i].time.to_string();
                    break;
                    case 'm':
                        streamOutput << messages[i].content;
                    break;
                    default:
                        streamOutput << "%" << aux; 
                    break;
                }
            } else {
                streamOutput << aux;
            }
        }
        streamOutput << "\n";
        auxVector.push_back(streamOutput.str());
    }
    return auxVector;
}

void Diary::load(){
    std::ifstream readFile(path);
    std::string line;
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
                messages.push_back(m);
                messages_size++;
                
            }
        }
    }
}

void Diary::updateConfig(){
    std::ifstream config("diary.config");
    if (config.is_open()){
        std::string line;
        getline(config, line);
        path = line.substr(5, line.length() - 1);
        getline(config, line);
        format = line.substr(15, line.length() - 1);
    } else {
        std::ofstream createFile("diary.config");
        createFile <<  "path=diary.md\ndefault_format=%d %t: %m\n";
        path = "diary.md";
        format = "%d %t: %m";
    }
}

std::vector<Message*> Diary::search(const std::string& findString) {
    std::vector<Message*> aux;
    for (auto& i : messages){
        int equal = -1;

        equal = i.content.find(findString);
        if (equal != -1){
            aux.push_back(&i);

        }
    }

    return aux;
}