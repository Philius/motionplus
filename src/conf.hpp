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


#ifndef _INCLUDE_CONF_HPP_
#define _INCLUDE_CONF_HPP_

#include <list>
#include <string>

/* Categories for the edits and display on web interface*/
enum PARM_CAT{
    PARM_CAT_00     /* system */
    ,PARM_CAT_01    /* camera */
    ,PARM_CAT_02    /* source */
    ,PARM_CAT_03    /* image */
    ,PARM_CAT_04    /* overlay */
    ,PARM_CAT_05    /* method */
    ,PARM_CAT_06    /* masks */
    ,PARM_CAT_07    /* detect */
    ,PARM_CAT_08    /* scripts */
    ,PARM_CAT_09    /* picture */
    ,PARM_CAT_10    /* movies */
    ,PARM_CAT_11    /* timelapse */
    ,PARM_CAT_12    /* pipes */
    ,PARM_CAT_13    /* webcontrol */
    ,PARM_CAT_14    /* streams */
    ,PARM_CAT_15    /* database */
    ,PARM_CAT_16    /* sql */
    ,PARM_CAT_17    /* tracking */
    ,PARM_CAT_18    /* sound */
    ,PARM_CAT_MAX
};
enum PARM_TYP{
    PARM_TYP_STRING
    , PARM_TYP_INT
    , PARM_TYP_LIST
    , PARM_TYP_BOOL
    , PARM_TYP_ARRAY
};

/** Current parameters in the config file */
struct ctx_parm {
    const std::string   parm_name;      /* name for this parameter                  */
    enum PARM_TYP       parm_type;      /* enum of parm_typ for bool,int or string. */
    enum PARM_CAT       parm_cat;       /* enum of parm_cat for grouping. */
    int                 webui_level;    /* Enum to display in webui: 0,1,2,3,99(always to never)*/
};

/** Deprecated parameters in the config file  */
struct ctx_parm_depr{
    const std::string   parm_name;     /* Name of the deprecated option */
    const std::string   last_version;  /* Last version this option was used in */
    const std::string   info;          /* Short text on why it was deprecated (removed, replaced with, etc) */
    const std::string   newname;       /* Name of the new parameter */
};

extern struct ctx_parm config_parms[];
extern struct ctx_parm_depr config_parms_depr[];

struct ctx_config {

    /* Overall system configuration parameters */
    std::string     conf_filename;
    bool            from_conf_dir;

    /* Overall application parameters */
    bool            daemon;
    std::string     pid_file;
    std::string     log_file;
    std::string     log_type_str;
    int             log_level;
    int             log_type;
    bool            setup_mode;
    bool            native_language;

    std::string     device_name;
    int             device_id;
    std::string     config_dir;
    std::string     target_dir;
    int             watchdog_tmo;
    int             watchdog_kill;
    int             device_tmo;
    bool            pause;

    /* Capture device configuration parameters */
    std::string     v4l2_device;
    std::string     v4l2_params;

    std::string     netcam_url;
    std::string     netcam_params;
    std::string     netcam_high_url;
    std::string     netcam_high_params;
    std::string     netcam_userpass;

    std::string     libcam_device;
    std::string     libcam_params;

    /* Image processing configuration parameters */
    int             width;
    int             height;
    int             framerate;
    int             rotate;
    std::string     flip_axis;
    std::string     locate_motion_mode;
    std::string     locate_motion_style;
    std::string     text_left;
    std::string     text_right;
    bool            text_changes;
    int             text_scale;
    std::string     text_event;

    /* Motion detection configuration parameters */
    bool            emulate_motion;
    int             threshold;
    int             threshold_maximum;
    int             threshold_sdevx;
    int             threshold_sdevy;
    int             threshold_sdevxy;
    int             threshold_ratio;
    int             threshold_ratio_change;
    bool            threshold_tune;
    std::string     secondary_method;
    std::string     secondary_params;
    int             noise_level;
    bool            noise_tune;
    std::string     despeckle_filter;
    std::string     area_detect;
    std::string     mask_file;
    std::string     mask_privacy;
    int             smart_mask_speed;
    int             lightswitch_percent;
    int             lightswitch_frames;
    int             minimum_motion_frames;
    int             static_object_time;
    int             event_gap;
    int             pre_capture;
    int             post_capture;

    /* Script execution configuration parameters */
    std::string     on_event_start;
    std::string     on_event_end;
    std::string     on_picture_save;
    std::string     on_area_detected;
    std::string     on_motion_detected;
    std::string     on_movie_start;
    std::string     on_movie_end;
    std::string     on_camera_lost;
    std::string     on_camera_found;
    std::string     on_secondary_detect;
    std::string     on_action_user;
    std::string     on_sound_alert;

    /* Picture output configuration parameters */
    std::string     picture_output;
    std::string     picture_output_motion;
    std::string     picture_type;
    int             picture_quality;
    std::string     picture_exif;
    std::string     picture_filename;

    /* Snapshot configuration parameters */
    int             snapshot_interval;
    std::string     snapshot_filename;

    /* Movie output configuration parameters */
    bool            movie_output;
    bool            movie_output_motion;
    int             movie_max_time;
    int             movie_bps;
    int             movie_quality;
    std::string     movie_container;
    bool            movie_passthrough;
    std::string     movie_filename;
    std::string     movie_retain;
    bool            movie_extpipe_use;
    std::string     movie_extpipe;


    /* Timelapse movie configuration parameters */
    int             timelapse_interval;
    std::string     timelapse_mode;
    int             timelapse_fps;
    std::string     timelapse_container;
    std::string     timelapse_filename;

    /* Loopback device configuration parameters */
    std::string     video_pipe;
    std::string     video_pipe_motion;

    /* Webcontrol configuration parameters */
    int             webcontrol_port;
    std::string     webcontrol_base_path;
    bool            webcontrol_ipv6;
    bool            webcontrol_localhost;
    int             webcontrol_parms;
    std::string     webcontrol_interface;
    std::string     webcontrol_auth_method;
    std::string     webcontrol_authentication;
    bool            webcontrol_tls;
    std::string     webcontrol_cert;
    std::string     webcontrol_key;
    std::string     webcontrol_headers;
    std::string     webcontrol_html;
    std::string     webcontrol_actions;
    int             webcontrol_lock_minutes;
    int             webcontrol_lock_attempts;

    /* Live stream configuration parameters */
    int             stream_preview_scale;
    bool            stream_preview_newline;
    std::string     stream_preview_method;
    bool            stream_preview_ptz;
    int             stream_quality;
    bool            stream_grey;
    bool            stream_motion;
    int             stream_maxrate;
    int             stream_scan_time;
    int             stream_scan_scale;

    /* Database and SQL configuration parameters */
    std::string     database_type;
    std::string     database_dbname;
    std::string     database_host;
    int             database_port;
    std::string     database_user;
    std::string     database_password;
    int             database_busy_timeout;

    std::string     sql_event_start;
    std::string     sql_event_end;
    std::string     sql_movie_start;
    std::string     sql_movie_end;
    std::string     sql_pic_save;

    bool            ptz_auto_track;         /* Bool to enable auto tracking */
    int             ptz_wait;               /* Frames to wait after a PTZ move */
    std::string     ptz_move_track;         /* Auto tracking command */
    std::string     ptz_pan_left;           /* Pan left command */
    std::string     ptz_pan_right;          /* Pan right command */
    std::string     ptz_tilt_up;            /* Tilt up command */
    std::string     ptz_tilt_down;          /* Tilt down command */
    std::string     ptz_zoom_in;            /* Zoom in command */
    std::string     ptz_zoom_out;           /* Zoom out command */

    /* Sound processing parameters */
    std::string             snd_device;
    std::string             snd_params;
    std::list<std::string>  snd_alerts;
    std::string             snd_window;
    bool                    snd_show;

    void conf_edit_set(std::string parm_nm, std::string parm_val);
    void conf_edit_get(std::string parm_nm
                       , std::string &parm_val, PARM_CAT parm_cat);
    void conf_edit_get(std::string parm_nm
                       , std::list<std::string> &parm_val, PARM_CAT parm_cat);
    void conf_edit_list(std::string parm_nm
                        , std::string &parm_val, PARM_CAT parm_cat);

    };
/*
    void conf_init(ctx_motapp *motapp);
    void conf_deinit(ctx_motapp *motapp);
    void conf_parms_log(ctx_motapp *motapp);
    void conf_parms_write(ctx_motapp *motapp);
    void conf_camera_add(ctx_motapp *motapp);

    void conf_edit_set(ctx_config *conf, std::string parm_nm
        , std::string parm_val);
    void conf_edit_get(ctx_config *conf, std::string parm_nm
        , std::string &parm_val, enum PARM_CAT parm_cat);
    void conf_edit_get(ctx_config *conf, std::string parm_nm
        , std::list<std::string> &parm_val, enum PARM_CAT parm_cat);
    void conf_edit_list(ctx_config *conf, std::string parm_nm
        , std::string &parm_val, enum PARM_CAT parm_cat);
*/

    extern std::string conf_type_desc(PARM_TYP ptype);
    extern std::string conf_cat_desc(PARM_CAT pcat, bool shrt);

#endif /* _INCLUDE_CONF_HPP_ */
