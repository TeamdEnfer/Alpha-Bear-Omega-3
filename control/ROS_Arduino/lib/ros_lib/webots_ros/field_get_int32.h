#ifndef _ROS_SERVICE_field_get_int32_h
#define _ROS_SERVICE_field_get_int32_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char FIELD_GET_INT32[] = "webots_ros/field_get_int32";

  class field_get_int32Request : public ros::Msg
  {
    public:
      typedef uint64_t _field_type;
      _field_type field;
      typedef int32_t _index_type;
      _index_type index;

    field_get_int32Request():
      field(0),
      index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->field >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->field >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->field >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->field >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->field >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->field >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->field >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->field >> (8 * 7)) & 0xFF;
      offset += sizeof(this->field);
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->field =  ((uint64_t) (*(inbuffer + offset)));
      this->field |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->field |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->field |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->field |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->field |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->field |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->field |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->field);
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->index = u_index.real;
      offset += sizeof(this->index);
     return offset;
    }

    virtual const char * getType() override { return FIELD_GET_INT32; };
    virtual const char * getMD5() override { return "828947932ebb9e813d3ef918f20f0d81"; };

  };

  class field_get_int32Response : public ros::Msg
  {
    public:
      typedef int32_t _value_type;
      _value_type value;

    field_get_int32Response():
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    virtual const char * getType() override { return FIELD_GET_INT32; };
    virtual const char * getMD5() override { return "b3087778e93fcd34cc8d65bc54e850d1"; };

  };

  class field_get_int32 {
    public:
    typedef field_get_int32Request Request;
    typedef field_get_int32Response Response;
  };

}
#endif
