#pragma once

#include <cstdint>

struct AbstractPlatformTypes
{
	//All basic types used by platform. Please define here all base types we're going to use.

	//~ Unsigned types

	// 8 bit wide unsigned integer
	typedef unsigned char		uint8;
	
	// 16 bit wide unsigned integer
	typedef unsigned short		uint16;
	
	// 32 bit wide unsigned integer
	typedef unsigned int		uint32;
	
	// 64 bit wide unsigned integer
	typedef unsigned long long	uint64;

	//~ Signed types
	// 8 bit wide signed integer
	typedef signed char			int8;

	// 16 bit wide signed integer
	typedef signed short		int16;

	// 32 bit wide signed integer
	typedef signed int			int32;

	// 64 bit wide signed integer
	typedef signed long long	int64;
};

//TODO move to HAL
typedef AbstractPlatformTypes::int8		int8;
typedef AbstractPlatformTypes::int16	int16;
typedef AbstractPlatformTypes::int32	int32;
typedef AbstractPlatformTypes::int64	int64;

typedef AbstractPlatformTypes::uint8	uint8;
typedef AbstractPlatformTypes::uint16	uint16;
typedef AbstractPlatformTypes::uint32	uint32;
typedef AbstractPlatformTypes::uint64	uint64;