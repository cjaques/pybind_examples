#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "display_array.h"

namespace py = pybind11;

/* C++ function that redirects to C func */
void display(py::array_t<double> input1){

	/*  read input arrays buffer_info */
	auto buf1 = input1.request();

	/*  variables */
	double *ptr1 = (double *) buf1.ptr;
	size_t N = buf1.shape[0];

	// C code call 
	loop_array(ptr1, (int)N);
}


/* Wrapping routines with PyBind */
PYBIND11_MODULE(wrapper, m) {
	    m.doc() = ""; // optional module docstring
	    m.def("display", &display, "display array");
}

