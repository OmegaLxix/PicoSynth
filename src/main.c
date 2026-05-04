#include <math.h>
#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"

#define SAMPLE_RATE 48000
#define FREQ 440.0f
#define AMPLITUDE 30000

static float phase = 0.0f;

// USB Audio buffer (mono, 16-bit)
int16_t audio_buffer[48]; // 1ms of audio at 48kHz

void generate_sine_wave() {
    for (int i = 0; i < 48; i++) {
        audio_buffer[i] = (int16_t)(AMPLITUDE * sinf(phase));
        phase += 2.0f * M_PI * FREQ / SAMPLE_RATE;

        if (phase > 2.0f * M_PI) {
            phase -= 2.0f * M_PI;
        }
    }
}

// Called by TinyUSB when host wants audio
bool tud_audio_tx_done_pre_load_cb(uint8_t rhport, uint8_t itf, uint8_t ep_in, uint8_t cur_alt_setting) {
    (void) rhport;
    (void) itf;
    (void) ep_in;
    (void) cur_alt_setting;

    generate_sine_wave();

    // Send audio buffer
    tud_audio_write((uint8_t*)audio_buffer, sizeof(audio_buffer));

    return true;
}

int main() {
    board_init();
    tusb_init();

    while (1) {
        tud_task(); // TinyUSB device task
    }
}
