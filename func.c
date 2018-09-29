#include "func.h"

int func(double t, const double y[], double f[], void *params)
{
    double k1 = ((struct rparams *)params)->k1; 
    double k2 = ((struct rparams *)params)->k2;
    double k3 = ((struct rparams *)params)->k3; 
    double cA = y[0];
    double cB = y[1];
    double cC = y[2];

    f[0] = -k1*cA + k2*cB*cC;
    f[1] = k1*cA - k2*cB*cC - k3*cB*cB;
    f[2] = k3*cB*cB;
        

    return GSL_SUCCESS;
}
