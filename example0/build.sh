#c++ -O2 -Wall -shared -std=c++11 -fPIC -I/usr/include/python2.7 -lpython2.7 `python -m pybind11 --includes` example.cpp -o example`python-config --extension-suffix`
#c++ -O3 -Wall -shared -std=c++11 -fPIC -I/Users/chris/.pyenv/shims/python3.6/includes/ `python -m pybind11 --includes` example.cpp -o example`/Users/chris/.pyenv/shims/python3.6-config --extension-suffix`
c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup -I/Users/chris/.pyenv/versions/3.6.6/envs/py36/include/site `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`

