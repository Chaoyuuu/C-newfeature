## Enviromant
- gcc-9 /g++-9
- [install cpp-17](https://solarianprogrammer.com/2019/05/09/cpp-17-stl-parallel-algorithms-gcc-intel-tbb-linux-macos/?fbclid=IwAR0qOi5L89R4sXbleKusH_LESaQGCFJAwXdoLoCz-8lUVRxeRvucodcYq20)

## run

### parallel.cpp
`g++-9 -L/usr/local/tbb-2019/lib -std=c++17 -Wall -Wextra -pedantic parallel.cpp -o parallel -ltbb`

### test.cpp
`g++ -std=c++11 test.cpp -o test`
