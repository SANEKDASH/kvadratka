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
    kBufferOverflowError,
    kEofError,
    kFileError,
    kHelp,
    kQuit,
    kMeow,
    kTest,
    kZeroStr,
} InputResults;

