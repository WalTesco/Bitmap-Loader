

void bitmapInfo(struct bitmapheader);
//These values represent the fixed width value of the various header formats , this value is in the headerSize section(offset 0x0E) of the DIB/BITMAPINFOHEADER

const unsigned char BITMAPCOREHEADER = 12;	//Windows 2.0 / OS/2 1.0
const unsigned char BITMAPINFOHEADER = 40;	//Windows NT / 3.1
const unsigned char BITMAPV2INFOHEADER = 52; //Adobe Photoshop ...undocumented
const unsigned char BITMAPV3INFOHEADER = 56; //Adobe Photoshop ...not offically documented
const unsigned char OS22XBITMAPHEADER = 64;	//OS/2 BITMAPCOREHEADER2
const unsigned char BITMAPV4HEADER = 108; //Windows NT 4.0 / Windows 95
const unsigned char BITMAPV5HEADER = 124; //Windows NT 5.0 / Windows 98

//These values represent the compression format , this value is found in the compression section(offset 0x1E) of the DIB/BITMAPINFOHEADER

const unsigned char BI_RGB = 0 ; //No compression , most commonly used
const unsigned char BI_RLE8 = 1 ; //RLE 8-bit/pixel , can only be used with 8-bit/pixel formats
const unsigned char BI_RLE4 = 2 ; //RLE 4-bit/pixel , can only be used with 4-bit/pixel formats
const unsigned char BI_BITFIELDS = 3; //OS22XBITMAPHEADER Huffman 1D
const unsigned char BI_JPEG = 4; //OS22XBITMAPHEADER: RLE-24
const unsigned char BI_PNG = 5; //PNG ???
const unsigned char BI_ALPHABITFIELDS = 6; //RGBA bit field masks
const unsigned char BI_CMYK = 11; //Only Windows Metafile CMYK ???
const unsigned char BI_CMYKRLE8 = 12; //RLE-8 Only Windows Metafile CMYK ???
const unsigned char BI_CMYKTLE4 = 13; //RLE-4 Only Windows Metafile CMYK ???

struct bitmapheader
	{
	//BMPHEADER Contains info about the file
	unsigned int signature ; //File signature/magic number usually BM for bitmap
	unsigned long int fileSize; //Size of entire file
	unsigned int researved1; //Not used
	unsigned int researved2; //Not used
	unsigned long int bmpOffset; //Offset to pixel data
	//BITMAPINFOHEADER Start of info header
    unsigned long int headerSize; //Size this header
    unsigned long int bmpWidth; //Width of Bitmap
    unsigned long int bmpHeight; //Height of Bitmap
    unsigned int colorPlanes; //color planes...usually 1
    unsigned int bitsPerPx; //Number of bits per pixel , 1 bit is mono-color/mono-chrome
    unsigned long int compression; //Compression scheme used ...not using any
    unsigned long int imageSize; //Pixel data size
    unsigned long int horizontalRez; // Just what you think it would be
    unsigned long int verticalRez; // Ditto
    unsigned long int colorsPalette; //Colors in pallet
    unsigned long int importantColors; // 0 = all important

	};

	void bitmapInfo (struct bitmapheader header)
	{
	cout <<"\n"<<header.bmpWidth<<"*"<<header.bmpHeight;
	cout <<"\nFile Size :"<<header.fileSize <<" Bytes";
	cout <<"\nOffset to BMP data :"<<header.bmpOffset;
	cout <<"\nFileHeader Size :"<<header.headerSize;
	cout <<"\n"<<header.bitsPerPx<<": Bits Per Pixel";
	cout <<"\nCompression scheme :"<<header.compression;
	cout <<"\nPixel Data size :"<<header.imageSize;
	cout <<"\nColors in palette :"<<header.colorsPalette;
	cout <<"\nImportant colors :"<<header.importantColors;
	}

