#ifndef SWEEPCREATORWRAPPER_H
#define SWEEPCREATORWRAPPER_H

#include <cstddef>

#ifdef __cplusplus
extern "C"
{
#endif

  int CalculateWrapper(size_t driving_direction,
                                   size_t operation_mode = 0);
  int TestHelloWorld(int value);

#ifdef __cplusplus
}
#endif
#endif // SWEEPCREATORWRAPPER_H