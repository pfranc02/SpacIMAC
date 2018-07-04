#include "project/Astre.hpp"
#include "../../include/project/Astre.hpp"

//getters
const std::string &Astre::getName() const {
    return name;
}
int Astre::getDiametre() const {
    return diametre;
}

float Astre::getRot_propre() const {
    return rot_propre;
}

int Astre::getPos_x() const {
    return pos_x;
}

int Astre::getPos_y() const {
    return pos_y;
}

Texte *Astre::getAstre_infos() const {
    return astre_infos;
}

const std::string &Astre::getType() const {
    return type;
}

//setters
void Astre::setName(const std::string &Name) {
    Astre::name = Name;
}

void Astre::setDiametre(int diametre) {
    Astre::diametre = diametre;
}

void Astre::setRot_propre(int rot_propre) {
    Astre::rot_propre = rot_propre;
}

void Astre::setPos_x(int pos_x) {
    Astre::pos_x = pos_x;
}

void Astre::setPos_y(int pos_y) {
    Astre::pos_y = pos_y;
}

void Astre::setAstre_infos(Texte *astre_infos) {
    Astre::astre_infos = astre_infos;
}

void Astre::setType(const std::string &type) {
    Astre::type = type;
}

//constructors
Astre::Astre() {

}

Astre::Astre(std::string n_name, int n_diametre,std::string n_type, float n_rot_propre, int n_pos_x, int n_pos_y) {
    name = n_name;
    diametre = n_diametre;
    type = n_type;
    rot_propre = n_rot_propre;
    pos_x = n_pos_x;
    pos_y = n_pos_y;
}

void Astre::display_infos() const {
    update_position_infos();
    astre_infos->display_infos();
}

void Astre::update_position_infos() const {
    astre_infos->set_case_infos(4,"Abscisse: " + std::to_string(pos_x));
    astre_infos->set_case_infos(5,"Ordonnée: " + std::to_string(pos_y));
}

void Astre::init_text(){
    astre_infos = new Texte();
    astre_infos->set_case_infos(0, name);
    astre_infos->set_case_infos(1,"Type: " + type);
    astre_infos->set_case_infos(2,"Diametre: " + std::to_string(diametre));

    astre_infos->set_case_infos(3,"Rotation propre: " + std::to_string(rot_propre));
    astre_infos->set_case_infos(4,"Abscisse: " + std::to_string(pos_x));
    astre_infos->set_case_infos(5,"Ordonnee: " + std::to_string(pos_y));
    astre_infos->display_infos();

}



int Astre::scale_diametre() {
    return 0;
}

void
Astre::create_satellite(std::string n_name, int n_diametre, float n_rot_propre, int n_sm_axis, float n_eccentricite,
                        float n_inclinaison, float plan_aphelion) {

}

