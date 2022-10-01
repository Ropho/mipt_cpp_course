#include "class_r_vector.hpp"


r_vector r_vector::get_perpendicular () const {

    r_vector perp (get_y () * get_y () / get_x (), -get_y (), 0);

    return perp;
}

r_vector r_vector::get_norm_perpendicular () const {

    return get_perpendicular () / get_length ();
}

// void r_vector::change_len (double len) {

//     if (get_last_upd () == PROJ)
//         synch ();

//     set_rho (get_rho () + len);

//     synch ();    
// }


// void r_vector::rotate (double phi) {

//     assert (0);
//     //REDO!!

//     if (get_last_upd () == PROJ)
//         synch ();
    
//     set_phi (get_phi () + grad_into_rad (phi));

//     synch ();
// }


void r_vector::print_coord () const {

    printf ("%.2f %.2f %.2f", get_x (), get_y (), get_z ());
}