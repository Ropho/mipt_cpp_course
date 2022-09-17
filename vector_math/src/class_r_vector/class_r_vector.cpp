#include "class_r_vector.hpp"


r_vector::r_vector (size_t mode, double first_param, double second_param) {

    set_last_upd (mode);

    switch (mode) {

        case PROJ:
            set_coord (first_param, second_param);
        break;

        case POLAR:
            set_rho (first_param);
            set_phi (grad_into_rad (second_param));
        break;

        default:
            perror ("UNDEFINED MODE, CONSTRUCTED WITH DEFAULT CTOR");

            r_vector {};

        break;
    }

    gen_color ();
    synch     ();
}


r_vector::r_vector (void) {

    set_coord (0, 0);
    set_rho (0);
    set_phi (0);

    set_last_upd (SYNCH);

    gen_color ();
}


r_vector::~r_vector () {
    set_coord (0, 0);
    set_rho (0);
    set_phi (0);
}


void r_vector::change_len (double len) {

    if (get_last_upd () == PROJ)
        synch ();

    set_rho (get_rho () + len);

    synch ();    
}


void r_vector::rotate (double phi) {

    if (get_last_upd () == PROJ)
        synch ();
    
    set_phi (get_phi () + grad_into_rad (phi));

    synch ();
}


void r_vector::print_coord () const {

    printf ("%.2f %.2f", get_x (), get_y ());
}