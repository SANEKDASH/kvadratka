//! Type of constants, each of which corresponds to a certain number of roots of the quadratic equation
typedef enum
{
    kOneRoot   = 1, //!< 0 roots
    kTwoRoots  = 2, //!< 1 root
    kInfRoots  = 8, //!< 2 roots
    kZeroRoots = 0, //!< infinite number of roots
} RootsCount;


//! The structure of the coefficients of the quadratic equation
typedef struct
{
    double a;  //!< coefficient x^2
    double b;  //!< coefficient x
    double c;  //!< free coefficient
} Coeffs;

//! Structure of solutions of the quadratic equation
typedef struct
{
    double x1;              //!< the first root
    double x2;              //!< the second root
    RootsCount roots_count; //!< number of roots in this case
} Solutions;

//! Type of constants responsible for the operation of CallInterface()
typedef enum
{
    kInputError,            //!< an unknown function has been introduced
    kInputSuccess,          //!<
    kBufferOverflowError,   //!< buffer is full
    kEofError,              //!< ran into EOF
    kInputFileError,        //!<
    kTestFileError,         //!<
    kHelp,                  //!< the help command is entered
    kQuit,                  //!< the quit command is entered
    kMeow,                  //!< the meow command has been introduced
    kTest,                  //!< the test command is entered
    kZeroStr,               //!< the null line is entered
} InputResults;

#ifdef DEBUG
const int kCommandArraySize = 4;
#else
const int kCommandArraySize = 3;
#endif

//! Command structure
typedef struct
{
    const char *command_name; //!< name of command
    InputResults result;      //!< is a constant corresponding to the command
    const char *help_text;    //!< command actions
} Command;

const Command CommandArray[kCommandArraySize] = {
                                                   #ifdef DEBUG
                                                   "test", kTest,"to start testing algorithm, using information from file test.txt in directory",
                                                   #endif
                                                   "help", kHelp,"invokes list of commands",
                                                   "meow", kMeow,"to print a kitty",
                                                   "quit", kQuit,"to shutdown the program"
                                                  };

