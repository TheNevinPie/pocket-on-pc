# pocket-on-pc

LeviLamina **client** mod: gives keyboard & mouse the touch block pick range.

- Keyboard/mouse/controller default: 5 blocks
- With this mod: **6 blocks in Survival, 12 blocks in Creative** (same as touch players)

It hooks `GameMode::getPickRange` and forces `InputMode::Touch`, so the game resolves the correct Survival/Creative distance itself.

## Install (lip)

1. In LeviLauncher, install a Minecraft version supported by LeviLamina `26.20.*` and install LeviLamina into it (Mods → Manage Mods → Install LeviLamina).
2. From the version directory terminal, run:

```bash
lip install github.com/TheNevinPie/pocket-on-pc#client
```

3. Launch and check the log for `pocket-on-pc active`.

## Install (manual)

Download `pocket-on-pc-client-windows-x64.zip` from the latest [release](https://github.com/TheNevinPie/pocket-on-pc/releases), extract the `pocket-on-pc/` folder into the version's `mods/` directory, and launch.

## Build

```bash
xmake f -y -p windows -a x64 -m release --target_type=client
xmake
```

Output lands in `bin/pocket-on-pc/`.

## Notes

- Client-side only: it changes your local raycast/pick range. Servers with server-authoritative block breaking or reach anticheat may still reject beyond-5 breaks.
- Entity melee range is untouched (vanilla 3 blocks Survival / 5 Creative).

## License

CC0-1.0 © LeviMC(LiteLDev) — see [LICENSE](LICENSE).
