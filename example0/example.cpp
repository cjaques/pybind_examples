#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;


py::array_t<double> add_arrays(py::array_t<double> input1, py::array_t<double> input2) {

/*  read input arrays buffer_info */
auto buf1 = input1.request(), buf2 = input2.request();
if (buf1.size != buf2.size)
	throw std::runtime_error("Input shapes must match");

/*  allocate the output buffer */
py::array_t<double> result = py::array_t<double>(buf1.size);
auto buf3 = result.request();

double *ptr1 = (double *) buf1.ptr, *ptr2 = (double *) buf2.ptr, *ptr3 = (double *) buf3.ptr;
size_t X = buf1.shape[0];
size_t Y = buf1.shape[1];

for (size_t idx = 0; idx < X; idx++)
	for (size_t idy = 0; idy < Y; idy++)
		ptr3[idx*Y + idy] = ptr1[idx*Y+ idy] + ptr2[idx*Y+ idy];

// reshape result
result.resize({X,Y});

return result;
}


PYBIND11_MODULE(example, m) {
	    m.doc() = "Add two vectors using pybind11"; // optional module docstring
	    m.def("add_arrays", &add_arrays, "Add two NumPy arrays");
}

