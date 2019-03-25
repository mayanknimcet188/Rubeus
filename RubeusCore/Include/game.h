#pragma once

#include <engine.h>

namespace Rubeus
{
	class RGame
	{
	protected:
		static RGame * CurrentGame;

		/** @brief	The entirety of the Rubeus Engine */
		REngine * const m_Engine;

	public:
		std::string m_StartupLevel;

		virtual void init() = 0;
		virtual void end() = 0;

		RGame(/* Preferably take configuration variables here */);
		~RGame();

		inline static RGame * getActiveGame() { return CurrentGame; }
		inline static REngine * const getEngine() { return CurrentGame->m_Engine; }
	};
}