#ifndef _ROS_SERVICE_skin_get_bone_position_h
#define _ROS_SERVICE_skin_get_bone_position_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace webots_ros
{

static const char SKIN_GET_BONE_POSITION[] = "webots_ros/skin_get_bone_position";

  class skin_get_bone_positionRequest : public ros::Msg
  {
    public:
      typedef int32_t _index_type;
      _index_type index;
      typedef bool _absolute_type;
      _absolute_type absolute;

    skin_get_bone_positionRequest():
      index(0),
      absolute(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      union {
        bool real;
        uint8_t base;
      } u_absolute;
      u_absolute.real = this->absolute;
      *(outbuffer + offset + 0) = (u_absolute.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->absolute);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      union {
        bool real;
        uint8_t base;
      } u_absolute;
      u_absolute.base = 0;
      u_absolute.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->absolute = u_absolute.real;
      offset += sizeof(this->absolute);
     return offset;
    }

    virtual const char * getType() override { return SKIN_GET_BONE_POSITION; };
    virtual const char * getMD5() override { return "8b80fdb520b22500446f343c69464386"; };

  };

  class skin_get_bone_positionResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _position_type;
      _position_type position;

    skin_get_bone_positionResponse():
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SKIN_GET_BONE_POSITION; };
    virtual const char * getMD5() override { return "e7bb0ef028c744b081acdc57743b11d8"; };

  };

  class skin_get_bone_position {
    public:
    typedef skin_get_bone_positionRequest Request;
    typedef skin_get_bone_positionResponse Response;
  };

}
#endif
