#pragma once

#if defined(WIN_SIM)
#define SIM_DLLEXPORT extern "C" __declspec(dllexport)
#elif defined(MAC_SIM) || defined(LIN_SIM)
#define SIM_DLLEXPORT extern "C" __attribute__((visibility("default")))
#else
#error Define one of WIN_SIM, MAC_SIM or LIN_SIM
#endif
