/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WIN_COMMON_H
#define WIN_COMMON_H

enum CriticalSection : __int32
{
	CRITSECT_ALLOC_MARK = 0x0,
	CRITSECT_FX_VIS = 0x1,
	CRITSECT_OCCLUSION_QUERY = 0x2,
	CRITSECT_PHYSICS = 0x3,
	CRITSECT_PHYSICS_UPDATE = 0x4,
	CRITSECT_PHYSICS_DESTRUCTIBLE_HIT = 0x5,
	CRITSECT_FX_UNIQUE_HANDLE = 0x6,
	CRITSECT_SOUND_COMMAND_ALLOC = 0x7,
	CRITSECT_SOUND_COMMAND_PUSH = 0x8,
	CRITSECT_SOUND_NOTIFY_ALLOC = 0x9,
	CRITSECT_SOUND_NOTIFY_PUSH = 0xA,
	CRITSECT_SOUND_BANK = 0xB,
	CRITSECT_SOUND_LOOKUP_CACHE = 0xC,
	CRITSECT_CAREER_STATS = 0xD,
	CRITSECT_CONSOLE = 0xE,
	CRITSECT_DEBUG_SOCKET = 0xF,
	CRITSECT_COM_ERROR = 0x10,
	CRITSECT_STATMON = 0x11,
	CRITSECT_MEM_ALLOC0 = 0x12,
	CRITSECT_MEM_ALLOC1 = 0x13,
	CRITSECT_DEBUG_LINE = 0x14,
	CRITSECT_DEBUG_BRUSHES_AND_PATCHES = 0x15,
	CRITSECT_CLIENT_MESSAGE = 0x16,
	CRITSECT_CLIENT_CMD = 0x17,
	CRITSECT_DOBJ_ALLOC = 0x18,
	CRITSECT_XANIM_ALLOC = 0x19,
	CRITSECT_KEY_BINDINGS = 0x1A,
	CRITSECT_SERVER_MESSAGE = 0x1B,
	CRITSECT_SERVER_PLAYERINFO = 0x1C,
	CRITSECT_SCRIPT_STRING = 0x1D,
	CRITSECT_MEMORY_TREE = 0x1E,
	CRITSECT_ASSERT = 0x1F,
	CRITSECT_RD_BUFFER = 0x20,
	CRITSECT_SYS_EVENT_QUEUE = 0x21,
	CRITSECT_FATAL_ERROR = 0x22,
	CRITSECT_DXDEVICE = 0x23,
	CRITSECT_DXDEVICE_GLOB = 0x24,
	CRITSECT_DXCONTEXT = 0x25,
	CRITSECT_SCRIPT_DEBUGGER_ALLOC = 0x26,
	CRITSECT_SCRIPT_DEBUGGER = 0x27,
	CRITSECT_REMOTE = 0x28,
	CRITSECT_MISSING_ASSET = 0x29,
	CRITSECT_LIVE = 0x2A,
	CRITSECT_AUDIO_PHYSICS = 0x2B,
	CRITSECT_LUI = 0x2C,
	CRITSECT_VCS = 0x2D,
	CRITSECT_CINEMATIC = 0x2E,
	CRITSECT_CINEMATIC_TARGET_CHANGE = 0x2F,
	CRITSECT_CINEMATIC_UPDATEFRAME = 0x30,
	CRITSECT_RB_TRANSFER = 0x31,
	CRITSECT_NETTHREAD_OVERRIDE = 0x32,
	CRITSECT_DEMONWARE = 0x33,
	CRITSECT_IK = 0x34,
	CRITSECT_TL_MEMALLOC = 0x35,
	CRITSECT_VA_ALLOC = 0x36,
	CRITSECT_MEMTRACK = 0x37,
	CRITSECT_CBUF = 0x38,
	CRITSECT_CURVEALLOC = 0x39,
	CRITSECT_NETQUEUE = 0x3A,
	CRITSECT_ZLIB = 0x3B,
	CRITSECT_BLACKBOX = 0x3C,
	CRITSECT_GDT_COMMAND = 0x3D,
	CRITSECT_STRINGED_COMMAND = 0x3E,
	CRITSECT_RADIANT_SERVER_COMMAND = 0x3F,
	CRITSECT_RADIANT_CLIENT_COMMAND = 0x40,
	CRITSECT_RECORDER = 0x41,
	CRITSECT_SERVERDEMO = 0x42,
	CRITSECT_IO_SCHEDULER = 0x43,
	CRITSECT_FILE_ID_ARRAY = 0x44,
	CRITSECT_MEMFIRSTFIT = 0x45,
	CRITSECT_FXBEAM = 0x46,
	CRITSECT_GLASS_ACTIONS = 0x47,
	CRITSECT_DBHASH = 0x48,
	CRITSECT_CLUMP = 0x49,
	CRITSECT_SNAPSHOT_PROFILE = 0x4A,
	CRITSEC_WEBM_STREAM_ACCESS = 0x4B,
	CRITSEC_SV_LEADERBOARDS = 0x4C,
	CRITSECT_COUNT = 0x4D,
};

void TRACK_win_common(void);
void Sys_Mkdir(char const*);
void Sys_MkdirEx(char const*);
char const* Sys_Cwd(void);
char const* Sys_DefaultCDPath(void);
char const* Sys_DefaultHomePath(void);
char const* Sys_DefaultInstallPath(void);
int HasFileExtension(const char*, const char*);
bool Sys_FileExists(char const*);
void Sys_ListFilteredFiles(struct HunkUser*, char const*, char const*, char const*, char**, int*);
char** Sys_ListFiles(char const*, char const*, char const*, int*, int);
int Sys_DirectoryHasContents(char const*);
void Sys_InitializeCriticalSections(void);
void Sys_EnterCriticalSection(enum CriticalSection);
bool Sys_TryEnterCriticalSection(enum CriticalSection);
void Sys_LeaveCriticalSection(enum CriticalSection);

#endif