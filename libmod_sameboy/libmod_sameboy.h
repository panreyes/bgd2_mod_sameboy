/*
 *  Copyright (C) 2024 Pablo Antonio Navarro Reyes <panreyes@panreyes.com>
 *  Copyright (C) 2016 Joseba García Etxebarria <joseba.gar@gmail.com>
 *
 *  This file is part of BennuGD2's Sameboy module
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 *
 */


#ifndef __LIBMOD_SAMEBOY_H
#define __LIBMOD_SAMEBOY_H

extern int64_t sameboy_start_emulator(INSTANCE * my, int64_t * params);
extern void sameboy_tick(INSTANCE * my, int64_t * params);
extern void sameboy_update_keys(INSTANCE * my, int64_t * params);
extern int64_t sameboy_save_state(INSTANCE * my, int64_t * params);
extern int64_t sameboy_load_state(INSTANCE * my, int64_t * params);
extern int64_t sameboy_read_gb_register(INSTANCE * my, int64_t * params);
extern void sameboy_write_gb_register(INSTANCE * my, int64_t * params);
extern void sameboy_change_emulation_mode(INSTANCE * my, int64_t * params);
extern void sameboy_save_sram(INSTANCE * my, int64_t * params);
extern void sameboy_load_sram(INSTANCE * my, int64_t * params);
extern void sameboy_set_audio_volume(INSTANCE * my, int64_t * params);

#endif
