#ifndef input
#define input

void PrintInputErrorMessage();

InputResults GetInput(FILE *ptr_file, Coeffs *ptr_coefficients);

void CallReadingInterface(Coeffs *ptr_coefficients, Solutions *solutions);

InputResults ConvertBuf(char *buf, Coeffs *ptr_coefficients);

InputResults ConvertBufToCoeffs(char *buf, Coeffs *ptr_coefficients);

#endif
