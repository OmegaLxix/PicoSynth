#ifndef TUSB_CONFIG_H_
#define TUSB_CONFIG_H_

#ifndef CFG_TUSB_OS
#define CFG_TUSB_OS OPT_OS_NONE
#endif

#define CFG_TUSB_RHPORT0_MODE       (OPT_MODE_DEVICE)
#define CFG_TUSB_OS                 OPT_OS_NONE
#define CFG_TUSB_MCU                OPT_MCU_RP2040

#define CFG_TUD_ENABLED             1
#define CFG_TUD_ENDPOINT0_SIZE      64

// Audio Class
#define CFG_TUD_AUDIO                      1
#define CFG_TUD_AUDIO_FUNC_DESC_LEN_MAX    128
#define CFG_TUD_AUDIO_FUNC_COUNT           1

// Mono 16-bit speaker
#define CFG_TUD_AUDIO_FUNC_1_N_AS_INT                1
#define CFG_TUD_AUDIO_FUNC_1_NUMBER_OF_CHANNELS      1
#define CFG_TUD_AUDIO_FUNC_1_N_BYTES_PER_SAMPLE      2
#define CFG_TUD_AUDIO_FUNC_1_N_CHANNELS_TX           1
#define CFG_TUD_AUDIO_FUNC_1_MAX_SAMPLE_RATE         48000

#define CFG_TUD_AUDIO_FUNC_1_DESC_LEN   (TUD_AUDIO_SPEAKER_MONO_DESC_LEN)

#endif
