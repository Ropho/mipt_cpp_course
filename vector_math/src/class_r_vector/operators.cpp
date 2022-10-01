#include "class_r_vector.hpp"


/////////////////////////////////////////////////ADD
r_vector operator+ (const r_vector& vec1, const r_vector& vec2) {

    r_vector vec_init (PROJ, vec1.get_x () + vec2.get_x (), vec1.get_y () + vec2.get_y ());

    return vec_init;
}


r_vector operator+ (const r_vector& vec, double num) {

    double x_init = vec.get_x () + num;
    double y_init = vec.get_y () + num;

    r_vector vec_init (PROJ, x_init, y_init);

    return vec_init;
}


/////////////////////////////////////////////////SUB
r_vector operator- (const r_vector& vec1, const r_vector& vec2) {

    r_vector vec_init (PROJ, vec1.get_x () - vec2.get_x (), vec1.get_y () - vec2.get_y ());

    return vec_init;
}


r_vector operator- (const r_vector& vec, double num) {
    
    // CHECK_SYNCH_PROJ (vec);

    double x_init = vec.get_x () - num;
    double y_init = vec.get_y () - num;

    r_vector vec_init (PROJ, x_init, y_init);

    return vec_init;
}


/////////////////////////////////////////////////SCALAR MUL
double operator* (const r_vector& vec1, const r_vector& vec2) {
    
    return (vec1.get_x () * vec2.get_x () + vec1.get_y () * vec2.get_y ());
}


r_vector operator* (const r_vector& vec, double num) {
    
    double phi = 0;
    
    r_vector vec_ret = vec;
    vec_ret.synch ();

    if (num >= 0)
        phi = vec_ret.get_phi ();
    else
        phi = grad_into_rad (180) + vec_ret.get_phi ();

    vec_ret.set_rho (vec.get_rho () * abs (num));
    vec_ret.set_phi (phi);
    
    vec_ret.synch ();

    return vec_ret;
}


r_vector operator/ (const r_vector& vec, double num) {
    
    double phi = 0;

    if (num == 0) {
        fprintf (stderr, "DIVISION BY ZERO");
        return r_vector {};
    }

    if (num > 0)
        phi = vec.get_phi ();
    else if (num)
        phi = grad_into_rad (180) + vec.get_phi ();

    r_vector vec_ret (POLAR, vec.get_rho () / abs (num), rad_into_grad (phi));

    return vec_ret;
}
/////////////////////////////////////////////////ANGLE BETWEEN
double operator^ (const r_vector& vec1, const r_vector& vec2) {
    
    return rad_into_grad (acos ((vec1 * vec2) / (vec1.get_length () * vec2.get_length ())));
}


// /////////////////////////////////////////////////ASSIGNMENT
r_vector& r_vector::operator= (const r_vector& vec) {

    set_coord   (vec.get_x (), vec.get_y ());
    set_rho     (vec.get_rho ());
    set_phi     (vec.get_phi ());

    set_last_upd (vec.get_last_upd ());

    return *this;
}
// x=y=z=a=r=t;

//NEED UPDATE FOR COMPARE FUNCTIONS
/////////////////////////////////////////////////COMPARE
// bool operator== (r_vector vec1, r_vector vec2) {
    // return (vec1.get_x () == vec2.get_x () && vec1.get_y () == vec2.get_y ());
// }

