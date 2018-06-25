//
// Created by Admin on 02/04/2018.
//

#include "project/Soleil.hpp"
//getters
Planete **Soleil::getPlanetes() const {
    return planetes;
}

//setters
void Soleil::setPlanetes(Planete **planetes) {
    Soleil::planetes = planetes;
}

//constructors
Soleil::Soleil() {

}

Soleil::Soleil(int n_diametre, float n_rot_propre) :Astre("soleil",n_diametre,"Etoile",n_rot_propre,0,0) {

}

