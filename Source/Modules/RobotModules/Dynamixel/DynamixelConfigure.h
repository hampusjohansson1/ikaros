//
//	Dynamixel.h		This file is a part of the IKAROS project
//
//    Copyright (C) 2018 Birger Johansson
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef DynamixelConfigure_
#define DynamixelConfigure_

#include "IKAROS.h"
#include "DynamixelComm.h"
#include "DynamixelServo.h"

class DynamixelConfigure: public Module
{
public:
	static Module * Create(Parameter * p) { return new DynamixelConfigure(p); }
	
	DynamixelConfigure(Parameter * p);
	virtual ~DynamixelConfigure();
	void        SetSizes();
	void		Init();
	void		Tick();
	
	void        PrintAll();
	
private:
	int         size;
	int         nrOfServos;
	int         blink;
	int         baudRate;
	
	int **      inAdress;
	int         protocol;
	int **      inAdressSize;
	
	float * 	resetModeOut;
	float * 	changeModeOut;
	
	float * 	set;
	float * 	active;
	
	bool 		resetMode;
	bool 		scan_mode;
	DynamixelServo **    servo;
	
	// Arrays used to send commands to servos // FIXME: USE separat list for continous servos
	int *       servoIndex;
	int *       servoId;
	
	const char * device;
	DynamixelComm * com;
	
	int 		changeAdress;
	int			newValue;
	int 		forceModel;
	
	void 		PrintChange(int active);
};
#endif
