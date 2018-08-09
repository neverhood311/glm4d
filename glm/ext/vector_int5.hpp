/// @ref core
/// @file glm/ext/vector_int5.hpp

#pragma once
#include "../detail/type_vec5.hpp"

namespace glm
{
	/// @addtogroup core
	/// @{

#	if(defined(GLM_PRECISION_LOWP_INT))
		typedef vec<5, int, lowp>		ivec5;
#	elif(defined(GLM_PRECISION_MEDIUMP_INT))
		typedef vec<5, int, mediump>	ivec5;
#	else //defined(GLM_PRECISION_HIGHP_INT)
		/// 5 components vector of signed integer numbers.
		///
		/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
		typedef vec<5, int, highp>		ivec5;
#	endif//GLM_PRECISION

	/// @}
}//namespace glm
