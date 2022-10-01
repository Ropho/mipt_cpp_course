#include "class_r_vector.hpp"

/////////////////////////////////////////////////ADD
r_vector operator+ (const r_vector& vec1, const r_vector& vec2) {

    r_vector vec_init (vec1.get_x () + vec2.get_x (), vec1.get_y () + vec2.get_y (), vec1.get_z () + vec2.get_z ());

    return vec_init;
}

/////////////////////////////////////////////////SUB
r_vector operator- (const r_vector& vec1, const r_vector& vec2) {

    r_vector vec_init (vec1.get_x () - vec2.get_x (), vec1.get_y () - vec2.get_y (), vec1.get_z () - vec2.get_z ());

    return vec_init;
}

r_vector operator - (const r_vector& vec) {

    return vec * (-1);
}


/////////////////////////////////////////////////SCALAR MUL
double operator* (const r_vector& vec1, const r_vector& vec2) {
    
    return (vec1.get_x () * vec2.get_x () + vec1.get_y () * vec2.get_y () + vec1.get_z () * vec2.get_z ());
}


r_vector operator * (const r_vector& vec, double num) {
    
    r_vector vec_init (vec.get_x () * num, vec.get_y () * num, vec.get_z () * num);

    return vec_init;
}



r_vector operator / (const r_vector& vec, double num) {

    if (num == 0) {
        fprintf (stderr, "DIVISION BY ZERO");
        return r_vector {};
    }

    r_vector vec_init (vec.get_x () / num, vec.get_y () / num, vec.get_z () / num);

    return vec_init;
}


/////////////////////////////////////////////////ANGLE BETWEEN
double operator ^ (const r_vector& vec1, const r_vector& vec2) {
    
    return rad_into_grad (acos ((vec1 * vec2) / (vec1.get_length () * vec2.get_length ())));
}


/////////////////////////////////////////////////COS ANGLE BETWEEN
double operator ^= (const r_vector& vec1, const r_vector& vec2) {
    
    return ((vec1 * vec2) / (vec1.get_length () * vec2.get_length ()));
}

// /////////////////////////////////////////////////ASSIGNMENT
r_vector& r_vector::operator = (const r_vector& vec) {

    set_coord   (vec.get_x (), vec.get_y (), vec.get_z ());
    
    return *this;
}

r_vector& r_vector::operator += (const r_vector& vec) {

    set_coord   (get_x () + vec.get_x (), get_y () + vec.get_y (), get_z () + vec.get_z ());
    
    return *this;
}

r_vector& r_vector::operator -= (const r_vector& vec) {

    set_coord   (get_x () - vec.get_x (), get_y () - vec.get_y (), get_z () - vec.get_z ());
    
    return *this;
}