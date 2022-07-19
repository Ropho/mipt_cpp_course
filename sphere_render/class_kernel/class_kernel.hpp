#ifndef CLASS_KERNEL_HPP
#define CLASS_KERNEL_HPP


#include "../general.hpp"


class point {

    private:
        double x_ = 0;
        double y_ = 0;
        double z_  = 0;

    public:
        point () {x_ = 0; y_ = 0; z_ = 0;}
        point (double x_init, double y_init, double z_init) {x_ = x_init; y_ = y_init; z_ = z_init;}
       
       ~point () {x_ = 0; y_ = 0; z_ = 0;}

        void set_coord (double x_set, double y_set, double z_set) {x_ = x_set; y_ = y_set; z_ = z_set;}
        void set_x (double x_set) {x_ = x_set;}
        void set_y (double y_set) {y_ = y_set;}
        void set_z (double z_set) {z_ = z_set;}


        double get_x () const {return x_;}
        double get_y () const {return y_;}
        double get_z () const {return z_;}
};


class kernel {

    protected:

    private:

        double x_ = 0;
        double y_ = 0;
        double z_ = 0;

        
    public:
        
        kernel () {}
       ~kernel () {}


/////////////////////////////////////////////////GETTERS
        double get_x        () const {return x_;}
        double get_y        () const {return y_;}
        double get_z        () const {return z_;}
        double get_length   () const;

/////////////////////////////////////////////////SETTERS
        void set_x          (double x)   {x_ = x;}
        void set_y          (double y)   {y_ = y;}
        void set_z          (double z)   {z_ = z;}
        void set_coord      (double x, double y, double z) {x_ = x; y_ = y; z_ = z;}
};


#endif