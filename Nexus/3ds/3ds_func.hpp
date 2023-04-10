#ifndef _3DS_FUNC_H
#define _3DS_FUNC_H

int  _3ds_init();
void _3ds_exit();

// framebuffer copy for SW rendering
void CopyFrameBuffer16(u16* ptr);
void _3ds_flip();
void _3ds_setColorDepth();
void hang();

#endif
