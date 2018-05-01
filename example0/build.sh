c++ -O2 -Wall -shared -std=c++11 -fPIC -I/usr/include/python2.7 -lpython2.7 `python -m pybind11 --includes` example.cpp -o example`python-config --extension-suffix`
