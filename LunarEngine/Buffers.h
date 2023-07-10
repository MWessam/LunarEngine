#pragma once
#include <cstdint>
#include <vector>

// Struct that stores the size of data of specifc elements.
// Example: storing 3 floats for position vertices, and 2 floats for tex coords.
struct BufferLayoutElement	// Currently only handles floats
{
public:		// Methods
	template <typename T>
	BufferLayoutElement(uint32_t count):
		Count(count), _sizePerElement(sizeof(T))
	{}
	inline const uint32_t getSize() const
	{
		return _sizePerElement;
	}

public:		// Members
	uint32_t Count;

private:	// Members
	uint32_t _sizePerElement;
};

class BufferLayout
{
public:
	BufferLayout():
		_stride(0) {}

	template<typename T>
	void push(uint32_t count)
	{
		_elements.push_back(BufferLayoutElement<T>(count));
		_stride += count * _elements.end()->getSize();
	}

	inline const std::vector<BufferLayoutElement> getElements() const { return _elements; }
	inline const uint32_t getStride() const { return _stride; }
private:	// Members
	uint32_t _stride;
	std::vector<BufferLayoutElement> _elements;
};

class Buffer
{
public:		// Methods
	virtual ~Buffer() = 0;
	virtual void bind() const = 0;
	virtual void unbind() const = 0;
	const inline uint32_t getSize() const { return _size; }
	inline BufferLayout getLayout() const { return _layout; }
protected:	// Methods
	virtual void setData() = 0;

protected:	// Members
	uint32_t _size;

private:	// Members
	BufferLayout _layout;
};


template <typename T>	// Generic template to handle all vertex data types
class VertexBuffer 
	: public Buffer
{
public:		// Methods
	void createBuffer(uint32_t size, T* data)
	{
		_size = size;
		_data = data;
		bind();
		setData();
	}

private:	// Methods



private:	// Members
	T* _data;
};

class IndexBuffer 
	: public Buffer
{
public:		// Methods
	void createBuffer(uint32_t size, uint32_t* data)
	{
		_size = size;
		_data = data;
		bind();
		setData();
	}

private:	// Methods


private:	// Members
	uint32_t* _data;
};

