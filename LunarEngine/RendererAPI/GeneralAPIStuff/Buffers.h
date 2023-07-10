#pragma once
#include <cstdint>
#include <vector>

namespace GeneralAPIs
{
	enum class ShaderDataType
	{
		None = 0, Vec3, Vec4, Float, Mat3, Mat4
	};
	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return 4;
		case ShaderDataType::Vec3:   return 4 * 3;
		case ShaderDataType::Vec4:   return 4 * 4;
		case ShaderDataType::Mat3:     return 4 * 3 * 3;
		case ShaderDataType::Mat4:     return 4 * 4 * 4;
		}
		return 0;
	}

	// Struct that stores the size of data of specifc elements.
	// Example: storing 3 floats for position vertices, and 2 floats for tex coords.
	struct BufferLayoutElement	// Currently only handles floats
	{
	public:		// Methods
		template <typename T>
		BufferLayoutElement(uint32_t count, ShaderDataType type):
			Count(count), _sizePerElement(sizeof(T)), Type(type), SizeInBytes(ShaderDataTypeSize(Type))
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
			_elements.push_back(BufferLayoutElement<T>(count, type));
			_elements.end()->Type = type;
			recalculateOffsetAndStride();
		}

		inline const std::vector<BufferLayoutElement> getElements() const { return _elements; }
		inline const uint32_t getStride() const { return _stride; }
	
	private:	// Methods
		void recalculateOffsetAndStride();
	
	private:	// Members
		uint32_t _stride;
		std::vector<BufferLayoutElement> _elements;
	};

	class Buffer
	{
	public:		// Methods
		virtual ~Buffer() = default;
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
		const inline uint32_t getSize() const { return _size; }
		inline BufferLayout getLayout() { return _layout; }
	protected:	// Methods
		virtual void setData(uint64_t dataSizeInBytes) = 0;
		virtual void updateData(uint64_t dataSizeInBytes) = 0;
		template <typename T> 
		void readyBuffer(uint32_t size, T* data)
		{
			bind();
			_size = size;
			_data = data;
		}

	protected:	// Members
		// Number of elements in buffer
		uint32_t _size;
		void* _data;	// TODO: test it, i dont think its the best idea to do that.

	private:	// Members
		BufferLayout _layout;
	};


		// Generic template to handle all vertex data types
	class VertexBuffer 
		: public Buffer
	{
	public:		// Methods
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
		void createBuffer(uint32_t size, uint64_t* data)
		{
			readyBuffer<uint64_t>(size, data);
			setData(sizeof(uint64_t));
		}

	private:	// Methods


	private:	// Members
	};
}

