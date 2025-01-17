#ifndef _ADD_INT
#define _ADD_INT
// when gcc is used to compile add_int and generate an library file and use this in another main file, it works well.
// but when the same is done using g++, we get linker error because the symbols are not the same for c++ and c compilation
// in cpp we have overloading support and hence the symbol is different. to make this work both with g++ and gcc, i.e cpp and c compilation
// we add a compiler flag and make add extern C 

#ifdef __cplusplus
extern "C"
#endif
int add_int(int , int);

#endif
