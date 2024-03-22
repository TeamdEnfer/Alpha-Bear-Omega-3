#ifndef _ROS_champ_msgs_PointArray_h
#define _ROS_champ_msgs_PointArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "champ_msgs/Point.h"

namespace champ_msgs
{

  class PointArray : public ros::Msg
  {
    public:
      typedef champ_msgs::Point _lf_type;
      _lf_type lf;
      typedef champ_msgs::Point _rf_type;
      _rf_type rf;
      typedef champ_msgs::Point _lh_type;
      _lh_type lh;
      typedef champ_msgs::Point _rh_type;
      _rh_type rh;

    PointArray():
      lf(),
      rf(),
      lh(),
      rh()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->lf.serialize(outbuffer + offset);
      offset += this->rf.serialize(outbuffer + offset);
      offset += this->lh.serialize(outbuffer + offset);
      offset += this->rh.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->lf.deserialize(inbuffer + offset);
      offset += this->rf.deserialize(inbuffer + offset);
      offset += this->lh.deserialize(inbuffer + offset);
      offset += this->rh.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "champ_msgs/PointArray"; };
    virtual const char * getMD5() override { return "e70791c6db4935709e33b9966d293c36"; };

  };

}
#endif
