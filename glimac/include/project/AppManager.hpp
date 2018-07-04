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
    std::map<std::string,Planete>systeme_solaire; //map contenant les informations des planètes
    Time* time; // temps permettant de gérer la vitesse de déplacement des planètes

public:
    //getters
    const std::map<std::string,Planete> &getSysteme_solaire() const;
    const Astre getAstre(std::string name);
    const Planete getPlanet(std::string name);
    Time *getTime() const;
    Soleil *getSoleil() const;


    //setters
    void setTime(Time *time);
    void setSoleil(Soleil *soleil);
    void setSysteme_solaire(const std::map<std::string, Planete> &systeme_solaire);

    //constructor
    AppManager();

    //methods
    void initier_system(); // déclanche les 4 fonctions suivantes
    void initier_soleil();
    void initier_planete();
    void initier_planete_texte();
    void initier_satellite();
    void create_planete(std::string n_name, int n_diametre, float n_rot_propre,std::string n_type, float n_aphelion, float n_perihelion, int n_periode, float n_inclinaison); // crée la map "sysem" avec les planètes
    float scale_distance(Planete p); //fonction  modifiant la taille de certaines planètes afin d'avoir un affichage compréhensible
};


#endif //IMACGL_APPMANAGER_H
