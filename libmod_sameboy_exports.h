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

#ifndef __LIBMOD_SAMEBOY_EXPORTS
#define __LIBMOD_SAMEBOY_EXPORTS

/* ----------------------------------------------------------------- */

#include "bgddl.h"

/* ----------------------------------------------------------------- */

#ifndef __BGDC__

#include "libmod_sameboy.h"

#endif

/* --------------------------------------------------------------------------- */

DLSYSFUNCS  __bgdexport( libmod_sameboy, functions_exports )[] = {
    FUNC("SAMEBOY_START_EMULATOR"       , "S"         , TYPE_INT       , sameboy_start_emulator       ),
	FUNC("SAMEBOY_TICK"                 , ""          , TYPE_UNDEFINED , sameboy_tick                 ),
	FUNC("SAMEBOY_UPDATE_KEYS"          , "BBBBBBBB"  , TYPE_UNDEFINED , sameboy_update_keys          ),
	FUNC("SAMEBOY_SAVE_STATE"           , "S"         , TYPE_INT       , sameboy_save_state           ),
	FUNC("SAMEBOY_LOAD_STATE"           , "S"         , TYPE_INT       , sameboy_load_state           ),
	FUNC("SAMEBOY_READ_GB_RAM_BYTE"     , "I"         , TYPE_INT       , sameboy_read_gb_register     ),
	FUNC("SAMEBOY_WRITE_GB_RAM_BYTE"    , "II"        , TYPE_UNDEFINED , sameboy_write_gb_register    ),
	FUNC("SAMEBOY_CHANGE_EMULATION_MODE", "I"         , TYPE_UNDEFINED , sameboy_change_emulation_mode),
	FUNC("SAMEBOY_SAVE_SRAM"            , "S"          , TYPE_UNDEFINED , sameboy_save_sram            ),
	FUNC("SAMEBOY_LOAD_SRAM"            , "S"          , TYPE_UNDEFINED , sameboy_load_sram            ),
	FUNC("SAMEBOY_SET_AUDIO_VOLUME"     , "I"         , TYPE_UNDEFINED  , sameboy_set_audio_volume     ),
	
    { NULL, NULL, 0, NULL }
};

char * __bgdexport( libmod_sameboy, modules_dependency )[] = {
    "libbggfx",
    "libbginput",
    NULL
};

#endif