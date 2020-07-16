#include <tepch.h>
#include <Entity/uuid.h>
#include <Entity/Entity.h>

int main(int argc, char** argv) {

	TE::uuid id;
	for (int i = 0; i < 100; i++) {
		TE::genuuid(&id);
		printf("%i\n", id.Data1);
		printf("%i\n", id.Data2);
		printf("%i\n", id.Data3);
		printf("\n");
	}

	return 0;
}