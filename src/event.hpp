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
#ifndef _INCLUDE_EVENT_HPP_
#define _INCLUDE_EVENT_HPP_

#include "motionplus.hpp"

typedef void(* event_handler)(ctx_dev *cam, motion_event, ctx_image_data *,
             char *, void *, struct timespec *);
/*
void event(ctx_dev *cam, motion_event evnt
           ,ctx_image_data *img_data, char *fname,void *ftype, struct timespec *ts1);
const char * imageext(ctx_dev *cam);
*/
#endif /* _INCLUDE_EVENT_HPP_ */
