#include "mod/MyMod.h"

#include "ll/api/mod/RegisterHelper.h"

namespace pocket_on_pc {

PocketOnPc& PocketOnPc::getInstance() {
    static PocketOnPc instance;
    return instance;
}

bool PocketOnPc::load() {
    getSelf().getLogger().debug("Loading pocket-on-pc...");
    // Hooks in ReachHook.cpp auto-register at load. No game access here.
    return true;
}

bool PocketOnPc::enable() {
    auto& logger = getSelf().getLogger();
    logger.debug("Enabling...");
    logger.info("pocket-on-pc active: keyboard & mouse now uses touch pick range (6 survival / 12 creative).");
    return true;
}

bool PocketOnPc::disable() {
    getSelf().getLogger().debug("Disabling...");
    // Hooks auto-unhook on unload; nothing to clean up.
    return true;
}

} // namespace pocket_on_pc

LL_REGISTER_MOD(pocket_on_pc::PocketOnPc, pocket_on_pc::PocketOnPc::getInstance());
