#pragma once

namespace Kore {
	class Reader;

	namespace Graphics1 {
		enum ImageCompression { ImageCompressionNone, ImageCompressionDXT5, ImageCompressionASTC, ImageCompressionPVRTC };

		class Image {
		public:
			enum Format { RGBA32, Grey8, RGB24, RGBA128, RGBA64, A32, BGRA32, A16 };

			static int sizeOf(Image::Format format);

			Image(int width, int height, Format format, bool readable);
			Image(int width, int height, int depth, Format format, bool readable);
			Image(const char* filename, bool readable);
			Image(Kore::Reader& reader, const char* format, bool readable);
			Image(void* data, int width, int height, Format format, bool readable);
			Image(void* data, int width, int height, int depth, Format format, bool readable);
			virtual ~Image();
			int at(int x, int y);

			int width, height, depth;
			Format format;
			bool readable;
			ImageCompression compression;
			u8* data;
			float* hdrData;
			int dataSize;
			unsigned internalFormat;

		protected:
			Image();
			void init(Kore::Reader& reader, const char* format, bool readable);
		};
	}
}
