#include "ofxPrinter.h"
#include "UnityPrinterPlugin.h"


ofxPrinter::ofxPrinter()
{
}


ofxPrinter::~ofxPrinter()
{
}

void ofxPrinter::print(ofImage & _img)
{
	ofImageType type = _img.getImageType();

	switch (type)
	{
	case OF_IMAGE_GRAYSCALE:
		ofLogError("ofxPrinter") << "image type grayscale,only support png and jpg" << endl;
		break;
	case OF_IMAGE_COLOR:
		ImgPrint24((char *)_img.getPixelsRef().getPixels(), _img.getWidth(), _img.getHeight(), true);
		break;
	case OF_IMAGE_COLOR_ALPHA:
		ImgPrint32((char *)_img.getPixelsRef().getPixels(), _img.getWidth(), _img.getHeight(), true);
		break;
	case OF_IMAGE_UNDEFINED:
		ofLogError("ofxPrinter") << "image type undefined,only support png and jpg" << endl;
		break;
	default:
		break;
	}
}

void ofxPrinter::print(string _filePath)
{
	ofImage img;
	if (img.load(_filePath))
	{
		print(img);
	}
	else
	{
		ofLogError("ofxPrinter") << "image load failed,please check file" << endl;
	}
}
