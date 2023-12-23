#pragma once
#include <cstdint>
#include <vector>
#include <memory>
#include <iostream>

namespace GeneralAPIs
{
	enum class ShaderDataType
	{
		None = 0, Vec2, Vec3, Vec4, Float, Mat3, Mat4
	};
	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return 4;
		case ShaderDataType::Vec2:	return 4 * 2;
		case ShaderDataType::Vec3:   return 4 * 3;
		case ShaderDataType::Vec4:   return 4 * 4;
		case ShaderDataType::Mat3:     return 4 * 3 * 3;
		case ShaderDataType::Mat4:     return 4 * 4 * 4;
		}
		return 0;
	}

	// Struct that stores the size of data of specifc elements.
	// Example: storing 3 floats for position vertices, and 2 floats for tex coords.
	template <typename T>
	struct BufferLayoutElement	// Currently only handles floats
	{
	public:		// Methods
		BufferLayoutElement(uint32_t count, ShaderDataType type):
			Count(count), Type(type), SizeInBytes(ShaderDataTypeSize(Type))
		{}

	public:		// Members
		uint32_t Count;
		ShaderDataType Type;
		size_t Offset;
		size_t SizeInBytes;
	};

	class BufferLayout
	{
	public:
		BufferLayout():
			_stride(0) {}

		template<typename T>
		void push(uint32_t count, ShaderDataType type)
		{
			_elements.emplace_back(BufferLayoutElement<T>(count, type));
			_elements.back().Type = type;
			recalculateOffsetAndStride();
		}

		inline const std::vector<BufferLayoutElement<float>>& getElements() const { return _elements; }
		inline const uint32_t getStride() const { return _stride; }
	
	private:	// Methods
		void recalculateOffsetAndStride();
	
	private:	// Members
		uint32_t _stride;
		std::vector<BufferLayoutElement<float>> _elements;
	};

	class Buffer
	{
	public:		// Methods
		Buffer()
		{

		}
		virtual ~Buffer() = default;
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		const inline uint32_t getSize() const { return _size; }
		inline BufferLayout& getLayout() { return _layout; }
	protected:	// Methods
		virtual void setData(uint64_t dataSizeInBytes) = 0;
		virtual void updateData(uint64_t dataSizeInBytes) = 0;
		template <typename T> 
		void readyBuffer(uint32_t size, T* data)
		{
			_size = size;
			_data = data;
		}

	protected:	// Members
		// Number of elements in buffer
		uint32_t _size;
		void* _data;	

	private:	// Members
		BufferLayout _layout;
	};


		// Generic template to handle all vertex data types
	class VertexBuffer 
		: public Buffer
	{
	public:		// Methods
		virtual ~VertexBuffer() = default;
		template <typename T>
		void createBuffer(uint32_t size, T* data)
		{
			readyBuffer<T>(size, data);
			setData(sizeof(T));
		}
		template <typename T>
		void updateBuffer(uint32_t size, T* data)
		{
			readyBuffer<T>(size, data);
			updateData(sizeof(T));
		}

	private:	// Methods



	protected:	// Members

	};

	class IndexBuffer 
		: public Buffer
	{
	public:		// Methods
		virtual ~IndexBuffer() = default;
		void createBuffer(uint32_t size, uint32_t* data)
		{
			readyBuffer<uint32_t>(size, data);
			setData(sizeof(uint32_t));
		}

	private:	// Methods


	private:	// Members
	};
}

