# C++ plugin framework for CoppeliaSim

Compile with your C++ project.

Example plugin (uses also simStubsGen):

```
#include <simPlusPlus/Plugin.h>
#include "stubs.h"

class Plugin : public sim::Plugin
{
public:
    void onStart()
    {
        if(!registerScriptStuff())
            throw std::runtime_error("script stuff initialization failed");
    }

    void test(test_in *in, test_out *out)
    {
        // ...
    }
};

SIM_PLUGIN("Skel", 1, Plugin)
#include "stubsPlusPlus.cpp"
```

See [simExtSkel](https://github.com/CoppeliaRobotics/simExtSkel) for a complete example.
