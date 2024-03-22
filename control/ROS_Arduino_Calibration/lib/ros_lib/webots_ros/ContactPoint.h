#ifndef _ROS_webots_ros_ContactPoint_h
#define _ROS_webots_ros_ContactPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace webots_ros
{

  class ContactPoint : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _point_type;
      _point_type point;
      typedef int32_t _node_id_type;
      _node_id_type node_id;

    ContactPoint():
      point(),
      node_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->point.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_node_id;
      u_node_id.real = this->node_id;
      *(outbuffer + offset + 0) = (u_node_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_node_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_node_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_node_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->node_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->point.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_node_id;
      u_node_id.base = 0;
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_node_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->node_id = u_node_id.real;
      offset += sizeof(this->node_id);
     return offset;
    }

    virtual const char * getType() override { return "webots_ros/ContactPoint"; };
    virtual const char * getMD5() override { return "c401f69a1503004a9e4aec8ae5ec3e17"; };

  };

}
#endif
