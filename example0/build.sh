# previous configuration to build with Python2 on a *nix environment
#c++ -O2 -Wall -shared -std=c++11 -fPIC -I/usr/include/python2.7 -lpython2.7 `python -m pybind11 --includes` example.cpp -o example`python-config --extension-suffix`
# I have a pyenv virtual environment named py36 that needs to be init-ed
eval "$(pyenv init -)"
pyenv shell py36
c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` example.cpp -o example`python3.6-config --extension-suffix`

