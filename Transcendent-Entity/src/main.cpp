#include <tepch.h>
#include <Entity/uuid.h>
#include <Entity/Entity.h>
#include <Entity/Storage.h>

struct Mat4x4
{
	std::array<std::array<double, 4>, 4> elements;

	Mat4x4() = default;
};

using Mat4 = Mat4x4;

struct Transform
{
	Mat4 Trasform;
};

int main(int argc, char** argv) {

	TE::registry<TE::Entity> reg;

	TE::Entity entity;
	reg.Create(entity);

	printf("0x%p", &entity);

	reg.emplace<Transform>(entity);

	return 0;
}
