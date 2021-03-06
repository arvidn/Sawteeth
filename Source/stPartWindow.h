/* Copyright 2001, Arvid and Jonas Norberg
Distributed under the terms of the MIT Licence. */

#ifndef _ST_PART_WINDOW_H_
#define _ST_PART_WINDOW_H_

#include <Window.h>
#include "stTrackerControl.h"
#include "stChannelView.h"
#include "stSong.h"

class stTrackerView;
class stMainWindow;

class stPartWindow:public BWindow
{
public:
	stPartWindow(stMainWindow *win, BPoint point,Part *part_to_edit, stSong *song);
	~stPartWindow();
	virtual void MessageReceived(BMessage *message);
	void Zoom(BPoint lefttop, float wide, float high);
private:
	void FullUpdate(int8 low, uint8 high);
	void UpdateTitle();
	
	stMainWindow *main_win;
	stTrackerControl *tracker_control;
	stSong *s;
	Part *part;
	BTextControl *name_string;
	
	BMenuBar* menu;
	BMenuItem* play;
};

#endif // _ST_PART_WINDOW_H_
