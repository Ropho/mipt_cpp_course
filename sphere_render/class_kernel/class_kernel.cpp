#include "class_kernel.hpp"

/////////////////////////////////////////////////KERNEL

double kernel::get_length () const {

    return sqrt (get_x () * get_x () + get_y () * get_y () + get_z () * get_z ());
}
