////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the TotoPlay library.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file 						TotoPlay/ActionManager.cpp
///	@author 					Lucas Bremond <lucas@axelspace.com>
///	@date 						9 Oct 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <TotoPlay/Configuration.hpp>
#include <TotoPlay/Duration.hpp>

#include <TotoPlay/ActionManager.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace TotoPlay
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

								ActionManager::ActionManager 					( )
								:	active_(false),
									currentActionPtr_(nullptr)
{

	// servoChannelPtr_															=		new(ServoChannel) ;

}

bool							ActionManager::isActive						( ) const
{
	return active_ ;
}

void							ActionManager::start							( )
{

	if (this->isActive())
	{
		this->stop() ;
	}

	servoChannel_.attach(D0) ;

	servoChannel_.setDegree(0.0) ;

	active_																		=		true ;

	timer_.initializeMs(10, Delegate<void()>(&ActionManager::onManage, this)) ; // TBM param
	
	timer_.start() ;

}

void							ActionManager::stop							( )
{

	if (!this->isActive())
	{
		return ;
	}

	timer_.stop() ;

	active_																		=		false ;

}

bool							ActionManager::addAction					(	const	Action&						anAction							)
{
	
	actions_.addElement(anAction) ;

	return true ;

}

void							ActionManager::onManage						( )
{

	for (uint idx = 0; idx < actions_.size(); ++idx)
	{

		Action&					action 											=		actions_[idx] ;

		if (action.getStatus() == Action::Status::Pending)
		{
			this->executeAction(action) ;
		}

	}

	// if (actions_.firstElement().getStatus() != Action::Status::Pending)
	// {
	// 	actions_.removeElementAt(0) ;
	// }

}

void							ActionManager::executeAction				(			Action&						anAction							)
{

	Serial.println("executeAction") ;

	if (!anAction.isDefined())
	{
		
		anAction.setStatus(Action::Status::Failed) ;

		return ;

	}

	anAction.setStatus(Action::Status::Executing) ;

	switch (anAction.getType())
	{

		case Action::Type::Rotation:
		{

			Serial.println(anAction.getRotationAngle().getDegrees()) ;

			servoChannel_.setDegree(anAction.getRotationAngle().getDegrees()) ;

			break ;

		}

		default:
			break ;

	}

	anAction.setStatus(Action::Status::Completed) ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////