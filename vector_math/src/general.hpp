#ifndef GENERAL_HPP
#define GENERAL_HPP


#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctime>
#include <limits.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>



enum STATUS {

    SYNCH = 0,
    PROJ  = 1,
    POLAR = 2,
};

double rad_into_grad (const double&  rad);
double grad_into_rad (const double& grad);


#endif