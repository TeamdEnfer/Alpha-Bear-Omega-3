#ifndef _ROS_cartesian_control_msgs_CartesianPosture_h
#define _ROS_cartesian_control_msgs_CartesianPosture_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cartesian_control_msgs
{

  class CartesianPosture : public ros::Msg
  {
    public:
      uint32_t posture_joint_names_length;
      typedef char* _posture_joint_names_type;
      _posture_joint_names_type st_posture_joint_names;
      _posture_joint_names_type * posture_joint_names;
      uint32_t posture_joint_values_length;
      typedef float _posture_joint_values_type;
      _posture_joint_values_type st_posture_joint_values;
      _posture_joint_values_type * posture_joint_values;

    CartesianPosture():
      posture_joint_names_length(0), st_posture_joint_names(), posture_joint_names(nullptr),
      posture_joint_values_length(0), st_posture_joint_values(), posture_joint_values(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->posture_joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->posture_joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->posture_joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->posture_joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->posture_joint_names_length);
      for( uint32_t i = 0; i < posture_joint_names_length; i++){
      uint32_t length_posture_joint_namesi = strlen(this->posture_joint_names[i]);
      varToArr(outbuffer + offset, length_posture_joint_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->posture_joint_names[i], length_posture_joint_namesi);
      offset += length_posture_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->posture_joint_values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->posture_joint_values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->posture_joint_values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->posture_joint_values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->posture_joint_values_length);
      for( uint32_t i = 0; i < posture_joint_values_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->posture_joint_values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t posture_joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      posture_joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      posture_joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      posture_joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->posture_joint_names_length);
      if(posture_joint_names_lengthT > posture_joint_names_length)
        this->posture_joint_names = (char**)realloc(this->posture_joint_names, posture_joint_names_lengthT * sizeof(char*));
      posture_joint_names_length = posture_joint_names_lengthT;
      for( uint32_t i = 0; i < posture_joint_names_length; i++){
      uint32_t length_st_posture_joint_names;
      arrToVar(length_st_posture_joint_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_posture_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_posture_joint_names-1]=0;
      this->st_posture_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_posture_joint_names;
        memcpy( &(this->posture_joint_names[i]), &(this->st_posture_joint_names), sizeof(char*));
      }
      uint32_t posture_joint_values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      posture_joint_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      posture_joint_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      posture_joint_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->posture_joint_values_length);
      if(posture_joint_values_lengthT > posture_joint_values_length)
        this->posture_joint_values = (float*)realloc(this->posture_joint_values, posture_joint_values_lengthT * sizeof(float));
      posture_joint_values_length = posture_joint_values_lengthT;
      for( uint32_t i = 0; i < posture_joint_values_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_posture_joint_values));
        memcpy( &(this->posture_joint_values[i]), &(this->st_posture_joint_values), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "cartesian_control_msgs/CartesianPosture"; };
    virtual const char * getMD5() override { return "fd61b7ee575c3e6d2dc191be6b741ff0"; };

  };

}
#endif
