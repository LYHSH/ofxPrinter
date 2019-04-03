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
		ofLogNotice("ofxPrinter") << "set image type OF_IMAGE_GRAYSCALE to OF_IMAGE_COLOR" << endl;
		_img.setImageType(OF_IMAGE_COLOR);
		break;
	case OF_IMAGE_COLOR:
		break;
	case OF_IMAGE_COLOR_ALPHA:
		ofLogNotice("ofxPrinter") << "set image type OF_IMAGE_COLOR_ALPHA to OF_IMAGE_COLOR" << endl;
		_img.setImageType(OF_IMAGE_COLOR);
		break;
	case OF_IMAGE_UNDEFINED:
		ofLogError("ofxPrinter") << "image type undefined" << endl;
		return;
		break;
	default:
		ofLogError("ofxPrinter") << "defalut:image type undefined" << endl;
		break;
	}
	ImgPrint24((char *)_img.getPixelsRef().getPixels(), _img.getWidth(), _img.getHeight(), true);
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
