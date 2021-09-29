#include <stdio.h>
#include <stdlib.h>

#include "TutorialConfig.h"
#ifdef USE_MYMATH
    #include "mysqrt.h"
#else
    #include <math.h>
#endif

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // report version
        printf("%s  Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        printf("Usage: %s number\n", argv[0]);
        return 1;
    }

    const double inputValue = atof(argv[1]);

#ifdef USE_MYMATH
    const double outputValue = operation(inputValue);
#else
    const double outputValue = sqrt(inputValue);
#endif
    printf("result %f\n", outputValue);
    return 0;
}