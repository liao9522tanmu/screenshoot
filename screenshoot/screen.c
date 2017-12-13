#include "screen.h"

HDC					mem_dc;
SIZE				screen_size;

void 
screen_caption(){

	HDC desk_dc = CreateDC(L"DISPLAY", NULL, NULL, NULL);// 桌面设备句柄

	mem_dc = CreateCompatibleDC(desk_dc);				// 与桌面desk_dc相兼容的临时缓存hdc

	screen_size.cx = GetDeviceCaps(desk_dc, HORZRES);	// 水平分辨率为宽

	screen_size.cy = GetDeviceCaps(desk_dc, VERTRES);	// 垂直分辨率为高

	HBITMAP hBmp = CreateCompatibleBitmap(desk_dc, screen_size.cx, screen_size.cy);	//与桌面desk_dc相兼容的画布handle

	SelectObject(mem_dc, hBmp);

	BitBlt(mem_dc, 0, 0, screen_size.cx, screen_size.cy, desk_dc, 0, 0, SRCCOPY);

}

