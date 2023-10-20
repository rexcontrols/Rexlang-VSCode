#ifdef REXLANG
#ifdef __DATE__ //rexlang nemá definici __DATE__ a díky tomu neinkluduje nic z tohoto soubnoru
/* -------------------------------------------------------------------------- */
// použití
// #include "rexlang.h" //pro fungování IntelliSence a našeptávání funkcí rexlangu
/* -------------------------------------------------------------------------- */

#pragma warning disable 4267
#define DISABLE_INTELLIGENCE_ERRORS
#pragma warning disable
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-W*"

#include "rexlang_definitions.h"

#pragma warning restore 4267
#pragma warning restore

#undef DISABLE_INTELLIGENCE_ERRORS
#pragma clang diagnostic pop
#endif
#endif