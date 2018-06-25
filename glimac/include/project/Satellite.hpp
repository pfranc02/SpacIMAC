#pragma once
#include <iostream>
#include "Astre.hpp"
#include <map>

#ifndef IMACGL_SATELLITE_H
#define IMACGL_SATELLITE_H


class Satellite : public Astre {
private:
    int sm_axis;
    float eccentricite;
    float inclinaison;

public:
    //getters
    int getSm_axis() const;
    float getEccentricite() const;
    float getInclinaison() const;

    //setters
    void setSm_axis(int sm_axis);
    void setEccentricite(float eccentricite);
    void setInclinaison(float inclinaison);

    //constructor
    Satellite();
    Satellite(int n_sm_axis, float n_eccentricite, float n_inclinaison, std::string n_name, int n_diametre, float n_rot_propre,float plan_aphelion);

    //methods
    void init_texte_satellite();
};


#endif //IMACGL_SATELLITE_H
