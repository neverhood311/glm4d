/// @ref core
/// @file glm/detail/type_vec5.hpp

#pragma once

#include "qualifier.hpp"
#if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
#	include "_swizzle.hpp"
#elif GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_FUNCTION
#	include "_swizzle_func.hpp"
#endif
#include <cstddef>

namespace glm
{
	template<typename T, qualifier Q>
	struct vec<5, T, Q>
	{
		// -- Implementation detail --
		
		typedef T value_type;
		typedef vec<5, T, Q> type;
		typedef vec<5, bool, Q> bool_type;
		
		// -- Data --
		
#		if GLM_USE_ANONYMOUS_STRUCT == GLM_ENABLE
			union
			{
				struct { T x, y, z, w, v; };
				struct { T s, t, p, q, r; };
				
				typename detail::storage<5, T, detail::is_aligned<Q>::value>::type data;
				
#				if GLM_SWIZZLE == GLM_SWIZZLE_OPERATOR
					GLM_SWIZZLE5_2_MEMBERS(T, Q, x, y, z, w, v)
					GLM_SWIZZLE5_2_MEMBERS(T, Q, s, t, p, q, r)
					GLM_SWIZZLE5_3_MEMBERS(T, Q, x, y, z, w, v)
					GLM_SWIZZLE5_3_MEMBERS(T, Q, s, t, p, q, r)
					GLM_SWIZZLE5_4_MEMBERS(T, Q, x, y, z, w, v)
					GLM_SWIZZLE5_4_MEMBERS(T, Q, s, t, p, q, r)
					GLM_SWIZZLE5_5_MEMBERS(T, Q, x, y, z, w, v)
					GLM_SWIZZLE5_5_MEMBERS(T, Q, s, t, p, q, r)
#				endif
			};
#		else
			union { T x, s; };
			union { T y, t; };
			union { T z, p; };
			union { T w, q; };
			union { T v, r; };
			
#			if GLM_SWIZZLE == GLM_SWIZZLE_FUNCTION
				GLM_SWIZZLE_GEN_VEC_FROM_VEC5(T, Q)
#			endif
#		endif

		// -- Component accesses --
		
		/// Return the count of components of the vector
		typedef length_t length_type;
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length(){return 5;}
		
		GLM_FUNC_DECL T & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR T const& operator(length_type i) const;
		
		// -- Implicit basic constructors --
		
		GLM_FUNC_DECL GLM_CONSTEXPR vec() GLM_DEFAULT;
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<5, T, Q> const& v) GLM_DEFAULT;
		template<qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<5, T, P> const& v);
		
		// -- Explicit basic constructors --
		
		GLM_FUNC_DECL GLM_CONSTEXPR explicit vec(T scalar);
		GLM_FUNC_DECL GLM_CONSTEXPR vec(T x, T y, T z, T w, T v);
		
		// -- Conversion scalar constructors --
		
		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR explicit vec(vec<1, U, P> const& v);
		
		/// Explicit conversions
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, Y _y, Z _z, W _w, V _v);	//xyzwv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, Z _z, W _w, V _v);	//Xyzwv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, Z _z, W _w, V _v);	//xYzwv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, W _w, V _v);	//XYzwv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, Y _y, vec<1, Z, Q> const& _z, W _w, V _v);	//xyZwv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, W _w, V _v);	//XyZwv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w, V _v);	//xYZwv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w, V _v);	//XYZwv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, Y _y, Z _z, vec<1, W, Q> const& _w, V _v);	//xyzWv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, Z _z, vec<1, W, Q> const& _w, V _v);	//XyzWv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w, V _v);	//xYzWv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w, V _v);	//XYzWv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, Y _y, vec<1, Z, q> const& _z, vec<1, W, Q> const& _w, V _v);	//xyZWv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w, V _v);	//XyZWv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w, V _v);	//xYZWv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w, V _v);	//XYZWv
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, Y _y, Z _z, W _w, vec<1, V, Q> const& _v);	//xyzwV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, Z _z, W _w, vec<1, V, Q> const& _v);	//XyzwV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, Z _z, W _w, vec<1, V, Q> const& _v);	//xYzwV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, W _w, vec<1, V, Q> const& _v);	//XYzwV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, Y _y, vec<1, Z, Q> const& _z, W _w, vec<1, V, Q> const& _v);	//xyZwV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, W _w, vec<1, V, Q> const& _v);	//XyZwV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w, vec<1, V, Q> const& _v);	//xYZwV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w, vec<1, V, Q> const& _v);	//XYZwV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, Y _y, Z _z, vec<1, W, Q> const& _w, vec<1, V, Q> const& _v);	//xyzWV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, Z _z, vec<1, W, Q> const& _w, vec<1, V, Q> const& _v);	//XyzWV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w, vec<1, V, Q> const& _v);	//xYzWV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w, vec<1, V, Q> const& _v);	//XYzWV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, Y _y, vec<1, Z, q> const& _z, vec<1, W, Q> const& _w, vec<1, V, Q> const& _v);	//xyZWV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w, vec<1, V, Q> const& _v);	//XyZWV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w, vec<1, V, Q> const& _v);	//xYZWV
		template<typename X, typename Y, typename Z, typename W, typename V>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w, vec<1, V, Q> const& _v);	//XYZWV
		
		// -- Conversion vector constructors --
		
		/// Explicit conversions
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, B _z, C _w, D _v);	//XY z w v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z, C _w, D _v);	//XY Z w v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, B _z, vec<1, C, P> const& _w, D _v);	//XY z W v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z, vec<1, C, P> const& _w, D _v);	//XY Z W v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, B _z, C _w, vec<1, D, P> const& _v);	//XY z w V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z, C _w, vec<1, D, P> const& _v);	//XY Z w V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, B _z, vec<1, C, P> const& _w, vec<1, D, P> const& _v);	//XY z W V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z, vec<1, C, P> const& _w, vec<1, D, P> const& _v);	//XY Z W V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<2, B, P> const& _yz, C _w, D _v);	//x YZ w v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz, C _w, D _v);	//X YZ w v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<2, B, P> const& _yz, vec<1, C, P> const& _w, D _v);	//x YZ W v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz, vec<1, C, P> const& _w, D _v);	//X YZ W v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<1, B, P> const& _yz, C _w, vec<1, D, P> const& _v);	//x YZ w V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz, C _w, vec<1, D, P> const& _v);	//X YZ w V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<2, B, P> const& _yz, vec<1, C, P> const& _w, vec<1, D, P> const& _v);	//x YZ W V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz, vec<1, C, P> const& _w, vec<1, D, P> const& _v);	//X YZ W V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, B _y, vec<2, C, P> const& _zw, D _v);	//x y ZW v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, A, P> const& _x, B _y, vec<2, C, P> const& _zw, D _v);	//X y ZW v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<1, B, P> const& _zw, D _v);	//x Y ZW v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, A, P> const& _x, vec<1, B, P> const& _y, vec<2, C, P> const& _zw, D _v);	//X Y ZW v
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, B _y, vec<2, C, P> const& _zw, vec<1, D, P> const& _v);	//x y ZW V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, A, P> const& _x, B _y, vec<2, D, P> const& _zw, vec<1, D, P> const& _v);	//X y ZW V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(A _x, vec<1, B, P> const& _y, vec<2, C, P> const& _zw, vec<1, D, P> const& _v);	//x Y ZW V
		template<typename A, typename B, typename C, typename D, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<1, A, P> const& _x, vec<1, B, P> const& _y, vec<2, C, P> const& _zw, vec<1, D, P> const& _v);	//X Y ZW V
		//x y z WV
		//X y z WV
		//x Y z WV
		//X Y z WV
		//x y Z WV
		//X y Z WV
		//x Y Z WV
		//X Y Z WV
		
		template<typename A, typename B, typename C, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<2, A, P> const& _xy, vec<2, B, P> const& _zw, C _v);	//XY ZW v
		//XY ZW V
		//XY z WV
		//XY Z WV
		//x YZ WV
		//X YZ WV
		
		template<typename A, typename B, typename C, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<3, A, P> const& _xyz, B _w, C _v);	//XYZ w v
		//XYZ W v
		//XYZ w V
		//XYZ W V
		//x YZW v
		//X YZW v
		//x YZW V
		//X YZW V
		//x y ZWV
		//X y ZWV
		//x Y ZWV
		//X Y ZWV
		
		template<typename A, typename B, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<3, A, P> const& _xyz, vec<2, B, P> const& _wv);	//XYZ WV
		//XY ZWV
		
		template<typename A, typename B, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR vec(vec<4, A, P> const& _xyzw, B _v);	//XYZW v
		//XYZW V
		//x YZWV
		//X YZWV
		
		/// Explicit conversions
		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT vec(vec<5, U, P> const& v);	//XYZWV
		
		// -- Swizzle constructors --
		if GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
			
		endif//GLM_CONFIG_SWIZZLE == GLM_SWIZZLE_OPERATOR
		
		// -- Unary arithmetic operators --
	}
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_vec5.inl"
#endif//GLM_EXTERNAL_TEMPLATE