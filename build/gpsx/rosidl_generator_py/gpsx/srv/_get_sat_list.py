# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gpsx:srv/GetSatList.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetSatList_Request(type):
    """Metaclass of message 'GetSatList_Request'."""

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
                'gpsx.srv.GetSatList_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_sat_list__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_sat_list__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_sat_list__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_sat_list__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_sat_list__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetSatList_Request(metaclass=Metaclass_GetSatList_Request):
    """Message class 'GetSatList_Request'."""

    __slots__ = [
        '_type',
    ]

    _fields_and_field_types = {
        'type': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.type = kwargs.get('type', int())

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
        if self.type != other.type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'type' field must be an integer in [-128, 127]"
        self._type = value


# Import statements for member types

# Member 'gnsstype'
# Member 'id'
# Member 'elevation'
# Member 'azimuth'
# Member 'snr'
import array  # noqa: E402, I100

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetSatList_Response(type):
    """Metaclass of message 'GetSatList_Response'."""

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
                'gpsx.srv.GetSatList_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_sat_list__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_sat_list__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_sat_list__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_sat_list__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_sat_list__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetSatList_Response(metaclass=Metaclass_GetSatList_Response):
    """Message class 'GetSatList_Response'."""

    __slots__ = [
        '_gnsstype',
        '_id',
        '_elevation',
        '_azimuth',
        '_snr',
    ]

    _fields_and_field_types = {
        'gnsstype': 'sequence<int16>',
        'id': 'sequence<int16>',
        'elevation': 'sequence<int16>',
        'azimuth': 'sequence<int16>',
        'snr': 'sequence<int16>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int16')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int16')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int16')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int16')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int16')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.gnsstype = array.array('h', kwargs.get('gnsstype', []))
        self.id = array.array('h', kwargs.get('id', []))
        self.elevation = array.array('h', kwargs.get('elevation', []))
        self.azimuth = array.array('h', kwargs.get('azimuth', []))
        self.snr = array.array('h', kwargs.get('snr', []))

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
        if self.gnsstype != other.gnsstype:
            return False
        if self.id != other.id:
            return False
        if self.elevation != other.elevation:
            return False
        if self.azimuth != other.azimuth:
            return False
        if self.snr != other.snr:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def gnsstype(self):
        """Message field 'gnsstype'."""
        return self._gnsstype

    @gnsstype.setter
    def gnsstype(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'h', \
                "The 'gnsstype' array.array() must have the type code of 'h'"
            self._gnsstype = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -32768 and val < 32768 for val in value)), \
                "The 'gnsstype' field must be a set or sequence and each value of type 'int' and each integer in [-32768, 32767]"
        self._gnsstype = array.array('h', value)

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if isinstance(value, array.array):
            assert value.typecode == 'h', \
                "The 'id' array.array() must have the type code of 'h'"
            self._id = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -32768 and val < 32768 for val in value)), \
                "The 'id' field must be a set or sequence and each value of type 'int' and each integer in [-32768, 32767]"
        self._id = array.array('h', value)

    @builtins.property
    def elevation(self):
        """Message field 'elevation'."""
        return self._elevation

    @elevation.setter
    def elevation(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'h', \
                "The 'elevation' array.array() must have the type code of 'h'"
            self._elevation = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -32768 and val < 32768 for val in value)), \
                "The 'elevation' field must be a set or sequence and each value of type 'int' and each integer in [-32768, 32767]"
        self._elevation = array.array('h', value)

    @builtins.property
    def azimuth(self):
        """Message field 'azimuth'."""
        return self._azimuth

    @azimuth.setter
    def azimuth(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'h', \
                "The 'azimuth' array.array() must have the type code of 'h'"
            self._azimuth = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -32768 and val < 32768 for val in value)), \
                "The 'azimuth' field must be a set or sequence and each value of type 'int' and each integer in [-32768, 32767]"
        self._azimuth = array.array('h', value)

    @builtins.property
    def snr(self):
        """Message field 'snr'."""
        return self._snr

    @snr.setter
    def snr(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'h', \
                "The 'snr' array.array() must have the type code of 'h'"
            self._snr = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -32768 and val < 32768 for val in value)), \
                "The 'snr' field must be a set or sequence and each value of type 'int' and each integer in [-32768, 32767]"
        self._snr = array.array('h', value)


class Metaclass_GetSatList(type):
    """Metaclass of service 'GetSatList'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('gpsx')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gpsx.srv.GetSatList')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_sat_list

            from gpsx.srv import _get_sat_list
            if _get_sat_list.Metaclass_GetSatList_Request._TYPE_SUPPORT is None:
                _get_sat_list.Metaclass_GetSatList_Request.__import_type_support__()
            if _get_sat_list.Metaclass_GetSatList_Response._TYPE_SUPPORT is None:
                _get_sat_list.Metaclass_GetSatList_Response.__import_type_support__()


class GetSatList(metaclass=Metaclass_GetSatList):
    from gpsx.srv._get_sat_list import GetSatList_Request as Request
    from gpsx.srv._get_sat_list import GetSatList_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
