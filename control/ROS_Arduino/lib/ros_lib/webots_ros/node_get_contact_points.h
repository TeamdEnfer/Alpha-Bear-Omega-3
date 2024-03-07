#ifndef _ROS_SERVICE_node_get_contact_points_h
#define _ROS_SERVICE_node_get_contact_points_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "webots_ros/ContactPoint.h"

namespace webots_ros
{

static const char NODE_GET_CONTACT_POINTS[] = "webots_ros/node_get_contact_points";

  class node_get_contact_pointsRequest : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;
      typedef bool _include_descendants_type;
      _include_descendants_type include_descendants;

    node_get_contact_pointsRequest():
      node(0),
      include_descendants(0)
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
      union {
        bool real;
        uint8_t base;
      } u_include_descendants;
      u_include_descendants.real = this->include_descendants;
      *(outbuffer + offset + 0) = (u_include_descendants.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->include_descendants);
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
      union {
        bool real;
        uint8_t base;
      } u_include_descendants;
      u_include_descendants.base = 0;
      u_include_descendants.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->include_descendants = u_include_descendants.real;
      offset += sizeof(this->include_descendants);
     return offset;
    }

    virtual const char * getType() override { return NODE_GET_CONTACT_POINTS; };
    virtual const char * getMD5() override { return "5c4df127c770c26f94b8cdc3c61f1dc0"; };

  };

  class node_get_contact_pointsResponse : public ros::Msg
  {
    public:
      uint32_t contact_points_length;
      typedef webots_ros::ContactPoint _contact_points_type;
      _contact_points_type st_contact_points;
      _contact_points_type * contact_points;

    node_get_contact_pointsResponse():
      contact_points_length(0), st_contact_points(), contact_points(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->contact_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contact_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contact_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contact_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contact_points_length);
      for( uint32_t i = 0; i < contact_points_length; i++){
      offset += this->contact_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t contact_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contact_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contact_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contact_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contact_points_length);
      if(contact_points_lengthT > contact_points_length)
        this->contact_points = (webots_ros::ContactPoint*)realloc(this->contact_points, contact_points_lengthT * sizeof(webots_ros::ContactPoint));
      contact_points_length = contact_points_lengthT;
      for( uint32_t i = 0; i < contact_points_length; i++){
      offset += this->st_contact_points.deserialize(inbuffer + offset);
        memcpy( &(this->contact_points[i]), &(this->st_contact_points), sizeof(webots_ros::ContactPoint));
      }
     return offset;
    }

    virtual const char * getType() override { return NODE_GET_CONTACT_POINTS; };
    virtual const char * getMD5() override { return "484624ae2556355b876c7bc286b22f3b"; };

  };

  class node_get_contact_points {
    public:
    typedef node_get_contact_pointsRequest Request;
    typedef node_get_contact_pointsResponse Response;
  };

}
#endif
