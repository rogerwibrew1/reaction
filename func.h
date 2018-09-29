#ifndef FUNC_H
#define FUNC_H

#include <gsl/gsl_errno.h>

struct rparams{
    double k1;
    double k2;
    double k3;
};

int func(double t, const double y[], double f[], void *params);

#endif
