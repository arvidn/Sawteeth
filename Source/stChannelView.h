/* Copyright 2001, Arvid and Jonas Norberg
Distributed under the terms of the MIT Licence. */

#ifndef ST_CHANNEL_VIEW_H
#define ST_CHANNEL_VIEW_H

#include "stPartSquare.h"
#include "stSong.h"

class stChannelView : public BView
{
public:
	stChannelView(stSong *song, Channel *channel, BRect frame);
	~stChannelView();
	
void	Draw(BRect frame);
void	MessageReceived(BMessage *message); 

void	Update();
void	SetZoom(float PixelsPerPAL);
int		Width();

void	FindSquare();
void	MakeFocusPAL(uint32 startPAL);
void	MakeFocusInd(int32 number);
void	Mark(uint32 ind);
void	UnMark(); // all

void	MakeSemiFocus();

int		GetFocusPosition();
void	Del();
void	Cut();
void	Copy();
void	Paste();

void	MovePart(int source, int dest);

int channelHeight() {return height;}

private:
	void Transpose(int8 t);
	
	bool marking;
	uint32 markstart;
	uint32 focus;	// den partsquaren som är 
	stSong *s;
	Channel *chan;
	int height;
	stPartSquare *ps[CHNSTEPS];

	float m_z; // zoom
};

#endif
