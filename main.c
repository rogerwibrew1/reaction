#include<stdio.h>
#include<stdalign.h>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_vector.h>

#include "func.h"

int main(int argc, char * argv[])
{
    struct rparams params;
    params.k1 = 0.08;
    params.k2 = 2e4;
    params.k3 = 6e7;

    size_t dim = 3;



    const gsl_odeiv2_step_type * T = gsl_odeiv2_step_rk8pd;

    gsl_odeiv2_step * s = gsl_odeiv2_step_alloc (T, dim);

    gsl_odeiv2_control *c = gsl_odeiv2_control_standard_new(1e-6, 0.0, 1.0, 1.0);
    
    gsl_odeiv2_evolve * e = gsl_odeiv2_evolve_alloc(dim);

    gsl_odeiv2_system sys = {func, NULL, dim, &params};

    double t = 0.0, t1 = 600.0;
    double h = 1e-6;
    double y[3] = {1.0,0.0,0.0};

    FILE * f = fopen ("test.csv", "w");

    while(t < t1)
    {
        int status = gsl_odeiv2_evolve_apply(e, c, s, &sys, &t, t1, &h, y);
        if(status != GSL_SUCCESS)
            break;
        fprintf(f, "%.2e,%.2e,%.2e,%.2e\n", t, y[0], y[1], y[2]);
    }

    system("gnuplot -p 'name.gp'");

    gsl_odeiv2_evolve_free (e);
    gsl_odeiv2_control_free (c);
    gsl_odeiv2_step_free(s);
    fclose(f);
    return 0;
}