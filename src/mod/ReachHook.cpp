// pocket-on-pc: give keyboard & mouse the touch pick range.
//
// Bedrock defaults (block interaction):
//   mouse / gamepad ......... 5 blocks (survival + creative)
//   touch ................... 6 blocks survival, 12 blocks creative
//
// GameMode::getPickRange(InputMode) is the virtual that branches on the
// input mode, so we force InputMode::Touch and let the game resolve the
// correct survival/creative value itself instead of hardcoding distances.

#include "ll/api/memory/Hook.h"
#include "mc/deps/input/InputMode.h"
#include "mc/world/gamemode/GameMode.h"

LL_AUTO_TYPE_INSTANCE_HOOK(
    PocketReachPickRangeHook,
    ll::memory::HookPriority::Normal,
    GameMode,
    &GameMode::$getPickRange,
    float,
    ::InputMode const& /*currentInputMode*/
) {
    static const ::InputMode touch = ::InputMode::Touch;
    return origin(touch);
}
