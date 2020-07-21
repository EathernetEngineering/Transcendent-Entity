#pragma once

namespace TE {

	class Entity
	{
	public:
		operator uuid&() { return m_ID; }

		operator const uuid&() const { return m_ID; }

		operator uuid*() { return &m_ID; }

		operator const uuid*() const { return &m_ID; }

		static void Create(Entity& entity) { genuuid(entity); }

		uuid GetID() { return m_ID; }

	private:
		uuid m_ID;
	};
}
