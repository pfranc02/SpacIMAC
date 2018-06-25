#pragma once
#include <iostream>
#include <map>
#include "Planete_gazeuse.hpp"
#include "Planete_tellurique.hpp"
#include "Soleil.hpp"
#include "Satellite.hpp"
#include "time.hpp"
#ifndef IMACGL_APPMANAGER_H
#define IMACGL_APPMANAGER_H


class AppManager {
private:
    Soleil* soleil;
    std::map<std::string,Planete>systeme_solaire;
    Time* time;

public:
    //getters
    const std::map<std::string,Planete> &getSysteme_solaire() const;
    const Astre getAstre(std::string name);
    const Planete getPlanet(std::string name);
    Time *getTime() const;
    void setTime(Time *time);

    Soleil *getSoleil() const;

    void setSoleil(Soleil *soleil);

    //setters
    void setSysteme_solaire(const std::map<std::string, Planete> &systeme_solaire);

    //constructor
    AppManager();

    //methods
    void initier_system();
    void initier_soleil();
    void initier_planete();
    void initier_planete_texte();
    void initier_satellite();
    void create_planete(std::string n_name, int n_diametre, float n_rot_propre,std::string n_type, float n_aphelion, float n_perihelion, int n_periode, float n_inclinaison);
    float scale_distance(Planete p);
};


#endif //IMACGL_APPMANAGER_H
