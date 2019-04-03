#pragma once
/************************************************************************/
/* Call the printer to print photos
/* date:2019.04.03
/* author:hui
/************************************************************************/
#include "ofMain.h"
class ofxPrinter
{
public:

	static void print(ofImage & _img);			//only support png and jpg
	static void print(string _filePath);
private:
	ofxPrinter();
	~ofxPrinter();
};

