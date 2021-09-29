#include <stdio.h>
#include <stdlib.h>

#include "TutorialConfig.h"
#include "mysqrt.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // report version
        printf("%s  Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        printf("Usage: %s number\n", argv[0]);
        return 1;
    }

    const double inputValue = atof(argv[1]);

    const double outputValue = operation(inputValue);
    printf("result %f\n", outputValue);
    return 0;
}