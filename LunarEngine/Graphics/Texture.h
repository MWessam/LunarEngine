#pragma once
#include "GLDebug.h"
#include <iostream>
#include <stb/stb_image.h>
class Texture
{
private:
	unsigned int _id;
	std::string _filePath;
	unsigned char* _localBuffer;
	int _width, _height, _BPP;		//Bits per pixel
public:
	Texture(const std::string& path);
	Texture() = default;
	~Texture();
	void bind(unsigned int slot = 0) const;
	void unbind() const;
	inline int GetWidth() const { return _width; }
	inline int GetHeight() const { return _height; }
	void createTexture();
};

