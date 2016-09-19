You can surround any action with following lines to record its time:

```
#include <time.h>

{
    clock_t start = clock();

    // ...

    clock_t end = clock();
    double time = (double)(end - start)/CLOCKS_PER_SEC;
}
```
