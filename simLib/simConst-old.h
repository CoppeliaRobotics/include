/* -------------------- deprecated ----------------------------- */

enum { /* Scene object main properties (serialized, see also deprecated values below): */
        sim_objectspecialproperty_collidable            = 0x0001,
        sim_objectspecialproperty_measurable            = 0x0002,
        sim_objectspecialproperty_detectable            = 0x01f0,
};

enum { /* Model properties (serialized, see also deprecated values below): */
        sim_modelproperty_not_collidable                = 0x0001,
        sim_modelproperty_not_measurable                = 0x0002,
        sim_modelproperty_not_detectable                = 0x0008,
        sim_modelproperty_not_dynamic                   = 0x0020,
        sim_modelproperty_not_respondable               = 0x0040, /* cannot be selected if sim_modelproperty_not_dynamic is not selected */
        sim_modelproperty_not_reset                     = 0x0080, /* Model is not reset at simulation end. This flag is cleared at simulation end */
        sim_modelproperty_not_visible                   = 0x0100, /* Whole model is invisible, independent of local visibility settings */
        sim_modelproperty_scripts_inactive              = 0x0200, /* All scripts in the model will not be executed */
        sim_modelproperty_not_showasinsidemodel         = 0x0400, /* Whole model is invisible to any model bounding box */
        sim_modelproperty_not_model                     = 0xf000  /* object is not a model. 0x1000 was intended, 0xf000 kept for backward compatibility */
};

enum { /* Scene object properties. Combine with the | operator */
    sim_objectproperty_ignoreviewfitting        =0x0001,
    sim_objectproperty_collapsed                =0x0010,
    sim_objectproperty_selectable               =0x0020,
    sim_objectproperty_selectmodelbaseinstead   =0x0080,
    sim_objectproperty_dontshowasinsidemodel    =0x0100,
    sim_objectproperty_selectinvisible          =0x0800,
    sim_objectproperty_depthinvisible           =0x1000,
    sim_objectproperty_cannotdelete             =0x2000,
    sim_objectproperty_cannotdeleteduringsim    =0x4000,
    sim_objectproperty_hiddenforsimulation      =0x10000,
};

enum { /* deprecated boolean parameters: */
    sim_boolparam_hierarchy_visible = 0,
    sim_boolparam_console_visible = 1,
    sim_boolparam_collision_handling_enabled = 2, /* deprecated */
    sim_boolparam_distance_handling_enabled = 3, /* deprecated */
    sim_boolparam_ik_handling_enabled = 4, /* deprecated */
    sim_boolparam_gcs_handling_enabled = 5, /* deprecated */
    sim_boolparam_dynamics_handling_enabled = 6,
    sim_boolparam_joint_motion_handling_enabled_deprecated = 7, /* deprecated */
    sim_boolparam_path_motion_handling_enabled_deprecated = 8, /* deprecated */
    sim_boolparam_proximity_sensor_handling_enabled = 9, /* deprecated */
    sim_boolparam_vision_sensor_handling_enabled = 10, /* deprecated */
    sim_boolparam_mill_handling_enabled = 11, /* deprecated */
    sim_boolparam_browser_visible = 12,
    sim_boolparam_scene_and_model_load_messages = 13, /* deprecated */
    sim_reserved0 = 14,
    sim_boolparam_shape_textures_are_visible = 15,
    sim_boolparam_display_enabled = 16,
    sim_boolparam_infotext_visible = 17,
    sim_boolparam_statustext_open = 18,
    sim_boolparam_fog_enabled = 19,
    sim_boolparam_rml2_available = 20,
    sim_boolparam_rml4_available = 21,
    sim_boolparam_mirrors_enabled = 22,
    sim_boolparam_aux_clip_planes_enabled = 23,
    sim_boolparam_reserved3 = 24,
    sim_boolparam_realtime_simulation = 25,
    sim_boolparam_use_glfinish_cmd = 26,
    sim_boolparam_force_show_wireless_emission = 27, /* deprecated */
    sim_boolparam_force_show_wireless_reception = 28, /* deprecated */
    sim_boolparam_video_recording_triggered = 29,
    sim_boolparam_reserved1 = 30,
    sim_boolparam_reserved2 = 31,
    sim_boolparam_threaded_rendering_enabled_old = 32, /* deprecated */
    sim_boolparam_fullscreen = 33,
    sim_boolparam_headless = 34,
    sim_boolparam_hierarchy_toolbarbutton_enabled = 35,
    sim_boolparam_browser_toolbarbutton_enabled = 36,
    sim_boolparam_objectshift_toolbarbutton_enabled = 37,
    sim_boolparam_objectrotate_toolbarbutton_enabled = 38,
    sim_boolparam_force_calcstruct_all_visible = 39,
    sim_boolparam_force_calcstruct_all = 40,
    sim_boolparam_exit_request = 41,
    sim_boolparam_play_toolbarbutton_enabled = 42,
    sim_boolparam_pause_toolbarbutton_enabled = 43,
    sim_boolparam_stop_toolbarbutton_enabled = 44,
    sim_boolparam_waiting_for_trigger = 45,
    sim_boolparam_objproperties_toolbarbutton_enabled = 46,
    sim_boolparam_calcmodules_toolbarbutton_enabled = 47, /* deprecated */
    sim_boolparam_rosinterface_donotrunmainscript = 48,
    sim_boolparam_online_mode = 49,
    sim_boolparam_xr_partrepository = 50,
    sim_boolparam_xr_palletrepository = 51,
    sim_boolparam_scene_closing = 52,
    sim_boolparam_show_w_emitters = 53,
    sim_boolparam_show_w_receivers = 54,
    sim_boolparam_xr_jobfunc = 55,
    sim_boolparam_rayvalid = 56,
    sim_boolparam_qglwidget = 57,
    sim_boolparam_execunsafe = 58,
    sim_boolparam_execunsafeext = 59,
    sim_boolparam_cansave = 60,
    sim_boolparam_usingscriptobjects = 61,
};

enum { /* deprecated integer parameters: */
    sim_intparam_error_report_mode = 0, /* DEPRECATED */
    sim_intparam_program_version = 1,       /* e.g Version 2.1.4 --> 20104. Can only be read. See also sim_intparam_program_revision */
    sim_intparam_instance_count = 2,    /* do not use anymore (always returns 1 since CoppeliaSim 2.5.11) */
    sim_intparam_custom_cmd_start_id = 3, /* can only be read */
    sim_intparam_compilation_version = 4, /* 0=evaluation version, 1=full version, 2=player version. Can only be read */
    sim_intparam_current_page = 5,
    sim_intparam_flymode_camera_handle = 6, /* deprecated */
    sim_intparam_dynamic_step_divider = 7, /* can only be read */
    sim_intparam_dynamic_engine = 8, /* 0=Bullet, 1=ODE, 2=Vortex, 3=Newton, 4=MuJoCo. Can only be read */
    sim_intparam_server_port_start = 9, /* can only be read */
    sim_intparam_server_port_range = 10, /* can only be read */
    sim_intparam_visible_layers = 11,
    sim_intparam_infotext_style = 12,
    sim_intparam_settings = 13,
    sim_intparam_edit_mode_type = 14, /* can only be read */
    sim_intparam_server_port_next = 15, /* is initialized at sim_intparam_server_port_start */
    sim_intparam_qt_version = 16, /* version of the used Qt framework */
    sim_intparam_event_flags_read_old = 17, /* deprecated */
    sim_intparam_event_flags_read_clear_old = 18, /* deprecated */
    sim_intparam_platform = 19, /* can only be read */
    sim_intparam_scene_unique_id = 20, /* can only be read */
    sim_intparam_work_thread_count = 21, /* deprecated */
    sim_intparam_mouse_x = 22, /* can only be read */
    sim_intparam_mouse_y = 23, /* can only be read */
    sim_intparam_core_count = 24, /* can only be read */
    sim_intparam_work_thread_calc_time_ms = 25, /* deprecated */
    sim_intparam_idle_fps = 26,
    sim_intparam_prox_sensor_select_down = 27,
    sim_intparam_prox_sensor_select_up = 28,
    sim_intparam_stop_request_counter = 29,
    sim_intparam_program_revision = 30, /* Can only be read. See also sim_intparam_program_version */
    sim_intparam_mouse_buttons = 31, /* can only be read */
    sim_intparam_dynamic_warning_disabled_mask = 32,
    sim_intparam_simulation_warning_disabled_mask = 33, /* deprecated */
    sim_intparam_scene_index = 34, /* can be used to switch to a different instance programmatically */
    sim_intparam_motionplanning_seed = 35,
    sim_intparam_speedmodifier = 36, /* can only be used while simulation is not stopped */
    sim_intparam_dynamic_iteration_count = 37,
    sim_intparam_job_count = 38, /* can only be read */
    sim_intparam_program_full_version = 39, /* can only be read */
    sim_intparam_verbosity = 40, /* see  sim_verbosity_none, sim_verbosity_errors, etc. */
    sim_intparam_statusbarverbosity = 41, /* see  sim_verbosity_none, sim_verbosity_errors, etc. */
    sim_intparam_dlgverbosity = 42, /* see  sim_verbosity_none, sim_verbosity_errors, etc. */
    sim_intparam_videoencoder_index = 43,
    sim_intparam_exitcode = 44,
    sim_intparam_bugfix1 = 45,
    sim_intparam_mouseclickcounterdown = 46,
    sim_intparam_mouseclickcounterup = 47,
    sim_intparam_objectcreationcounter = 48,
    sim_intparam_objectdestructioncounter = 49,
    sim_intparam_hierarchychangecounter = 50,
    sim_intparam_notifydeprecated = 51,
    sim_intparam_processid = 52,
    sim_intparam_processcnt = 53
};

enum { /* deprecated uint64 parameters: */
    sim_uint64param_simulation_time_step_ns=0, /* deprecated. Use simGet/SetSimulationTimeStep instead */
    sim_uint64param_simulation_time_ns      /* deprecated. Use simGetSimulationTime instead */
};

enum { /* deprecated float parameters: */
    sim_floatparam_rand=0, /* random value (0.0-1.0) */
    sim_floatparam_simulation_time_step, /* deprecated, use simGet/SetSimulationTimeStep instead */
    sim_floatparam_stereo_distance,
    sim_floatparam_dynamic_step_size, /* deprecated, use sim_floatparam_physicstimestep instead */
    sim_floatparam_mouse_wheel_zoom_factor,
    sim_floatparam_physicstimestep,
    sim_floatparam_maxtrisizeabs,
    sim_floatparam_mintrisizerel,
};

enum { /* deprecated string parameters: */
    sim_stringparam_application_path=0, /* path of CoppeliaSim's executable */
    sim_stringparam_video_filename, /* name + path without extension! */
    sim_stringparam_app_arg1, /* specify those args with "coppeliaSim -gxxxx" */
    sim_stringparam_app_arg2,
    sim_stringparam_app_arg3,
    sim_stringparam_app_arg4,
    sim_stringparam_app_arg5,
    sim_stringparam_app_arg6,
    sim_stringparam_app_arg7,
    sim_stringparam_app_arg8,
    sim_stringparam_app_arg9,
    sim_stringparam_additional_addonscript1, /* do not use. Can only be written. */
    sim_stringparam_additional_addonscript_firstscene=sim_stringparam_additional_addonscript1, /* deprecated */
    sim_stringparam_additional_addonscript2, /* do not use. Can only be written. */
    sim_stringparam_additional_addonscript=sim_stringparam_additional_addonscript2, /* deprecated */
    sim_stringparam_scene_path_and_name, /* can only be read */
    sim_stringparam_scene_path, /* can only be read */
    sim_stringparam_scene_name, /* can only be read */
    sim_stringparam_remoteapi_temp_file_dir, /* can only be read */
    sim_stringparam_job, /* Current job. can only be read */
    sim_stringparam_job0, /* Job0. can only be read */
    sim_stringparam_job99=sim_stringparam_job0+99, /* can only be read */
    sim_stringparam_scene_unique_id, /* can only be read */
    sim_stringparam_machine_id, /* can only be read */
    sim_stringparam_machine_id_legacy, /* can only be read */
    sim_stringparam_verbosity, /* can only be written */
    sim_stringparam_statusbarverbosity, /* can only be written */
    sim_stringparam_dlgverbosity, /* can only be written */
    sim_stringparam_consolelogfilter,
    sim_stringparam_startupscriptstring,
    sim_stringparam_uniqueid, /* can only be read */
    sim_stringparam_tempdir, /* can only be read */
    sim_stringparam_tempscenedir, /* can only be read */
    sim_stringparam_datadir, /* can only be read */
    sim_stringparam_importexportdir,
    sim_stringparam_addonpath, /* can only be read. Path + name of the calling add-on */
    sim_stringparam_scenedefaultdir, /* can only be read */
    sim_stringparam_modeldefaultdir, /* can only be read */
    sim_stringparam_defaultpython, /* can only be read. See also pythonWrapper.python named string parameter */
    sim_stringparam_additionalpythonpath, /* can only be read */
    sim_stringparam_luadir, /* can only be read */
    sim_stringparam_pythondir, /* can only be read */
    sim_stringparam_mujocodir, /* can only be read */
    sim_stringparam_usersettingsdir, /* can only be read */
    sim_stringparam_systemdir, /* can only be read */
    sim_stringparam_resourcesdir, /* can only be read */
    sim_stringparam_legacymachinetag, /* can only be read */
    sim_stringparam_addondir, /* can only be read. Path of all add-ons */
    sim_stringparam_sandboxlang,
};

enum { /* deprecated array parameters: */
    sim_arrayparam_gravity = 0,
    sim_arrayparam_fog,
    sim_arrayparam_fog_color,
    sim_arrayparam_background_color1,
    sim_arrayparam_background_color2,
    sim_arrayparam_ambient_light,
    sim_arrayparam_random_euler,
    sim_arrayparam_rayorigin,
    sim_arrayparam_raydirection,
};

enum { /* Object int/double/string parameters */
    /* scene objects */
    sim_objintparam_visibility_layer= 10,
    sim_objfloatparam_abs_x_velocity= 11,
    sim_objfloatparam_abs_y_velocity= 12,
    sim_objfloatparam_abs_z_velocity= 13,
    sim_objfloatparam_abs_rot_velocity= 14,
    sim_objfloatparam_objbbox_min_x= 15,
    sim_objfloatparam_objbbox_min_y= 16,
    sim_objfloatparam_objbbox_min_z= 17,
    sim_objfloatparam_objbbox_max_x= 18,
    sim_objfloatparam_objbbox_max_y= 19,
    sim_objfloatparam_objbbox_max_z= 20,
    sim_objfloatparam_modelbbox_min_x= 21,
    sim_objfloatparam_modelbbox_min_y= 22,
    sim_objfloatparam_modelbbox_min_z= 23,
    sim_objfloatparam_modelbbox_max_x= 24,
    sim_objfloatparam_modelbbox_max_y= 25,
    sim_objfloatparam_modelbbox_max_z= 26,
    sim_objintparam_collection_self_collision_indicator= 27,
    sim_objfloatparam_transparency_offset= 28,
    sim_objintparam_child_role= 29, /* DEPRECATED */
    sim_objintparam_parent_role= 30, /* DEPRECATED */
    sim_objintparam_manipulation_permissions= 31,
    sim_objintparam_illumination_handle= 32,
    sim_objstringparam_dna= 33, /* DEPRECATED */
    sim_objfloatparam_size_factor= 34,
    sim_objstringparam_unique_id= 35,
    sim_objintparam_visible= 36,
    sim_objintparam_unique_id= 37,
    sim_objintparam_hierarchycolor= 38,

    sim_objparam_end= 999,

    /* vision_sensors */
    sim_visionfloatparam_near_clipping= 1000,
    sim_visionfloatparam_far_clipping= 1001,
    sim_visionintparam_resolution_x= 1002,
    sim_visionintparam_resolution_y= 1003,
    sim_visionfloatparam_perspective_angle= 1004,
    sim_visionfloatparam_ortho_size= 1005,
    sim_visionintparam_disabled_light_components= 1006,
    sim_visionintparam_rendering_attributes= 1007,
    sim_visionintparam_entity_to_render= 1008,
    sim_visionintparam_windowed_size_x= 1009,
    sim_visionintparam_windowed_size_y= 1010,
    sim_visionintparam_windowed_pos_x= 1011,
    sim_visionintparam_windowed_pos_y= 1012,
    sim_visionintparam_pov_focal_blur= 1013,
    sim_visionfloatparam_pov_blur_distance= 1014,
    sim_visionfloatparam_pov_aperture= 1015,
    sim_visionintparam_pov_blur_sampled= 1016,
    sim_visionintparam_render_mode= 1017,
    sim_visionintparam_perspective_operation= 1018,
    sim_visionfarrayparam_viewfrustum= 1019,
    sim_visionintparam_rgbignored= 1020,
    sim_visionintparam_depthignored= 1021,

    /* joints */
    sim_jointintparam_motor_enabled= 2000, /* deprecated */
    sim_jointintparam_ctrl_enabled= 2001, /* deprecated */
    sim_jointfloatparam_pid_p= 2002, /* deprecated, use e.g. sim_bullet_joint_pospid1 and similar */
    sim_jointfloatparam_pid_i= 2003, /* deprecated, use e.g. sim_bullet_joint_pospid2 and similar */
    sim_jointfloatparam_pid_d= 2004, /* deprecated, use e.g. sim_bullet_joint_pospid3 and similar */
    sim_jointfloatparam_intrinsic_x= 2005,
    sim_jointfloatparam_intrinsic_y= 2006,
    sim_jointfloatparam_intrinsic_z= 2007,
    sim_jointfloatparam_intrinsic_qx= 2008,
    sim_jointfloatparam_intrinsic_qy= 2009,
    sim_jointfloatparam_intrinsic_qz= 2010,
    sim_jointfloatparam_intrinsic_qw= 2011,
    sim_jointfloatparam_velocity= 2012,
    sim_jointfloatparam_spherical_qx= 2013,
    sim_jointfloatparam_spherical_qy= 2014,
    sim_jointfloatparam_spherical_qz= 2015,
    sim_jointfloatparam_spherical_qw= 2016,
    sim_jointfloatparam_upper_limit= 2017, /* deprecated, use sim_jointfloatparam_maxvel instead */
    sim_jointfloatparam_kc_k= 2018,
    sim_jointfloatparam_kc_c= 2019,
    sim_jointfloatparam_ik_weight= 2021, /* deprecated */
    sim_jointfloatparam_error_x= 2022,
    sim_jointfloatparam_error_y= 2023,
    sim_jointfloatparam_error_z= 2024,
    sim_jointfloatparam_error_a= 2025,
    sim_jointfloatparam_error_b= 2026,
    sim_jointfloatparam_error_g= 2027,
    sim_jointfloatparam_error_pos= 2028,
    sim_jointfloatparam_error_angle= 2029,
    sim_jointintparam_velocity_lock= 2030, /* deprecated */
    sim_jointintparam_vortex_dep_handle= 2031,
    sim_jointfloatparam_vortex_dep_multiplication= 2032,
    sim_jointfloatparam_vortex_dep_offset= 2033,
    sim_jointfloatparam_screw_pitch= 2034, /* deprecated */
    sim_jointfloatparam_step_size= 2035, /* deprecated */
    sim_jointfloatparam_maxvel= 2036,
    sim_jointfloatparam_maxaccel= 2037,
    sim_jointfloatparam_maxjerk= 2038,
    sim_jointintparam_dynctrlmode= 2039,
    sim_jointintparam_dynvelctrltype= 2040,
    sim_jointintparam_dynposctrltype= 2041,
    sim_jointfloatparam_screwlead= 2042,

    /* shapes */
    sim_shapefloatparam_init_velocity_x= 3000,
    sim_shapefloatparam_init_velocity_y= 3001,
    sim_shapefloatparam_init_velocity_z= 3002,
    sim_shapeintparam_static= 3003,
    sim_shapeintparam_respondable= 3004,
    sim_shapefloatparam_mass= 3005,
    sim_shapefloatparam_texture_x= 3006,
    sim_shapefloatparam_texture_y= 3007,
    sim_shapefloatparam_texture_z= 3008,
    sim_shapefloatparam_texture_a= 3009,
    sim_shapefloatparam_texture_b= 3010,
    sim_shapefloatparam_texture_g= 3011,
    sim_shapefloatparam_texture_scaling_x= 3012,
    sim_shapefloatparam_texture_scaling_y= 3013,
    sim_shapeintparam_culling= 3014,
    sim_shapeintparam_wireframe= 3015,
    sim_shapeintparam_compound= 3016,
    sim_shapeintparam_convex= 3017,
    sim_shapeintparam_convex_check= 3018, /* DEPRECATED */
    sim_shapeintparam_respondable_mask= 3019,
    sim_shapefloatparam_init_velocity_a= 3020, /* DEPRECATED */
    sim_shapefloatparam_init_ang_velocity_x= 3020,
    sim_shapefloatparam_init_velocity_b= 3021, /* DEPRECATED */
    sim_shapefloatparam_init_ang_velocity_y= 3021,
    sim_shapefloatparam_init_velocity_g= 3022, /* DEPRECATED */
    sim_shapefloatparam_init_ang_velocity_z= 3022,
    sim_shapestringparam_color_name= 3023, /* DEPRECATED */
    sim_shapeintparam_edge_visibility= 3024,
    sim_shapefloatparam_shading_angle= 3025,
    sim_shapefloatparam_edge_angle= 3026,
    sim_shapeintparam_edge_borders_hidden= 3027,
    sim_shapeintparam_component_cnt= 3028,
    sim_shapeintparam_sleepmodestart= 3029,
    sim_shapeintparam_kinematic= 3030,
    sim_shapeintparam_respondablesuspendcnt= 3031,
    sim_shapestringparam_colorname= 3032,

    /* proximity sensors */
    sim_proxintparam_ray_invisibility= 4000,
    sim_proxintparam_volume_type= 4001,
    sim_proxintparam_entity_to_detect= 4002,

    /* force sensors */
    sim_forcefloatparam_error_x= 5000,
    sim_forcefloatparam_error_y= 5001,
    sim_forcefloatparam_error_z= 5002,
    sim_forcefloatparam_error_a= 5003,
    sim_forcefloatparam_error_b= 5004,
    sim_forcefloatparam_error_g= 5005,
    sim_forcefloatparam_error_pos= 5006,
    sim_forcefloatparam_error_angle= 5007,

    /* lights */
    sim_lightintparam_pov_casts_shadows= 8000,
    sim_lightfloatparam_spot_exponent= 8001,
    sim_lightfloatparam_spot_cutoff= 8002,
    sim_lightfloatparam_const_attenuation= 8003,
    sim_lightfloatparam_lin_attenuation= 8004,
    sim_lightfloatparam_quad_attenuation= 8005,

    /* cameras */
    sim_cameraintparam_disabled_light_components= 9000,
    sim_camerafloatparam_perspective_angle= 9001,
    sim_camerafloatparam_ortho_size= 9002,
    sim_cameraintparam_rendering_attributes= 9003,
    sim_cameraintparam_pov_focal_blur= 9004,
    sim_camerafloatparam_pov_blur_distance= 9005,
    sim_camerafloatparam_pov_aperture= 9006,
    sim_cameraintparam_pov_blur_samples= 9007,
    sim_camerafloatparam_near_clipping= 9008,
    sim_camerafloatparam_far_clipping= 9009,
    sim_cameraintparam_perspective_operation= 9010,
    sim_cameraintparam_trackedobject= 9011,
    sim_cameraintparam_remotecameramode= 9012, /* deprecated */
    sim_camerafarrayparam_viewfrustum= 9013,

    /* dummies */
    sim_dummyintparam_dummytype= 10000,
    sim_dummyintparam_link_type= sim_dummyintparam_dummytype, /* deprecated */
    sim_dummyintparam_follow_path= 10001,
    sim_dummyfloatparam_follow_path_offset= 10002,
    sim_dummyfloatparam_size= 10003,
    sim_dummystringparam_assemblytag= 10004,

    /* scripts */
    sim_scriptintparam_execorder= 10100,
    sim_scriptintparam_execcount= 10101,
    sim_scriptintparam_type= 10102,
    sim_scriptintparam_handle= 10103, /* deprecated */
    sim_scriptintparam_enabled= 10104,
    sim_scriptintparam_objecthandle= 10105, /* deprecated */
    sim_scriptintparam_lang= 10106, /* deprecated */
    sim_scriptintparam_autorestartonerror= 10107,
    sim_scriptstringparam_description= 10108,
    sim_scriptstringparam_name= 10109,
    sim_scriptstringparam_text= 10110,
    sim_scriptstringparam_nameext= 10111,
    sim_scriptstringparam_lang= 10112,

    /* graphs */
    sim_graphintparam_needs_refresh= 10500,

    /* mills */
    sim_millintparam_volume_type= 11000,

    /* mirrors */
    sim_mirrorfloatparam_width= 12000,
    sim_mirrorfloatparam_height= 12001,
    sim_mirrorfloatparam_reflectance= 12002,
    sim_mirrorintparam_enable= 12003,

    /* oc trees */
    sim_octreefloatparam_voxelsize= 13000,

    /* path planning */
    sim_pplanfloatparam_x_min= 20000,
    sim_pplanfloatparam_x_range= 20001,
    sim_pplanfloatparam_y_min= 20002,
    sim_pplanfloatparam_y_range= 20003,
    sim_pplanfloatparam_z_min= 20004,
    sim_pplanfloatparam_z_range= 20005,
    sim_pplanfloatparam_delta_min= 20006,
    sim_pplanfloatparam_delta_range= 20007,

    /* motion planning */
    sim_mplanintparam_nodes_computed_old= 25000,
    sim_mplanintparam_prepare_nodes_old= 25001,
    sim_mplanintparam_clear_nodes_old= 25002,
};

enum { /* Physics engines params */
    /* Bullet */
    sim_bullet_global_float_start=0,
    sim_bullet_global_stepsize,                 /* deprecated, use sim_floatparam_physicstimestep instead */
    sim_bullet_global_internalscalingfactor,
    sim_bullet_global_collisionmarginfactor,
    sim_bullet_global_float_end,

    sim_bullet_global_int_start=1000,
    sim_bullet_global_constraintsolvingiterations,
    sim_bullet_global_bitcoded,
    sim_bullet_global_constraintsolvertype,
    sim_bullet_global_int_end,

    sim_bullet_global_bool_start=2000,
    sim_bullet_global_fullinternalscaling,
    sim_bullet_global_computeinertias,
    sim_bullet_global_bool_end,

    sim_bullet_joint_float_start=3000,
    sim_bullet_joint_stoperp,
    sim_bullet_joint_stopcfm,
    sim_bullet_joint_normalcfm,
    sim_bullet_joint_free1,
    sim_bullet_joint_free2,
    sim_bullet_joint_pospid1,
    sim_bullet_joint_pospid2,
    sim_bullet_joint_pospid3,
    sim_bullet_joint_float_end,

    sim_bullet_joint_int_start=4000,
    sim_bullet_joint_int_end,

    sim_bullet_joint_bool_start=5000,
    sim_bullet_joint_bool_end,

    sim_bullet_body_float_start=6000,
    sim_bullet_body_restitution,
    sim_bullet_body_oldfriction,
    sim_bullet_body_friction,
    sim_bullet_body_lineardamping,
    sim_bullet_body_angulardamping,
    sim_bullet_body_nondefaultcollisionmargingfactor,
    sim_bullet_body_nondefaultcollisionmargingfactorconvex,
    sim_bullet_body_float_end,

    sim_bullet_body_int_start=7000,
    sim_bullet_body_bitcoded,
    sim_bullet_body_int_end,

    sim_bullet_body_bool_start=8000,
    sim_bullet_body_sticky,
    sim_bullet_body_usenondefaultcollisionmargin,
    sim_bullet_body_usenondefaultcollisionmarginconvex,
    sim_bullet_body_autoshrinkconvex,
    sim_bullet_body_bool_end,

    /* ODE */
    sim_ode_global_float_start=9000,
    sim_ode_global_stepsize,                /* deprecated, use sim_floatparam_physicstimestep instead */
    sim_ode_global_internalscalingfactor,
    sim_ode_global_cfm,
    sim_ode_global_erp,
    sim_ode_global_float_end,

    sim_ode_global_int_start=10000,
    sim_ode_global_constraintsolvingiterations,
    sim_ode_global_bitcoded,
    sim_ode_global_randomseed,
    sim_ode_global_int_end,

    sim_ode_global_bool_start=11000,
    sim_ode_global_fullinternalscaling,
    sim_ode_global_quickstep,
    sim_ode_global_computeinertias,
    sim_ode_global_bool_end,

    sim_ode_joint_float_start=12000,
    sim_ode_joint_stoperp,
    sim_ode_joint_stopcfm,
    sim_ode_joint_bounce,
    sim_ode_joint_fudgefactor,
    sim_ode_joint_normalcfm,
    sim_ode_joint_pospid1,
    sim_ode_joint_pospid2,
    sim_ode_joint_pospid3,
    sim_ode_joint_float_end,

    sim_ode_joint_int_start=13000,
    sim_ode_joint_int_end,

    sim_ode_joint_bool_start=14000,
    sim_ode_joint_bool_end,

    sim_ode_body_float_start=15000,
    sim_ode_body_friction,
    sim_ode_body_softerp,
    sim_ode_body_softcfm,
    sim_ode_body_lineardamping,
    sim_ode_body_angulardamping,
    sim_ode_body_float_end,

    sim_ode_body_int_start=16000,
    sim_ode_body_maxcontacts,
    sim_ode_body_int_end,

    sim_ode_body_bool_start=17000,
    sim_ode_body_bool_end,

    /* Vortex */
    sim_vortex_global_float_start=18000,
    sim_vortex_global_stepsize,                     /* deprecated, use sim_floatparam_physicstimestep instead */
    sim_vortex_global_internalscalingfactor,
    sim_vortex_global_contacttolerance,
    sim_vortex_global_constraintlinearcompliance,
    sim_vortex_global_constraintlineardamping,
    sim_vortex_global_constraintlinearkineticloss,
    sim_vortex_global_constraintangularcompliance,
    sim_vortex_global_constraintangulardamping,
    sim_vortex_global_constraintangularkineticloss,
    sim_vortex_global_float_end,

    sim_vortex_global_int_start=19000,
    sim_vortex_global_bitcoded,
    sim_vortex_global_int_end,

    sim_vortex_global_bool_start=20000,
    sim_vortex_global_autosleep,
    sim_vortex_global_multithreading,
    sim_vortex_global_computeinertias=sim_vortex_global_multithreading+3, /* previous 2 are reserved */
    sim_vortex_global_bool_end,

    sim_vortex_joint_float_start=21000,
    sim_vortex_joint_lowerlimitdamping,
    sim_vortex_joint_upperlimitdamping,
    sim_vortex_joint_lowerlimitstiffness,
    sim_vortex_joint_upperlimitstiffness,
    sim_vortex_joint_lowerlimitrestitution,
    sim_vortex_joint_upperlimitrestitution,
    sim_vortex_joint_lowerlimitmaxforce,
    sim_vortex_joint_upperlimitmaxforce,
    sim_vortex_joint_motorconstraintfrictioncoeff,
    sim_vortex_joint_motorconstraintfrictionmaxforce,
    sim_vortex_joint_motorconstraintfrictionloss,
    sim_vortex_joint_p0loss,
    sim_vortex_joint_p0stiffness,
    sim_vortex_joint_p0damping,
    sim_vortex_joint_p0frictioncoeff,
    sim_vortex_joint_p0frictionmaxforce,
    sim_vortex_joint_p0frictionloss,
    sim_vortex_joint_p1loss,
    sim_vortex_joint_p1stiffness,
    sim_vortex_joint_p1damping,
    sim_vortex_joint_p1frictioncoeff,
    sim_vortex_joint_p1frictionmaxforce,
    sim_vortex_joint_p1frictionloss,
    sim_vortex_joint_p2loss,
    sim_vortex_joint_p2stiffness,
    sim_vortex_joint_p2damping,
    sim_vortex_joint_p2frictioncoeff,
    sim_vortex_joint_p2frictionmaxforce,
    sim_vortex_joint_p2frictionloss,
    sim_vortex_joint_a0loss,
    sim_vortex_joint_a0stiffness,
    sim_vortex_joint_a0damping,
    sim_vortex_joint_a0frictioncoeff,
    sim_vortex_joint_a0frictionmaxforce,
    sim_vortex_joint_a0frictionloss,
    sim_vortex_joint_a1loss,
    sim_vortex_joint_a1stiffness,
    sim_vortex_joint_a1damping,
    sim_vortex_joint_a1frictioncoeff,
    sim_vortex_joint_a1frictionmaxforce,
    sim_vortex_joint_a1frictionloss,
    sim_vortex_joint_a2loss,
    sim_vortex_joint_a2stiffness,
    sim_vortex_joint_a2damping,
    sim_vortex_joint_a2frictioncoeff,
    sim_vortex_joint_a2frictionmaxforce,
    sim_vortex_joint_a2frictionloss,
    sim_vortex_joint_dependencyfactor, /* deprecated. Use simGetJointDependency instead */
    sim_vortex_joint_dependencyoffset, /* deprecated. Use simGetJointDependency instead */
    sim_vortex_joint_free1,
    sim_vortex_joint_free2,
    sim_vortex_joint_pospid1,
    sim_vortex_joint_pospid2,
    sim_vortex_joint_pospid3,
    sim_vortex_joint_float_end,

    sim_vortex_joint_int_start=22000,
    sim_vortex_joint_bitcoded,
    sim_vortex_joint_relaxationenabledbc,
    sim_vortex_joint_frictionenabledbc,
    sim_vortex_joint_frictionproportionalbc,
    sim_vortex_joint_objectid, /* deprecated. */
    sim_vortex_joint_dependentobjectid, /* deprecated. Use simGetJointDependency instead */
    sim_vortex_joint_int_end,

    sim_vortex_joint_bool_start=23000,
    sim_vortex_joint_motorfrictionenabled,
    sim_vortex_joint_proportionalmotorfriction,
    sim_vortex_joint_bool_end,

    sim_vortex_body_float_start=24000,
    sim_vortex_body_primlinearaxisfriction,
    sim_vortex_body_seclinearaxisfriction,
    sim_vortex_body_primangularaxisfriction,
    sim_vortex_body_secangularaxisfriction,
    sim_vortex_body_normalangularaxisfriction,
    sim_vortex_body_primlinearaxisstaticfrictionscale,
    sim_vortex_body_seclinearaxisstaticfrictionscale,
    sim_vortex_body_primangularaxisstaticfrictionscale,
    sim_vortex_body_secangularaxisstaticfrictionscale,
    sim_vortex_body_normalangularaxisstaticfrictionscale,
    sim_vortex_body_compliance,
    sim_vortex_body_damping,
    sim_vortex_body_restitution,
    sim_vortex_body_restitutionthreshold,
    sim_vortex_body_adhesiveforce,
    sim_vortex_body_linearvelocitydamping,
    sim_vortex_body_angularvelocitydamping,
    sim_vortex_body_primlinearaxisslide,
    sim_vortex_body_seclinearaxisslide,
    sim_vortex_body_primangularaxisslide,
    sim_vortex_body_secangularaxisslide,
    sim_vortex_body_normalangularaxisslide,
    sim_vortex_body_primlinearaxisslip,
    sim_vortex_body_seclinearaxisslip,
    sim_vortex_body_primangularaxisslip,
    sim_vortex_body_secangularaxisslip,
    sim_vortex_body_normalangularaxisslip,
    sim_vortex_body_autosleeplinearspeedthreshold,
    sim_vortex_body_autosleeplinearaccelthreshold,
    sim_vortex_body_autosleepangularspeedthreshold,
    sim_vortex_body_autosleepangularaccelthreshold,
    sim_vortex_body_skinthickness,
    sim_vortex_body_autoangulardampingtensionratio,
    sim_vortex_body_primaxisvectorx,
    sim_vortex_body_primaxisvectory,
    sim_vortex_body_primaxisvectorz,
    sim_vortex_body_float_end,

    sim_vortex_body_int_start=25000,
    sim_vortex_body_primlinearaxisfrictionmodel,
    sim_vortex_body_seclinearaxisfrictionmodel,
    sim_vortex_body_primangulararaxisfrictionmodel,
    sim_vortex_body_secangularaxisfrictionmodel,
    sim_vortex_body_secmangulararaxisfrictionmodel=sim_vortex_body_secangularaxisfrictionmodel,
    sim_vortex_body_normalangularaxisfrictionmodel,
    sim_vortex_body_normalmangulararaxisfrictionmodel=sim_vortex_body_normalangularaxisfrictionmodel,
    sim_vortex_body_bitcoded,
    sim_vortex_body_autosleepsteplivethreshold,
    sim_vortex_body_materialuniqueid,
    sim_vortex_body_int_end,

    sim_vortex_body_bool_start=26000,
    sim_vortex_body_pureshapesasconvex,
    sim_vortex_body_convexshapesasrandom,
    sim_vortex_body_randomshapesasterrain,
    sim_vortex_body_fastmoving,
    sim_vortex_body_autoslip,
    sim_vortex_body_seclinaxissameasprimlinaxis,
    sim_vortex_body_secangaxissameasprimangaxis,
    sim_vortex_body_normangaxissameasprimangaxis,
    sim_vortex_body_autoangulardamping,
    sim_vortex_body_bool_end,

    /* Newton */
    sim_newton_global_float_start=27000,
    sim_newton_global_stepsize, /* deprecated, use sim_floatparam_physicstimestep instead */
    sim_newton_global_contactmergetolerance,
    sim_newton_global_float_end,

    sim_newton_global_int_start=28000,
    sim_newton_global_constraintsolvingiterations,
    sim_newton_global_bitcoded,
    sim_newton_global_int_end,

    sim_newton_global_bool_start=29000,
    sim_newton_global_multithreading,
    sim_newton_global_exactsolver,
    sim_newton_global_highjointaccuracy,
    sim_newton_global_computeinertias,
    sim_newton_global_bool_end,

    sim_newton_joint_float_start=30000,
    sim_newton_joint_dependencyfactor, /* deprecated. Use simGetJointDependency instead */
    sim_newton_joint_dependencyoffset, /* deprecated. Use simGetJointDependency instead */
    sim_newton_joint_pospid1,
    sim_newton_joint_pospid2,
    sim_newton_joint_pospid3,
    sim_newton_joint_float_end,

    sim_newton_joint_int_start=31000,
    sim_newton_joint_objectid, /* deprecated. */
    sim_newton_joint_dependentobjectid, /* deprecated. Use simGetJointDependency instead */
    sim_newton_joint_int_end,

    sim_newton_joint_bool_start=32000,
    /* if you add something here, search for njb11032016 */
    sim_newton_joint_bool_end,

    sim_newton_body_float_start=33000,
    sim_newton_body_staticfriction,
    sim_newton_body_kineticfriction,
    sim_newton_body_restitution,
    sim_newton_body_lineardrag,
    sim_newton_body_angulardrag,
    sim_newton_body_float_end,

    sim_newton_body_int_start=34000,
    sim_newton_body_bitcoded,
    sim_newton_body_int_end,

    sim_newton_body_bool_start=35000,
    sim_newton_body_fastmoving,
    sim_newton_body_bool_end,


    /* MuJoCo */
    sim_mujoco_global_float_start=37000,
    sim_mujoco_global_stepsize,             /* deprecated, use sim_floatparam_physicstimestep instead */
    sim_mujoco_global_impratio,
    sim_mujoco_global_wind1,
    sim_mujoco_global_wind2,
    sim_mujoco_global_wind3,
    sim_mujoco_global_density,
    sim_mujoco_global_viscosity,
    sim_mujoco_global_boundmass,
    sim_mujoco_global_boundinertia,
    sim_mujoco_global_overridemargin,
    sim_mujoco_global_overridesolref1,
    sim_mujoco_global_overridesolref2,
    sim_mujoco_global_overridesolimp1,
    sim_mujoco_global_overridesolimp2,
    sim_mujoco_global_overridesolimp3,
    sim_mujoco_global_overridesolimp4,
    sim_mujoco_global_overridesolimp5,
    sim_mujoco_global_kinmass,
    sim_mujoco_global_kininertia,
    sim_mujoco_global_float_end,

    sim_mujoco_global_int_start=38000,
    sim_mujoco_global_bitcoded, /* b0=compute inertias,b1=multithreaded,b2=multiccd,b3=balance inertias,b4=override contacts */
    sim_mujoco_global_iterations,
    sim_mujoco_global_integrator, /* 0=euler,1=rk4,2=implicit */
    sim_mujoco_global_solver, /* 0=pgs,1=cg,2=newton */
    sim_mujoco_global_njmax,
    sim_mujoco_global_nconmax,
    sim_mujoco_global_cone, /* 0=pyramidal,1=elliptic */
    sim_mujoco_global_overridekin, /* 0=do not override,1=all disabled,2=all enabled */
    sim_mujoco_global_nstack,
    sim_mujoco_global_rebuildtrigger, /* bit coded: bit0=object added, bit1=object removed, bit2=hierarchy changed, bit3=dynamic refresh flag found, bit4=xml injections, bit5=CoppeliaSim particles */
    sim_mujoco_global_int_end,

    sim_mujoco_global_bool_start=39000,
    sim_mujoco_global_computeinertias,
    sim_mujoco_global_multithreaded,
    sim_mujoco_global_multiccd,
    sim_mujoco_global_balanceinertias,
    sim_mujoco_global_overridecontacts,
    sim_mujoco_global_bool_end,

    sim_mujoco_joint_float_start=40000,
    sim_mujoco_joint_solreflimit1,
    sim_mujoco_joint_solreflimit2,
    sim_mujoco_joint_solimplimit1,
    sim_mujoco_joint_solimplimit2,
    sim_mujoco_joint_solimplimit3,
    sim_mujoco_joint_solimplimit4,
    sim_mujoco_joint_solimplimit5,
    sim_mujoco_joint_frictionloss,
    sim_mujoco_joint_solreffriction1,
    sim_mujoco_joint_solreffriction2,
    sim_mujoco_joint_solimpfriction1,
    sim_mujoco_joint_solimpfriction2,
    sim_mujoco_joint_solimpfriction3,
    sim_mujoco_joint_solimpfriction4,
    sim_mujoco_joint_solimpfriction5,
    sim_mujoco_joint_stiffness,
    sim_mujoco_joint_damping,
    sim_mujoco_joint_springref,
    sim_mujoco_joint_springdamper1,
    sim_mujoco_joint_springdamper2,
    sim_mujoco_joint_armature,
    sim_mujoco_joint_margin,
    sim_mujoco_joint_polycoef1, /* deprecated. Use simGetJointDependency instead */
    sim_mujoco_joint_polycoef2, /* deprecated. Use simGetJointDependency instead */
    sim_mujoco_joint_polycoef3,
    sim_mujoco_joint_polycoef4,
    sim_mujoco_joint_polycoef5,
    sim_mujoco_joint_pospid1,
    sim_mujoco_joint_pospid2,
    sim_mujoco_joint_pospid3,
    sim_mujoco_joint_float_end,

    sim_mujoco_joint_int_start=41000,
    sim_mujoco_joint_objectid, /* deprecated. */
    sim_mujoco_joint_dependentobjectid, /* deprecated. Use simGetJointDependency instead */
    sim_mujoco_joint_int_end,

    sim_mujoco_joint_bool_start=42000,
    sim_mujoco_joint_bool_end,

    sim_mujoco_body_float_start=43000,
    sim_mujoco_body_friction1,
    sim_mujoco_body_friction2,
    sim_mujoco_body_friction3,
    sim_mujoco_body_solref1,
    sim_mujoco_body_solref2,
    sim_mujoco_body_solimp1,
    sim_mujoco_body_solimp2,
    sim_mujoco_body_solimp3,
    sim_mujoco_body_solimp4,
    sim_mujoco_body_solimp5,
    sim_mujoco_body_solmix,
    sim_mujoco_body_margin,
    sim_mujoco_body_float_end,

    sim_mujoco_body_int_start=44000,
    sim_mujoco_body_condim,
    sim_mujoco_body_priority,
    sim_mujoco_body_int_end,

    sim_mujoco_body_bool_start=45000,
    sim_mujoco_body_bool_end,

    sim_mujoco_dummy_float_start=46000,
    sim_mujoco_dummy_range1,
    sim_mujoco_dummy_range2,
    sim_mujoco_dummy_solreflimit1,
    sim_mujoco_dummy_solreflimit2,
    sim_mujoco_dummy_solimplimit1,
    sim_mujoco_dummy_solimplimit2,
    sim_mujoco_dummy_solimplimit3,
    sim_mujoco_dummy_solimplimit4,
    sim_mujoco_dummy_solimplimit5,
    sim_mujoco_dummy_margin,
    sim_mujoco_dummy_springlength,
    sim_mujoco_dummy_stiffness,
    sim_mujoco_dummy_damping,
    sim_mujoco_dummy_float_end,

    sim_mujoco_dummy_int_start=47000,
    sim_mujoco_dummy_bitcoded,
    sim_mujoco_dummy_proxyjointid,
    sim_mujoco_dummy_int_end,

    sim_mujoco_dummy_bool_start=48000,
    sim_mujoco_dummy_limited,
    sim_mujoco_dummy_bool_end

};

enum { /* Default dynamic materials */
    sim_dynmat_default = 2310013, /* i.e. SIM_IDSTART_DEFDYNMATERIAL_old */
    sim_dynmat_highfriction,
    sim_dynmat_lowfriction,
    sim_dynmat_nofriction,
    sim_dynmat_reststackgrasp,
    sim_dynmat_foot,
    sim_dynmat_wheel,
    sim_dynmat_gripper,
    sim_dynmat_floor
};

enum { /* deprecated joint modes: */
    sim_jointmode_passive = 0, 
    sim_jointmode_motion_deprecated = 1, 
    sim_jointmode_ik_deprecated = 2, 
    sim_jointmode_reserved_previously_ikdependent = 3, 
    sim_jointmode_force = 5,
    sim_jointmode_hybrid_deprecated = 32 
};

enum { /* deprecated joint dyn. ctrl modes: */
    sim_jointdynctrl_positioncb = 9,
    sim_jointdynctrl_springcb = 13,
};

enum { /* deprecated */
    sim_moduleinfo_extversionstr = 0,
    sim_moduleinfo_builddatestr,
    sim_moduleinfo_extversionint,
    sim_moduleinfo_verbosity,
    sim_moduleinfo_statusbarverbosity,
};

enum { /* deprecated navigation and selection modes */
    sim_navigation_cameratilt               =0x000004, /* deprecated */
    sim_navigation_camerafly_old            =0x000006, /* deprecated */
    sim_navigation_camerarotaterightbutton  =0x002000, /* deprecated */
};

enum { /* Reflexxes Motion Library flags, deprecated. Use Ruckig instead. */
    /* enable one of following: */
    simrml_phase_sync_if_possible                   =0x0000,
    simrml_only_time_sync                           =0x0001,
    simrml_only_phase_sync                          =0x0002,
    simrml_no_sync                                  =0x0003,

    /* enable one of following: */
    simrml_keep_target_vel                          =0x0000,
    simrml_recompute_trajectory                     =0x0004,

    /* enable any: */
    simrml_disable_extremum_motion_states_calc      =0x0008,
    simrml_keep_current_vel_if_fallback_strategy    =0x0010
};

enum { /* deprecated */
    sim_filedlg_type_load=0,
    sim_filedlg_type_save,
    sim_filedlg_type_load_multiple,
    sim_filedlg_type_folder
};

enum { /* deprecated */
    sim_msgbox_type_info=0,
    sim_msgbox_type_question,
    sim_msgbox_type_warning,
    sim_msgbox_type_critical
};

enum { /* deprecated */
    sim_msgbox_buttons_ok=0,
    sim_msgbox_buttons_yesno,
    sim_msgbox_buttons_yesnocancel,
    sim_msgbox_buttons_okcancel
};

enum { /* deprecated */
    sim_msgbox_return_cancel=0,
    sim_msgbox_return_no,
    sim_msgbox_return_yes,
    sim_msgbox_return_ok,
    sim_msgbox_return_error
};

enum { /* deprecated */
    sim_pure_primitive_none=0,
    sim_pure_primitive_plane,
    sim_pure_primitive_disc,
    sim_pure_primitive_cuboid,
    sim_pure_primitive_spheroid,
    sim_pure_primitive_cylinder,
    sim_pure_primitive_cone,
    sim_pure_primitive_heightfield
};

enum { /* dummy types */
    sim_dummylink_dynloopclosure = 0,  /* deprecated */
    sim_dummy_linktype_dynamics_loop_closure = 0,  /* deprecated */
    sim_dummy_linktype_dynamics_force_constraint = 1, /* deprecated */
    sim_dummy_linktype_gcs_loop_closure = 2, /* deprecated */
    sim_dummy_linktype_gcs_tip = 3, /* deprecated */
    sim_dummy_linktype_gcs_target = 4, /* deprecated */
    sim_dummy_linktype_ik_tip_target = 5, /* deprecated */
    sim_dummy_linktype_reserved = 6,  /* deprecated */
    sim_dummylink_dyntendon = 7,  /* deprecated */
};

enum { /* path planning types */
    sim_pathplanning_holonomic=0,
    sim_pathplanning_reserved,
    sim_pathplanning_nonholonomic
};

enum { /* Holonomic path planning types */
    sim_holonomicpathplanning_xy=0,     // 2 DoF
    sim_holonomicpathplanning_xg,
    sim_holonomicpathplanning_xyz,      // 3 DoF
    sim_holonomicpathplanning_xyg,
    sim_holonomicpathplanning_abg,
    sim_holonomicpathplanning_xyzg,     // 4 DoF
    sim_holonomicpathplanning_xabg,
    sim_holonomicpathplanning_xyabg,    // 5 DoF
    sim_holonomicpathplanning_xyzabg    // 6 Dof
};

enum { /* deprecated */
    sim_lock_ui_wants_to_read=0,
    sim_lock_ui_wants_to_write,
    sim_lock_nonui_wants_to_write
};

enum { // deprecated rendering attributes:
        sim_displayattribute_renderpass     =0x0001,
        sim_displayattribute_depthpass      =0x0002,
        sim_displayattribute_pickpass       =0x0004,
        sim_displayattribute_selected       =0x0008,
        sim_displayattribute_groupselection_old =0x0010,
        sim_displayattribute_mainselection  =0x0020,
        sim_displayattribute_forcewireframe =0x0040,
        sim_displayattribute_forbidwireframe=0x0080,
        sim_displayattribute_forbidedges    =0x0100,
        sim_displayattribute_originalcolors =0x0200,
        sim_displayattribute_ignorelayer    =0x0400,
        sim_displayattribute_forvisionsensor    =0x0800,
        sim_displayattribute_colorcodedpickpass =0x1000,
        sim_displayattribute_colorcoded         =0x2000,
        sim_displayattribute_trianglewireframe  =0x4000,
        sim_displayattribute_inertiaonly        =0x8000,
        sim_displayattribute_thickEdges             =0x10000,
        sim_displayattribute_dynamiccontentonly     =0x20000,
        sim_displayattribute_mirror                 =0x40000,
        sim_displayattribute_useauxcomponent        =0x80000,
        sim_displayattribute_ignorerenderableflag   =0x100000,
        sim_displayattribute_noopenglcallbacks      =0x200000,
        sim_displayattribute_FREE                   =0x400000,
        sim_displayattribute_noghosts               =0x800000,
        sim_displayattribute_nopointclouds          =0x1000000,
        sim_displayattribute_nodrawingobjects       =0x2000000,
        sim_displayattribute_noparticles            =0x4000000,
        sim_displayattribute_colorcodedtriangles    =0x8000000
};

enum { /* Deprecated scene object properties */
    sim_objectproperty_reserved1    =0x0000,
    sim_objectproperty_reserved3    =0x0002,
    sim_objectproperty_reserved4    =0x0003,
    sim_objectproperty_reserved5    =0x0004,
    sim_objectproperty_reserved6    =0x0008,
    sim_objectproperty_canupdatedna             =0x0400,
    sim_objectproperty_hierarchyhiddenmodelchild=0x8000,
};

enum { /* Deprecated */
    sim_lua_arg_nil=0,
    sim_lua_arg_bool,
    sim_lua_arg_int,
    sim_lua_arg_float,
    sim_lua_arg_string,
    sim_lua_arg_invalid,
    sim_lua_arg_charbuff,
    sim_lua_arg_double,
    sim_lua_arg_table=8
};

enum { /* Deprecated OpenGl-based custom UI menu attributes: */
    sim_ui_menu_title       =1,
    sim_ui_menu_minimize    =2,
    sim_ui_menu_close       =4,
    sim_ui_menu_systemblock =8
};

enum { /* Deprecated OpenGl-based custom UI properties. Values are serialized. */
    sim_ui_property_visible                     =0x0001,
    sim_ui_property_visibleduringsimulationonly =0x0002,
    sim_ui_property_moveable                    =0x0004,
    sim_ui_property_relativetoleftborder        =0x0008,
    sim_ui_property_relativetotopborder         =0x0010,
    sim_ui_property_fixedwidthfont              =0x0020,
    sim_ui_property_systemblock                 =0x0040,
    sim_ui_property_settocenter                 =0x0080,
    sim_ui_property_rolledup                    =0x0100,
    sim_ui_property_selectassociatedobject      =0x0200,
    sim_ui_property_visiblewhenobjectselected   =0x0400,
    sim_ui_property_systemblockcanmovetofront   =0x0800,
    sim_ui_property_pauseactive                 =0x1000
};

enum { /* Deprecated button properties. Values are serialized. */
    sim_buttonproperty_button               =0x0000,
    sim_buttonproperty_label                =0x0001,
    sim_buttonproperty_slider               =0x0002,
    sim_buttonproperty_editbox              =0x0003,
    sim_buttonproperty_staydown             =0x0008,
    sim_buttonproperty_enabled              =0x0010,
    sim_buttonproperty_borderless           =0x0020,
    sim_buttonproperty_horizontallycentered =0x0040,
    sim_buttonproperty_ignoremouse          =0x0080,
    sim_buttonproperty_isdown               =0x0100,
    sim_buttonproperty_transparent          =0x0200,
    sim_buttonproperty_nobackgroundcolor    =0x0400,
    sim_buttonproperty_rollupaction         =0x0800,
    sim_buttonproperty_closeaction          =0x1000,
    sim_buttonproperty_verticallycentered   =0x2000,
    sim_buttonproperty_downupevent          =0x4000
};

enum { /* deprecated */
    sim_script_no_error                 =0,
    sim_script_main_script_nonexistent  =1,
    sim_script_main_script_not_called   =2,
    sim_script_reentrance_error         =4,
    sim_script_lua_error                =8,
    sim_script_call_error               =16
};

enum { /* deprecated */
    sim_scripttype_mainscript = sim_scripttype_main,
    sim_scripttype_childscript = sim_scripttype_simulation,
    sim_scripttype_addonscript = sim_scripttype_addon,
    sim_scripttype_addonfunction = 3,
    sim_scripttype_jointctrlcallback_old = 4,
    sim_scripttype_contactcallback_old = 5,
    sim_scripttype_customizationscript = sim_scripttype_customization,
    sim_scripttype_generalcallback_old = 7,
    sim_scripttype_sandboxscript = sim_scripttype_sandbox,
#if COPPELIASIM_ENABLE_DEPRECATED_SINCE >= 20201014
    sim_scripttype_threaded = 0x00f0
#else
    sim_scripttype_threaded_old = 0x00f0
#endif
};

enum { /* deprecated */
    sim_customizationscriptattribute_activeduringsimulation=0,
    sim_scriptattribute_executionorder,
    sim_scriptattribute_executioncount,
    sim_childscriptattribute_automaticcascadingcalls,
    sim_scriptattribute_enabled,
    sim_childscriptattribute_enabled=sim_scriptattribute_enabled,
    sim_customizationscriptattribute_cleanupbeforesave,
    sim_scriptattribute_debuglevel,
    sim_scriptattribute_scripttype,
    sim_scriptattribute_scripthandle
};

enum { /* deprecated */
    sim_scripttreetraversal_reverse=0,
    sim_scripttreetraversal_forward,
    sim_scripttreetraversal_parent
};

enum { /* Deprecated */
    sim_scriptdebug_none=0,
    sim_scriptdebug_syscalls=1,
    sim_scriptdebug_vars_interval=2,
    sim_scriptdebug_allcalls=3,
    sim_scriptdebug_vars=4,
    sim_scriptdebug_callsandvars=5
};

enum { /* Deprecated */
    sim_scriptthreadresume_launch           =-2,
    sim_scriptthreadresume_allnotyetresumed =-1,
    sim_scriptthreadresume_default          =0,
    sim_scriptthreadresume_actuation_first  =1,
    sim_scriptthreadresume_actuation_last   =2,
    sim_scriptthreadresume_sensing_first    =3,
    sim_scriptthreadresume_sensing_last     =4,
    sim_scriptthreadresume_custom           =5
};

enum { /* Deprecated */
    sim_callbackid_rossubscriber            =1,
    sim_callbackid_dynstep                  =2,
    sim_callbackid_userdefined              =1000
};


enum { /* Deprecated */
    sim_api_error_report =1,
    sim_api_error_output =2,
    sim_api_warning_output =4,
    sim_api_errormessage_ignore =0,
    sim_api_errormessage_report =1,
    sim_api_errormessage_output =2
};

enum { /* Deprecated special handle flags: */
    sim_handleflag_setmultiple          =0x00400000,
    sim_handleflag_altname              =0x00400000,
};

enum { /* Deprecated */
    sim_dlgstyle_message        =0,
    sim_dlgstyle_input,
    sim_dlgstyle_ok,
    sim_dlgstyle_ok_cancel,
    sim_dlgstyle_yes_no,
    sim_dlgstyle_dont_center    =32
};

enum { /* Deprecated */
    sim_dlgret_still_open=0,
    sim_dlgret_ok,
    sim_dlgret_cancel,
    sim_dlgret_yes,
    sim_dlgret_no
};

enum { /* Deprecated path properties: */
    sim_pathproperty_show_line              =0x0001,
    sim_pathproperty_show_orientation       =0x0002,
    sim_pathproperty_closed_path            =0x0004,
    sim_pathproperty_automatic_orientation  =0x0008,
    sim_pathproperty_invert_velocity_deprecated     =0x0010,
    sim_pathproperty_infinite_acceleration_deprecated   =0x0020,
    sim_pathproperty_flat_path              =0x0040,
    sim_pathproperty_show_position          =0x0080,
    sim_pathproperty_auto_velocity_profile_translation_deprecated   =0x0100,
    sim_pathproperty_auto_velocity_profile_rotation_deprecated      =0x0200,
    sim_pathproperty_endpoints_at_zero_deprecated                   =0x0400,
    sim_pathproperty_keep_x_up                          =0x0800
};

enum { /* Deprecated drawing objects: */
    sim_drawing_trianglepoints = 3,
    sim_drawing_quadpoints,
    sim_drawing_discpoints,
    sim_drawing_cubepoints,
    sim_drawing_spherepoints,
    sim_drawing_backfaceculling         =0x000100,
    sim_drawing_itemcolors              =0x000020,
    sim_drawing_vertexcolors            =0x000040,
    sim_drawing_itemsizes               =0x000080,
    sim_drawing_wireframe               =0x000200,
    sim_drawing_followparentvisibility  =0x000800,
    sim_drawing_50percenttransparency   =0x002000,
    sim_drawing_25percenttransparency   =0x004000,
    sim_drawing_12percenttransparency   =0x008000,
    sim_drawing_emissioncolor           =0x010000,
    sim_drawing_facingcamera            =0x020000,
    sim_drawing_itemtransparency        =0x080000,
    sim_drawing_persistent              =0x100000,
    sim_drawing_auxchannelcolor1        =0x200000,
    sim_drawing_auxchannelcolor2        =0x400000,
};

enum { /* Deprecated banner values: */
    sim_banner_left                     =0x00001,
    sim_banner_right                    =0x00002,
    sim_banner_nobackground             =0x00004,
    sim_banner_overlay                  =0x00008,
    sim_banner_followparentvisibility   =0x00010,
    sim_banner_clickselectsparent       =0x00020,
    sim_banner_clicktriggersevent       =0x00040,
    sim_banner_facingcamera             =0x00080,
    sim_banner_fullyfacingcamera        =0x00100,
    sim_banner_backfaceculling          =0x00200,
    sim_banner_keepsamesize             =0x00400,
    sim_banner_bitmapfont               =0x00800
};

enum { /* Deprecated particle objects: */
    sim_particle_points1=0,
    sim_particle_points2,
    sim_particle_points4,
    sim_particle_roughspheres,
    sim_particle_spheres,
    sim_particle_respondable1to4        =0x0020,
    sim_particle_respondable5to8        =0x0040,
    sim_particle_particlerespondable    =0x0080,
    sim_particle_ignoresgravity         =0x0100,
    sim_particle_invisible              =0x0200,
    sim_particle_itemsizes              =0x0400,
    sim_particle_itemdensities          =0x0800,
    sim_particle_itemcolors             =0x1000,
    sim_particle_cyclic                 =0x2000,
    sim_particle_emissioncolor          =0x4000,
    sim_particle_water                  =0x8000,
    sim_particle_painttag               =0x10000
};

enum { /* Deprecated scene object types. Values are serialized */
        sim_sceneobject_path = 8,
        sim_sceneobject_mill = 11,
        sim_sceneobject_mirror = 14
};


enum { /* Deprecated scene object main properties (serialized): */
        sim_objectspecialproperty_detectable_ultrasonic         = 0x0010,
        sim_objectspecialproperty_detectable_infrared           = 0x0020,
        sim_objectspecialproperty_detectable_laser              = 0x0040,
        sim_objectspecialproperty_detectable_inductive          = 0x0080,
        sim_objectspecialproperty_detectable_capacitive         = 0x0100,
        sim_objectspecialproperty_renderable                    = 0x0200,
        sim_objectspecialproperty_detectable_all                = 0x01f0,
        sim_objectspecialproperty_cuttable_old                  = 0x0400,
        sim_objectspecialproperty_pathplanning_ignored          = 0x0800
};

enum { /* Deprecated model properties (serialized): */
        sim_modelproperty_not_renderable                =0x0004,
        sim_modelproperty_not_cuttable_old              =0x0010
};

enum { /* Deprecated  */
        sim_object_shape_type = sim_sceneobject_shape,
        sim_object_joint_type = sim_sceneobject_joint,
        sim_object_graph_type = sim_sceneobject_graph,
        sim_object_camera_type = sim_sceneobject_camera,
        sim_object_dummy_type = sim_sceneobject_dummy,
        sim_object_proximitysensor_type = sim_sceneobject_proximitysensor,
        sim_object_path_type = sim_sceneobject_path,
        sim_object_visionsensor_type = sim_sceneobject_visionsensor,
        sim_object_mill_type = sim_sceneobject_mill,
        sim_object_forcesensor_type = sim_sceneobject_forcesensor,
        sim_object_light_type = sim_sceneobject_light,
        sim_object_mirror_type = sim_sceneobject_mirror,
        sim_object_octree_type = sim_sceneobject_octree,
        sim_object_pointcloud_type = sim_sceneobject_pointcloud,
        sim_object_script_type = sim_sceneobject_script,
};

enum { /* Deprecated  */
    sim_appobj_object_type = sim_objecttype_sceneobject,
    sim_appobj_collision_type = 110,
    sim_appobj_distance_type = 111,
    sim_appobj_simulation_type = 112,
    sim_appobj_ik_type = 113,
    sim_appobj_constraintsolver_type_old = 114,
    sim_appobj_collection_type = sim_objecttype_collection,
    sim_appobj_ui_type = 116,
    sim_appobj_script_type = 117,
    sim_appobj_pathplanning_type = 118,
    sim_appobj_texture_type = sim_objecttype_texture,
    sim_appobj_motionplanning_type_old = 121
};

enum { /* Deprecated  */
        sim_light_omnidirectional_subtype = sim_light_omnidirectional,
        sim_light_spot_subtype = sim_light_spot,
        sim_light_directional_subtype = sim_light_directional,
        sim_joint_revolute_subtype = sim_joint_revolute,
        sim_joint_prismatic_subtype = sim_joint_prismatic,
        sim_joint_spherical_subtype = sim_joint_spherical,
        sim_shape_simpleshape_subtype = sim_shape_simple,
        sim_shape_multishape_subtype = sim_shape_compound,
        sim_proximitysensor_pyramid_subtype = sim_proximitysensor_pyramid,
        sim_proximitysensor_cylinder_subtype = sim_proximitysensor_cylinder,
        sim_proximitysensor_disc_subtype = sim_proximitysensor_disc,
        sim_proximitysensor_cone_subtype = sim_proximitysensor_cone,
        sim_proximitysensor_ray_subtype = sim_proximitysensor_ray,
        sim_mill_pyramid_subtype = 40,
        sim_mill_cylinder_subtype = 41,
        sim_mill_disc_subtype = 42,
        sim_mill_cone_subtype = 43,
        sim_object_no_subtype = 200
};

enum { /* Deprecated  */
        sim_ik_pseudo_inverse_method=0,
        sim_ik_damped_least_squares_method,
        sim_ik_jacobian_transpose_method,
        sim_ik_undamped_pseudo_inverse_method
};

enum { /* Deprecated  */
        sim_ik_x_constraint=1,
        sim_ik_y_constraint=2,
        sim_ik_z_constraint=4,
        sim_ik_alpha_beta_constraint=8,
        sim_ik_gamma_constraint=16,
        sim_ik_avoidance_constraint_old=64
};

enum { /* Deprecated  */
    sim_ikresult_not_performed=0,
    sim_ikresult_success,
    sim_ikresult_fail
};

enum { /* Deprecated filter component types. Not used anymore (use vision callback functions instead) */
    sim_filtercomponent_originalimage_deprecated=1,
    sim_filtercomponent_originaldepth_deprecated,
    sim_filtercomponent_uniformimage_deprecated,
    sim_filtercomponent_tooutput_deprecated,
    sim_filtercomponent_tobuffer1_deprecated,
    sim_filtercomponent_tobuffer2_deprecated,
    sim_filtercomponent_frombuffer1_deprecated,
    sim_filtercomponent_frombuffer2_deprecated,
    sim_filtercomponent_swapbuffers_deprecated,
    sim_filtercomponent_addbuffer1_deprecated,
    sim_filtercomponent_subtractbuffer1_deprecated,
    sim_filtercomponent_multiplywithbuffer1_deprecated,
    sim_filtercomponent_horizontalflip_deprecated,
    sim_filtercomponent_verticalflip_deprecated,
    sim_filtercomponent_rotate_deprecated,
    sim_filtercomponent_shift_deprecated,
    sim_filtercomponent_resize_deprecated,
    sim_filtercomponent_3x3filter_deprecated,
    sim_filtercomponent_5x5filter_deprecated,
    sim_filtercomponent_sharpen_deprecated,
    sim_filtercomponent_edge_deprecated,
    sim_filtercomponent_rectangularcut_deprecated,
    sim_filtercomponent_circularcut_deprecated,
    sim_filtercomponent_normalize_deprecated,
    sim_filtercomponent_intensityscale_deprecated,
    sim_filtercomponent_keeporremovecolors_deprecated,
    sim_filtercomponent_scaleandoffsetcolors_deprecated,
    sim_filtercomponent_binary_deprecated,
    sim_filtercomponent_swapwithbuffer1_deprecated,
    sim_filtercomponent_addtobuffer1_deprecated,
    sim_filtercomponent_subtractfrombuffer1_deprecated,
    sim_filtercomponent_correlationwithbuffer1_deprecated,
    sim_filtercomponent_colorsegmentation_deprecated,
    sim_filtercomponent_blobextraction_deprecated,
    sim_filtercomponent_imagetocoord_deprecated,
    sim_filtercomponent_pixelchange_deprecated,
    sim_filtercomponent_velodyne_deprecated,
    sim_filtercomponent_todepthoutput_deprecated,
    sim_filtercomponent_customized_deprecated=1000
};

#define SIMX_VERSION 11
#define SIMX_HEADER_SIZE 18
#define simx_headeroffset_crc 0             /* 1 simxUShort. Generated by the client or server. The CRC for the message */
#define simx_headeroffset_version 2         /* 1 byte. Generated by the client or server. The version of the remote API software */
#define simx_headeroffset_message_id 3      /* 1 simxInt. Generated by the client (and used in a reply by the server) */
#define simx_headeroffset_client_time 7     /* 1 simxInt. Client time stamp generated by the client (and sent back by the server) */
#define simx_headeroffset_server_time 11    /* 1 simxInt. Generated by the server when a reply is generated. The server timestamp */
#define simx_headeroffset_scene_id 15       /* 1 simxUShort. Generated by the server. A unique ID identifying the scene currently displayed */
#define simx_headeroffset_server_state 17   /* 1 byte. Generated by the server. Bit coded: 0 set --> simulation not stopped, 1 set --> simulation paused, 2 set --> real-time switch on, 3-5: edit mode type (0=no edit mode, 1=triangle, 2=vertex, 3=edge, 4=path, 5=UI) */
#define SIMX_SUBHEADER_SIZE 26
#define simx_cmdheaderoffset_mem_size 0         /* 1 simxInt. Generated by the client or server. The buffer size of the command. */
#define simx_cmdheaderoffset_full_mem_size 4    /* 1 simxInt. Generated by the client or server. The full buffer size of the command (applies to split chunks). */
#define simx_cmdheaderoffset_pdata_offset0 8    /* 1 simxUShort. Generated by the client or server. The amount of data that is part of the command identification. */
#define simx_cmdheaderoffset_pdata_offset1 10   /* 1 simxInt. Generated by the client or server. The amount of shift of the pure data buffer (applies to split chunks). */
#define simx_cmdheaderoffset_cmd 14             /* 1 simxInt. Generated by the client (and used in a reply by the server). The command, combined with the operation mode of the command. */
#define simx_cmdheaderoffset_delay_or_split 18  /* 1 simxUShort. Generated by the client or server. The amount of delay in ms of a streaming command, or the max. pure data size to send at once (applies to split commands). */
#define simx_cmdheaderoffset_sim_time 20        /* 1 simxInt. Generated by the server. The simulation time (in ms) when the command was executed (or 0 if simulation is not running) */
#define simx_cmdheaderoffset_status 24          /* 1 byte. Generated by the server. (1: bit 0 is set --> error in function execution on server side). The client writes bit 1 if command cannot be overwritten*/
#define simx_cmdheaderoffset_reserved 25        /* 1 byte. Not yet used */
enum {  simx_cmdnull_start              =0,
        simx_cmd_synchronous_enable,
        simx_cmd_synchronous_disable,
        simx_cmd_synchronous_next,
        simx_cmd_get_last_errors,
        simx_cmd_close_scene,
        simx_cmd_get_object_selection,
        simx_cmd_reserved1,
        simx_cmd_reserved2,
        simx_cmd_create_dummy,
        simx_cmd_kill_connection,
        simx_cmdnull_custom_start       =0x000800,
        simx_cmd4bytes_start            =0x001000,
        simx_cmd_get_joint_position,
        simx_cmd_set_joint_position,
        simx_cmd_get_vision_sensor_image_bw,
        simx_cmd_get_vision_sensor_image_rgb,
        simx_cmd_set_vision_sensor_image_bw,
        simx_cmd_set_vision_sensor_image_rgb,
        simx_cmd_start_pause_stop_simulation,
        simx_cmd_set_joint_target_velocity,
        simx_cmd_read_proximity_sensor,
        simx_cmd_get_joint_matrix,
        simx_cmd_set_spherical_joint_matrix,
        simx_cmd_set_joint_target_position,
        simx_cmd_get_joint_force,
        simx_cmd_set_joint_force,
        simx_cmd_read_force_sensor,
        simx_cmd_break_force_sensor,
        simx_cmd_read_vision_sensor,
        simx_cmd_get_object_parent,
        simx_cmd_spotcanbeused5,
        simx_cmd_aux_console_close,
        simx_cmd_aux_console_print,
        simx_cmd_aux_console_show,
        simx_cmd_get_vision_sensor_depth_buffer,
        simx_cmd_get_object_orientation,
        simx_cmd_get_object_position,
        simx_cmd_set_object_orientation,
        simx_cmd_set_object_position,
        simx_cmd_set_object_parent,
        simx_cmd_get_array_parameter,
        simx_cmd_set_array_parameter,
        simx_cmd_get_boolean_parameter,
        simx_cmd_set_boolean_parameter,
        simx_cmd_get_integer_parameter,
        simx_cmd_set_integer_parameter,
        simx_cmd_get_floating_parameter,
        simx_cmd_set_floating_parameter,
        simx_cmd_get_string_parameter,
        simx_cmd_read_collision,
        simx_cmd_read_distance,
        simx_cmd_remove_object,
        simx_cmd_remove_ui,
        simx_cmd_get_objects,
        simx_cmd_end_dialog,
        simx_cmd_get_dialog_input,
        simx_cmd_get_dialog_result,
        simx_cmd_copy_paste_objects,
        simx_cmd_set_object_selection,
        simx_cmd_spotcanbeused1,
        simx_cmd_spotcanbeused2,
        simx_cmd_spotcanbeused3,
        simx_cmd_spotcanbeused4,
        simx_cmd_get_model_property,
        simx_cmd_set_model_property,
        simx_cmd_get_object_velocity,
        simx_cmd_remove_model,
        simx_cmd_get_joint_max_force,
        simx_cmd4bytes_custom_start =0x001800,
        simx_cmd_set_object_quaternion,
        simx_cmd8bytes_start            =0x002000,
        simx_cmd_get_ui_slider,
        simx_cmd_set_ui_slider,
        simx_cmd_get_ui_event_button,
        simx_cmd_get_ui_button_property,
        simx_cmd_set_ui_button_property,
        simx_cmd_set_ui_button_label,
        simx_cmd_get_object_float_parameter,
        simx_cmd_get_object_int_parameter,
        simx_cmd_set_object_float_parameter,
        simx_cmd_set_object_int_parameter,
        simx_cmd_get_object_child,
        simx_cmd_get_object_group_data,
        simx_cmd_get_object_orientation2,
        simx_cmd_get_object_position2,
        simx_cmd_check_collision,
        simx_cmd_check_distance,
        simx_cmd8bytes_custom_start     =0x002800,
        simx_cmd_get_object_quaternion,
        simx_cmd1string_start           =0x003000,
        simx_cmd_get_object_handle,
        simx_cmd_load_scene,
        simx_cmd_load_model,
        simx_cmd_transfer_file,
        simx_cmd_load_ui,
        simx_cmd_erase_file,
        simx_cmd_get_ui_handle,
        simx_cmd_add_statusbar_message,
        simx_cmd_aux_console_open,
        simx_cmd_get_collision_handle,
        simx_cmd_get_distance_handle,
        simx_cmd_display_dialog,
        simx_cmd_clear_float_signal,
        simx_cmd_clear_integer_signal,
        simx_cmd_clear_string_signal,
        simx_cmd_get_float_signal,
        simx_cmd_get_integer_signal,
        simx_cmd_get_string_signal,
        simx_cmd_set_float_signal,
        simx_cmd_set_integer_signal,
        simx_cmd_set_string_signal,
        simx_cmd_append_string_signal,
        simx_cmd_write_string_stream=simx_cmd_append_string_signal,
        simx_cmd_get_and_clear_string_signal,
        simx_cmd_read_string_stream,
        simx_cmd_get_collection_handle,
        simx_cmd4bytes2strings_start            =0x003400,
        simx_cmd_call_script_function,
        simx_cmd4bytes2strings_end              =0x003500,
        simx_cmd1string_custom_start    =0x003800,
        simx_cmdreserved_start          =0x004000,
        simx_cmdmask                    =0x00ffff,
        simx_opmode_oneshot             =0x000000,      /* sends command as one chunk. Reply will also come as one chunk. Doesn't wait for the reply. */
        simx_opmode_blocking            =0x010000,      /* sends command as one chunk. Reply will also come as one chunk. Waits for the reply (_REPLY_WAIT_TIMEOUT_IN_MS is the timeout). */
        simx_opmode_oneshot_wait        =0x010000,      /* same as simx_opmode_blocking */
        simx_opmode_streaming           =0x020000,      /* sends command as one chunk. Command will be stored on the server and always executed (every x ms (as far as possible), where x can be 0-65535. just add x to simx_opmode_streaming). A reply will be sent continuously, each time as one chunk. Doesn't wait for the reply. */
        simx_opmode_continuous          =0x020000,      /* same as simx_opmode_streaming */
        simx_opmode_oneshot_split       =0x030000,      /* sends command as several chunks (max chunk size is x bytes, where x can be _MIN_SPLIT_AMOUNT_IN_BYTES-65535. Just add x to simx_opmode_oneshot_split). Reply will also come as several chunks. Doesn't wait for the reply. */
        simx_opmode_streaming_split     =0x040000,      /* sends command as several chunks (max chunk size is x bytes, where x can be _MIN_SPLIT_AMOUNT_IN_BYTES-65535. Just add x to simx_opmode_streaming_split). Command will be stored on the server and always executed. A reply will be sent continuously, each time as several chunks. Doesn't wait for the reply. */
        simx_opmode_continuous_split    =0x040000,      /* same as simx_opmode_streaming_split */
        simx_opmode_discontinue         =0x050000,      /* removes and cancels all commands of the given type stored on the client or server side (also streaming commands) */
        simx_opmode_buffer              =0x060000,      /* doesn't send anything, but checks if a reply for the given command is available in the input buffer (i.e. previously received from the server) */
        simx_opmode_remove              =0x070000       /* doesn't send anything and doesn't return any specific value. It just erases a similar command reply in the inbox (to free some memory) */
};
enum {  simx_return_ok                      =0x000000,
        simx_return_novalue_flag            =0x000001,      /* input buffer doesn't contain the specified command. Maybe you forgot to enable data streaming, or streaming hasn't started yet */
        simx_return_timeout_flag            =0x000002,      /* command reply not received in time for simx_opmode_blocking operation mode */
        simx_return_illegal_opmode_flag     =0x000004,      /* command doesn't support the specified operation mode */
        simx_return_remote_error_flag       =0x000008,      /* command caused an error on the server side */
        simx_return_split_progress_flag     =0x000010,      /* previous similar command not yet fully processed (applies to simx_opmode_oneshot_split operation modes) */
        simx_return_local_error_flag        =0x000020,      /* command caused an error on the client side */
        simx_return_initialize_error_flag   =0x000040       /* simxStart was not yet called */
};
enum {  simx_error_noerror                  =0x000000,
        simx_error_novalue_flag             =0x000001,
        simx_error_timeout_flag             =0x000002,
        simx_error_illegal_opmode_flag      =0x000004,
        simx_error_remote_error_flag        =0x000008,
        simx_error_split_progress_flag      =0x000010,
        simx_error_local_error_flag         =0x000020,
        simx_error_initialize_error_flag    =0x000040
};
enum {  simros_strmcmdnull_start                =0,
        simros_strmcmd_get_object_selection,
        simros_strmcmd_get_info, // do not use. Is streamed anyway with topic name "info"
        simros_strmcmdnull_subscriber_start         =0x000800,
        simros_strmcmd_add_status_bar_message,
        simros_strmcmd_set_object_selection,
        simros_strmcmd_set_joint_state,
        simros_strmcmdint_start         =0x001000,
        simros_strmcmd_get_array_parameter,
        simros_strmcmd_get_boolean_parameter,
        simros_strmcmd_get_dialog_result,
        simros_strmcmd_get_floating_parameter,
        simros_strmcmd_get_integer_parameter,
        simros_strmcmd_get_joint_state,
        simros_strmcmd_get_object_parent,
        simros_strmcmd_get_objects,
        simros_strmcmd_get_string_parameter,
        simros_strmcmd_get_ui_event_button,
        simros_strmcmd_get_vision_sensor_depth_buffer,
        simros_strmcmd_get_vision_sensor_image,
        simros_strmcmd_read_collision,
        simros_strmcmd_read_distance,
        simros_strmcmd_read_force_sensor,
        simros_strmcmd_read_proximity_sensor,
        simros_strmcmd_read_vision_sensor,
        simros_strmcmd_get_vision_sensor_info,
        simros_strmcmd_get_range_finder_data,
        simros_strmcmd_get_laser_scanner_data,
        simros_strmcmd_get_odom_data,
        simros_strmcmd_get_depth_sensor_data,
        simros_strmcmdint_subscriber_start          =0x001800,
        simros_strmcmd_auxiliary_console_print,
        simros_strmcmd_set_array_parameter,
        simros_strmcmd_set_boolean_parameter,
        simros_strmcmd_set_floating_parameter,
        simros_strmcmd_set_integer_parameter,
        simros_strmcmd_set_joint_force,
        simros_strmcmd_set_joint_position,
        simros_strmcmd_set_joint_target_position,
        simros_strmcmd_set_joint_target_velocity,
        simros_strmcmd_set_vision_sensor_image,
        simros_strmcmd_set_joy_sensor,
        simros_strmcmd_set_twist_command,
        simros_strmcmdintint_start          =0x002000,
        simros_strmcmd_get_object_pose,
        simros_strmcmd_get_object_float_parameter,
        simros_strmcmd_get_object_int_parameter,
        simros_strmcmd_get_ui_button_property,
        simros_strmcmd_get_ui_slider,
        simros_strmcmd_get_transform,
        simros_strmcmd_get_object_group_data,
        simros_strmcmdintint_subscriber_start           =0x002800,
        simros_strmcmd_set_object_float_parameter,
        simros_strmcmd_set_object_int_parameter,
        simros_strmcmd_set_object_pose,
        simros_strmcmd_set_object_position,
        simros_strmcmd_set_object_quaternion,
        simros_strmcmd_set_ui_button_label,
        simros_strmcmd_set_ui_button_property,
        simros_strmcmd_set_ui_slider,
        simros_strmcmdstring_start          =0x003000,
        simros_strmcmd_get_float_signal,
        simros_strmcmd_get_integer_signal,
        simros_strmcmd_get_string_signal,
        simros_strmcmd_reserved1,
        simros_strmcmd_get_and_clear_string_signal,
        simros_strmcmdstring_subscriber_start           =0x003800,
        simros_strmcmd_clear_float_signal,
        simros_strmcmd_clear_integer_signal,
        simros_strmcmd_clear_string_signal,
        simros_strmcmd_set_float_signal,
        simros_strmcmd_set_integer_signal,
        simros_strmcmd_set_string_signal,
        simros_strmcmd_reserved2,
        simros_strmcmd_append_string_signal,
        simros_strmcmd_set_joint_trajectory,
        simros_strmcmdintstring_start           =0x004000,
        simros_strmcmd_get_twist_status,
        simros_strmcmd_receive_data_from_script_function,
        simros_strmcmdintstring_subscriber_start            =0x004800,
        simros_strmcmd_send_data_to_script_function,
        simros_strmcmdreserved_start            =0x005000,
};
