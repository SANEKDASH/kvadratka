/*!
* Type of constants, each of which corresponds to a certain number of roots of the quadratic equation
*
* kZeroRoots - 0 roots
* kOneRoot - 1 root
* kTwoRoots - 2 roots
* kInfRoots - infinite number of roots
*/
typedef enum
{
    kZeroRoots,
    kOneRoot,
    kTwoRoots,
    kInfRoots,
} RootsCount;

/*!
* The structure of the coefficients of the quadratic equation
*
* a - coefficient A,
* b - coefficient B,
* c - coefficient C,
*/
typedef struct
{
    double a;
    double b;
    double c;
} Coeffs;

/*!
* Structure of solutions of the quadratic equation
* x1 is the first root
* x2 is the second root
*/
typedef struct
{
    double x1;
    double x2;
} Solutions;

/*!
* Type of constants responsible for the operation of CallInterface()
*
* kInputSucces - coefficients entered successfully
* kInputError - an unknown function has been introduced
* kBufferOverFlowError - buffer is full
* kEofError - ran into EOF
* kFileError - error in opening the file
* kHelp - the help command is entered
* kQuit - the quit command is entered
* kMeow - the meow command has been introduced
* kTest - the test command is entered
* kZeroStr - the null line is entered
*/
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

#ifdef DEBUG
const int kCommandArraySize = 4;
#else
const int kCommandArraySize = 3;
#endif

/*!
* Command structure
*
* command name command name
* result is a constant corresponding to the command
* help_text command actions
*/
typedef struct
{
    const char *command_name;
    InputResults result;
    const char *help_text;
} Command;

const Command command_array[kCommandArraySize] = {
                                                   #ifdef DEBUG
                                                   "test", kTest,"to start testing algorithm, using information from file test.txt in directory",
                                                   #endif
                                                   "help", kHelp,"invokes list of commands",
                                                   "meow", kMeow,"to print a kitty",
                                                   "quit", kQuit,"to shutdown the program"
                                                  };

