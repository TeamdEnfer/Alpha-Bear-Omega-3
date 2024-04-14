#ifndef _ROS_SERVICE_supervisor_get_from_def_h
#define _ROS_SERVICE_supervisor_get_from_def_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char SUPERVISOR_GET_FROM_DEF[] = "webots_ros/supervisor_get_from_def";

  class supervisor_get_from_defRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef uint64_t _proto_type;
      _proto_type proto;

    supervisor_get_from_defRequest():
      name(""),
      proto(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->proto >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->proto >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->proto >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->proto >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->proto >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->proto >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->proto >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->proto >> (8 * 7)) & 0xFF;
      offset += sizeof(this->proto);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->proto =  ((uint64_t) (*(inbuffer + offset)));
      this->proto |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->proto |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->proto |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->proto |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->proto |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->proto |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->proto |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->proto);
     return offset;
    }

    virtual const char * getType() override { return SUPERVISOR_GET_FROM_DEF; };
    virtual const char * getMD5() override { return "178cf7495b55fb0d5a2e01c746ab4754"; };

  };

  class supervisor_get_from_defResponse : public ros::Msg
  {
    public:
      typedef uint64_t _node_type;
      _node_type node;

    supervisor_get_from_defResponse():
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

    virtual const char * getType() override { return SUPERVISOR_GET_FROM_DEF; };
    virtual const char * getMD5() override { return "364f76d0680a5475664d98abd705f036"; };

  };

  class supervisor_get_from_def {
    public:
    typedef supervisor_get_from_defRequest Request;
    typedef supervisor_get_from_defResponse Response;
  };

}
#endif
