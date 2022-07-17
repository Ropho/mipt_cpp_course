#include "general.hpp"


double rad_into_grad (const double& rad) {
    return rad * 180 / M_PI;
}

double grad_into_rad (const double& grad) {
    return grad * M_PI / 180;
}