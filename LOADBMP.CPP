#include <iostream.h>
#include <fstream.h>
#include <bitmap.h>
#include <plot.h>

int main()
{
	



		bitmapheader myheader;		//Create new struct myheader found in BITMAP.h
		
		ifstream BITMAP;	//Create a new ifstream class called bitmap
		
		BITMAP.open("C:\\TC\\bin\\rocket.bmp" , ios::binary);		//Opens our bitmap in binary mode
		//The read member function of ifstream takes a pointer to a char and the number of bytes to read
		//So if I want to store an int I typecast an address of a pointer to char and read 2 bytes
		//I'm not sure how I figured this out or how it really works , but it does :)
		BITMAP.read((char*)&myheader.signature , 2);
		BITMAP.read((char*)&myheader.fileSize , 4);
		BITMAP.read((char*)&myheader.researved1 , 2);
		BITMAP.read((char*)&myheader.researved2 , 2);
		BITMAP.read((char*)&myheader.bmpOffset , 4);
		BITMAP.read((char*)&myheader.headerSize , 4);
		BITMAP.read((char*)&myheader.bmpWidth , 4);
		BITMAP.read((char*)&myheader.bmpHeight , 4);
		BITMAP.read((char*)&myheader.colorPlanes , 2);
		BITMAP.read((char*)&myheader.bitsPerPx , 2);
		BITMAP.read((char*)&myheader.compression , 4);
		BITMAP.read((char*)&myheader.imageSize , 4);
		BITMAP.read((char*)&myheader.horizontalRez , 4);
		BITMAP.read((char*)&myheader.verticalRez , 4);
		BITMAP.read((char*)&myheader.colorsPalette ,4);
		BITMAP.read((char*)&myheader.importantColors ,4);

		unsigned char * palettedata = new unsigned char[1020];	//Each palette entry consists of a blue , green , red , and reserved byte , in that order . 255 * 4 bytes =1020
		unsigned char * bitmapdata = new unsigned char[myheader.bmpWidth * myheader.bmpHeight];	//Each pixel is represented by its 8-bit palette reference

		BITMAP.read(palettedata , 1020);	//Read 1020 bytes of palette data to memory
		BITMAP.read(bitmapdata ,myheader.bmpWidth*myheader.bmpHeight);	//Read bitmap image data to memory

		setscreen((unsigned char)0x13); //Set screen to VGA mode 0x13 : 320*200 256 , colors . This function is defined in Plot.h


		for (unsigned char x=0 ; x<63 ;x++ )
		{
		plotpixel(bitmapdata[i] , x , 32);	//Pixel plotting function take an unsigned char for color , an unsigned int for x position , and an unsigned int for y position
		}
		
		cin.get();
		BITMAP.close();
		return 0;
}