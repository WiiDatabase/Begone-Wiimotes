#include <wups.h>
#include <string.h>

#include <nsysnet/socket.h>
#include <vpad/input.h>
#include <padscore/wpad.h>
#include <utils/logger.h>

WUPS_PLUGIN_NAME("Begone Wiimotes!");
WUPS_PLUGIN_DESCRIPTION("Disconnects Wiimotes with a button combination.");
WUPS_PLUGIN_VERSION("v1.0");
WUPS_PLUGIN_AUTHOR("Brawl");
WUPS_PLUGIN_LICENSE("Mit");

ON_APPLICATION_START(args){
   socket_lib_init();
   log_init();

   DEBUG_FUNCTION_LINE("Init of begone-wiimote!\n");
}

bool allowAction = true;

ON_APP_STATUS_CHANGED(status){
    allowAction = ( status == WUPS_APP_STATUS_FOREGROUND);
}

DECL_FUNCTION(int32_t, VPADRead, int32_t chan, VPADStatus *buffer, uint32_t buffer_size, int32_t *error) {
    int32_t result = real_VPADRead(chan, buffer, buffer_size, error);
    if (allowAction) {
        if(result > 0 && *error == VPAD_READ_SUCCESS) {
            if(buffer[0].hold == (VPAD_BUTTON_ZL | VPAD_BUTTON_L | VPAD_BUTTON_DOWN) ) {
                    WPADDisconnect(0);
            } else if(buffer[0].hold == (VPAD_BUTTON_ZL | VPAD_BUTTON_L | VPAD_BUTTON_LEFT) ) {
                    WPADDisconnect(1);
            } else if(buffer[0].hold == (VPAD_BUTTON_ZL | VPAD_BUTTON_L | VPAD_BUTTON_UP) ) {
                    WPADDisconnect(2);
            } else if(buffer[0].hold == (VPAD_BUTTON_ZL | VPAD_BUTTON_L | VPAD_BUTTON_RIGHT) ) {
                    WPADDisconnect(3);
            }
        }
    }
    return result;
}

WUPS_MUST_REPLACE(VPADRead ,WUPS_LOADER_LIBRARY_VPAD, VPADRead);
