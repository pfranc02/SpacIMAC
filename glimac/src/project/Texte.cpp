#include "project/Texte.hpp"
#include <stdio.h>



//setters

//constructors
Texte::Texte() {

}

//methods
void Texte::display_infos() {
    int i =0;
    while(infos[i] != "\0"){
      //  std::cout << infos[i] << std::endl;
        i++;
    }
}

void Texte::set_case_infos(int i, std::string n_infos) {
    infos[i] = n_infos;
}




