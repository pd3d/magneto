#ifndef levmarq_h
#define levmarq_h

//#include "Arduino.h"

typedef struct {
	int verbose;
  	int max_it;
  	double init_lambda;
  	double up_factor;
  	double down_factor;
  	double target_derr;
  	int final_it;
  	double final_err;
  	double final_derr;
} LMstat;

class levmarq
{
	public:
//		levmarq_init( int verbose, int max_it, double initi_lambda, double up_factor, double down_factor,
//					  double target_derr, int final_it, double final_err, double final_derr );
//
//		levmarq_init( int verbose, int max_it, double initi_lambda, double up_factor,
//					  double down_factor, double target_derr);
		levmarq( LMstat *lmstat );

		int levmarq_solve(
							int 	npar,
							double 	*par,
							int 	ny,
							double 	*y,
							double 	*dysq,
							double 	(*func)(double *, int, void *),
							void 	(*grad)(double *, double *, int, void *),
							void 	*fdata,
							LMstat 	*lmstat
						);

		double error_func(
							double 	*par,
							int 	ny,
							double 	*y,
							double 	*dysq,
							double 	(*func)(double *, int, void *),
							void 	*fdata
						);

		// void solve_axb_cholesky(
		// 						int 	n 		, 
		// 						double 	l[n][n]	,
		// 						double 	x[n]	,
		// 						double 	b[n]
		// 					   );

		void solve_axb_cholesky(
									int n,
									double** l,
									double* x,
									double* b
									);

		int cholesky_decomp(
							int n,
							double** l,
							double** a
							);

	private:
		int _pin;
};

#endif