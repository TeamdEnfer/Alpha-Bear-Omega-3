#ifndef _ROS_SERVICE_node_set_string_h
#define _ROS_SERVICE_node_set_string_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char NODE_SET_STRING[] = "webots_ros/node_set_string";

  class node_set_stringRequest : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;
      typedef const char* _state_name_type;
      _state_name_type state_name;

    node_set_stringRequest():
      node(0),
      state_name("")
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
      uint32_t length_state_name = strlen(this->state_name);
      varToArr(outbuffer + offset, length_state_name);
      offset += 4;
      memcpy(outbuffer + offset, this->state_name, length_state_name);
      offset += length_state_name;
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
      uint32_t length_state_name;
      arrToVar(length_state_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state_name-1]=0;
      this->state_name = (char *)(inbuffer + offset-1);
      offset += length_state_name;
     return offset;
    }

    virtual const char * getType() override { return NODE_SET_STRING; };
    virtual const char * getMD5() override { return "5262a198fe3532bd7eee27115a5826d0"; };

  };

  class node_set_stringResponse : public ros::Msg
  {
    public:
      typedef int32_t _success_type;
      _success_type success;

    node_set_stringResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_success.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_success.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_success.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_success.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_success.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_success.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return NODE_SET_STRING; };
    virtual const char * getMD5() override { return "3c2bcf2ff0894cb3058b1bf4c8c4175a"; };

  };

  class node_set_string {
    public:
    typedef node_set_stringRequest Request;
    typedef node_set_stringResponse Response;
  };

}
#endif
