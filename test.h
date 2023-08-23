#ifndef test
#define test

void Test();

int TestAlgorithm(Coeffs *ptr_coefficients,
                  Solutions *ptr_real_solutions);

InputResults ConvertBuf(char *buf,
                        Coeffs *ptr_coefficients,
                        Solutions *ptr_solutions);

InputResults GetInput_test(FILE *ptr_file,
                           Coeffs *ptr_coefficients,
                           Solutions *ptr_solutions);

InputResults GetCoeffsAndSolutions(char *buf,
                                   Coeffs *ptr_coefficients,
                                   Solutions *ptr_solutions);

#endif
