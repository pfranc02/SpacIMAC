#pragma once
#include <iostream>
#include "Planete.hpp"
#ifndef IMACGL_PLANETE_GAZEUZE_H
#define IMACGL_PLANETE_GAZEUZE_H


class Planete_gazeuse : public Planete{

public:
    Planete_gazeuse(std::string n_name, int n_diametre, int n_rot_propre, float n_aphelion, float n_perihelion, int n_periode, float n_inclinaison);
};


#endif //IMACGL_PLANETE_GAZEUZE_H
