#include "entt/entt.hpp"
namespace Scene
{
	class Scene
	{
	public:
		Scene();
		void OnUpdate(float timeStep);
		~Scene();
	private:
		entt::registry _registery;
	};
}