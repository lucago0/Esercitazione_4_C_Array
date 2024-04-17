#include "Utils.hpp"

namespace UtilsLibrary {
double dot_product(unsigned int n, double* v1, double* v2){
    double out = 0;
    for (unsigned int i = 0; i<n; i++){
        out += *(v1 + i) * *(v2 + i);
    }
    return out;
}
}
