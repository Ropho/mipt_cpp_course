#ifndef CLASS_KERNEL_HPP
#define CLASS_KERNEL_HPP


#include "../general.hpp"


class point {

    private:
        double x_ = 0;
        double y_ = 0;

    public:
        point () {x_ = 0; y_ = 0;}
        point (double x_init, double y_init) {x_ = x_init; y_ = y_init;}
       
       ~point () {x_ = 0; y_ = 0;}

        void set_coord (double x_set, double y_set) {x_ = x_set; y_ = y_set;}
        void set_x (double x_set) {x_ = x_set;}
        void set_y (double y_set) {y_ = y_set;}

        double get_x () const {return x_;}
        double get_y () const {return y_;}

};


class kernel {

    protected:

    private:

        double x_ = 0;
        double y_ = 0;

        double rho_ = 0;
        double phi_ = 0;

        size_t last_upd = PROJ;
        
    public:
        
        kernel () {}
       ~kernel () {}


/////////////////////////////////////////////////GETTERS
        double get_x        () const {return x_;}
        double get_y        () const {return y_;}
        double get_rho      () const {return rho_;}
        double get_phi      () const {return phi_;}
        size_t get_last_upd () const {return last_upd;}
        double get_length   () const;

/////////////////////////////////////////////////SETTERS
        void set_rho        (double rho) {rho_ = rho; set_last_upd (POLAR);}
        void set_phi        (double phi) {phi_ = phi; set_last_upd (POLAR);}
        void set_x          (double x)   {x_ = x;     set_last_upd (PROJ);}
        void set_y          (double y)   {y_ = y;     set_last_upd (PROJ);}
        void set_coord      (double x, double y) {x_ = x; y_ = y; set_last_upd (PROJ);}
        void set_last_upd   (size_t status) {last_upd = status;}


/////////////////////////////////////////////////
        void synch ();

};


#endif