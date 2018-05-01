#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>


namespace py = pybind11;

int add(int i, int j) {
	    return i + j;
}

void f(py::array_t<double> array)
{
	// loop through array
	auto buf = array.request(); // gets information from array

	std::cout << "mimu " << +buf.ndim  <<  std::endl;
}


py::array_t<double> add_arrays(py::array_t<double> input1, py::array_t<double> input2) {
auto buf1 = input1.request(), buf2 = input2.request();

if (buf1.ndim != 1 || buf2.ndim != 1)
	throw std::runtime_error("Number of dimensions must be one");

if (buf1.size != buf2.size)
	throw std::runtime_error("Input shapes must match");

/* No pointer is passed, so NumPy will allocate the buffer */
py::array_t<double> result = py::array_t<double>(buf1.size);
py::buffer_info buf3 = result.request();

double *ptr1 = (double *) buf1.ptr,
		*ptr2 = (double *) buf2.ptr,
		*ptr3 = (double *) buf3.ptr;

for (size_t idx = 0; idx < buf1.shape[0]; idx++)
	ptr3[idx] = ptr1[idx] + ptr2[idx];

return result;
}


PYBIND11_MODULE(example, m) {
	    m.doc() = "pybind11 example plugin"; // optional module docstring

		m.def("add", &add, "A function which adds two numbers");
		m.def("numpy_mimu", &f, "A function which plays with numpy");
	    m.def("add_arrays", &add_arrays, "Add two NumPy arrays");
}

