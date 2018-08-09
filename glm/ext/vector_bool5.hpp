/// @ref core
/// @file glm/ext/vector_bool4.hpp

#pragma once
#include "../detail/type_vec5.hpp"

namespace glm
{
	/// @addtogroup core
	/// @{

#	if(defined(GLM_PRECISION_LOWP_BOOL))
		typedef vec<5, bool, lowp>		bvec5;
#	elif(defined(GLM_PRECISION_MEDIUMP_BOOL))
		typedef vec<5, bool, mediump>	bvec5;
#	else //defined(GLM_PRECISION_HIGHP_BOOL)
		/// 5 components vector of boolean.
		///
		/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
		typedef vec<5, bool, highp>		bvec5;
#	endif//GLM_PRECISION

	/// @}
}//namespace glm
