#include "class_r_vector.hpp"


r_vector::r_vector (double first_param, double second_param, double third_param) {


    set_coord (first_param, second_param, third_param);

    gen_color ();
}


r_vector::r_vector (void) {

    set_coord (0, 0, 0);

    gen_color ();
}


r_vector::~r_vector () {
    set_coord (0, 0, 0);
}


void r_vector::print_coord () const {

    printf ("x = %.2lf\t y = %.2lf\t z = %.2lf\n", get_x (), get_y (), get_z ());
}