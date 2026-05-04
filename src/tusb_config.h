#ifndef TUSB_CONFIG_H_
#define TUSB_CONFIG_H_

#define CFG_TUSB_RHPORT0_MODE       (OPT_MODE_DEVICE)
#define CFG_TUSB_OS                 OPT_OS_NONE

#define CFG_TUD_ENDPOINT0_SIZE      64

// Enable Audio Class
#define CFG_TUD_AUDIO               1

// Audio settings
#define CFG_TUD_AUDIO_FUNC_1_NUMBER_OF_CHANNELS             1
#define CFG_TUD_AUDIO_FUNC_1_N_BYTES_PER_SAMPLE             2   // 16-bit
#define CFG_TUD_AUDIO_FUNC_1_N_CHANNELS_TX                  1
#define CFG_TUD_AUDIO_FUNC_1_MAX_SAMPLE_RATE                48000

#endif
