#ifndef _ROS_SERVICE_node_get_pose_h
#define _ROS_SERVICE_node_get_pose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"

namespace webots_ros
{

static const char NODE_GET_POSE[] = "webots_ros/node_get_pose";

  class node_get_poseRequest : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;
      typedef uint64_t _from_node_type;
      _from_node_type from_node;

    node_get_poseRequest():
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

    virtual const char * getType() override { return NODE_GET_POSE; };
    virtual const char * getMD5() override { return "eda5466e6469f685de429bfb11a7d60a"; };

  };

  class node_get_poseResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Transform _pose_type;
      _pose_type pose;

    node_get_poseResponse():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return NODE_GET_POSE; };
    virtual const char * getMD5() override { return "96280f359de4c102d6564b28af811210"; };

  };

  class node_get_pose {
    public:
    typedef node_get_poseRequest Request;
    typedef node_get_poseResponse Response;
  };

}
#endif
