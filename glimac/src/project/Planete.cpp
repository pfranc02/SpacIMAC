#include <map>
#include "project/Planete.hpp"

//getters
float Planete::getAphelion() const {
    return aphelion;
}

float Planete::getPerihelion() const {
    return perihelion;
}

int Planete::getPeriode() const {
    return periode;
}

float Planete::getInclinaison() const {
    return inclinaison;
}

const Satellite getSatellite(std::string name){
    return satellites[name];
}

const std::map<std::string, Satellite> &Planete::getSatellites() const {
    return satellites;
}


//Setters
void Planete::setAphelion(float aphelion) {
    Planete::aphelion = aphelion;
}

void Planete::setPerihelion(float perihelion) {
    Planete::perihelion = perihelion;
}

void Planete::setPeriode(int periode) {
    Planete::periode = periode;
}

void Planete::setInclinaison(float inclinaison) {
    Planete::inclinaison = inclinaison;
}

void Planete::setSatellites(const std::map<std::string, Satellite> &satellites) {
    Planete::satellites = satellites;
}

//constructor
Planete::Planete() {

}

Planete::Planete(std::string n_name, int n_diametre, float n_rot_propre, std::string n_type, float n_aphelion, float n_perihelion, int n_periode, float n_inclinaison) : Astre(n_name, n_diametre, n_type, n_rot_propre, n_aphelion,0) {
    aphelion = n_aphelion;
    perihelion = n_perihelion;
    periode = n_periode;
    inclinaison = n_inclinaison;
}

void Planete::init_text() {
    Astre::init_text();
    getAstre_infos()->set_case_infos(6,"Aphelion : " + std::to_string(aphelion));
    getAstre_infos()->set_case_infos(7,"Perihelion: " + std::to_string(perihelion));
    getAstre_infos()->set_case_infos(8,"Periode: " + std::to_string(periode));
    getAstre_infos()->set_case_infos(9,"Inclinaison: " + std::to_string(inclinaison));

}

void Planete::create_satellite( std::string n_name, int n_diametre, float n_rot_propre, int n_sm_axis, float n_eccentricite, float n_inclinaison,float plan_aphelion) {
    satellites["n_name"] =  Satellite(n_sm_axis,n_eccentricite,n_inclinaison,n_name,n_diametre,n_rot_propre,plan_aphelion);

}

int Planete::scale_diametre() {
    if(getDiametre() > 40000){
        return getDiametre()/4;
    }
    return getDiametre();
}

void Planete::display_satellites() {
    for(std::map<std::string,Satellite>::iterator it = satellites.begin(); it != satellites.end(); it++){
        std::cout << it->second.getName();
    }
}


