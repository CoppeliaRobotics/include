#if !defined(SIMCONST_INCLUDED_)
#define SIMCONST_INCLUDED_

#define TOSTRING0(x) #x
#define TOSTRING(x) TOSTRING0(x)

#define SIM_VERSION_MAJOR 4
#define SIM_VERSION_MINOR 10
#define SIM_VERSION_PATCH 0
#define SIM_VERSION_REVNB 0

#ifndef SIM_EVENT_PROTOCOL_VERSION
#define SIM_EVENT_PROTOCOL_VERSION 3
#endif // SIM_EVENT_PROTOCOL_VERSION

#define LARGE_PROPERTY_SIZE 200

// for checking version:
#define SIM_VERSION_CHECK(major, minor, patch, rev) ((((major) * 10000) + ((minor) * 100) + (patch)) * 100 + (rev))
#define SIM_VERSION SIM_VERSION_CHECK(SIM_VERSION_MAJOR, SIM_VERSION_MINOR, SIM_VERSION_PATCH, SIM_VERSION_REVNB)
#define SIM_VERSION_STR TOSTRING(SIM_VERSION_MAJOR) "." TOSTRING(SIM_VERSION_MINOR) "." TOSTRING(SIM_VERSION_PATCH) " (rev. " TOSTRING(SIM_VERSION_REVNB) ")"
#define SIM_VERSION_STR_SHORT TOSTRING(SIM_VERSION_MAJOR) "." TOSTRING(SIM_VERSION_MINOR) "." TOSTRING(SIM_VERSION_PATCH) "." TOSTRING(SIM_VERSION_REVNB)
// e.g.: #if SIM_VERSION >= SIM_VERSION_CHECK(4, 6, 0, 2) ...

// derive the old macros for backwards compatibility:
#define SIM_PROGRAM_REVISION_NB SIM_VERSION_REVNB
#define SIM_PROGRAM_VERSION_NB (((SIM_VERSION_MAJOR) * 10000) + ((SIM_VERSION_MINOR) * 100) + (SIM_VERSION_PATCH))
#define SIM_PROGRAM_FULL_VERSION_NB ((SIM_PROGRAM_VERSION_NB) * 100 + (SIM_PROGRAM_REVISION_NB))
#define SIM_PROGRAM_VERSION TOSTRING(SIM_VERSION_MAJOR) "." TOSTRING(SIM_VERSION_MINOR) "." TOSTRING(SIM_VERSION_PATCH)
#define SIM_PROGRAM_REVISION "(rev. " TOSTRING(SIM_VERSION_REVNB) ")"

#ifndef SIM_DISABLE_DEPRECATED_BEFORE
#define SIM_DISABLE_DEPRECATED_BEFORE 0
#endif

/* Scene object types. Values are serialized */
enum {
        sim_sceneobject_shape =0,
        sim_sceneobject_joint = 1,
        sim_sceneobject_graph = 2,
        sim_sceneobject_camera = 3,
        sim_sceneobject_dummy = 4,
        sim_sceneobject_proximitysensor = 5,
        sim_sceneobject_visionsensor = 9,
        sim_sceneobject_forcesensor = 12,
        sim_sceneobject_light = 13,
        sim_sceneobject_octree = 15,
        sim_sceneobject_pointcloud = 16,
        sim_sceneobject_script = 17,
};

/* General object types. Values are serialized */
enum {
    sim_objecttype_sceneobject = 109,
    sim_objecttype_collection = 115,
    sim_objecttype_script = 117,
    sim_objecttype_texture = 120,
    sim_objecttype_mesh = 122,
    sim_objecttype_interfacestack = 123,
};

/* Scene object sub-types. Values are serialized (see also deprecated values below) */
enum {
        sim_light_omnidirectional = 1,
        sim_light_spot = 2,
        sim_light_directional = 3,
        sim_joint_revolute = 10,
        sim_joint_prismatic = 11,
        sim_joint_spherical = 12,
        sim_shape_simple = 20,
        sim_shape_compound = 21,
        sim_proximitysensor_pyramid = 30,
        sim_proximitysensor_cylinder = 31,
        sim_proximitysensor_disc = 32,
        sim_proximitysensor_cone = 33,
        sim_proximitysensor_ray = 34,
};

enum { /* type of arguments (input and output) for custom script commands */
    sim_script_arg_null=0,
    sim_script_arg_bool,
    sim_script_arg_int32,
    sim_script_arg_float,
    sim_script_arg_string,
    sim_script_arg_invalid,
    sim_script_arg_charbuff,
    sim_script_arg_double,
    sim_script_arg_table=8
    /* SIM_SCRIPT_ARG_NULL_ALLOWED=65536 is defined and used in CScriptFunctionData.h. This flag is reserved here. */
};

enum { /* Simulation status */
    sim_simulation_stopped                      =0x00,                              /* Simulation is stopped */
    sim_simulation_paused                       =0x08,                              /* Simulation is paused */
    sim_simulation_advancing                    =0x10,                              /* Simulation is advancing */
    sim_simulation_advancing_firstafterstop     =sim_simulation_advancing|0x00,     /* First simulation pass (1x) */
    sim_simulation_advancing_running            =sim_simulation_advancing|0x01,     /* Normal simulation pass (>=1x) */
    /* reserved                                 =sim_simulation_advancing|0x02, */
    sim_simulation_advancing_lastbeforepause    =sim_simulation_advancing|0x03,     /* Last simulation pass before pause (1x) */
    sim_simulation_advancing_firstafterpause    =sim_simulation_advancing|0x04,     /* First simulation pass after pause (1x) */
    sim_simulation_advancing_abouttostop        =sim_simulation_advancing|0x05,     /* "Trying to stop" simulation pass (>=1x) */
    sim_simulation_advancing_lastbeforestop     =sim_simulation_advancing|0x06      /* Last simulation pass (1x) */
};

enum { /* Script types (serialized!) */
    sim_scripttype_main = 0,
    sim_scripttype_simulation = 1,
    sim_scripttype_addon = 2,
    sim_scripttype_customization = 6,
    sim_scripttype_sandbox = 8,
    sim_scripttype_passive = 9,
};

enum { /* System callbacks */
    sim_syscb_info=0,
    sim_syscb_cleanup, /* last time called. Do some clean-up */
    sim_syscb_init,
    sim_syscb_nonsimulation, /* called while simulation not running */
    sim_syscb_beforesimulation, /* called just before simulation starts */
    sim_syscb_aftersimulation, /* called just after simulation ended */
    sim_syscb_actuation, /* called in the "actuation" phase of the main script. Called only if the script is flagged as sim_customizationscriptattribute_activeduringsimulation */
    sim_syscb_sensing, /* called in the "sensing" phase of the main script. Called only if the script is flagged as sim_customizationscriptattribute_activeduringsimulation */
    sim_syscb_suspended, /* called while simulation is paused */
    sim_syscb_suspend, /* called just after a simulation was paused */
    sim_syscb_resume, /* called just before a simulation is unpaused */
    sim_syscb_beforeinstanceswitch, /* called just before an instance switch (switch to another scene) */
    sim_syscb_afterinstanceswitch, /* called just after an instance switch (switch to another scene) */
    sim_syscb_beforecopy, /* called just before objects are copied (in an object copy/cut operation, or a model save operation). Arg1 is a map with 'objectHandles' keys */
    sim_syscb_aftercopy, /* called just after objects were copied. Arg1 is a map with 'objectHandles' keys */
    sim_syscb_aos_run_old, /* deprecated */
    sim_syscb_aos_suspend, /* special for add-on scripts */
    sim_syscb_aos_resume, /* special for add-on scripts */
    sim_syscb_jointcallback, /* deprecated. Use sim_syscb_joint instead */
    sim_syscb_contactcallback, /* deprecated. Use sim_syscb_contact instead */
    sim_syscb_customcallback1, /* reserved */
    sim_syscb_customcallback2, /* reserved */
    sim_syscb_customcallback3, /* reserved */
    sim_syscb_customcallback4, /* reserved */
    sim_syscb_beforedelete, /* called just before objects are deleted (in an object delete or cut operation). Arg1 is a map with 'objectHandles' and 'allObjects' keys */
    sim_syscb_afterdelete, /* called just after objects were deleted. Arg1 is a map with 'objectHandles' keys */
    sim_syscb_aftercreate, /* called just after objects were created/pasted/loaded. Not called for the created objects. Arg1 is a map with 'objectHandles' array */
    sim_syscb_threadmain, /* deprecated. Use sim_syscb_thread instead */
    sim_syscb_dyncallback, /* deprecated. Use sim_syscb_dyn instead */
    sim_syscb_beforemainscript, /* called just before calling the main script. Can be used to step a simulation */
    sim_syscb_vision, /* called just after a vision sensor image was acquired, for processing */
    sim_syscb_trigger, /* called by vision, proximity or force/torque sensors when they trigger */
    sim_syscb_userconfig, /* called for the customization script, when the user double-clicks the script simulation parameters icon */
    sim_syscb_moduleentry, /* called when a module menu entry is selected. Must be first created with sim.moduleEntry */
    sim_syscb_event, /* called on many different occasions, mainly to synchronize CoppeliaSim with an external application */
    sim_syscb_ext, /* intercepts user callback calls */
    sim_syscb_realtimeidle, /* when in real-time mode, idle signaling */
    sim_syscb_beforesave, /* called just before a scene save operation */
    sim_syscb_aftersave, /* called just after a scene save operation */
    sim_syscb_msg, /* triggered via sim.broadcastMsg */
    sim_syscb_dyn, /* called by the physics engine twice per dyn. simulation pass */
    sim_syscb_contact, /* called by the physics engine when two respondable shapes are contacting */
    sim_syscb_joint, /* called with dyn. joints in custom ctrl mode, and kin. joints with sim.setJointTargetPosition & similar commands */
    sim_syscb_thread, /* the main section of a threaded script */
    sim_syscb_selchange, /* called when selection changed */
    sim_syscb_data, /* called when a custom data block changed */
    sim_syscb_afterload, /* called just after a scene load operation */
    sim_syscb_endoflist
};

enum { /* code lang (scripts) */
    sim_lang_undefined=-1,
    sim_lang_lua=0,
    sim_lang_python
};

enum { /* Script execution order, is serialized */
    sim_scriptexecorder_first=0,
    sim_scriptexecorder_normal,
    sim_scriptexecorder_last
};

enum { /* special argument of some functions: */
    sim_handle_world                    = -1,
    sim_handle_all                      = -2,
    sim_handle_all_except_explicit      = -3,
    sim_handle_self                     = -4,
    sim_handle_mainscript               = -5,
    sim_handle_main_script              = sim_handle_mainscript, /* deprecated */
    sim_handle_tree                     = -6,
    sim_handle_chain                    = -7,
    sim_handle_single                   = -8,
    sim_handle_default                  = -9,
    sim_handle_all_except_self          = -10,
    sim_handle_parent                   = -11,
    sim_handle_scene                    = -12,
    sim_handle_app                      = -13,
    sim_handle_inverse                  = -14,
    sim_handle_appstorage               = -15,
    sim_handle_sceneobject              = -16,
    sim_handle_sandbox                  = -17,
    sim_handle_mesh                     = -18,
};

enum { /* special handle flags (use only below 4 bits, i.e. 0x3c00000): */
#if defined(USE_LONG_LONG_HANDLES) || defined(SIM_UNIFIED_HANDLES)
    sim_handleflag_assembly             =0x0040000000000000,
    sim_handleflag_togglevisibility     =0x0040000000000000,
    sim_handleflag_extended             =0x0040000000000000,
    sim_handleflag_greyscale            =0x0040000000000000,
    sim_handleflag_codedstring          =0x0040000000000000, /* all, except double */
    sim_handleflag_wxyzquat             =0x0100000000000000,
    sim_handleflag_reljointbaseframe    =0x0040000000000000,
    sim_handleflag_addmultiple          =0x0100000000000000,
    sim_handleflag_abscoords            =0x0080000000000000,
    sim_handleflag_depthbuffer          =0x0080000000000000,
    sim_handleflag_depthbuffermeters    =0x0080000000000000,
    sim_handleflag_keeporiginal         =0x0040000000000000,
    sim_handleflag_camera               =0x0040000000000000,
    sim_handleflag_axis                 =0x0040000000000000,
    sim_handleflag_resetforce           =0x0040000000000000,
    sim_handleflag_resettorque          =0x0080000000000000,
    sim_handleflag_resetforcetorque     =sim_handleflag_resetforce|sim_handleflag_resettorque,
    sim_handleflag_model                =0x0080000000000000,
    sim_handleflag_rawvalue             =0x0100000000000000,
    sim_handleflag_silenterror          =0x0200000000000000,
#else
    sim_handleflag_assembly             =0x00400000,
    sim_handleflag_togglevisibility     =0x00400000,
    sim_handleflag_extended             =0x00400000,
    sim_handleflag_greyscale            =0x00400000,
    sim_handleflag_codedstring          =0x00400000, /* all, except double */
    sim_handleflag_wxyzquat             =0x01000000,
    sim_handleflag_reljointbaseframe    =0x00400000,
    sim_handleflag_addmultiple          =0x01000000,
    sim_handleflag_abscoords            =0x00800000,
    sim_handleflag_depthbuffer          =0x00800000,
    sim_handleflag_depthbuffermeters    =0x00800000,
    sim_handleflag_keeporiginal         =0x00400000,
    sim_handleflag_camera               =0x00400000,
    sim_handleflag_axis                 =0x00400000,
    sim_handleflag_resetforce           =0x00400000,
    sim_handleflag_resettorque          =0x00800000,
    sim_handleflag_resetforcetorque     =sim_handleflag_resetforce|sim_handleflag_resettorque,
    sim_handleflag_model                =0x00800000,
    sim_handleflag_rawvalue             =0x01000000,
    sim_handleflag_silenterror          =0x02000000,
#endif
};

enum { /* distance calculation methods: (serialized) */
    sim_distcalcmethod_dl=0,
    sim_distcalcmethod_dac,
    sim_distcalcmethod_max_dl_dac,
    sim_distcalcmethod_dl_and_dac,
    sim_distcalcmethod_sqrt_dl2_and_dac2,
    sim_distcalcmethod_dl_if_nonzero,
    sim_distcalcmethod_dac_if_nonzero
};

enum { /* drawing objects: */
    /* following are mutually exclusive: */
    sim_drawing_points = 0,         /* 3 values per point (point size in pixels) */
    sim_drawing_lines,              /* 6 values per line (line size in pixels) */
    sim_drawing_triangles,          /* 9 values per triangle */
    sim_drawing_spherepts = 7,      /* 3 values per point (sphere size in meters) */
    sim_drawing_linestrip,       /* 3 values per point */
    sim_drawing_trianglepts,     /* 7 values per point (3 for triangle position, 4 for orientation as quaternion) (triangle size in meters) */
    sim_drawing_quadpts,         /* 7 values per point (3 for quad position, 4 for orientation as quaternion) (quad size in meters) */
    sim_drawing_discpts,         /* 7 values per point (3 for disc position, 4 for orientation as quaternion) (disc size in meters) */
    sim_drawing_cubepts,         /* 7 values per point (3 for cube position, 4 for orientation as quaternion) (cube size in meters) */

    /* following can be or-combined: */
    sim_drawing_painttag                =0x000400, /* all items are tagged as paint (for additinal processing at a later stage) */
    sim_drawing_cyclic                  =0x001000, /* if the max item count was reached, then the first items are overwritten. */
    sim_drawing_overlay                 =0x040000, /* When specified, objects are always drawn on top of "regular objects" */
    sim_drawing_local                   =0x800000,  /* coordinates are specified locally to the attached object */
};

enum { /* UI properties: */
    sim_gui_menubar                     =0x00001,
    sim_gui_popups                      =0x00002,
    sim_gui_toolbar1                    =0x00004,
    sim_gui_toolbar2                    =0x00008,
    sim_gui_hierarchy                   =0x00010,
    sim_gui_infobar                     =0x00020,
    sim_gui_statusbar                   =0x00040,
    sim_gui_scripteditor                =0x00080,
    sim_gui_scriptsimulationparameters  =0x00100,
    sim_gui_dialogs                     =0x00200,
    sim_gui_browser                     =0x00400,
    sim_gui_splash                      =0x00800,
    sim_gui_all                         =0x0ffff,
    sim_gui_headless                    =0x10000,
};

enum { /* Joint modes: */
    sim_jointmode_kinematic = 0,
    sim_jointmode_dependent = 4,
    sim_jointmode_dynamic = 5,
};

enum { /* Joint dyn. ctrl modes: */
    sim_jointdynctrl_free = 0,
    sim_jointdynctrl_force = 1,
    sim_jointdynctrl_velocity = 4,
    sim_jointdynctrl_position = 8,
    sim_jointdynctrl_spring = 12,
    sim_jointdynctrl_callback = 16
};

enum { /* verbosity */
    sim_verbosity_useglobal = -1,
    sim_verbosity_none = 100,
    sim_verbosity_errors = 200,
    sim_verbosity_warnings = 300,
    sim_verbosity_loadinfos = 400, /* default for console */
    sim_verbosity_questions = 410, /* only for dialog verbosity */
    sim_verbosity_scripterrors = 420,
    sim_verbosity_scriptwarnings = 430,
    sim_verbosity_scriptinfos = 450, /* mainly for statusbar info prints. Default for statusbar */
    sim_verbosity_msgs = sim_verbosity_scriptinfos,
    sim_verbosity_infos = 500,
    sim_verbosity_debug = 600,
    sim_verbosity_trace = 700,
    sim_verbosity_tracelua = 800,
    sim_verbosity_traceall = 900,
    sim_verbosity_default = sim_verbosity_loadinfos,
    sim_verbosity_undecorated = 0x0f000,
    sim_verbosity_onlyterminal = 0x10000,
    sim_verbosity_once = 0x20000,
};

enum { /* plugin info */
    sim_plugininfo_extversionstr = 0,
    sim_plugininfo_builddatestr,
    sim_plugininfo_extversionint,
    sim_plugininfo_verbosity,
    sim_plugininfo_statusbarverbosity,
};

enum { /* Navigation and selection modes with the mouse. Lower byte values are mutually exclusive, upper byte bits can be combined */
    sim_navigation_passive                  =0x000000,
    sim_navigation_camerashift              =0x000001,
    sim_navigation_camerarotate             =0x000002,
    sim_navigation_camerazoom               =0x000003,
    sim_navigation_cameraangle              =0x000005,
    sim_navigation_objectshift              =0x000007,
    sim_navigation_objectrotate             =0x000008,
    sim_navigation_reserved2                =0x000009,
    sim_navigation_reserved3                =0x00000A,
    sim_navigation_reserved4                =0x00000B,
    sim_navigation_reserved5                =0x00000C,
    sim_navigation_reserved6                =0x00000D,
    /* Bit-combine following values and add them to one of above's values for a valid navigation mode: */
    sim_navigation_createpathpoint          =0x000100,
    sim_navigation_clickselection           =0x000200,
    sim_navigation_ctrlselection            =0x000400,
    sim_navigation_shiftselection           =0x000800,
    sim_navigation_camerazoomwheel          =0x001000,
    sim_navigation_camerarotatemiddlebutton =0x002000
};

enum { /* Ruckig Library flags */
    /* enable one of following: */
    sim_ruckig_phasesync                            =0x0000,
    sim_ruckig_timesync                             =0x0001,
    sim_ruckig_nosync                               =0x0003,
    /* combine with following: */
    sim_ruckig_minvel                               =0x0100,
    sim_ruckig_minaccel                             =0x0200,
};

enum { /* physics engine */
    sim_physics_bullet=0,
    sim_physics_ode,
    sim_physics_vortex,
    sim_physics_newton,
    sim_physics_mujoco,
    sim_physics_drake
};

enum { /* primitive shapes */
    sim_primitiveshape_none=0,
    sim_primitiveshape_plane=1,
    sim_primitiveshape_disc=2,
    sim_primitiveshape_cuboid=3,
    sim_primitiveshape_spheroid=4,
    sim_primitiveshape_cylinder=5,
    sim_primitiveshape_cone=6,
    sim_primitiveshape_heightfield=7,
    sim_primitiveshape_capsule=8,
};

enum { /* dummy types */
    sim_dummytype_dynloopclosure = 0,
    sim_dummytype_dyntendon = 7,
    sim_dummytype_default = 8,
    sim_dummytype_assembly = 9,
};

enum { /* texture map modes (serialized) */
    sim_texturemap_plane = 0,
    sim_texturemap_cylinder,
    sim_texturemap_sphere,
    sim_texturemap_cube
};

enum { /* color components */
    sim_colorcomponent_ambient=0,
    sim_colorcomponent_ambient_diffuse=0, /* objects only */
    sim_colorcomponent_diffuse, /* lights only */
    sim_colorcomponent_specular,
    sim_colorcomponent_emission,
    sim_colorcomponent_transparency,
    sim_colorcomponent_auxiliary
};

enum { /* prox. sensor volume types */
    sim_volume_pyramid=0,
    sim_volume_cylinder,
    sim_volume_disc,
    sim_volume_cone,
    sim_volume_ray,
    sim_volume_randomizedray
};

enum { /* Pov pattern types */
    sim_pov_pattern_null=0,
    sim_pov_white_marble,
    sim_pov_blood_marble,
    sim_pov_blue_agate,
    sim_pov_sapphire_agate,
    sim_pov_brown_agate,
    sim_pov_pink_granite,
    sim_pov_pink_alabaster,
    sim_pov_cherry_wood,
    sim_pov_pine_wood,
    sim_pov_dark_wood,
    sim_pov_tan_wood,
    sim_pov_white_wood,
    sim_pov_tom_wood,
    sim_pov_dmf_wood1,
    sim_pov_dmf_wood2,
    sim_pov_dmf_wood3,
    sim_pov_dmf_wood4,
    sim_pov_dmf_wood5,
    sim_pov_dmf_wood6,
    sim_pov_dmf_light_oak,
    sim_pov_dmf_dark_oak,
    sim_pov_emb_wood1,
    sim_pov_yellow_pine,
    sim_pov_rose_wood,
    sim_pov_sandal_wood,
    sim_pov_glass,
    sim_pov_glass2,
    sim_pov_glass3,
    sim_pov_green_glass,
    sim_pov_light_glass,
    sim_pov_bold_glass,
    sim_pov_wine_bottle,
    sim_pov_beer_bottle,
    sim_pov_ruby_glass,
    sim_pov_blue_glass,
    sim_pov_yellow_glass,
    sim_pov_orange_glass,
    sim_pov_vicks_bottle_glass,
    sim_pov_chrome_metal,
    sim_pov_brass_metal,
    sim_pov_copper_metal,
    sim_pov_bronze_metal,
    sim_pov_silver_metal,
    sim_pov_gold_metal,
    sim_pov_polished_chrome,
    sim_pov_polished_brass,
    sim_pov_new_brass,
    sim_pov_spun_brass,
    sim_pov_brushed_aluminum,
    sim_pov_silver1,
    sim_pov_silver2,
    sim_pov_silver3,
    sim_pov_brass_valley,
    sim_pov_rust,
    sim_pov_rusty_iron,
    sim_pov_soft_silver,
    sim_pov_new_penny,
    sim_pov_tinny_brass,
    sim_pov_gold_nugget,
    sim_pov_aluminum,
    sim_pov_bright_bronze,
    sim_pov_water,
    sim_pov_cork,
    sim_pov_lightning,
    sim_pov_mirror
};

enum { /* string types */
    sim_string_text=0,
    sim_string_binary,
    sim_string_buffer
};

enum { /* stack item types */
    sim_stackitem_null=0,
    sim_stackitem_double,
    sim_stackitem_bool,
    sim_stackitem_string,
    sim_stackitem_table,
    sim_stackitem_func,
    sim_stackitem_userdat,
    sim_stackitem_thread,
    sim_stackitem_lightuserdat,
    sim_stackitem_integer
};

enum { /* stack table info */
    sim_stack_table_circular_ref=-4,
    sim_stack_table_not_table=-3,
    sim_stack_table_map=-2,
    sim_stack_table_empty=0
};

enum { /* property type */
    sim_propertytype_bool=0,
    sim_propertytype_int,
    sim_propertytype_float,
    sim_propertytype_string,
    sim_propertytype_buffer,
    sim_propertytype_vector3,
    sim_propertytype_quaternion,
    sim_propertytype_pose,
    sim_propertytype_matrix3x3, /* not used */
    sim_propertytype_matrix4x4, /* not used */
    sim_propertytype_color,
    sim_propertytype_floatarray,
    sim_propertytype_table,
    sim_propertytype_intarray,
    sim_propertytype_vector2,
    sim_propertytype_intarray2,
    sim_propertytype_long,
};

enum { /* properties info */
    sim_propertyinfo_notwritable        = 0x001,
    sim_propertyinfo_notreadable        = 0x002,
    sim_propertyinfo_removable          = 0x004,
    sim_propertyinfo_modelhashexclude   = 0x008,
    sim_propertyinfo_deprecated         = 0x010,
    sim_propertyinfo_largedata          = 0x100,
};

enum { /* Vortex friction models */
    sim_vortex_bodyfrictionmodel_box=0,
    sim_vortex_bodyfrictionmodel_scaledbox,
    sim_vortex_bodyfrictionmodel_proplow,
    sim_vortex_bodyfrictionmodel_prophigh,
    sim_vortex_bodyfrictionmodel_scaledboxfast,
    sim_vortex_bodyfrictionmodel_neutral,
    sim_vortex_bodyfrictionmodel_none
};

enum { /* Bullet constraint solver type */
    sim_bullet_constraintsolvertype_sequentialimpulse=0,
    sim_bullet_constraintsolvertype_nncg,
    sim_bullet_constraintsolvertype_dantzig,
    sim_bullet_constraintsolvertype_projectedgaussseidel
};

enum {
    sim_objdynprop_dynamic=1,
    sim_objdynprop_respondable=2,
};

enum {
    sim_announce_pureconenotsupported=0,
    sim_announce_purespheroidnotsupported,
    sim_announce_containsnonpurenonconvexshapes,
    sim_announce_containsstaticshapesondynamicconstruction,
    sim_announce_purehollowshapenotsupported,
    sim_announce_vortexpluginisdemo,
};

enum {
    sim_dynamicsimicon_none=0,
    sim_dynamicsimicon_objectisdynamicallysimulated,
    sim_dynamicsimicon_objectisnotdynamicallyenabled
};

enum { /* Buffer types */
    sim_buffer_uint8=0,
    sim_buffer_int8,
    sim_buffer_uint16,
    sim_buffer_int16,
    sim_buffer_uint32,
    sim_buffer_int32,
    sim_buffer_float,
    sim_buffer_double,
    sim_buffer_uint8rgb,
    sim_buffer_uint8bgr,
    sim_buffer_uint8rgba,
    sim_buffer_uint8argb,
    sim_buffer_base64,
    sim_buffer_split,
    sim_buffer_clamp=256 /* flag */
};

enum { /* Image combination */
    sim_imgcomb_vertical=0,
    sim_imgcomb_horizontal
};

enum { /* Graph data stream transformations */
    sim_stream_transf_raw=0,
    sim_stream_transf_derivative,
    sim_stream_transf_integral,
    sim_stream_transf_cumulative
};

enum { /* Vision sensors render modes */
    sim_rendermode_opengl=0,
    sim_rendermode_auxchannels, /* deprecated */
    sim_rendermode_colorcoded,
    sim_rendermode_povray,
    sim_rendermode_reserved,
    sim_rendermode_extrenderer,
    sim_rendermode_extrendererwindowed, /* deprecated */
    sim_rendermode_opengl3,
    sim_rendermode_opengl3windowed, /* deprecated */
    sim_rendermode_oglimg,
    sim_rendermode_codedimg,
};

enum { /* Check the documentation instead of comments below!! */
        /* Following messages are dispatched to the Lua-message container: */
        sim_message_ui_button_state_change=0,   /* a UI button, slider, etc. changed (due to a user's action). aux[0]=UI handle, aux[1]=button handle, aux[2]=button attributes, aux[3]=slider position (if slider) */
        sim_message_reserved9,                  /* Do not use */
        sim_message_object_selection_changed,
        sim_message_reserved10,                 /* do not use */
        sim_message_model_loaded,
        sim_message_reserved11,                 /* do not use */
        sim_message_keypress,                   /* a key was pressed while the focus was on a page (aux[0]=key, aux[1]=ctrl and shift key state) */
        sim_message_bannerclicked,              /* a banner was clicked (aux[0]=banner ID) */
        sim_message_scene_loaded,               /* a scene was loaded */

        sim_message_prox_sensor_select_down,    /* deprecated */
        sim_message_prox_sensor_select_up,      /* deprecated */
        sim_message_pick_select_down,           /* deprecated */


        /* Following messages are dispatched only to the C-API (not available from Lua): */
        sim_message_for_c_api_only_start=0x0100,            /* Do not use */
        sim_message_reserved1,                              /* Do not use */
        sim_message_reserved2,                              /* Do not use */
        sim_message_reserved3,                              /* Do not use */


        sim_message_eventcallback_scenesave,                /* about to save a scene */
        sim_message_eventcallback_modelsave,                /* about to save a model (current selection will be saved) */
        sim_message_eventcallback_moduleopen,               /* deprecated */
        sim_message_eventcallback_modulehandle,             /* deprecated */
        sim_message_eventcallback_moduleclose,              /* deprecated */
        sim_message_reserved4,                              /* Do not use */
        sim_message_reserved5,                              /* Do not use */
        sim_message_reserved6,                              /* Do not use */
        sim_message_reserved7,                              /* Do not use */
        sim_message_eventcallback_instancepass,             /* Called once every main application loop pass. auxiliaryData[0] contains event flags of events that happened since last time: */
                                                            /* bit0 set: object(s) erased */
                                                            /* bit1 set: object(s) created */
                                                            /* bit2 set: model loaded */
                                                            /* bit3 set: scene loaded */
                                                            /* bit4 set: undo called */
                                                            /* bit5 set: redo called */
                                                            /* bit6 set: scene switched (similar to scene loaded, basically: scene content completely changed) */
                                                            /* bit7 set: edit mode active. This is not an event flag, but a state flag */
                                                            /* bit8 set: object(s) scaled */
                                                            /* bit9 set: selection state changed. (different objects are selected now) */
                                                            /* bit10 set: key pressed */
                                                            /* bit11 set: simulation started */
                                                            /* bit12 set: simulation ended */

        sim_message_eventcallback_broadcast, /* deprecated */
        sim_message_eventcallback_imagefilter_enumreset, /* deprecated */
        sim_message_eventcallback_imagefilter_enumerate, /* deprecated */
        sim_message_eventcallback_imagefilter_adjustparams, /* deprecated */
        sim_message_eventcallback_imagefilter_reserved, /* deprecated */
        sim_message_eventcallback_imagefilter_process, /* deprecated */

        sim_message_eventcallback_reserved1, /* do not use */
        sim_message_eventcallback_reserved2, /* do not use */
        sim_message_eventcallback_reserved3, /* do not use */
        sim_message_eventcallback_reserved4, /* do not use */

        sim_message_eventcallback_abouttoundo,      /* the undo button was hit and a previous state is about to be restored */
        sim_message_eventcallback_undoperformed,    /* the undo button was hit and a previous state restored */
        sim_message_eventcallback_abouttoredo,      /* the redo button was hit and a future state is about to be restored  */
        sim_message_eventcallback_redoperformed,    /* the redo button was hit and a future state restored  */
        sim_message_eventcallback_scripticondblclick, /* deprecated */
        sim_message_eventcallback_simulationabouttostart,
        sim_message_eventcallback_simulationended,

        sim_message_eventcallback_reserved5,            /* do not use */
        sim_message_eventcallback_keypress,         /* a key was pressed while the focus was on a page (aux[0]=key, aux[1]=ctrl and shift key state) */
        sim_message_eventcallback_modulehandleinsensingpart, /* deprecated */

        sim_message_eventcallback_renderingpass, /* deprecated */
        sim_message_eventcallback_bannerclicked, /* deprecated */
        sim_message_eventcallback_menuitemselected, /* auxiliaryData[0] indicates the handle of the item, auxiliaryData[1] indicates the state of the item */
        sim_message_eventcallback_refreshdialogs, /* aux[0]=refresh degree (0=light, 1=medium, 2=full) */
        sim_message_eventcallback_sceneloaded,
        sim_message_eventcallback_modelloaded,
        sim_message_eventcallback_instanceswitch,


        sim_message_eventcallback_guipass,
        sim_message_eventcallback_mainscriptabouttobecalled,

        sim_message_eventcallback_rmlposition, /* deprecated */
        sim_message_eventcallback_rmlvelocity, /* deprecated */

        sim_message_eventcallback_reserved18,
        sim_message_eventcallback_reserved19,
        sim_message_eventcallback_pathplanningplugin, /* deprecated */
        sim_message_eventcallback_colladaplugin, /* deprecated */

        sim_message_eventcallback_opengl, /* deprecated */
        sim_message_eventcallback_openglframe, /* deprecated */
        sim_message_eventcallback_openglcameraview, /* deprecated */

        sim_message_eventcallback_proxsensorselectdown, /* deprecated */
        sim_message_eventcallback_proxsensorselectup, /* deprecated */
        sim_message_eventcallback_pickselectdown, /* deprecated */

        sim_message_eventcallback_rmlpos, /* deprecated */
        sim_message_eventcallback_rmlvel, /* deprecated */
        sim_message_eventcallback_rmlstep, /* deprecated */
        sim_message_eventcallback_rmlremove, /* deprecated */
        sim_message_eventcallback_rmlinfo, /* deprecated */

        sim_message_eventcallback_beforerendering, /* deprecated */

        sim_message_eventcallback_extrenderer_start,
        sim_message_eventcallback_extrenderer_light,
        sim_message_eventcallback_extrenderer_mesh,
        sim_message_eventcallback_extrenderer_stop,

        sim_message_eventcallback_reserved6,
        sim_message_eventcallback_reserved7,
        sim_message_eventcallback_reserved8,
        sim_message_eventcallback_reserved9,
        sim_message_eventcallback_reserved10,
        sim_message_eventcallback_reserved11,
        sim_message_eventcallback_reserved12,
        sim_message_eventcallback_reserved13,
        sim_message_eventcallback_reserved14,
        sim_message_eventcallback_reserved15,
        sim_message_eventcallback_reserved16,
        sim_message_eventcallback_reserved17,

        sim_message_eventcallback_extrenderer_triangles, /* deprecated */
        sim_message_eventcallback_simulationabouttoend,
        sim_message_eventcallback_instanceabouttoswitch,

        sim_message_eventcallback_lastinstancepass, /* deprecated */
        sim_message_eventcallback_uipass, /* deprecated */
        sim_message_eventcallback_scriptstateabouttobedestroyed,
        sim_message_eventcallback_scriptstatedestroyed = sim_message_eventcallback_scriptstateabouttobedestroyed,
        sim_message_eventcallback_scriptabouttobedestroyed,
        sim_message_eventcallback_scriptdestroyed = sim_message_eventcallback_scriptabouttobedestroyed,

        /* Following called before/after the main script's corresponding sections. auxData[0]=0:before, auxData[0]=1:after */
        sim_message_eventcallback_simulationinit,
        sim_message_eventcallback_simulationactuation,
        sim_message_eventcallback_simulationsensing,
        sim_message_eventcallback_simulationcleanup,

        sim_message_eventcallback_moduleentry, /* auxiliaryData[0] indicates the handle of the item, auxiliaryData[1] indicates the state of the item */
        sim_message_eventcallback_events, /* auxPointer is a const unsigned char* to CBOR data, reflecting (all) the changes that happened in CoppeliaSim. auxData[0] indicates the number of events */

        sim_message_simulation_start_resume_request=0x1000,
        sim_message_simulation_pause_request,
        sim_message_simulation_stop_request

};

#include <simLib/simConst-old.h>

#endif /* !defined(SIMCONST_INCLUDED_) */
