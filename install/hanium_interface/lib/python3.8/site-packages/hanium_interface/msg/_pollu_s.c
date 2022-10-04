// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "hanium_interface/msg/detail/pollu__struct.h"
#include "hanium_interface/msg/detail/pollu__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hanium_interface__msg__pollu__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[34];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("hanium_interface.msg._pollu.Pollu", full_classname_dest, 33) == 0);
  }
  hanium_interface__msg__Pollu * ros_message = _ros_message;
  {  // pm10
    PyObject * field = PyObject_GetAttrString(_pymsg, "pm10");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pm10 = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pm2_5
    PyObject * field = PyObject_GetAttrString(_pymsg, "pm2_5");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pm2_5 = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hanium_interface__msg__pollu__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Pollu */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hanium_interface.msg._pollu");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Pollu");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hanium_interface__msg__Pollu * ros_message = (hanium_interface__msg__Pollu *)raw_ros_message;
  {  // pm10
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pm10);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pm10", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pm2_5
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pm2_5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pm2_5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
