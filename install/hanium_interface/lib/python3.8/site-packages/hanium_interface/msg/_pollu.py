# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hanium_interface:msg/Pollu.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Pollu(type):
    """Metaclass of message 'Pollu'."""

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
            module = import_type_support('hanium_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hanium_interface.msg.Pollu')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__pollu
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__pollu
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__pollu
            cls._TYPE_SUPPORT = module.type_support_msg__msg__pollu
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__pollu

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Pollu(metaclass=Metaclass_Pollu):
    """Message class 'Pollu'."""

    __slots__ = [
        '_pm10',
        '_pm2_5',
    ]

    _fields_and_field_types = {
        'pm10': 'int16',
        'pm2_5': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pm10 = kwargs.get('pm10', int())
        self.pm2_5 = kwargs.get('pm2_5', int())

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
        if self.pm10 != other.pm10:
            return False
        if self.pm2_5 != other.pm2_5:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def pm10(self):
        """Message field 'pm10'."""
        return self._pm10

    @pm10.setter
    def pm10(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pm10' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'pm10' field must be an integer in [-32768, 32767]"
        self._pm10 = value

    @property
    def pm2_5(self):
        """Message field 'pm2_5'."""
        return self._pm2_5

    @pm2_5.setter
    def pm2_5(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pm2_5' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'pm2_5' field must be an integer in [-32768, 32767]"
        self._pm2_5 = value
