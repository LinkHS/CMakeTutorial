#include <math.h>

double mysqrt(double inputValue)
{
    // if we have both log and exp then use them
#if defined (HAVE_LOG) && defined (HAVE_EXP)
    return exp(log(inputValue)*0.5);
#else
    return sqrt(inputValue);
#endif
}