#ifndef _ROS_jsk_recognition_msgs_VQATaskGoal_h
#define _ROS_jsk_recognition_msgs_VQATaskGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CompressedImage.h"

namespace jsk_recognition_msgs
{

  class VQATaskGoal : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef sensor_msgs::CompressedImage _compressed_image_type;
      _compressed_image_type compressed_image;
      uint32_t questions_length;
      typedef char* _questions_type;
      _questions_type st_questions;
      _questions_type * questions;

    VQATaskGoal():
      image(),
      compressed_image(),
      questions_length(0), st_questions(), questions(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->image.serialize(outbuffer + offset);
      offset += this->compressed_image.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->questions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->questions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->questions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->questions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->questions_length);
      for( uint32_t i = 0; i < questions_length; i++){
      uint32_t length_questionsi = strlen(this->questions[i]);
      varToArr(outbuffer + offset, length_questionsi);
      offset += 4;
      memcpy(outbuffer + offset, this->questions[i], length_questionsi);
      offset += length_questionsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->compressed_image.deserialize(inbuffer + offset);
      uint32_t questions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      questions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      questions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      questions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->questions_length);
      if(questions_lengthT > questions_length)
        this->questions = (char**)realloc(this->questions, questions_lengthT * sizeof(char*));
      questions_length = questions_lengthT;
      for( uint32_t i = 0; i < questions_length; i++){
      uint32_t length_st_questions;
      arrToVar(length_st_questions, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_questions; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_questions-1]=0;
      this->st_questions = (char *)(inbuffer + offset-1);
      offset += length_st_questions;
        memcpy( &(this->questions[i]), &(this->st_questions), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/VQATaskGoal"; };
    virtual const char * getMD5() override { return "6d989868a8332f72b725e727adff21b1"; };

  };

}
#endif
