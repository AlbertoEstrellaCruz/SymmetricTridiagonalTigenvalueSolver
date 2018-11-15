#include <math.h>

#include "calculate_normq_v1.h"

void calculate_normq_c( double *normq, double *dfmlc, double *v, int c, int n )
{
	int f;

	normq[c] = 0.0;

    for ( f = 0; f < n; ++f )
	{
   	    normq[c] += ( ( v[f] * v[f] ) / ( dfmlc[ f + n * c ] * dfmlc[ f + n * c ] ) );
    }

    normq[c]  = sqrt( normq[c] );
}

void calculate_normq( double *normq, double *dfmlc, double *v, int n )
{
	int c;

	for ( c = 0; c < n; ++c )
    {
		calculate_normq_c( normq, dfmlc, v, c, n );
	}
}

