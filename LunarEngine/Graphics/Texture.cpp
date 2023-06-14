#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "Texture.h"

Texture::Texture(const std::string& path)
	: _id(0), _filePath(path), _localBuffer(nullptr), _width(0), _height(0), _BPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	_localBuffer = stbi_load(path.c_str(), &_width, &_height, &_BPP, 4);
	glCall(glGenTextures(1, &_id));
	glCall(glBindTexture(GL_TEXTURE_2D, _id));

	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT));
	if (_localBuffer)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer);
		unbind();
		stbi_image_free(_localBuffer);
	}
	else
	{
		std::cout << "\nError: Failed to load texture" << std::endl;
		std::cout << stbi_failure_reason() << std::endl;
		__debugbreak();
	}
}

Texture::~Texture()
{
	glCall(glDeleteTextures(1, &_id));
}

void Texture::bind(unsigned int slot) const
{
	if (this == nullptr)
		return;
	glCall(glActiveTexture(GL_TEXTURE0 + slot));
	glCall(glBindTexture(GL_TEXTURE_2D, _id));

}

void Texture::unbind() const
{
	glCall(glBindTexture(GL_TEXTURE_2D, 0));
}
