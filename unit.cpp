#include "unit.h"

unit::unit()
{
    ReadFile();
}

void unit::cppSlot(int x, int y, int index){
    emit cppSignal(index, ships[index]);
}

void unit::ReadFile(std::string path){
    std::ifstream in(path);
    if (in){
        for(int i=0; i<100; i++){
            char ch;
            in>>ch;
            ships[i]=std::atoi(&ch);
        }
    }
    else {
        qDebug()<<"Error read file";
    }

}
