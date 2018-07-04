#include "project/AppManager.hpp"
#include "../../include/project/AppManager.hpp"

//getters
const std::map<std::string, Planete> &AppManager::getSysteme_solaire() const {
    return systeme_solaire;
}

const Astre AppManager::getAstre(std::string name) {
  return systeme_solaire[name];
}

const Planete AppManager::getPlanet(std::string name) {
    return systeme_solaire[name];
}

Time *AppManager::getTime() const {
    return time;
}

Soleil *AppManager::getSoleil() const {
    return soleil;
}


//setters
void AppManager::setSysteme_solaire(const std::map<std::string, Planete> &systeme_solaire) {
    AppManager::systeme_solaire = systeme_solaire;
}

void AppManager::setTime(Time *time) {
    AppManager::time = time;
}

void AppManager::setSoleil(Soleil *soleil) {
    AppManager::soleil = soleil;
}

//constructor
AppManager::AppManager() {
    time = new Time();
}

void AppManager::initier_system() {
    initier_soleil();
    initier_planete();
    initier_satellite();
    initier_planete_texte();

}

void AppManager::initier_planete() {
    //distances divisées par 1000
    create_planete("Mercury",4879,59,"tellurique",69800,46000,88,7);
    create_planete("Venus",12104,243,"tellurique",108900,107500,225,3.4);
    create_planete("Earth",12756,0.99,"tellurique",152100,147100,365,0);
    create_planete("Mars",6792,1.05,"tellurique",249200,206600,687,1.9);
    create_planete("Jupiter",142984,0.41,"gazeuse",816600,740500,4331,1.3);
    create_planete("Saturn",120536,0.43,"gazeuse",1514500,1352600,10747,2.5);
    create_planete("Uranus",51118,0.71,"gazeuse",3003600,2741300,30589,0.8);
    create_planete("Neptune",49528,0.76,"gazeuse",4545700,4444500,59800,1.8);
    create_planete("Pluto",2370,3.39,"gazeuse",7375900,4436800,90560,17.2);

}

void AppManager::initier_planete_texte() {
    for(std::map<std::string,Planete>::iterator it = systeme_solaire.begin(); it!= systeme_solaire.end(); ++it){

        it->second.init_text();
    }
}

void AppManager::initier_satellite() {
    //Satellite de la Earth
    systeme_solaire["Earth"].create_satellite("Lune",3478,27.32,384400,0.0549,5.145,systeme_solaire["Earth"].getAphelion());

    //Satellites de Mars
    systeme_solaire["Mars"].create_satellite("Phobios",13,0.31891,9378,0.0151,1.08,systeme_solaire["Mars"].getAphelion());
    systeme_solaire["Mars"].create_satellite("Deimos",8,1.26244,23459,0.0005,1.79,systeme_solaire["Mars"].getAphelion());

    //Satellites de Jupiter
    systeme_solaire["Jupiter"].create_satellite("Callisto",4821,16.6,1882700,0.007,0.19,systeme_solaire["Jupiter"].getAphelion());
    systeme_solaire["Jupiter"].create_satellite("Ganymede",5262,7.15,1070400,0.001,0.18,systeme_solaire["Jupiter"].getAphelion());
    systeme_solaire["Jupiter"].create_satellite("Europa",3122,3.55,671100,0.009,0.47,systeme_solaire["Jupiter"].getAphelion());
    systeme_solaire["Jupiter"].create_satellite("Io",3643,1.76,421800,0.004,0.04,systeme_solaire["Jupiter"].getAphelion());

    //Satellites de Saturn
    systeme_solaire["Saturn"].create_satellite("Mimas",396,27.32,185520,0.0202,1.53,systeme_solaire["Saturn"].getAphelion());
    systeme_solaire["Saturn"].create_satellite("Enceladus",504,27.32,238020,0.0045,0,systeme_solaire["Saturn"].getAphelion());
    systeme_solaire["Saturn"].create_satellite("Tethys",1062,27.32,294660,0.0,1.86,systeme_solaire["Saturn"].getAphelion());
    systeme_solaire["Saturn"].create_satellite("Dione",1123,27.32,377400,0.0022,0.02,systeme_solaire["Saturn"].getAphelion());
    systeme_solaire["Saturn"].create_satellite("Rhea",1528,27.32,527040,0.0010,0.35,systeme_solaire["Saturn"].getAphelion());
    systeme_solaire["Saturn"].create_satellite("Titan",5151,27.32,1221830,0.0292,0.33,systeme_solaire["Saturn"].getAphelion());
    systeme_solaire["Saturn"].create_satellite("Hyperion",270,27.32,148100,0.1042,0.43,systeme_solaire["Saturn"].getAphelion());
    systeme_solaire["Saturn"].create_satellite("Iapetus",1469,27.32,3561300,0.0283,14.72,systeme_solaire["Saturn"].getAphelion());

    //Satellites d'Uranus
    systeme_solaire["Uranus"].create_satellite("Miranda",472,27.32,129900,0.0013,4.34,systeme_solaire["Uranus"].getAphelion());
    systeme_solaire["Uranus"].create_satellite("Ariel",1158,27.32,199900,0.0012,0.04,systeme_solaire["Uranus"].getAphelion());
    systeme_solaire["Uranus"].create_satellite("Umbriel",1169,27.32,266000,0.0039,0.13,systeme_solaire["Uranus"].getAphelion());
    systeme_solaire["Uranus"].create_satellite("Titania",1577,8.706,436300,0.0011,0.08,systeme_solaire["Uranus"].getAphelion());
    systeme_solaire["Uranus"].create_satellite("Oberon",1523,27.32,583500,0.0014,0.07,systeme_solaire["Uranus"].getAphelion());


    //Satellites de Neptune
    systeme_solaire["Neptune"].create_satellite("Triton",2707,5.877,384400,0.0549,5.145,systeme_solaire["Neptune"].getAphelion());
    systeme_solaire["Neptune"].create_satellite("Nereid",340,360.14,384400,0.0549,5.145,systeme_solaire["Neptune"].getAphelion());

    //Satellite de Pluto
    systeme_solaire["Pluto"].create_satellite("Charon",1212,6.3,384400,0.0549,5.145,systeme_solaire["Neptune"].getAphelion());



}

void AppManager::initier_soleil() {
    soleil = new Soleil(1391400,27);
}

void AppManager::create_planete(std::string n_name, int n_diametre, float n_rot_propre, std::string n_type, float n_aphelion,
                           float n_perihelion, int n_periode, float n_inclinaison) {
    if(n_type == "tellurique"){
        systeme_solaire[n_name] = Planete_tellurique(n_name,n_diametre, n_rot_propre, n_aphelion, n_perihelion, n_periode, n_inclinaison);
    }
    if(n_type == "gazeuse"){
        systeme_solaire[n_name] = Planete_gazeuse(n_name,n_diametre, n_rot_propre, n_aphelion, n_perihelion, n_periode, n_inclinaison);
    }
}

float AppManager::scale_distance(Planete p) {
    float distance = 1.5;
    for(std::map<std::string,Planete>::iterator it = systeme_solaire.begin(); it!= systeme_solaire.end(); ++it){
        if(p.getAphelion() > it->second.getAphelion()){
            distance += it->second.getDiametre()/100000 + 1.3;

        }
    }
    return distance;
}










