#ifndef _ROS_SERVICE_node_get_velocity_h
#define _ROS_SERVICE_node_get_velocity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"

namespace webots_ros
{

static const char NODE_GET_VELOCITY[] = "webots_ros/node_get_velocity";

  class node_get_velocityRequest : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;

    node_get_velocityRequest():
      node(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->node >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->node >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->node >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->node >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->node >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->node >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->node >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->node >> (8 * 7)) & 0xFF;
      offset += sizeof(this->node);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->node =  ((uint64_t) (*(inbuffer + offset)));
      this->node |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->node |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->node |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->node |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->node |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->node |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->node |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->node);
     return offset;
    }

    virtual const char * getType() override { return NODE_GET_VELOCITY; };
    virtual const char * getMD5() override { return "364f76d0680a5475664d98abd705f036"; };

  };

  class node_get_velocityResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Twist _velocity_type;
      _velocity_type velocity;

    node_get_velocityResponse():
      velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->velocity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return NODE_GET_VELOCITY; };
    virtual const char * getMD5() override { return "5fef62192d910a8ed2d056bd880fb973"; };

  };

  class node_get_velocity {
    public:
    typedef node_get_velocityRequest Request;
    typedef node_get_velocityResponse Response;
  };

}
#endif
