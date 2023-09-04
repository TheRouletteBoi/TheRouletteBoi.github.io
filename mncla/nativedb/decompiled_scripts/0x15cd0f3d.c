void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24;

   var2 = 1;
   var3 = mcHookman_GetId(L[0].v0.v97.v0);
   mcHookman_SetState(L[0].v0.v97.v0, 3);
   mcHookman_SetDifficulty(L[0].v0.v97.v0, var2);
   var4.v0 = 1569.6f;
   var4.v1 = -11.67f;
   var4.v2 = 580.54f;
   var7 = 269.39f;
   var8.v2.v0.v0 = 0.0f;
   var8.v2.v0.v1 = 0.0f;
   var8.v2.v0.v2 = 0.0f;
   var8.v2.v3 = 0.0f;
   L[0].v0.v97.v1 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(L[0].v0.v97.v1, mcHookman_GetCarConfigName(L[0].v0.v97.v0), &var4, 0);
   OpponentManager_AddOpponentToWorld(L[0].v0.v97.v1);
   var14 = Opponent_GetRacer(L[0].v0.v97.v1);
   Racer_SetUIDAndCharacterName(var14, var3, mcCareer_GetHookmanCharacterSet(mcHookman_GetName(L[0].v0.v97.v0)));
   Racer_SetModValue(var14, mcHookman_GetModValue(L[0].v0.v97.v0));
   mcTargetManager_RegisterRacer(var3, var14);
   mcTargetManager_HideTarget(var3, 0);
   Racer_InitializeResetPosition(var14, &var4, var7);
   Racer_Reset(var14);
   L[0].v0.v97.v2 = mcHudMapServer_CreateElement();
   mcHudMapServer_SetVehicleElement(L[0].v0.v97.v2, 2, var14);
   Racer_SetIconType(var14, 4);
   Racer_SetIconColorByDifficulty(var14, var2);
   Racer_HideIcon(var14, 0);
   mcHudMapServer_AddElement(L[0].v0.v97.v2);
   var15 = mcMissionManager_GetMission("FIND_SH_05");
   var16 = UIManager_GetState("Cruising_Offline");
   var17 = sub_1e2(0);
   var18 = 0.0f;
   var19 = 0;
   var20 = 0;
   var21 = 0;
   var22 = null;
   var23 = null;
   var24 = 0;
   while (!var24)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var21);
       if (var21 == 1)
       {
           Racer_HideIcon(var14, 1);
           mcHudMapServer_RemoveElement(L[0].v0.v97.v2);
           Racer_SetStreamingLockedOut(var14);
           while (var21 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var21);
               if (IsExitFlagSet())
               {
               }
               else
               {
                   WAITUNWARPED(100);
               }
           }
           Racer_SetStreamingUnlocked(var14);
           Racer_HideIcon(var14, 0);
           mcHudMapServer_AddElement(L[0].v0.v97.v2);
       }
       var19 = mcHookman_GetState(L[0].v0.v97.v0);
       if (var19 == 1)
       {
           while (var19 == 1)
           {
               var19 = mcHookman_GetState(L[0].v0.v97.v0);
               WAITUNWARPED(100);
           }
       }
       if ((var19 == 4) || IsExitFlagSet())
       {
       }
       else
       {
           if (vhsmState_IsListener(var16) && (!Game_IsPaused()))
           {
               if ((var20 > 0) && (PoliceManager_CheckPoliceActivity(1) != 100))
               {
                   var20 = var20 - 1;
               }
               var18 = Racer_DistanceToPoint(var17, &var4);
               if (var18 < 20.0f)
               {
                   if (PoliceManager_CheckPoliceActivity(1) > 1)
                   {
                       if (var20 == 0)
                       {
                           SplashManager_Splash(0, 4, "LOSE_COPS", 0x40000000, 1, 0);
                           var20 = 100;
                       }
                       WAITUNWARPED(100);
                   }
                   else
                   {
                       Racer_HideIcon(var14, 1);
                       mcHookman_SetState(L[0].v0.v97.v0, 1);
                       Racer_Activate(var17);
                       mcEvent_PostEventStr("MISSION_EVENT", "FIND_SH_05_OBJ_01_COMPLETE");
                   }
               }
           }
           WAITUNWARPED(30);
       }
   }
   PRINTSTRING("Deleting Story Hookman -");
   PRINTINT(var3);
   PRINTSTRING("\n");
   Racer_HideIcon(var14, 1);
   mcTargetManager_UnRegisterTarget(var3);
   mcHudMapServer_DeleteElement(L[0].v0.v97.v2);
   var22 = BrainFactory_CreateBrainCruising(var14);
   sub_502(RAND_INT_RANGE(0, 7), var22);
   BrainCruising_SetLooping(var22, 1);
   BrainCruising_DriveToNearestRail(var22);
   Opponent_ToggleDeleteOnEviction(L[0].v0.v97.v1, 1);
   mcSlotSystem_RequestSlotRemoval(L[0].v0.v97.v0, 1);
   PRINTSTRING("Story Hookman -");
   PRINTINT(var3);
   PRINTSTRING(" deleted.\n");
}

function sub_1e2(var0)
{
   auto var3, var4;

   var3 = Player_FindRacerObject(var0);
   while (var3 == null)
   {
       var3 = Player_FindRacerObject(var0);
       WAITUNWARPED(10);
   }
   return var3;
}

function sub_502(var0, var1)
{
   auto var4, var5, var6, var7, var8;

   switch (var0)
   {
       case 0:
       {
           var4.v0 = -2171.86f;
           var4.v1 = -3.73355f;
           var4.v2 = 38.2942f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -2082.38f;
           var4.v1 = -0.150024f;
           var4.v2 = -103.202f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1848.6f;
           var4.v1 = -5.57857f;
           var4.v2 = 181.021f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1889.23f;
           var4.v1 = -4.57721f;
           var4.v2 = 322.555f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -2098.78f;
           var4.v1 = 0.623314f;
           var4.v2 = 382.108f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 1:
       {
           var4.v0 = -1394.98f;
           var4.v1 = 1.90915f;
           var4.v2 = 382.569f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1399.92f;
           var4.v1 = 2.64949f;
           var4.v2 = 191.428f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1284.03f;
           var4.v1 = -0.438019f;
           var4.v2 = 78.4054f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1146.79f;
           var4.v1 = -3.56482f;
           var4.v2 = 83.3016f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1056.79f;
           var4.v1 = -3.82222f;
           var4.v2 = 231.915f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1028.64f;
           var4.v1 = -1.64497f;
           var4.v2 = 336.496f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1156.35f;
           var4.v1 = -6.13051f;
           var4.v2 = 495.91f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 2:
       {
           var4.v0 = -529.196f;
           var4.v1 = -8.41289f;
           var4.v2 = 203.315f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -241.864f;
           var4.v1 = -13.1316f;
           var4.v2 = 306.687f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -24.9188f;
           var4.v1 = -8.92001f;
           var4.v2 = 127.65f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -134.135f;
           var4.v1 = 18.2821f;
           var4.v2 = -9.99714f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -502.507f;
           var4.v1 = -1.23221f;
           var4.v2 = -3.32185f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -593.266f;
           var4.v1 = -5.1629f;
           var4.v2 = 79.92f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 3:
       {
           var4.v0 = 364.965f;
           var4.v1 = -4.43402f;
           var4.v2 = 120.526f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 366.118f;
           var4.v1 = -11.8294f;
           var4.v2 = 326.516f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 568.537f;
           var4.v1 = -13.1919f;
           var4.v2 = 359.886f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 778.476f;
           var4.v1 = -10.1129f;
           var4.v2 = 213.564f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 772.173f;
           var4.v1 = -4.87628f;
           var4.v2 = 26.1546f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 697.668f;
           var4.v1 = 1.48578f;
           var4.v2 = -89.3486f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 492.799f;
           var4.v1 = 2.23468f;
           var4.v2 = -31.1908f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 4:
       {
           var4.v0 = 1132.48f;
           var4.v1 = 19.5945f;
           var4.v2 = -995.254f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1181.5f;
           var4.v1 = 14.85f;
           var4.v2 = -668.24f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1027.25f;
           var4.v1 = 14.85f;
           var4.v2 = -587.388f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 886.057f;
           var4.v1 = 14.8471f;
           var4.v2 = -666.398f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1027.84f;
           var4.v1 = 19.0699f;
           var4.v2 = -984.565f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 5:
       {
           var4.v0 = 1930.96f;
           var4.v1 = -7.88059f;
           var4.v2 = 519.85f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 1974.67f;
           var4.v1 = -5.14804f;
           var4.v2 = 317.939f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2161.5f;
           var4.v1 = -3.14887f;
           var4.v2 = -3.44634f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2279.15f;
           var4.v1 = -5.8414f;
           var4.v2 = -37.9429f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2287.03f;
           var4.v1 = -10.1456f;
           var4.v2 = 150.248f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2089.7f;
           var4.v1 = -10.1458f;
           var4.v2 = 494.101f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       case 6:
       {
           var4.v0 = 2337.39f;
           var4.v1 = -0.149963f;
           var4.v2 = -661.406f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2278.43f;
           var4.v1 = 1.57553f;
           var4.v2 = -911.264f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2154.28f;
           var4.v1 = 5.34701f;
           var4.v2 = -921.462f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2065.79f;
           var4.v1 = 6.84834f;
           var4.v2 = -679.637f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = 2196.87f;
           var4.v1 = 4.55591f;
           var4.v2 = -512.556f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
       default:
       {
           var4.v0 = -1394.98f;
           var4.v1 = 1.90915f;
           var4.v2 = 382.569f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1399.92f;
           var4.v1 = 2.64949f;
           var4.v2 = 191.428f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1284.03f;
           var4.v1 = -0.438019f;
           var4.v2 = 78.4054f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1146.79f;
           var4.v1 = -3.56482f;
           var4.v2 = 83.3016f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1056.79f;
           var4.v1 = -3.82222f;
           var4.v2 = 231.915f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1028.64f;
           var4.v1 = -1.64497f;
           var4.v2 = 336.496f;
           BrainCruising_AppendDest(var1, &var4);
           var4.v0 = -1156.35f;
           var4.v1 = -6.13051f;
           var4.v2 = 495.91f;
           BrainCruising_AppendDest(var1, &var4);
           return 1;
       }
   }
}

