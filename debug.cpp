#include "debug.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int DebugPrintf(const char *fmt, ...)
{
    va_list arg_list;
    va_start(arg_list, fmt);

    return vprintf( fmt, arg_list);

    va_end(arg_list);

    return 0;
}

void CheckIt(bool expr,
             int line,
             const char *func_name,
             const char* file_name)
{
    if (!expr)
    {
        printf("\n@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@@@@&BGP55555555555555PG#@@@@@@@@@@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@&#BPPGGBBBBBBBBBBBBG5YJJ5B&@@@@@@@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@#B########&&&&&&&&&###BGPPPPGBBB#&&@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@&&@@@&&&&&@&&&&@@@&&&BGB#&@@@@&####BG&@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@@&&@@@@&@@@@@@&&#BBG@@&@@@@@@@@@@GB@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@@&@@@@@@@@@@@&#B#@&BBPPPGB&@@@@&&B&@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@&&@@@@@@@@@@&&G#@B5JJ???YGB@@@@#&@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@&#@@@@@@@@@@&#&##G5YJ???JY5B&@@##@@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@B#&&@@@@@@@&B&B5JJYYJJJJJJ7J5&&P#@@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@&BB&@@@@@@@&#G##GP5YYGGP5PPGG5P@BB@@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@&GG&@@@@@@@#&@@@@@@@&#B#&@@@@@&#@##&@@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@BBB##&@@@&&#B#GBGGBBGG5JJG#BBBB5#@##@@@@@@@@@@@@@");
        printf("\n@@@@@@@@@#BBBBB#@@@@##&#PYY5P5PBPB##GPJJ??JB@&B@@@@@@@@@@@@@");
        printf("\n@@@@@@@@#B&BGB&@@@@&&&@&&&&#B##PB&G&BGB&###@@&##@@@@@@@@@@@@");
        printf("\n@@@@@@@@#&&B##&@@@&B&@@BB&#P555PP5PP5G&B&@@@#PYB@@@@@@@@@@@@");
        printf("\n@@@@@@@@&@&&#&@@@&&#B@&JJ##BGGGPGGPPPBBY&@@YJYB@@@@@@@@@@@@@");
        printf("\n@@@@@&@@@@@&&@@@&#@@&&@PY5PGBBGGGGGGBPJ5@BJJB&@@@@@@@@@@@@@@");
        printf("\n&&####&@@@@&@@@@&&@@@@@@@BP555PGGGPP5Y#@G75P@@&&@@@@@@@@@@@@");
        printf("\n#&#&&&&&@@@@@@@@&&@@@@@@@@B?YYJJ55JJ5&#5JP&@&@&&@@@@@@@@@@@@");
        printf("\n&&&#@&@&&@@@@@@&&#&@@@@@@@#J?GGPGBGB&J7JP&&YYP@@@@@@@@@@@@@@");
        printf("\n&&&&@@@@@@@@@@@&&&#&@@@@@@#JJY&@@&#GYYPPYY?Y#B5P&@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@@&&&&@@@@@@&GGGYYYJYY555P5JY5YYB#&@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5Y555YPG55PPBGY?PG5P@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G5PP5GGGP5PPPP5PYJB&@@@@@@@@@@@");
        printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#BBG#&#GGBGGGGPGB&@@@@@@@@@@@@@");

        printf("\n//CheckIt: spoted a problem in file: %s, function: %s, line: %d", file_name, func_name, line);
        abort();
    }
}
