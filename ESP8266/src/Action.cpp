////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the TotoPlay library.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file						TotoPlay/Action.cpp
///	@author						Lucas Bremond <lucas@axelspace.com>
///	@date						9 Oct 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <TotoPlay/Configuration.hpp>
#include <TotoPlay/StepperMotorController.hpp>

#include <TotoPlay/Action.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace TotoPlay
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

								Action::Action								(	const	Action::Type&				aType								)
								:	id_(0),
									type_(aType),
									status_(Action::Status::Undefined),
									rotationAngle_(Angle::Undefined())
{

}

bool							Action::isDefined							( ) const
{
	return (type_ != Action::Type::Undefined) && (status_ != Action::Status::Undefined) ;
}

uint							Action::getId								( ) const
{
	return id_ ;
}

Action::Type					Action::getType								( ) const
{
	return type_ ;
}

Action::Status					Action::getStatus							( ) const
{
	return status_ ;
}

Angle							Action::getRotationAngle					( ) const
{
	return rotationAngle_ ;
}

void							Action::setStatus							(	const	Action::Status&				aStatus								)
{
	status_																		=		aStatus ;
}

Action							Action::Undefined							( )
{
	return Action(Action::Type::Undefined) ;
}

Action							Action::Rotation							(	const	Angle&						anAngle								)
{

	Action						action(Action::Type::Rotation) ;

	action.status_																=		Action::Status::Pending ;
	action.rotationAngle_														=		anAngle ;

	return action ;

}

Action::Type					Action::TypeFromString						(	const	String&						aString								)
{

	if (aString == "Undefined")
	{
		return Action::Type::Undefined ;
	}

	if (aString == "Rotation")
	{
		return Action::Type::Rotation ;
	}

	return Action::Type::Undefined ;

}

String							Action::StringFromType						(	const	Action::Type&				aType								)
{

	switch (aType)
	{

		case Action::Type::Undefined:
			return "Undefined" ;

		case Action::Type::Rotation:
			return "Rotation" ;

		default:
			return "Error" ;

	}

	return "Error" ;

}

Action::Status					Action::StatusFromString					(	const	String&						aString								)
{

	if (aString == "Undefined")
	{
		return Action::Status::Undefined ;
	}

	if (aString == "Pending")
	{
		return Action::Status::Pending ;
	}

	if (aString == "Executing")
	{
		return Action::Status::Executing ;
	}

	if (aString == "Completed")
	{
		return Action::Status::Completed ;
	}

	if (aString == "Failed")
	{
		return Action::Status::Failed ;
	}

	return Action::Status::Undefined ;

}

String							Action::StringFromStatus					(	const	Action::Status&				aStatus								)
{

	switch (aStatus)
	{

		case Action::Status::Undefined:
			return "Undefined" ;

		case Action::Status::Pending:
			return "Pending" ;

		case Action::Status::Executing:
			return "Executing" ;

		case Action::Status::Completed:
			return "Completed" ;

		case Action::Status::Failed:
			return "Failed" ;

		default:
			return "Error" ;

	}

	return "Error" ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////