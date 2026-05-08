#include "tusb.h"

// Device Descriptor
tusb_desc_device_t const desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,
    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = 0xCAFE,
    .idProduct          = 0xCAFE,
    .bcdDevice          = 0x0100,
    .iManufacturer      = 0x01,
    .iProduct           = 0x02,
    .iSerialNumber      = 0x03,
    .bNumConfigurations = 0x01
};

// Configuration + Audio Descriptor (Mono Speaker)
#define CONFIG_TOTAL_LEN  (TUD_CONFIG_DESC_LEN + TUD_AUDIO_SPEAKER_MONO_DESC_LEN)

uint8_t const desc_configuration[] = {
    TUD_CONFIG_DESCRIPTOR(1, 2, 0, CONFIG_TOTAL_LEN, 0, 100),
    TUD_AUDIO_SPEAKER_MONO_DESCRIPTOR(2, 1)   // interface number, EP number
};

// String Descriptors
char const* string_desc_arr[] = {
    (const char[]) { 0x09, 0x04 },  // 0: English
    "PicoSynth",                    // 1: Manufacturer
    "PicoSynth",                    // 2: Product
    "123456"                        // 3: Serial
};

uint8_t const * tud_descriptor_device_cb(void) {
    return (uint8_t const *)&desc_device;
}

uint8_t const * tud_descriptor_configuration_cb(uint8_t index) {
    (void)index;
    return desc_configuration;
}

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    (void)langid;
    static uint16_t desc_str[32];
    if (index == 0) {
        memcpy(desc_str, string_desc_arr[0], 2);
        return desc_str;
    }
    uint8_t str_index = index < 4 ? index : 0;
    return (uint16_t const*)tud_descriptor_string_cb(str_index, langid); // simplified
}
