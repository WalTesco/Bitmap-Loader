#include <iostream.h>

void setscreen (char mode); //Function prototype for setting screen mode
void setpal (unsigned char index , unsigned char r , unsigned char g , unsigned char b); //Function for setting color palette in VGA 
void plotpixel (unsigned char color , unsigned int xpos,unsigned int ypos); //Function prototype for pixel plotter

void setscreen(unsigned char mode)
{
asm{mov ah , 0x00}; //Set screen mode first byte to 00
asm{mov al , mode}; //Set most significant byte to user input typically 0x13 for VGA mode 13 : 320 * 200 resolution , 256 colors
asm{int 0x10}; //Call BIOS video service interrupt to set screen mode
return;
}

void setpal(unsigned int index , unsigned char b , unsigned char g , unsigned char r)
{

asm{mov dx , 0x3C6}; //DAC write function
asm{mov ax , 0xFF}; //Mask all write registers r,g,b to make writeable
asm{out dx , ax}; //Write to memory mapped DAC IO

asm{mov dx ,0x3C8}; //Set palette index register to write to
asm{mov ax ,index};
asm{out dx , ax};

asm{mov dx , 0x3C9}; //Write red value to DAC write register
asm{mov al , b};
asm{out dx , al};

asm{mov dx , 0x3C9}; //Write green value to DAC write register
asm{mov al , g};
asm{out dx , al};

asm{mov dx , 0x3C9}; //Write blue value to DAC write register
asm{mov al , r};
asm{out dx , al};

}

void plotpixel(unsigned char color ,unsigned int xpos ,unsigned int ypos)
{
asm{mov ah , 0x0c}; //Write pixel function
asm{mov al , color}; //Store pixel color to register
asm{mov bh , 0x01}; //Video memory page number , first visible page
asm{mov cx , xpos}; //Store X position to register
asm{mov dx , ypos}; //Store Y position to register
asm{int 0x10}; //Call BIOS video service interrupt to plot pixel
return;
}


