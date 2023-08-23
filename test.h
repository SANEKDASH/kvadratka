#ifndef test
#define test

int TestAlgorithm(Coeffs *ptr_coefficients,
                  Solutions *ptr_real_solutions,
                  RootsCount real_roots_count);

InputResults ConvertBuf(char *buf,
                        Coeffs *ptr_coefficients,
                        Solutions *ptr_solutions);

#endif
