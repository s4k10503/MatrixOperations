
# Matrix Operations Implementations

This repository contains implementations of various matrix operations.
Currently, the following languages are supported:

- C++

Each implementation can be found in the respective directory under `src/`.

## C++ Implementation

The C++ implementation can be found in the `src/cpp` directory.

### Dependencies

The C++ implementation does not use any specific libraries, only the standard C++ library.

### Usage

```cpp
#include "MatrixOperations.hpp"
#include <vector>
#include <iostream>

int main() {
    MatrixOperations matOps;

    // Example matrices
    std::vector<float> A = {1, 2, 3, 4, 5, 6};
    std::vector<float> B = {7, 8, 9, 10, 11, 12};
    
    // Matrix addition
    std::vector<float> sum = matOps.add(A, B, 2, 3);
    std::cout << "Sum of A and B: ";
    matOps.printMatrix(sum, 2, 3);

    // Matrix subtraction
    std::vector<float> diff = matOps.subtract(A, B, 2, 3);
    std::cout << "Difference of A and B: ";
    matOps.printMatrix(diff, 2, 3);

    // ... (other operations like multiplication, inversion, etc.)
    
    return 0;
}
```
