#include "Buffers.h"

void GeneralAPIs::BufferLayout::recalculateOffsetAndStride()
{
	size_t offset = 0;
	_stride = 0;
	for (auto& element : _elements)
	{
		element.Offset = offset;
		offset += element.SizeInBytes * element.Count;
		_stride += element.SizeInBytes * element.Count;
	}
}
