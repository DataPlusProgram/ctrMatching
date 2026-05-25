| Index | Role |
|---|---|
| 0 |  one-shot state setup |
| 1 | Per-frame update |
| 2 | Linear physics step |
| 3 | Audio step |
| 4 | Angular physics step |
| 5 | Force application step |
| 6 | Moved collision search |
| 7 | Driver-vs-driver collision |
| 8 | Fixed collision search |
| 9 | Jump / weapon  |
| 10 | Translate matrix  |
| 11 | Animate |
| 12 | Particles |


| State | Init | Update | PhysLinear | Audio | PhysAngular | ApplyForces | MovedColl | CollideDrivers | FixedColl | Aux/Weapon | TranslateMatrix | Animate | Particles |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Driving | 0 | `VehPhysProc_Driving_Update` | `VehPhysProc_Driving_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysGeneral_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehFrameProc_Driving` | `VehEmitter_DriverMain` |
| FreezeEndEvent | 0 | 0 | `VehPhysProc_FreezeEndEvent_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysGeneral_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehFrameProc_Driving` | `VehEmitter_DriverMain` |
| FreezeVShift | 0 | `VehPhysProc_FreezeVShift_Update` | `VehPhysProc_Driving_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysGeneral_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysProc_FreezeVShift_ReverseOneFrame` | `VehPhysForce_TranslateMatrix` | `VehFrameProc_Driving` | `VehEmitter_DriverMain` |
| PowerSlide | `VehPhysProc_PowerSlide_InitSetUpdate` | 0 | `VehPhysProc_PowerSlide_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysProc_PowerSlide_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehFrameProc_Driving` | `VehEmitter_DriverMain` |
| PowerSlide_InitSetUpdate | 0 | `VehPhysProc_PowerSlide_Update` | `VehPhysProc_PowerSlide_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysProc_PowerSlide_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehFrameProc_Driving` | `VehEmitter_DriverMain` |
| SlamWall | 0 | `VehPhysProc_SlamWall_Update` | `VehPhysProc_SlamWall_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysProc_SlamWall_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehPhysProc_SlamWall_Animate` | `VehEmitter_DriverMain` |
| SpinFirst | `VehPhysProc_SpinFirst_InitSetUpdate` | 0 | `VehPhysProc_SpinFirst_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysProc_SpinFirst_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehFrameProc_Spinning` | `VehEmitter_DriverMain` |
| SpinFirst_InitSetUpdate | 0 | `VehPhysProc_SpinFirst_Update` | `VehPhysProc_SpinFirst_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysProc_SpinFirst_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehFrameProc_Spinning` | `VehEmitter_DriverMain` |
| SpinLast | 0 | `VehPhysProc_SpinLast_Update` | `VehPhysProc_SpinLast_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysProc_SpinLast_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehFrameProc_LastSpin` | `VehEmitter_DriverMain` |
| SpinStop | 0 | `VehPhysProc_SpinStop_Update` | `VehPhysProc_SpinStop_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysProc_SpinStop_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehPhysProc_SpinStop_Animate` | `VehEmitter_DriverMain` |
| MaskGrab | 0 | `VehStuckProc_MaskGrab_Update` | `VehStuckProc_MaskGrab_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehPhysGeneral_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehStuckProc_MaskGrab_Animate` | `VehEmitter_DriverMain` |
| PlantEaten | 0 | `VehStuckProc_PlantEaten_Update` | `VehStuckProc_PlantEaten_PhysLinear` | `VehPhysProc_Driving_Audio` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | `VehStuckProc_PlantEaten_Animate` | 0 |
| RIP | 0 | 0 | `VehStuckProc_PlantEaten_PhysLinear` | `VehPhysProc_Driving_Audio` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| RevEngine | 0 | `VehStuckProc_RevEngine_Update` | `VehStuckProc_RevEngine_PhysLinear` | `VehPhysProc_Driving_Audio` | 0 | 0 | 0 | 0 | 0 | 0 | `VehPhysForce_TranslateMatrix` | `VehStuckProc_RevEngine_Animate` | `VehEmitter_DriverMain` |
| Tumble | 0 | `VehStuckProc_Tumble_Update` | `VehStuckProc_Tumble_PhysLinear` | `VehPhysProc_Driving_Audio` | `VehStuckProc_Tumble_PhysAngular` | `VehPhysForce_OnApplyForces` | `COLL_MOVED_PlayerSearch` | `VehPhysForce_CollideDrivers` | `COLL_FIXED_PlayerSearch` | `VehPhysGeneral_JumpAndFriction` | `VehPhysForce_TranslateMatrix` | `VehStuckProc_Tumble_Animate` | `VehEmitter_DriverMain` |
| Warp | 0 | 0 | 0 | `VehPhysProc_Driving_Audio` | `VehStuckProc_Warp_PhysAngular` | 0 | 0 | 0 | 0 | 0 | `VehPhysForce_TranslateMatrix` | `VehFrameProc_Driving` | `VehEmitter_DriverMain` |