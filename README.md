# ue_gas_prediction

Minimal example for GAS prediction with usage of the attribute value change delegate.

The point is, to **run this with 2 (or more) players (PIE is fine) and activate abilities on client to see results and issues**.

It uses OnScreen output to present what is happening. Text in Magenta means removal of predicted GEs. This will cause fluctuation when using the attribute value change delegate for UI output.

GAS relevant contents:
- one GameplayAttribute
- one GameplayEffect
- two GameplayAbilities, `ApplyGEToTarget` and `ApplyGEToSelf` and several prediction windows

Hotkey | Functionality
--|--
1 or Left mouse | Ability 1 (projectile)
2 or Right mouse | Ability 2 (apply to self)

The default, simulated network settings are bad by intention (500ms lag, 15% packet loss).
