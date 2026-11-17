/*
 * Copyright 2000-2008, François Revol, <revol@free.fr>. All rights reserved.
 * Distributed under the terms of the MIT License.
 */

#include "ScreenshotView.h"
#include <View.h>
#include <Bitmap.h>
#include <stdio.h>
#include <Debug.h>


ScreenshotView::ScreenshotView(BRect bounds, const char *name,
						uint32 resizeMask,
						uint32 flags)
	: BView(bounds, name, resizeMask, flags)
{
	fBitmap = NULL;
}


ScreenshotView::~ScreenshotView()
{
	if (fBitmap)
		delete fBitmap;
}


void
ScreenshotView::AttachedToWindow()
{
	UpdateScreenshot();
}


void
ScreenshotView::UpdateScreenshot()
{
	if (Window() == NULL)
		return;

	ClearViewBitmap();

	if (fBitmap) {
		SetViewBitmap(fBitmap, fBitmap->Bounds(), Bounds(), B_FOLLOW_ALL,
			B_FILTER_BITMAP_BILINEAR);
	}

	Invalidate();
}


void
ScreenshotView::SetScreenshot(BBitmap *bitmap)
{
	if (fBitmap)
		delete fBitmap;
	fBitmap = bitmap;
	UpdateScreenshot();
}
