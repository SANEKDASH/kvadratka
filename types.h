typedef enum
{
    kZeroRoots,
    kOneRoot,
    kTwoRoots,
    kInfRoots,
} RootsCount;

typedef struct
{
    double a;
    double b;
    double c;
} Coeffs;

typedef struct
{
    double x1;
    double x2;
} Solutions;

typedef enum
{
    kInputError,
    kInputSucces,
} InputResults;

typedef enum
{
    kReadingError,
    kReadingSucces,
} ReadingResults;
