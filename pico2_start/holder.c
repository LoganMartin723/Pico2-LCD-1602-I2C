#include "stdint.h"
#include <stdio.h>

static inline bool find_btn_in_report(hid_gamepad_report const *report, uint8_t btn)
{

	if(report->buttons == btn) 
		return true;
	return false;
}


static void process_gamepad_report(hid_gamepad_report const* report);

static void process_gamepad_report(hid_gamepad_report const* report)
{
	static hid_gamepad_report prev_report = {0,0,0,0,0,0,0}; //This will check if any buttons were released

	if(report->x)

	return;
}
