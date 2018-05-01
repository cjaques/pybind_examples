# Examples of C/C++ calls from Python using PyBind

If you need help, just send me a mail christian.jaques@gmail.com

For now on, there are two examples:
- Example0: an example that I give on [my website](http://www.christianjaques.ch/code). It consists of a C++ wrapper with a function accepting two numpy arrays as input and returns an (dynamically created in C++) array that is the sum of both inputs.
Interesting example related to Numpy, with a simple build command.
- Example1: Acccepts a Numpy array, sends it to a C function that will loop through all elements of the array and print them. The interest of this example is the inclusion of C code and the build done with Python `distutils` through `setup.py`. 

## Compile

** Example 0 **

```
cd example0
bash build.sh
```

** Example 1 **
```
cd example1
python setup.py build_ext --inplace
```

This will build `wrapper.so` and copy it next to `setup.py`.
You can now run the code with 
```
python ex.py
```
