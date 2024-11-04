project(mod_sameboy)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "../../bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "../../bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../bin/")

set(CMAKE_MODULE_PATH ../../cmake/Modules)

find_package(SDL2 REQUIRED)

add_definitions(${EXTRA_CFLAGS})

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS} ../../core/include ../../core/bgdrtm ../../modules/libbggfx ../../modules/libmod_sameboy ../../modules/libmod_sameboy/sameboy)

add_definitions(-DGB_INTERNAL -DVERSION="1.0.0.0" -DGB_VERSION="1.0.0.0" -DGB_COPYRIGHT_YEAR="2023")
add_definitions(-Wno-multichar -Wno-attributes)
add_definitions($ENV{EXTRA_CFLAGS})

file(GLOB SOURCES_LIBMOD_SAMEBOY
     "../../modules/libmod_sameboy/*.c"
	 "../../modules/libmod_sameboy/sameboy/Core/*.c"
	 "../../modules/libmod_sameboy/sameboy/OpenDialog/stub.c"
	 "../../modules/libmod_sameboy/sameboy/OpenDialog/open_dialog.h"
	 "../../modules/libmod_sameboy/sameboy/SDL/audio/sdl.c"
	 "../../modules/libmod_sameboy/sameboy/SDL/audio.c"
	 "../../modules/libmod_sameboy/sameboy/SDL/configuration.c"
	 "../../modules/libmod_sameboy/sameboy/SDL/font.c"
	 "../../modules/libmod_sameboy/sameboy/SDL/gui.c"
	 "../../modules/libmod_sameboy/sameboy/SDL/sameboy.c"
	 "../../modules/libmod_sameboy/sameboy/SDL/utils.c"
     )

add_library(mod_sameboy ${LIBRARY_BUILD_TYPE} ${SOURCES_LIBMOD_SAMEBOY})
target_link_libraries(mod_sameboy ${SDL2_LIBRARY} ${SDL2_LIBRARIES} -L../../bin bgdrtm bggfx)
