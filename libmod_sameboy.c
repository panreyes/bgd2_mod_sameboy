/*
 *  Copyright (C) 2016 Pablo Antonio Navarro Reyes <panreyes@panreyes.com>
 *  Copyright (C) 2016 Joseba García Etxebarria <joseba.gar@gmail.com>
 *
 *  This file is part of PixTudio
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

#include <stdlib.h>
#include <stdbool.h>

#include "bgdrtm.h"
#include "bgddl.h"

#include "libmod_sameboy.h"

#include "libmod_sameboy_exports.h"

#include "sameboy/SDL/sameboy.h"

#include "xstrings.h"

#include "../libbggfx/libbggfx.h"
#include "../libbggfx/g_blit.h"

GRAPH *sameboy_map;
int64_t sameboy_status = 0;

int64_t sameboy_start_emulator(INSTANCE * my, int64_t * params) {
	char * argv[] = { "sameboy", string_get( params[ 0 ] ) };
	sameboy_map = bitmap_new_syslib(160, 144);
	
	// Create Surface and Texture manually, so they'll be available right away, not when rendering
	sameboy_map->surface = SDL_CreateRGBSurface( 0, sameboy_map->width, sameboy_map->height, gPixelFormat->BitsPerPixel, 
		gPixelFormat->Rmask, gPixelFormat->Gmask, gPixelFormat->Bmask, gPixelFormat->Amask );
	
	// TESTING:
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
	sameboy_map->tex = SDL_CreateTexture(gRenderer, SDL_GetWindowPixelFormat(gWindow), SDL_TEXTUREACCESS_STREAMING, 160, 144);
	SDL_UpdateTexture(sameboy_map->tex, NULL, sameboy_map->surface->pixels, sameboy_map->surface->pitch );
	
	start_emulator(2, argv, &sameboy_map->tex);
    
	string_discard( params[ 0 ] );
	
	sameboy_status = 1;
	
	return sameboy_map->code;
}

void sameboy_tick(INSTANCE * my, int64_t * params){
	
	/*
	int width, height, aaccess;
	unsigned int format;
	
	SDL_QueryTexture(sameboy_map->tex, &format, &aaccess, &width, &height );
	printf("SDL_QueryTexture %u %i %i %i\n", format, aaccess, width, height );
*/
	
	if(sameboy_status) {
		emulator_tick();
	}
}

int64_t sameboy_save_state(INSTANCE * my, int64_t * params){
	char * path = string_get( params[ 0 ] );
	
	int64_t result = (int64_t) save_state(path);
	
	string_discard( params[ 0 ] );
	return result;
}

int64_t sameboy_load_state(INSTANCE * my, int64_t * params){
	char * path = string_get( params[ 0 ] );
	
	int64_t result = (int64_t) load_state(path);
	
	string_discard( params[ 0 ] );
	return result;
}

void sameboy_update_keys(INSTANCE * my, int64_t * params){
	if(sameboy_status) {
		update_keys(params[0],params[1],params[2],params[3],params[4],params[5],params[6],params[7]);
	}
}

int64_t sameboy_read_gb_register(INSTANCE * my, int64_t * params){
	return (int64_t) read_gb_register((uint16_t) params[0]);
}

void sameboy_write_gb_register(INSTANCE * my, int64_t * params){
	write_gb_register((uint16_t) params[0], (uint8_t) params[1]);
}

void sameboy_change_emulation_mode(INSTANCE * my, int64_t * params){
	gb_change_emulation_type((uint8_t) params[0]);
}

void sameboy_save_sram(INSTANCE * my, int64_t * params){
	char * path = string_get( params[ 0 ] );
	
	gb_save_sram(path);
	
	string_discard( params[ 0 ] );
	return;
}

void sameboy_load_sram(INSTANCE * my, int64_t * params){
	char * path = string_get( params[ 0 ] );
	
	gb_load_sram(path);
	
	string_discard( params[ 0 ] );
	return;
}

void sameboy_set_audio_volume(INSTANCE * my, int64_t * params){
	gb_set_audio_volume((uint8_t) params[0]);
	return;
}