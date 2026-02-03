# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gpsx:msg/Gpsx.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Gpsx(type):
    """Metaclass of message 'Gpsx'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('gpsx')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gpsx.msg.Gpsx')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gpsx
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gpsx
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gpsx
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gpsx
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gpsx

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Gpsx(metaclass=Metaclass_Gpsx):
    """Message class 'Gpsx'."""

    __slots__ = [
        '_longitude',
        '_latitude',
        '_altitude',
        '_ground_speed',
        '_satellites',
        '_mode_indicator',
        '_separation',
        '_true_course',
        '_true_course_magnetic',
        '_dilution',
        '_utc_time',
    ]

    _fields_and_field_types = {
        'longitude': 'double',
        'latitude': 'double',
        'altitude': 'double',
        'ground_speed': 'float',
        'satellites': 'uint8',
        'mode_indicator': 'uint8',
        'separation': 'float',
        'true_course': 'float',
        'true_course_magnetic': 'float',
        'dilution': 'float',
        'utc_time': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.longitude = kwargs.get('longitude', float())
        self.latitude = kwargs.get('latitude', float())
        self.altitude = kwargs.get('altitude', float())
        self.ground_speed = kwargs.get('ground_speed', float())
        self.satellites = kwargs.get('satellites', int())
        self.mode_indicator = kwargs.get('mode_indicator', int())
        self.separation = kwargs.get('separation', float())
        self.true_course = kwargs.get('true_course', float())
        self.true_course_magnetic = kwargs.get('true_course_magnetic', float())
        self.dilution = kwargs.get('dilution', float())
        self.utc_time = kwargs.get('utc_time', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.longitude != other.longitude:
            return False
        if self.latitude != other.latitude:
            return False
        if self.altitude != other.altitude:
            return False
        if self.ground_speed != other.ground_speed:
            return False
        if self.satellites != other.satellites:
            return False
        if self.mode_indicator != other.mode_indicator:
            return False
        if self.separation != other.separation:
            return False
        if self.true_course != other.true_course:
            return False
        if self.true_course_magnetic != other.true_course_magnetic:
            return False
        if self.dilution != other.dilution:
            return False
        if self.utc_time != other.utc_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def longitude(self):
        """Message field 'longitude'."""
        return self._longitude

    @longitude.setter
    def longitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'longitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._longitude = value

    @builtins.property
    def latitude(self):
        """Message field 'latitude'."""
        return self._latitude

    @latitude.setter
    def latitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'latitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'latitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._latitude = value

    @builtins.property
    def altitude(self):
        """Message field 'altitude'."""
        return self._altitude

    @altitude.setter
    def altitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'altitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'altitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._altitude = value

    @builtins.property
    def ground_speed(self):
        """Message field 'ground_speed'."""
        return self._ground_speed

    @ground_speed.setter
    def ground_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ground_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ground_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ground_speed = value

    @builtins.property
    def satellites(self):
        """Message field 'satellites'."""
        return self._satellites

    @satellites.setter
    def satellites(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'satellites' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'satellites' field must be an unsigned integer in [0, 255]"
        self._satellites = value

    @builtins.property
    def mode_indicator(self):
        """Message field 'mode_indicator'."""
        return self._mode_indicator

    @mode_indicator.setter
    def mode_indicator(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode_indicator' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mode_indicator' field must be an unsigned integer in [0, 255]"
        self._mode_indicator = value

    @builtins.property
    def separation(self):
        """Message field 'separation'."""
        return self._separation

    @separation.setter
    def separation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'separation' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'separation' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._separation = value

    @builtins.property
    def true_course(self):
        """Message field 'true_course'."""
        return self._true_course

    @true_course.setter
    def true_course(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'true_course' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'true_course' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._true_course = value

    @builtins.property
    def true_course_magnetic(self):
        """Message field 'true_course_magnetic'."""
        return self._true_course_magnetic

    @true_course_magnetic.setter
    def true_course_magnetic(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'true_course_magnetic' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'true_course_magnetic' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._true_course_magnetic = value

    @builtins.property
    def dilution(self):
        """Message field 'dilution'."""
        return self._dilution

    @dilution.setter
    def dilution(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dilution' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'dilution' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._dilution = value

    @builtins.property
    def utc_time(self):
        """Message field 'utc_time'."""
        return self._utc_time

    @utc_time.setter
    def utc_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_time' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'utc_time' field must be an unsigned integer in [0, 4294967295]"
        self._utc_time = value
