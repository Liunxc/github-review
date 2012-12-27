#pragma once

typedef short u16;
typedef unsigned int u32;

#pragma pack(1)

struct bmp_head {
	u16 ID;
	u32 filesize;
	u32 reserved;
	u32 dataoffset;
	u32 headsize;
	u32 width;
	u32 height;
	u16 planes;
	u16 bpp;
	u32 compressiom;
	u32 datasize;
	u32 hresolution;
	u32 versolution;
	u32 color;
};
#pragma park()

