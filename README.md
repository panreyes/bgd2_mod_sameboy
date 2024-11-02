# BennuGD2 SameBoy Module
This is SameBoy ( https://sameboy.github.io/ ) but trimmed and with quirks to make it work as a BennuGD2 module by Pablo Navarro, a person that never actually learnt how to actually C.

Thanks to Lior Halphon (LIJI32) for letting us use SameBoy for making this module! ♥

## How to use it:
Put it as the texture of a process like this:

```graph = sameboy_start_emulator(string rom_path);```
	
To send the GB input, use:

```sameboy_update_keys(bool left, bool right, bool up, bool down, bool a, bool b, bool select, bool start);```
	
And before every frame of that process, run this:

```sameboy_tick();```

You can save and load save states like this:

```sameboy_save_state(string save_state_path);```

```sameboy_load_state(string save_state_path);```
	
You can read and write bytes from the GB RAM with this:

```sameboy_read_gb_ram_byte(int ram_address);```

```sameboy_write_gb_ram_byte(int ram_address, int value);```

You can change the emulation mode between GB, GBC, SGB, etc... with this:

```sameboy_change_emulation_mode(int emulation_mode);```

emulation_mode [ 0: GBC (default), 1: GB ]

SRAM is not saved and loaded automatically, you should take care of it when you think its wise:

```sameboy_save_sram(string sram_save_path);```

```sameboy_load_sram(string sram_save_path);```

You can change the GB audio volume with this:

```sameboy_set_audio_volume(int volume);```
	- volume [0-255]
