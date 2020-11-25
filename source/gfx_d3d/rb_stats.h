#pragma once

enum GfxPrimStatsTarget
{
	GFX_PRIM_STATS_FIRST = 0x0,
	GFX_PRIM_STATS_DEFAULT = 0x0,
	GFX_PRIM_STATS_WORLD = 0x1,
	GFX_PRIM_STATS_SMODELRIGID = 0x2,
	GFX_PRIM_STATS_XMODELRIGID = 0x3,
	GFX_PRIM_STATS_XMODELSKINNED = 0x4,
	GFX_PRIM_STATS_BMODEL = 0x5,
	GFX_PRIM_STATS_FX = 0x6,
	GFX_PRIM_STATS_HUD = 0x7,
	GFX_PRIM_STATS_DEBUG = 0x8,
	GFX_PRIM_STATS_CODE = 0x9,
	GFX_PRIM_STATS_LAST = 0x9,
	GFX_PRIM_STATS_COUNT = 0xA,
};

enum GfxPrimStatsStage
{
	GFX_PRIM_STATS_STAGE_FIRST = 0x0,
	GFX_PRIM_STATS_STAGE_DEFAULT = 0x0,
	GFX_PRIM_STATS_STAGE_SHADOW_SUN = 0x1,
	GFX_PRIM_STATS_STAGE_SHADOW_SPOT = 0x2,
	GFX_PRIM_STATS_STAGE_PREPASS = 0x3,
	GFX_PRIM_STATS_STAGE_LIT = 0x4,
	GFX_PRIM_STATS_STAGE_SONAR = 0x5,
	GFX_PRIM_STATS_STAGE_SONAR_DEPTH = 0x6,
	GFX_PRIM_STATS_STAGE_DEPTH_HACK = 0x7,
	GFX_PRIM_STATS_STAGE_LIGHTMAP = 0x8,
	GFX_PRIM_STATS_STAGE_LIT_QUASI_OPAQUE = 0x9,
	GFX_PRIM_STATS_STAGE_LIT_TRANS = 0xA,
	GFX_PRIM_STATS_STAGE_LIT_FX = 0xB,
	GFX_PRIM_STATS_STAGE_EMISSIVE_OPAQUE = 0xC,
	GFX_PRIM_STATS_STAGE_EMISSIVE_TRANS = 0xD,
	GFX_PRIM_STATS_STAGE_EMISSIVE_FX = 0xE,
	GFX_PRIM_STATS_STAGE_2D = 0xF,
	GFX_PRIM_STATS_STAGE_COUNT = 0x10,
	GFX_PRIM_STATS_STAGE_LAST = 0xF,
};

struct GfxPrimStats
{
	int counters[8];
};

struct GfxStageStats
{
	bool used;
	GfxPrimStats prims[10];
};

struct GfxFrameStats
{
	GfxStageStats stages[16];
	GfxPrimStatsStage currentStage;
	GfxPrimStatsTarget currentTarget;
	struct {
		int gfxEntCount;
		int geoIndexCount;
		int fxIndexCount;
	} counters;
};

int previous;
unsigned int frameCount;
float frameRate;