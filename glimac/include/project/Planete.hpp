#pragma once
#include <iostream>
#include "Satellite.hpp"
#include "Astre.hpp"


#ifndef IMACGL_PLANETE_H
#define IMACGL_PLANETE_H


class Planete: public Astre {
private:
    float aphelion;
    float perihelion;
    int periode;
    float inclinaison;
    std::map<std::string,Satellite>satellites;



public:
    //getters

    float getAphelion() const;
    float getPerihelion() const;
    int getPeriode() const;
    float getInclinaison() const;
    const std::map<std::string, Satellite> &getSatellites() const;
    const Satellite getSatellite(std::string name);


    //setters
    void setAphelion(float aphelion);
    void setPerihelion(float perihelion);
    void setPeriode(int periode);
    void setInclinaison(float inclinaison);
    void setSatellites(const std::map<std::string, Satellite> &satellites);


    //constructeur
    Planete();
    Planete(std::string n_name, int n_diametre, float n_rot_propre,std::string n_type, float n_aphelion, float n_perihelion, int n_periode, float n_inclinaison);

    //methods
    using Astre::init_text;
    void init_text();
    void create_satellite( std::string n_name, int n_diametre, float n_rot_propre,int n_sm_axis, float n_eccentricite, float n_inclinaison,float plan_aphelion) override;
    int scale_diametre() override;
    void display_satellites();
};


#endif //IMACGL_PLANETE_H
