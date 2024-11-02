#include <stdbool.h>
#include <SDL.h>

int start_emulator(int argc, char **argv, SDL_Texture **_texture);
void emulator_tick();
void update_keys(bool left, bool right, bool up, bool down, bool a, bool b, bool select, bool start);
int save_state(const char *path);
int load_state(const char *path);
uint8_t read_gb_register(uint16_t addr);
void write_gb_register(uint16_t addr, uint8_t value);
void gb_change_emulation_type(uint8_t emulation_mode);
void gb_save_sram(const char *path);
void gb_load_sram(const char *path);
void gb_set_audio_volume(uint8_t new_volume);