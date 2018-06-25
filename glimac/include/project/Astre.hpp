#pragma once
#include <iostream>
#include <string>
#include "Texte.hpp"
#ifndef IMACGL_ASTRE_H
#define IMACGL_ASTRE_H


class Astre {
private:
    std::string type;
    std::string name;
    int diametre;
    float rot_propre;
    Texte *astre_infos;
    int pos_x;
    int pos_y;

public:
    //getters
    const std::string &getName() const;
    int getDiametre() const;
    float getRot_propre() const;
    int getPos_x() const;
    int getPos_y() const;
    Texte *getAstre_infos() const;
    const std::string &getType() const;

    //setters
    void setName(const std::string &Name);
    void setDiametre(int diametre);
    void setRot_propre(int rot_propre);
    void setPos_x(int pos_x);
    void setPos_y(int pos_y);
    void setAstre_infos(Texte *astre_infos);
    void setType(const std::string &type);

    //constructor
    Astre();
    Astre(std::string n_name, int n_diametre,std::string n_type, float n_rot_propre, int n_pos_x, int n_pos_y);

    //methods
    void update_position_infos() const;
    virtual void init_text();
    void display_infos() const;
    virtual void create_satellite( std::string n_name, int n_diametre, float n_rot_propre, int n_sm_axis, float n_eccentricite, float n_inclinaison, float plan_aphelion);
    virtual int scale_diametre();

};


#endif //IMACGL_ASTRE_H
