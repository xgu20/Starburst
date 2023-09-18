#include <math.h>
#include <stdlib.h>
#include "svd.h"

//svd function
#define SIGN(u, v)     ( (v)>=0.0 ? fabs(u) : -fabs(u) )
#define MAX(x, y)     ( (x) >= (y) ? (x) : (y) )  