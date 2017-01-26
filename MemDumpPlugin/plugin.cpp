#include "plugin.h"
#include <DbgHelp.h>

static bool cbCommand(int argc, char* argv[])
{
	if (argc < 3) return false;
	duint ptr;
	duint cnt;

	ptr = DbgValFromString(argv[1]);
	cnt = DbgValFromString(argv[2]);

	byte* buff = new byte[cnt];

	DbgMemRead(ptr, buff, cnt);

	for (duint i = 0; i < cnt; i++) {
		if ((i % 16) == 0) {
			if (i > 0) _plugin_logprintf("\n");
			_plugin_logprintf("%04x", i);
		}

		if ((i % 8) == 0) {
			_plugin_logprintf(" ");
		}

		_plugin_logprintf("%02x ", buff[i]);
	}
	_plugin_logprintf("\n");

    //_plugin_logputs(PLUGIN_NAME);
    return true; //Return false to indicate the command failed.
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    if(!_plugin_registercommand(pluginHandle, PLUGIN_NAME, cbCommand, false))
        _plugin_logputs("[" PLUGIN_NAME "] Error registering the \"" PLUGIN_NAME "\" command!");
    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here (clearing menus optional).
bool pluginStop()
{
    return true;
}

//Do GUI/Menu related things here.
void pluginSetup()
{
}
