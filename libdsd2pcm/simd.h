#pragma once

#ifdef _M_IX86_FP

#include <xmmintrin.h>  // SSE2 inlines

#else

struct __m128d
{
	double v[2];
};

__m128d _mm_setzero_pd()
{
	return {0,0};
}

__m128d _mm_load_pd(const double* d)
{
	return {d[0], d[1]};
}

__m128d _mm_loadu_pd(const double* d)
{
	return _mm_load_pd(d);
}

void _mm_storeu_pd(double* d, const __m128d s)
{
	d[0] = s.v[0]; d[1] = s.v[1];
}

__m128d _mm_add_pd(__m128d a, __m128d b)
{
	return {a.v[0]+b.v[0], a.v[1]+b.v[1]};
}

__m128d _mm_mul_pd(__m128d a, __m128d b)
{
	return {a.v[0]*b.v[0], a.v[1]*b.v[1]};
}

#endif
