#pragma once
// #define STB_C_LEXER_IMPLEMENTATION
// #define STB_CONNECTED_COMPONENTS_IMPLEMENTATION
// #define STB_DIVIDE_IMPLEMENTATION
// #define STB_DS_IMPLEMENTATION
// #define STB_DXT_IMPLEMENTATION
// #define STB_EASY_FONT_IMPLEMENTATION
// #define STB_HERRINGBONE_WANG_TILE_IMPLEMENTATION
// #define STB_HEXWAVE_IMPLEMENTATION
// #define STB_IMAGE_IMPLEMENTATION
// #define STB_IMAGE_RESIZE2_IMPLEMENTATION
// #define STB_IMAGE_WRITE_IMPLEMENTATION
// #define STB_INCLUDE_IMPLEMENTATION
// #define STB_LEAKCHECK_IMPLEMENTATION
// #define STB_PERLIN_IMPLEMENTATION
// #define STB_RECT_PACK_IMPLEMENTATION
// #define STB_SPRINTF_IMPLEMENTATION
// #define STB_TEXTEDIT_IMPLEMENTATION
// #define STB_TILEMAP_EDITOR_IMPLEMENTATION
// #define STB_TRUETYPE_IMPLEMENTATION
// #define STB_VOXEL_RENDER_IMPLEMENTATION
#define STB_LEAKCHECK_IMPLEMENTATION

#ifdef STB_TRUETYPE_IMPLEMENTATION
#define STB_RECT_PACK_IMPLEMENTATION
#endif

#include <stdio.h>
#include "stb/stb_c_lexer.h"
#include "stb/stb_connected_components.h"
#include "stb/stb_divide.h"
#include "stb/stb_ds.h"
#include "stb/stb_dxt.h"
#include "stb/stb_easy_font.h"
#include "stb/stb_herringbone_wang_tile.h"
#include "stb/stb_hexwave.h"
#include "stb/stb_image_resize2.h"
#include "stb/stb_image_write.h"
#include "stb/stb_image.h"
#include "stb/stb_include.h"
#include "stb/stb_leakcheck.h"
#include "stb/stb_perlin.h"
#include "stb/stb_rect_pack.h"
#include "stb/stb_sprintf.h"
#include "stb/stb_textedit.h"
#include "stb/stb_tilemap_editor.h"
#include "stb/stb_truetype.h"
#include "stb/stb_voxel_render.h"
