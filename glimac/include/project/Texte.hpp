#pragma once
#include <iostream>
#include <string>
#ifndef IMACGL_TEXTE_H
#define IMACGL_TEXTE_H


class Texte {
private:
    std::string infos[10];

public:
    //getters


    //setters


    //constructor
    Texte();

    //methods
    void display_infos();
    void set_case_infos(int i, std::string n_infos);
};


#endif //IMACGL_TEXTE_H
