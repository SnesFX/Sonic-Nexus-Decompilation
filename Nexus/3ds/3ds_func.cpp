#include "../RetroEngine.hpp"

int _3ds_init() {
	gfxInitDefault();
	consoleInit(GFX_BOTTOM, NULL);

	if (Engine.useC2DRender) {
		// TODO: set up Citro2D stuff
	}

#if RETRO_USING_SDL1_AUDIO || RETRO_USING_SDLMIXER
	SDL_Init(SDL_INIT_AUDIO);	
#endif

	return 0;
}

void _3ds_exit() {
	if (Engine.useC2DRender) {
		// TODO: stuff
	}

	gfxExit();
}

void _3ds_setColorDepth() {

	if (Engine.colourMode == 1) {
		printf("NOTE: using 16-bit color\n");
		gfxSetScreenFormat(GFX_TOP, GSP_RGB565_OES);
	} else {
		gfxSetScreenFormat(GFX_TOP, GSP_RGBA8_OES);
	}
}

// basically copied from the RSDKv3/4 port
void CopyFrameBuffer16(u16* ptr) {
	u16* fb = (u16*) gfxGetFramebuffer(GFX_TOP, GFX_LEFT, 0, 0);

	for (int y = 0; y < SCREEN_YSIZE; y++) {
        	for (int x = 0; x < SCREEN_XSIZE; x++) {
            		fb[((x * 240) + (240 - y - 1))] = *ptr++;
		}
    	}
}

void hang() {
	while (aptMainLoop()) {
		hidScanInput();
		if (hidKeysDown())
			break;

		_3ds_flip();
	}
}

void _3ds_flip() {
	gfxFlushBuffers();
	gfxSwapBuffers();
	gspWaitForVBlank();
}
