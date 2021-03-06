////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the TotoPlay library.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file 						TotoPlay/Time.hpp
///	@author 					Lucas Bremond <lucas@axelspace.com>
///	@date 						9 Oct 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __TotoPlay_Time_HPP_INCLUDED__
#define __TotoPlay_Time_HPP_INCLUDED__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SmingCore/SmingCore.h>

#include <TotoPlay/Duration.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace TotoPlay
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CalendarDate ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Time
{

	public:

								Time 										( ) ;

		bool					operator ==									(	const 	Time&						aTime 								) const ;
		bool					operator !=									(	const 	Time&						aTime 								) const ;
		bool					operator <=									(	const 	Time&						aTime 								) const ;
		bool					operator <									(	const 	Time&						aTime 								) const ;
		bool					operator >=									(	const 	Time&						aTime 								) const ;
		bool					operator >									(	const 	Time&						aTime 								) const ;

		Time 					operator +									(	const 	Duration&					aDuration							) const ;

		bool					isDefined									( ) const ;

		time_t 					getUnixTime									( ) const ;
		String					getString									( ) const ;

		static Time 			Undefined									( ) ;

		static Time 			Now											( ) ;

		static Time 			Unix										( 	const 	time_t&						aTimestamp							) ;

		static Time 			CalendarDate								( 	const 	TotoPlay::CalendarDate&		aCalendarDate						) ;

	private:

		time_t					timestamp_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////