#include "class_kernel.hpp"

/////////////////////////////////////////////////KERNEL


void kernel::synch () {

    switch (get_last_upd ()) {

        case SYNCH:
        break;

        case POLAR:
            x_ = rho_ * cos (phi_);
            y_ = rho_ * sin (phi_);

            last_upd = SYNCH;
        break;

        case PROJ:
            rho_ = get_length ();
            phi_ = atan2 (y_, x_);

            last_upd = SYNCH;
        break;

        default:
            fprintf (stderr, "UNDEFINED STATUS %d", __LINE__);
        break;
    }    
}


double kernel::get_length () const {
    
    if (get_last_upd () == SYNCH || get_last_upd () == POLAR) {
        return get_rho ();
    }
    else {
        return sqrt (get_x () * get_x () + get_y () * get_y ());
    }
}
