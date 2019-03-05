
#pragma once

#define XS_ROUNDS 4

template < INT X >
struct ENSURE_COMPILE_TIME
{
	enum : INT
	{
		Value = X,
	};
};

#define XS_SEED ( ( ( __TIME__ [ 4 ] - '0' ) * 60 ) + ( ( __TIME__ [ 3 ] - '0' ) * 600 ) + ( ( __TIME__ [ 1 ] - '0' ) * 3600 ) + ( ( __TIME__ [ NULL ] - '0' ) * 36000 ) )

constexpr FORCEINLINE INT LINEAR_CONGRUENT_GENERATOR (INT Rounds)
{
	return 1013904223 + (1664525 * ((Rounds > NULL) ? (LINEAR_CONGRUENT_GENERATOR (Rounds - 1)) : (XS_SEED & 0xFFFFFFFF)));
};

#define XS_RANDOM( ) ( ENSURE_COMPILE_TIME < LINEAR_CONGRUENT_GENERATOR ( XS_ROUNDS ) > :: Value )
#define XS_RANDOM_NUMBER( Min, Max ) ( Min + ( XS_RANDOM ( ) % ( Max - Min + 1 ) ) )

template < INT ... Pack >
struct XS_INDEX_LIST
{

};

template < typename XS_INDEX_LIST, INT Right >
struct XS_APPEND;

template < INT ... Left, INT Right >
struct XS_APPEND < XS_INDEX_LIST < Left ... >, Right >
{
	typedef XS_INDEX_LIST < Left ..., Right > Result;
};

template < INT N >
struct XS_CONSTRUCT_INDEX_LIST
{
	typedef typename XS_APPEND < typename XS_CONSTRUCT_INDEX_LIST < N - 1 > ::Result, N - 1 > ::Result Result;
};

template < >
struct XS_CONSTRUCT_INDEX_LIST < NULL >
{
	typedef XS_INDEX_LIST < > Result;
};

constexpr CONST CHAR CONST XS_XORKEY = static_cast <CONST CHAR CONST> (XS_RANDOM_NUMBER (NULL, 0x000000FF));

constexpr FORCEINLINE CONST CHAR CONST XS_ENCRYPT_CHARACTER (CONST CHAR CONST Character, INT Index)
{
	return Character ^ (XS_XORKEY + Index);
};

template < typename XS_INDEX_LIST >
class XS;

template < INT ... Index >
class XS < XS_INDEX_LIST < Index ... > >
{
private:

	CHAR Value[(((sizeof ... (Index)) + 1) + ((__TIME__[NULL] - '0') + (__TIME__[1] - '0') + (__TIME__[3] - '0') + (__TIME__[4] - '0')))] = { };

public:

	constexpr FORCEINLINE XS (CONST CHAR * CONST pszString) : Value{ XS_ENCRYPT_CHARACTER (pszString[Index], Index) ... }
	{

	};

	constexpr FORCEINLINE string Decrypt (VOID)
	{
		static INT Iter = NULL;

		for (Iter = NULL; Iter < (sizeof ... (Index)); Iter++)
		{
			Value[Iter] = (Value[Iter] ^ (XS_XORKEY + Iter));
		};

		Value[(sizeof ... (Index))] = NULL;

		return string (Value);
	};
};

#define XorString( String ) ( ( string ( XS < XS_CONSTRUCT_INDEX_LIST < sizeof ( String ) - 1 > :: Result> ( String ) . Decrypt ( ) ) ) . c_str ( ) )

#define XS_RANDOM_SIZE_250_1 ( SIZE_T ( MAX_PATH + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_250_1_FLOAT ( FLOAT ( FLOAT ( MAX_PATH ) + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_250_2 ( SIZE_T ( MAX_PATH + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_250_2_FLOAT ( FLOAT ( FLOAT ( MAX_PATH ) + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_250_3 ( SIZE_T ( MAX_PATH + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_250_3_FLOAT ( FLOAT ( FLOAT ( MAX_PATH ) + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_250_4 ( SIZE_T ( MAX_PATH + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_250_4_FLOAT ( FLOAT ( FLOAT ( MAX_PATH ) + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_4_1 ( SIZE_T ( 4 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_4_1_FLOAT ( FLOAT ( 4.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_4_2 ( SIZE_T ( 4 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_4_2_FLOAT ( FLOAT ( 4.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_4_3 ( SIZE_T ( 4 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_4_3_FLOAT ( FLOAT ( 4.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_4_4 ( SIZE_T ( 4 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_4_4_FLOAT ( FLOAT ( 4.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_8_1 ( SIZE_T ( 8 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_8_1_FLOAT ( FLOAT ( 8.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_8_2 ( SIZE_T ( 8 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_8_2_FLOAT ( FLOAT ( 8.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_8_3 ( SIZE_T ( 8 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_8_3_FLOAT ( FLOAT ( 8.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_8_4 ( SIZE_T ( 8 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_8_4_FLOAT ( FLOAT ( 8.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_12_1 ( SIZE_T ( 12 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_12_1_FLOAT ( FLOAT ( 12.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_12_2 ( SIZE_T ( 12 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_12_2_FLOAT ( FLOAT ( 12.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_12_3 ( SIZE_T ( 12 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_12_3_FLOAT ( FLOAT ( 12.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_12_4 ( SIZE_T ( 12 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_12_4_FLOAT ( FLOAT ( 12.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_16_1 ( SIZE_T ( 16 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_16_1_FLOAT ( FLOAT ( 16.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_16_2 ( SIZE_T ( 16 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_16_2_FLOAT ( FLOAT ( 16.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_16_3 ( SIZE_T ( 16 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_16_3_FLOAT ( FLOAT ( 16.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_16_4 ( SIZE_T ( 16 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_16_4_FLOAT ( FLOAT ( 16.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_32_1 ( SIZE_T ( 32 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_32_1_FLOAT ( FLOAT ( 32.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_32_2 ( SIZE_T ( 32 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_32_2_FLOAT ( FLOAT ( 32.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_32_3 ( SIZE_T ( 32 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_32_3_FLOAT ( FLOAT ( 32.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_32_4 ( SIZE_T ( 32 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_32_4_FLOAT ( FLOAT ( 32.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_40_1 ( SIZE_T ( 40 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_40_1_FLOAT ( FLOAT ( 40.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_40_2 ( SIZE_T ( 40 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_40_2_FLOAT ( FLOAT ( 40.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_40_3 ( SIZE_T ( 40 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_40_3_FLOAT ( FLOAT ( 40.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_40_4 ( SIZE_T ( 40 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_40_4_FLOAT ( FLOAT ( 40.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_64_1 ( SIZE_T ( 64 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_64_1_FLOAT ( FLOAT ( 64.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_64_2 ( SIZE_T ( 64 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_64_2_FLOAT ( FLOAT ( 64.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_64_3 ( SIZE_T ( 64 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_64_3_FLOAT ( FLOAT ( 64.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_64_4 ( SIZE_T ( 64 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_64_4_FLOAT ( FLOAT ( 64.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_96_1 ( SIZE_T ( 96 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_96_1_FLOAT ( FLOAT ( 96.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_96_2 ( SIZE_T ( 96 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_96_2_FLOAT ( FLOAT ( 96.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_96_3 ( SIZE_T ( 96 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_96_3_FLOAT ( FLOAT ( 96.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_96_4 ( SIZE_T ( 96 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_96_4_FLOAT ( FLOAT ( 96.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_128_1 ( SIZE_T ( 128 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_128_1_FLOAT ( FLOAT ( 128.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_128_2 ( SIZE_T ( 128 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_128_2_FLOAT ( FLOAT ( 128.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_128_3 ( SIZE_T ( 128 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_128_3_FLOAT ( FLOAT ( 128.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_128_4 ( SIZE_T ( 128 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_128_4_FLOAT ( FLOAT ( 128.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_192_1 ( SIZE_T ( 192 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_192_1_FLOAT ( FLOAT ( 192.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_192_2 ( SIZE_T ( 192 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_192_2_FLOAT ( FLOAT ( 192.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_192_3 ( SIZE_T ( 192 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_192_3_FLOAT ( FLOAT ( 192.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_192_4 ( SIZE_T ( 192 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_192_4_FLOAT ( FLOAT ( 192.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_256_1 ( SIZE_T ( 256 + ( ( __TIME__ [ NULL ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_256_1_FLOAT ( FLOAT ( 256.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_256_2 ( SIZE_T ( 256 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_256_2_FLOAT ( FLOAT ( 256.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_256_3 ( SIZE_T ( 256 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_256_3_FLOAT ( FLOAT ( 256.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE_256_4 ( SIZE_T ( 256 + ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) )
#define XS_RANDOM_SIZE_256_4_FLOAT ( FLOAT ( 256.f + ( FLOAT ( ( ( __TIME__ [ NULL ] - '0' ) + ( __TIME__ [ 1 ] - '0' ) + ( __TIME__ [ 3 ] - '0' ) + ( __TIME__ [ 4 ] - '0' ) ) ) ) ) )

#define XS_RANDOM_SIZE XS_RANDOM_SIZE_250_4
#define XS_RANDOM_SIZE_FLOAT XS_RANDOM_SIZE_250_4_FLOAT

FORCEINLINE CONST VOID CONST xprintf (PCHAR pBuffer, string Rules, ...)
{
	static PCHAR pData = NULL;
	va_start (pData, Rules), vsprintf (pBuffer, Rules.c_str (), pData), va_end (pData);
};
