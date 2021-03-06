#pragma once

#include <map>
#include <string>

namespace Kore {
	struct ShaderConstant {
		u32 offset;
		u32 size;
	};

	class Shader5Impl {
	public:
		Shader5Impl();
		std::map<std::string, ShaderConstant> constants;
		int constantsSize;
		std::map<std::string, int> attributes;
		std::map<std::string, int> textures;
		void* shader;
		u8* data;
		int length;
	};
}
