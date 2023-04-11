#if !defined(SIMEXP_INCLUDED_)
#define SIMEXP_INCLUDED_

#ifdef WIN_SIM
    #define SIM_DLLEXPORT extern "C" __declspec(dllexport)
#endif
#ifdef MAC_SIM
    #define SIM_DLLEXPORT extern "C" __attribute__((visibility("default")))
#endif
#ifdef LIN_SIM
    #define SIM_DLLEXPORT extern "C" __attribute__((visibility("default")))
#endif


#endif // !defined(SIMEXP_INCLUDED_)
