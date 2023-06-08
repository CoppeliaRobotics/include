#py from parse import parse
#py import model
#py plugin = parse(pycpp.params['xml_file'])

// include this file after calling the SIM_PLUGIN(...) macro

#py for cmd in plugin.commands:
SIM_DLLEXPORT void `plugin.name`_`cmd.c_name`(`cmd.c_in_name` *in, `cmd.c_out_name` *out)
{
    sim::plugin->`cmd.c_name`(in, out);
}
#py endfor

