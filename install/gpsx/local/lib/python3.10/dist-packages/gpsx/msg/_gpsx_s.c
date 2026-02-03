// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gpsx:msg/Gpsx.idl
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
#include "gpsx/msg/detail/gpsx__struct.h"
#include "gpsx/msg/detail/gpsx__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool gpsx__msg__gpsx__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[20];
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
    assert(strncmp("gpsx.msg._gpsx.Gpsx", full_classname_dest, 19) == 0);
  }
  gpsx__msg__Gpsx * ros_message = _ros_message;
  {  // longitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "longitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->longitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // latitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "latitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->latitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // altitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "altitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->altitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ground_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "ground_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ground_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // satellites
    PyObject * field = PyObject_GetAttrString(_pymsg, "satellites");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->satellites = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mode_indicator
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode_indicator");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode_indicator = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // separation
    PyObject * field = PyObject_GetAttrString(_pymsg, "separation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->separation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // true_course
    PyObject * field = PyObject_GetAttrString(_pymsg, "true_course");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->true_course = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // true_course_magnetic
    PyObject * field = PyObject_GetAttrString(_pymsg, "true_course_magnetic");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->true_course_magnetic = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dilution
    PyObject * field = PyObject_GetAttrString(_pymsg, "dilution");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dilution = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // utc_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_time = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gpsx__msg__gpsx__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Gpsx */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gpsx.msg._gpsx");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Gpsx");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gpsx__msg__Gpsx * ros_message = (gpsx__msg__Gpsx *)raw_ros_message;
  {  // longitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->longitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "longitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // latitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->latitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "latitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // altitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->altitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "altitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ground_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ground_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ground_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // satellites
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->satellites);
    {
      int rc = PyObject_SetAttrString(_pymessage, "satellites", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode_indicator
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mode_indicator);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode_indicator", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // separation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->separation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "separation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // true_course
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->true_course);
    {
      int rc = PyObject_SetAttrString(_pymessage, "true_course", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // true_course_magnetic
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->true_course_magnetic);
    {
      int rc = PyObject_SetAttrString(_pymessage, "true_course_magnetic", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dilution
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dilution);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dilution", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->utc_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
