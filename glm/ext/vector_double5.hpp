/// @ref core
/// @file glm/ext/vector_double5.hpp

#pragma once
#include "../detail/type_vec5.hpp"

namespace glm
{
	/// @addtogroup core
	/// @{

#	if(defined(GLM_PRECISION_LOWP_DOUBLE))
		typedef vec<5, double, lowp>		dvec5;
#	elif(defined(GLM_PRECISION_MEDIUMP_DOUBLE))
		typedef vec<5, double, mediump>		dvec5;
#	else //defined(GLM_PRECISION_HIGHP_DOUBLE)
		/// 5 components vector of double-precision floating-point numbers.
		///
		/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
		typedef vec<5, double, highp>		dvec5;
#	endif//GLM_PRECISION

	/// @}
}//namespace glm
