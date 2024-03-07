#ifndef _ROS_SERVICE_node_disable_pose_tracking_h
#define _ROS_SERVICE_node_disable_pose_tracking_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char NODE_DISABLE_POSE_TRACKING[] = "webots_ros/node_disable_pose_tracking";

  class node_disable_pose_trackingRequest : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;
      typedef uint64_t _from_node_type;
      _from_node_type from_node;

    node_disable_pose_trackingRequest():
      node(0),
      from_node(0)
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
      *(outbuffer + offset + 0) = (this->from_node >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->from_node >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->from_node >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->from_node >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->from_node >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->from_node >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->from_node >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->from_node >> (8 * 7)) & 0xFF;
      offset += sizeof(this->from_node);
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
      this->from_node =  ((uint64_t) (*(inbuffer + offset)));
      this->from_node |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->from_node |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->from_node |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->from_node |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->from_node |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->from_node |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->from_node |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->from_node);
     return offset;
    }

    virtual const char * getType() override { return NODE_DISABLE_POSE_TRACKING; };
    virtual const char * getMD5() override { return "eda5466e6469f685de429bfb11a7d60a"; };

  };

  class node_disable_pose_trackingResponse : public ros::Msg
  {
    public:
      typedef int8_t _success_type;
      _success_type success;

    node_disable_pose_trackingResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return NODE_DISABLE_POSE_TRACKING; };
    virtual const char * getMD5() override { return "0b13460cb14006d3852674b4c614f25f"; };

  };

  class node_disable_pose_tracking {
    public:
    typedef node_disable_pose_trackingRequest Request;
    typedef node_disable_pose_trackingResponse Response;
  };

}
#endif
