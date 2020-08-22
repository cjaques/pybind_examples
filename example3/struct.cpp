// https://stackoverflow.com/questions/57829000/how-to-bind-two-nested-structures-using-pybind11
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py=pybind11;

typedef struct _Names
{
	int a;
	int b;
	int c;
} Names;

typedef struct _values
{
	Names names;
} values;


// Wrapping code
PYBIND11_MODULE(wrapper, m) {
	py::class_<Names>(m, "Names")
	    .def(py::init<>())
	    .def_readwrite("a", &Names::a)
	    .def_readwrite("b", &Names::b)
	    .def_readwrite("c", &Names::c);

	py::class_<values>(m, "values")
	    .def(py::init<>())
	    .def_readwrite("names", &values::names);
}


