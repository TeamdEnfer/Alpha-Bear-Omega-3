#ifndef _ROS_SERVICE_get_urdf_h
#define _ROS_SERVICE_get_urdf_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char GET_URDF[] = "webots_ros/get_urdf";

  class get_urdfRequest : public ros::Msg
  {
    public:
      typedef const char* _prefix_type;
      _prefix_type prefix;

    get_urdfRequest():
      prefix("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_prefix = strlen(this->prefix);
      varToArr(outbuffer + offset, length_prefix);
      offset += 4;
      memcpy(outbuffer + offset, this->prefix, length_prefix);
      offset += length_prefix;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_prefix;
      arrToVar(length_prefix, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_prefix; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_prefix-1]=0;
      this->prefix = (char *)(inbuffer + offset-1);
      offset += length_prefix;
     return offset;
    }

    virtual const char * getType() override { return GET_URDF; };
    virtual const char * getMD5() override { return "8a471f61d96890d8f43bc26d6b147ee7"; };

  };

  class get_urdfResponse : public ros::Msg
  {
    public:
      typedef const char* _value_type;
      _value_type value;

    get_urdfResponse():
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
     return offset;
    }

    virtual const char * getType() override { return GET_URDF; };
    virtual const char * getMD5() override { return "64e58419496c7248b4ef25731f88b8c3"; };

  };

  class get_urdf {
    public:
    typedef get_urdfRequest Request;
    typedef get_urdfResponse Response;
  };

}
#endif
