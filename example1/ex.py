# 
# christian.jaques@gmail.com
#
# demo code for the use of PyBind with the inclusion of a C module
# check the use of "extern "C"{" in display_array.h
# 
import numpy as np
import wrapper


# instantiate a Python array that'll be sent to C++ and C
b = np.ones(10)*3
wrapper.display(b)  # example function that displays the array

