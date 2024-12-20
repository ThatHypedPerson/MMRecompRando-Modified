#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "bombchu_bag.h"

u64 bombchu_bag_zobjTex_000000[] = {
#include "bombchu_bag_ci8.inc.c"
};

u8 bombchu_bag_zobj_unaccounted_000100[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x06, 0x06, 0x06, 0x08, 0x09, 0x09, 0x0A, 0x05, 
    0x0B, 0x02, 0x0C, 0x0C, 0x0D, 0x03, 0x00, 0x0E, 0x0E, 0x0F, 0x00, 0x0F, 0x0E, 0x10, 0x11, 0x01, 
    0x12, 0x0D, 0x13, 0x14, 0x14, 0x15, 0x0D, 0x01, 0x01, 0x12, 0x02, 0x02, 0x02, 0x16, 0x0D, 0x0C, 
    0x01, 0x17, 0x13, 0x18, 0x19, 0x1A, 0x14, 0x0C, 0x1B, 0x1B, 0x0D, 0x0C, 0x0C, 0x15, 0x15, 0x15, 
    0x1C, 0x02, 0x0C, 0x14, 0x19, 0x19, 0x1A, 0x13, 0x17, 0x17, 0x0D, 0x0C, 0x13, 0x13, 0x0C, 0x0C, 
    0x00, 0x1C, 0x17, 0x15, 0x1A, 0x1A, 0x14, 0x0C, 0x17, 0x1B, 0x17, 0x0D, 0x1D, 0x0D, 0x0D, 0x17, 
    0x1E, 0x1F, 0x20, 0x21, 0x0C, 0x15, 0x0C, 0x17, 0x22, 0x22, 0x1B, 0x1B, 0x1B, 0x1B, 0x02, 0x12, 
    0x23, 0x1E, 0x00, 0x1C, 0x22, 0x1B, 0x02, 0x22, 0x22, 0x1B, 0x0D, 0x0D, 0x1B, 0x22, 0x01, 0x1C, 
    0x23, 0x1E, 0x0E, 0x00, 0x24, 0x1C, 0x1C, 0x12, 0x1B, 0x0C, 0x15, 0x15, 0x25, 0x1B, 0x20, 0x24, 
    0x1E, 0x0E, 0x1F, 0x26, 0x27, 0x28, 0x1C, 0x22, 0x29, 0x15, 0x1A, 0x1A, 0x14, 0x29, 0x2A, 0x24, 
    0x00, 0x04, 0x24, 0x27, 0x27, 0x28, 0x20, 0x22, 0x25, 0x14, 0x19, 0x19, 0x14, 0x0C, 0x12, 0x28, 
    0x03, 0x01, 0x01, 0x1C, 0x28, 0x28, 0x1C, 0x12, 0x29, 0x15, 0x1A, 0x1A, 0x15, 0x29, 0x12, 0x1C, 
    0x16, 0x02, 0x12, 0x1C, 0x27, 0x27, 0x24, 0x20, 0x22, 0x29, 0x0C, 0x0C, 0x0D, 0x1B, 0x22, 0x12, 
    0x02, 0x22, 0x20, 0x27, 0x26, 0x1F, 0x1F, 0x24, 0x20, 0x12, 0x22, 0x03, 0x01, 0x22, 0x1B, 0x17, 
    0x01, 0x2B, 0x00, 0x1F, 0x0E, 0x0E, 0x26, 0x27, 0x2B, 0x1C, 0x2B, 0x2B, 0x0B, 0x01, 0x0D, 0x0C, 
    0x0F, 0x0E, 0x1E, 0x2C, 0x0E, 0x0F, 0x04, 0x2B, 0x1C, 0x24, 0x27, 0x27, 0x2B, 0x01, 0x0D, 0x0C, 
};

u64 bombchu_bag_zobjTLUT_000200[] = {
#include "bombchu_bag_rgba16.inc.c"
};

u64 bombchu_bag_zobjTLUT_000238[] = {
#include "bombchu_bag_rgba16.inc.c"
};

u8 bombchu_bag_zobj_unaccounted_000438[] = {
    0xFF, 0xF7, 0x00, 0x0D, 0xFF, 0xF4, 0xFF, 0x00, 0x00, 0x79, 0x00, 0x5B, 0x2D, 0x73, 0x1B, 0xFF, 
    0xFF, 0xED, 0x00, 0x12, 0xFF, 0xF2, 0xFF, 0x00, 0x00, 0x20, 0x00, 0x5A, 0x0B, 0x74, 0x31, 0xFF, 
    0xFF, 0xEB, 0x00, 0x11, 0xFF, 0xF4, 0xFF, 0x00, 0x00, 0x13, 0x00, 0x75, 0xDA, 0x66, 0x3F, 0xFF, 
    0xFF, 0xF0, 0x00, 0x05, 0x00, 0x0A, 0xFF, 0x00, 0x00, 0x6F, 0x01, 0x2C, 0xA8, 0x3A, 0x45, 0xFF, 
};

Vtx bombchu_bag_zobjVtx_000478[] = {
#include "bombchu_bag.zobjVtx_000478.vtx.inc"
};

u8 bombchu_bag_zobj_unaccounted_000698[] = {
    0xE3, 0x00, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 
};

Gfx gGiBombchu0DL[] = {
    gsSPTexture(0x09C4, 0x09C4, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(0x04032530, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR |
                         G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x003C, 0x003C),
    gsDPLoadTLUT_pal256(bombchu_bag_zobjTLUT_000238),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsSPClearGeometryMode(G_FOG),
    gsSPSetGeometryMode(G_CULL_BACK | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsDPNoOp(),
    gsSPVertex(0x06000298, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 6, 9, 0),
    gsSP2Triangles(8, 9, 10, 0, 6, 4, 3, 0),
    gsSP2Triangles(11, 3, 5, 0, 12, 0, 13, 0),
    gsSP2Triangles(6, 14, 15, 0, 3, 16, 14, 0),
    gsSP2Triangles(17, 18, 10, 0, 6, 3, 14, 0),
    gsSP2Triangles(19, 14, 16, 0, 20, 21, 16, 0),
    gsSP2Triangles(20, 22, 23, 0, 22, 17, 24, 0),
    gsSP2Triangles(9, 6, 15, 0, 22, 18, 17, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 29, 27, 0),
    gsSPVertex(bombchu_bag_zobjVtx_000478, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(0, 6, 1, 0, 2, 7, 8, 0),
    gsSP2Triangles(9, 10, 7, 0, 2, 11, 12, 0),
    gsSP2Triangles(13, 7, 12, 0, 14, 1, 6, 0),
    gsSP2Triangles(2, 12, 7, 0, 13, 12, 15, 0),
    gsSP2Triangles(5, 13, 16, 0, 5, 16, 17, 0),
    gsSP2Triangles(3, 18, 19, 0, 1, 11, 2, 0),
    gsSP2Triangles(3, 14, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 9, 13, 0, 25, 0, 2, 0),
    gsSP2Triangles(13, 9, 7, 0, 26, 4, 27, 0),
    gsSP2Triangles(16, 13, 15, 0, 28, 29, 13, 0),
    gsSP2Triangles(28, 5, 30, 0, 3, 5, 17, 0),
    gsSPVertex(&bombchu_bag_zobjVtx_000478[31], 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};

Vtx bombchu_bag_zobjVtx_000818[] = {
#include "bombchu_bag.zobjVtx_000818.vtx.inc"
};

u8 bombchu_bag_zobj_unaccounted_0008D8[] = {
    0xE7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

Gfx gGiBombchu1DL[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0x09C4, 0x09C4, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(0x04032530, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR |
                         G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPLoadTLUT_pal256(bombchu_bag_zobjTLUT_000238),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsSPClearGeometryMode(G_FOG),
    gsSPSetGeometryMode(G_CULL_BACK | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsDPNoOp(),
    gsSPVertex(bombchu_bag_zobjVtx_000818, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(4, 5, 6, 0, 2, 7, 0, 0),
    gsSP2Triangles(8, 9, 7, 0, 10, 5, 9, 0),
    gsSP2Triangles(0, 11, 1, 0, 1, 11, 3, 0),
    gsSP2Triangles(4, 3, 5, 0, 2, 8, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 10, 6, 5, 0),
    gsSPEndDisplayList(),
};

Vtx bombchu_bag_zobjVtx_0009C0[] = {
#include "bombchu_bag.zobjVtx_0009C0.vtx.inc"
};

Gfx gGiBombchu2DL[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(bombchu_bag_zobjTex_000000, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPLoadTLUT_pal256(bombchu_bag_zobjTLUT_000200),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPClearGeometryMode(G_CULL_BACK | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPSetGeometryMode(G_FOG | G_LIGHTING | G_CLIPPING),
    gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
    gsSPVertex(bombchu_bag_zobjVtx_0009C0, 29, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 4, 0),
    gsSP2Triangles(5, 1, 0, 0, 6, 7, 8, 0),
    gsSP2Triangles(1, 3, 9, 0, 7, 6, 10, 0),
    gsSP2Triangles(1, 9, 11, 0, 9, 12, 11, 0),
    gsSP2Triangles(13, 14, 12, 0, 14, 15, 12, 0),
    gsSP2Triangles(11, 2, 1, 0, 1, 5, 4, 0),
    gsSP2Triangles(6, 16, 10, 0, 7, 17, 3, 0),
    gsSP2Triangles(3, 18, 9, 0, 19, 12, 15, 0),
    gsSP2Triangles(18, 13, 9, 0, 12, 9, 13, 0),
    gsSP2Triangles(14, 13, 20, 0, 14, 21, 15, 0),
    gsSP2Triangles(10, 16, 22, 0, 23, 18, 3, 0),
    gsSP2Triangles(6, 8, 24, 0, 3, 17, 23, 0),
    gsSP2Triangles(4, 5, 25, 0, 8, 7, 4, 0),
    gsSP2Triangles(25, 8, 4, 0, 7, 3, 4, 0),
    gsSP2Triangles(13, 18, 20, 0, 26, 27, 28, 0),
    gsSPVertex(&bombchu_bag_zobjVtx_0009C0[29], 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 0, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 9, 0, 12, 7, 9, 0),
    gsSP2Triangles(13, 14, 15, 0, 9, 16, 10, 0),
    gsSP2Triangles(15, 17, 13, 0, 9, 18, 16, 0),
    gsSP2Triangles(16, 18, 19, 0, 20, 19, 21, 0),
    gsSP2Triangles(21, 19, 22, 0, 18, 9, 8, 0),
    gsSP2Triangles(23, 18, 8, 0, 9, 11, 12, 0),
    gsSP2Triangles(13, 17, 24, 0, 15, 10, 25, 0),
    gsSP2Triangles(10, 16, 26, 0, 26, 16, 20, 0),
    gsSP2Triangles(19, 20, 16, 0, 21, 27, 20, 0),
    gsSP2Triangles(21, 22, 28, 0, 22, 29, 28, 0),
    gsSPVertex(&bombchu_bag_zobjVtx_0009C0[59], 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 3, 1, 0, 0),
    gsSP2Triangles(8, 9, 10, 0, 7, 8, 11, 0),
    gsSP2Triangles(9, 8, 7, 0, 11, 8, 3, 0),
    gsSP2Triangles(12, 13, 4, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 17, 21, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 24, 26, 0, 28, 29, 30, 0),
    gsSP1Triangle(21, 17, 19, 0),
    gsSPVertex(&bombchu_bag_zobjVtx_0009C0[90], 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 16, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 19, 20, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 23, 24, 0),
    gsSP2Triangles(24, 25, 26, 0, 26, 27, 28, 0),
    gsSP1Triangle(12, 29, 30, 0),
    gsSPVertex(&bombchu_bag_zobjVtx_0009C0[121], 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 7, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP1Triangle(16, 17, 18, 0),
    gsSPEndDisplayList(),
};

