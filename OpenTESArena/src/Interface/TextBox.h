#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include <memory>
#include <string>
#include <vector>

#include "../Media/FontName.h"
#include "Surface.h"

// A scrollable text box could just have a text box surface, and then use a Rectangle
// to use only the visible part of it. The scroll bar can be thought of as a kind of
// "sliding window"; the size of the clickable scroll bar is the percentage of the lines 
// shown, and the position would follow a similar pattern.

class Color;
class TextureManager;

class TextBox : public Surface
{
private:
	std::vector<std::string> textLines;
	FontName fontName;
public:
	TextBox(int x, int y, const Color &color, const std::string &text,
		FontName fontName, TextureManager &textureManager);
	//TextBox(const Point &center, ...);
	~TextBox();

	// I think the "centered" text box would be very useful, but it might need to
	// use a separate constructor that doesn't call the other one.

	// Alignment...? Maybe it should be a constructor argument, not a void function. 
	// Things like game world on-screen text might be centered. Everything else is 
	// left-aligned.
};

#endif