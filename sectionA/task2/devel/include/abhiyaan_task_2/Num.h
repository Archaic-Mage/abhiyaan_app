// Generated by gencpp from file abhiyaan_task_2/Num.msg
// DO NOT EDIT!


#ifndef ABHIYAAN_TASK_2_MESSAGE_NUM_H
#define ABHIYAAN_TASK_2_MESSAGE_NUM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace abhiyaan_task_2
{
template <class ContainerAllocator>
struct Num_
{
  typedef Num_<ContainerAllocator> Type;

  Num_()
    : num(0)  {
    }
  Num_(const ContainerAllocator& _alloc)
    : num(0)  {
  (void)_alloc;
    }



   typedef int64_t _num_type;
  _num_type num;





  typedef boost::shared_ptr< ::abhiyaan_task_2::Num_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::abhiyaan_task_2::Num_<ContainerAllocator> const> ConstPtr;

}; // struct Num_

typedef ::abhiyaan_task_2::Num_<std::allocator<void> > Num;

typedef boost::shared_ptr< ::abhiyaan_task_2::Num > NumPtr;
typedef boost::shared_ptr< ::abhiyaan_task_2::Num const> NumConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::abhiyaan_task_2::Num_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::abhiyaan_task_2::Num_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::abhiyaan_task_2::Num_<ContainerAllocator1> & lhs, const ::abhiyaan_task_2::Num_<ContainerAllocator2> & rhs)
{
  return lhs.num == rhs.num;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::abhiyaan_task_2::Num_<ContainerAllocator1> & lhs, const ::abhiyaan_task_2::Num_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace abhiyaan_task_2

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::abhiyaan_task_2::Num_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::abhiyaan_task_2::Num_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::abhiyaan_task_2::Num_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::abhiyaan_task_2::Num_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::abhiyaan_task_2::Num_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::abhiyaan_task_2::Num_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::abhiyaan_task_2::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "57d3c40ec3ac3754af76a83e6e73127a";
  }

  static const char* value(const ::abhiyaan_task_2::Num_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x57d3c40ec3ac3754ULL;
  static const uint64_t static_value2 = 0xaf76a83e6e73127aULL;
};

template<class ContainerAllocator>
struct DataType< ::abhiyaan_task_2::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "abhiyaan_task_2/Num";
  }

  static const char* value(const ::abhiyaan_task_2::Num_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::abhiyaan_task_2::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 num\n"
;
  }

  static const char* value(const ::abhiyaan_task_2::Num_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::abhiyaan_task_2::Num_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.num);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Num_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::abhiyaan_task_2::Num_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::abhiyaan_task_2::Num_<ContainerAllocator>& v)
  {
    s << indent << "num: ";
    Printer<int64_t>::stream(s, indent + "  ", v.num);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ABHIYAAN_TASK_2_MESSAGE_NUM_H
