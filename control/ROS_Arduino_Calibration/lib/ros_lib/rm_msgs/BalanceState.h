#ifndef _ROS_rm_msgs_BalanceState_h
#define _ROS_rm_msgs_BalanceState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rm_msgs
{

  class BalanceState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _x_type;
      _x_type x;
      typedef float _phi_type;
      _phi_type phi;
      typedef float _theta_type;
      _theta_type theta;
      typedef float _x_b_l_type;
      _x_b_l_type x_b_l;
      typedef float _x_b_r_type;
      _x_b_r_type x_b_r;
      typedef float _x_dot_type;
      _x_dot_type x_dot;
      typedef float _phi_dot_type;
      _phi_dot_type phi_dot;
      typedef float _theta_dot_type;
      _theta_dot_type theta_dot;
      typedef float _x_b_l_dot_type;
      _x_b_l_dot_type x_b_l_dot;
      typedef float _x_b_r_dot_type;
      _x_b_r_dot_type x_b_r_dot;
      typedef float _T_l_type;
      _T_l_type T_l;
      typedef float _T_r_type;
      _T_r_type T_r;
      typedef float _f_b_l_type;
      _f_b_l_type f_b_l;
      typedef float _f_b_r_type;
      _f_b_r_type f_b_r;

    BalanceState():
      header(),
      x(0),
      phi(0),
      theta(0),
      x_b_l(0),
      x_b_r(0),
      x_dot(0),
      phi_dot(0),
      theta_dot(0),
      x_b_l_dot(0),
      x_b_r_dot(0),
      T_l(0),
      T_r(0),
      f_b_l(0),
      f_b_r(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->phi);
      offset += serializeAvrFloat64(outbuffer + offset, this->theta);
      offset += serializeAvrFloat64(outbuffer + offset, this->x_b_l);
      offset += serializeAvrFloat64(outbuffer + offset, this->x_b_r);
      offset += serializeAvrFloat64(outbuffer + offset, this->x_dot);
      offset += serializeAvrFloat64(outbuffer + offset, this->phi_dot);
      offset += serializeAvrFloat64(outbuffer + offset, this->theta_dot);
      offset += serializeAvrFloat64(outbuffer + offset, this->x_b_l_dot);
      offset += serializeAvrFloat64(outbuffer + offset, this->x_b_r_dot);
      offset += serializeAvrFloat64(outbuffer + offset, this->T_l);
      offset += serializeAvrFloat64(outbuffer + offset, this->T_r);
      offset += serializeAvrFloat64(outbuffer + offset, this->f_b_l);
      offset += serializeAvrFloat64(outbuffer + offset, this->f_b_r);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->phi));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_b_l));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_b_r));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_dot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->phi_dot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta_dot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_b_l_dot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_b_r_dot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->T_l));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->T_r));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->f_b_l));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->f_b_r));
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/BalanceState"; };
    virtual const char * getMD5() override { return "1ad01479a611712f3c0679dc678d8b47"; };

  };

}
#endif
