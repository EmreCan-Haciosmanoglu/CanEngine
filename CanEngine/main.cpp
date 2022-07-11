#include "canpch.h"
#include "Can.h"

using namespace::Can;

int main(int argc, const char * argv[]) {
    v3 a(1.0f);
    v3 b(2.0f);
    v3 c = a + b;
    printf("%f + %f = %f", a.x, b.x, c.x);
    return 0;
}
