#pragma once
#include <iostream>
#include "Astre.hpp"
#include "Planete.hpp"

#ifndef IMACGL_SUN_H
#define IMACGL_SUN_H


class Soleil : public Astre {
private:
    Planete **planetes;
public:
    //getters
    Planete **getPlanetes() const;

    //setters
    void setPlanetes(Planete **planetes);

    //constructeur
    Soleil();
    Soleil( int n_diametre, float n_rot_propre);
};


#endif //IMACGL_SUN_H
