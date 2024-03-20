#ifndef _ROS_SERVICE_get_float_array_h
#define _ROS_SERVICE_get_float_array_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char GET_FLOAT_ARRAY[] = "webots_ros/get_float_array";

  class get_float_arrayRequest : public ros::Msg
  {
    public:
      typedef bool _ask_type;
      _ask_type ask;

    get_float_arrayRequest():
      ask(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ask;
      u_ask.real = this->ask;
      *(outbuffer + offset + 0) = (u_ask.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ask);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ask;
      u_ask.base = 0;
      u_ask.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ask = u_ask.real;
      offset += sizeof(this->ask);
     return offset;
    }

    virtual const char * getType() override { return GET_FLOAT_ARRAY; };
    virtual const char * getMD5() override { return "fbe9700edfca44c5eefb040d9b60f6d6"; };

  };

  class get_float_arrayResponse : public ros::Msg
  {
    public:
      uint32_t value_length;
      typedef float _value_type;
      _value_type st_value;
      _value_type * value;

    get_float_arrayResponse():
      value_length(0), st_value(), value(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_length);
      for( uint32_t i = 0; i < value_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->value_length);
      if(value_lengthT > value_length)
        this->value = (float*)realloc(this->value, value_lengthT * sizeof(float));
      value_length = value_lengthT;
      for( uint32_t i = 0; i < value_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_value));
        memcpy( &(this->value[i]), &(this->st_value), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return GET_FLOAT_ARRAY; };
    virtual const char * getMD5() override { return "0db98d790b5b039efb61505385ae8369"; };

  };

  class get_float_array {
    public:
    typedef get_float_arrayRequest Request;
    typedef get_float_arrayResponse Response;
  };

}
#endif
