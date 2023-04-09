/*
 *    This file is part of MotionPlus.
 *
 *    MotionPlus is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    MotionPlus is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with MotionPlus.  If not, see <https://www.gnu.org/licenses/>.
 *
 *    Copyright 2020-2023 MotionMrDave@gmail.com
*/

#ifndef _INCLUDE_VIDEO_V4L2_HPP_
#define _INCLUDE_VIDEO_V4L2_HPP_

#include "src/motionplus.hpp"
#include <linux/videodev2.h>
typedef struct video_image_buff {
    unsigned char   *ptr;
    int             content_length;
    size_t          size;                    /* total allocated size */
    size_t          used;                    /* bytes already used */
    struct timeval  image_time;      /* time this image was received */
} video_buff;

typedef struct palette_item_struct{
    unsigned int    v4l2id;
    char            fourcc[5];
} palette_item;

struct ctx_v4l2cam_ctrl {
    char            *ctrl_name;       /* The name as provided by the device */
    char            *ctrl_iddesc;     /* A motion description of the ID number for the control*/
    int             ctrl_minimum;    /* The minimum value permitted as reported by device*/
    int             ctrl_maximum;    /* The maximum value permitted as reported by device*/
    int             ctrl_default;    /* The default value for the control*/
    int             ctrl_currval;    /* The current value the control was set to */
    int             ctrl_newval;     /* The new value to set for the control */
    unsigned int    ctrl_id;         /* The ID number for the control as provided by the device*/
    unsigned int    ctrl_type;       /* The type of control as reported by the device*/
    bool            ctrl_menuitem;   /* bool for whether item is a menu item description */
};

struct ctx_v4l2cam {
    int                     fd_device;
    int                     width;
    int                     height;
    int                     fps;
    int                     pixfmt_src;
    int                     buffer_count;
    ctx_v4l2cam_ctrl        *devctrl_array;        /*Array of all the controls in the device*/
    int                     devctrl_count;         /*Count of the controls in the device*/
    int                     device_type;           /*Camera, tuner, etc as provided by driver enum*/
    int                     device_tuner;          /*Tuner number if applicable from driver*/
    ctx_params              *params;               /*User parameters for the camera */
    video_buff              *buffers;
    int                     pframe;
    volatile bool           finish;                /* End the thread */
    #ifdef HAVE_V4L2
        struct v4l2_capability cap;
        struct v4l2_format fmt;
        struct v4l2_requestbuffers req;
        struct v4l2_buffer buf;
    #endif
};

    void v4l2_start(ctx_dev *cam);
    int v4l2_next(ctx_dev *cam,  ctx_image_data *img_data);
    void v4l2_cleanup(ctx_dev *cam);

#endif /* _INCLUDE_VIDEO_V4L2_HPP_ */
