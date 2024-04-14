#ifndef _ROS_SERVICE_node_get_field_by_index_h
#define _ROS_SERVICE_node_get_field_by_index_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char NODE_GET_FIELD_BY_INDEX[] = "webots_ros/node_get_field_by_index";

  class node_get_field_by_indexRequest : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;
      typedef uint32_t _index_type;
      _index_type index;
      typedef bool _proto_type;
      _proto_type proto;

    node_get_field_by_indexRequest():
      node(0),
      index(0),
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
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
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
      this->index =  ((uint32_t) (*(inbuffer + offset)));
      this->index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->index);
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

    virtual const char * getType() override { return NODE_GET_FIELD_BY_INDEX; };
    virtual const char * getMD5() override { return "9b49b500661f860e9fb67bf931d052d8"; };

  };

  class node_get_field_by_indexResponse : public ros::Msg
  {
    public:
      typedef uint64_t _field_type;
      _field_type field;

    node_get_field_by_indexResponse():
      field(0)
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
     return offset;
    }

    virtual const char * getType() override { return NODE_GET_FIELD_BY_INDEX; };
    virtual const char * getMD5() override { return "6e05f2ccbc5e22655a0890e2557862bd"; };

  };

  class node_get_field_by_index {
    public:
    typedef node_get_field_by_indexRequest Request;
    typedef node_get_field_by_indexResponse Response;
  };

}
#endif
