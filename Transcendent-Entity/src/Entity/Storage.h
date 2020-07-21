#pragma once

#include <Entity/uuid.h>

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

namespace TE {


	template<typename Entity_Type, typename Componant_Type>
	class Storage
	{
	public:
		Storage() {
			componants = *&std::vector<std::pair<Entity_Type, Componant_Type>>();
			instance = this;
		}

	private:
		template<typename... Args>
		void intemplace(Entity_Type& entity, Args &&... args) {
			componants.push_back(std::pair<Entity_Type, Componant_Type>(entity, Componant_Type(std::forward<Args>(args)...)));
		}

		Componant_Type intGet(Entity_Type& entity) {
			for (auto& pair : componants)
				if (pair.first.GetID() == entity.GetID())
					return pair.second;
			
			#ifdef TE_DEBUG
				__debugbreak();
			#endif
			return *&Componant_Type();
		}

	public:
		static Componant_Type Get(Entity_Type& entity) {
			return instance->intGet(entity);
		}

		template<typename... Args>
		static void emplace(Entity_Type& entity, Args&&... args) {
			instance->intemplace(entity, std::foward<Args>(args)...);
		}

	private:
		std::vector<std::pair<Entity_Type, Componant_Type>> componants;
		static Storage* instance;
	};

	template<typename Entity_Type, typename Componant_Type>
	Storage<Entity_Type, Componant_Type>* Storage<Entity_Type, Componant_Type>::instance;

	/**
	  * @tparam E E is entity type, must have a GetID Function.
	  */
	template<typename E>
	class registry
	{
	public:
		using Entity_Type = E;

		void Create(Entity_Type& entity) {
			Entity_Type::Create(entity);
		}

		template<typename Componant, typename... Args>
		Componant emplace(registry& owner, Entity_Type& entity, Args&&... args) {
			Storage<Entity_Type, Componant>::emplace(entity, std::forward<Args>(args)...);
			return Storage<Entity_Type, Componant>::Get(entity);
		}

		template<typename Componant, typename... Args>
		Componant emplace(Entity_Type& entity, Args&&... args) {
			return emplace<Componant>(*this, entity, std::forward<Args>(args)...);
		}

		template<typename Componant>
		Componant GetComponant(Entity_Type entity) {
		
		}

	private:
		std::vector<Entity_Type> Entites;
	};
}
