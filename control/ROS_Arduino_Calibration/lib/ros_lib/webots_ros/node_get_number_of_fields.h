#ifndef _ROS_SERVICE_node_get_number_of_fields_h
#define _ROS_SERVICE_node_get_number_of_fields_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char NODE_GET_NUMBER_OF_FIELDS[] = "webots_ros/node_get_number_of_fields";

  class node_get_number_of_fieldsRequest : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;
      typedef bool _proto_type;
      _proto_type proto;

    node_get_number_of_fieldsRequest():
      node(0),
      proto(0)
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
      } u_proto;
      u_proto.real = this->proto;
      *(outbuffer + offset + 0) = (u_proto.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->proto);
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
      } u_proto;
      u_proto.base = 0;
      u_proto.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->proto = u_proto.real;
      offset += sizeof(this->proto);
     return offset;
    }

    virtual const char * getType() override { return NODE_GET_NUMBER_OF_FIELDS; };
    virtual const char * getMD5() override { return "c0118192008356d8ad845d5f20024814"; };

  };

  class node_get_number_of_fieldsResponse : public ros::Msg
  {
    public:
      typedef int32_t _value_type;
      _value_type value;

    node_get_number_of_fieldsResponse():
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

    virtual const char * getType() override { return NODE_GET_NUMBER_OF_FIELDS; };
    virtual const char * getMD5() override { return "b3087778e93fcd34cc8d65bc54e850d1"; };

  };

  class node_get_number_of_fields {
    public:
    typedef node_get_number_of_fieldsRequest Request;
    typedef node_get_number_of_fieldsResponse Response;
  };

}
#endif
