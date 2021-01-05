/*
PicButton.h - animated button with picture
Copyright (C) 2010 Uncle Mike
Copyright (C) 2017 a1batross

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#pragma once
#ifndef MENU_PICBUTTON_H
#define MENU_PICBUTTON_H

#include "BtnsBMPTable.h"
#include "BaseWindow.h"

// Use hover bitmap from btns_main.bmp instead of head_%s.bmp
// #define TA_ALT_MODE 1

// Use banner for animation
#define TA_ALT_MODE2 1

// Title Transition Time period
#define TTT_PERIOD		200.0f

class CMenuPicButton : public CMenuBaseItem
{
public:
	typedef CMenuBaseItem BaseClass;

	CMenuPicButton();
	bool KeyUp( int key ) override;
	bool KeyDown( int key ) override;
	void Draw( void ) override;

	void SetPicture( EDefaultBtns ID );
	void SetPicture( const char *filename );

	bool bEnableTransitions;
	bool bPulse;

	static bool DrawTitleAnim( CMenuBaseWindow::EAnimation anim );
	static void ClearButtonStack( void );
	static float GetTitleTransFraction( void );

	static void SetupTitleQuadForLast( int x,int y, int w, int h);
	static void SetTransPicForLast( HIMAGE pic );

	void SetupTitleQuad( int x,int y, int w, int h);
	void SetTransPic( HIMAGE pic );

	static void RootChanged( bool isForward );
private:
	bool bRollOver;

	enum animState_e { AS_TO_TITLE = 0, AS_TO_BUTTON };
	struct Quad
	{
		Quad(): x(0), y(0), lx(0), ly(0) {}
		float x, y, lx, ly;
	};

	static void SetTitleAnim( int state );
	void TACheckMenuDepth( void );
	void PushPButtonStack( void );
	static void PopPButtonStack( void );
	static const char *GetLastButtonText( void );

	void DrawButton( int r, int g, int b, int a, wrect_t *rects, int state );

	HIMAGE hPic;
	int button_id;
	int iFocusStartTime;
	int iOldState;

	Quad TitleLerpQuads[2];
	HIMAGE TransPic;

	static CMenuPicButton *temp;

	static Quad LerpQuad( Quad a, Quad b, float frac );

	static int transition_initial_time;
	static int transition_state;

	static HIMAGE s_hCurrentTransPic;
	static wrect_t s_pCurrentTransRect;
	static Quad s_CurrentLerpQuads[2];
	friend class CMenuBannerBitmap;
};

#endif
