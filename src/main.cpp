#include "main.h"
#include "utils/logger.h"
#include <padscore/wpad.h>
#include <vpad/input.h>
#include <wups.h>

WUPS_PLUGIN_NAME("Begone-Wiimotes");
WUPS_PLUGIN_DESCRIPTION("Disconnects Wiimotes with a button combination.");
WUPS_PLUGIN_VERSION(VERSION_FULL);
WUPS_PLUGIN_AUTHOR("WiiDatabase.de");
WUPS_PLUGIN_LICENSE("MIT");

ON_APPLICATION_START() { initLogging(); }

ON_APPLICATION_ENDS() { deinitLogging(); }

DECL_FUNCTION(int32_t, VPADRead, int32_t chan, VPADStatus *buffer,
              uint32_t buffer_size, VPADReadError *error) {
  VPADReadError real_error = VPAD_READ_SUCCESS;
  int32_t result = real_VPADRead(chan, buffer, buffer_size, &real_error);

  if (result > 0 && real_error == VPAD_READ_SUCCESS) {
    if (buffer[0].hold == (VPAD_BUTTON_ZL | VPAD_BUTTON_L | VPAD_BUTTON_DOWN)) {
      WPADDisconnect(WPAD_CHAN_0);
    } else if (buffer[0].hold ==
               (VPAD_BUTTON_ZL | VPAD_BUTTON_L | VPAD_BUTTON_LEFT)) {
      WPADDisconnect(WPAD_CHAN_1);
    } else if (buffer[0].hold ==
               (VPAD_BUTTON_ZL | VPAD_BUTTON_L | VPAD_BUTTON_UP)) {
      WPADDisconnect(WPAD_CHAN_2);
    } else if (buffer[0].hold ==
               (VPAD_BUTTON_ZL | VPAD_BUTTON_L | VPAD_BUTTON_RIGHT)) {
      WPADDisconnect(WPAD_CHAN_3);
    }
  }
  return result;
}

WUPS_MUST_REPLACE(VPADRead, WUPS_LOADER_LIBRARY_VPAD, VPADRead);
