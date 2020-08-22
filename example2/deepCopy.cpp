// https://stackoverflow.com/questions/56575285/is-there-a-deep-copy-constructor-for-pybind11array-t/56635791#56635791
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void testCopy(){
	size_t len = 20L;
	using py_arr = pybind11::array_t<double>; 
	py_arr a(len); //  b;
	auto buf = a.request(); 
	double *ptr1 = (double *)buf.ptr;
	for(size_t idx = 0; idx<len; idx++)
		ptr1[idx] = (double)idx;


	py_arr b = py_arr(buf);

//	pybind11::array_t<double> b = new pybind11::init_holder_from_existing(
	std::cout << b.data() << " " << a.data() << std::endl;	

	auto buf2 = b.request();
	double *ptr2 = (double *)buf2.ptr;

	std::cout << "second loop " << std::endl;

	for(size_t idx=0; idx < len; idx++)
		std::cout << ptr1[idx] << " should be == " << ptr2[idx] << std::endl;

	std::cout << std::endl;
}

/* Wrapping routines with PyBind */
PYBIND11_MODULE(wrapper, m) {
	    m.doc() = ""; // optional module docstring
	    m.def("test_copy", &testCopy, "deep copy");
}

