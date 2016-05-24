/*
 * File:   main.c
 * Author: vicente
 *
 * Created on May 23, 2016, 11:54 PM
 */

#include "system.h"
#include "app_device_cdc_basic.h"
#include "app_led_usb_status.h"
#include "usb.h"
#include "usb_device.h"
#include "usb_device_cdc.h"

MAIN_RETURN main(void) {
    SYSTEM_Initialize(SYSTEM_STATE_USB_START);
    USBDeviceInit();
    USBDeviceAttach();
    while (1) {
        SYSTEM_Tasks();
#if defined(USB_POLLING)
        USBDeviceTasks();
#endif
        APP_DeviceCDCBasicDemoTasks();
    }
}
