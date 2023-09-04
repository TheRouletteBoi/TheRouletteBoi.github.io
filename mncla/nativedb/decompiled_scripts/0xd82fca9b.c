void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79, var80, var81, var82, var83, var84, var85, var86, var87, var88, var89, var90, var91, var92, var93, var94, var95;

   if ((Net_IsConnecting() || Net_IsNetworked()) && (!L[0].v4.v780))
   {
       return;
   }
   else
   {
       var2 = AmbientMgr_GetTrafficEnable();
       if (!L[0].v4.v780)
       {
           sub_45(&L[0]);
       }
       Race_SetRaceData(L[0].v3, &(L[0].v4));
       Race_LoadAmbientPathArray(L[0].v3, L[0].v0);
       var3 = LookupCity(GetCurrentCity());
       if (L[0].v4.v779 == 0)
       {
           if (!(L[0].v4.v0 == -1))
           {
               var4 = CityDescription_LookupRaceByIndex(var3, L[0].v4.v0);
               L[0].v4.v779 = RaceDescription_GetDefaultNumLaps(var4);
           }
           else
           {
               L[0].v4.v779 = 1;
           }
       }
       Registry_SetValueString("raceName", CityDescription_GetRaceNameByIndex(var3, L[0].v4.v0));
       PoliceManager_CurrentRaceLapChanged(0);
       Graphics_SetShadowDisable(1);
       var5 = Race_GetCheckpointList(L[0].v3);
       CheckpointManager_SetActiveCheckpointList(var5);
       var6 = 64;
       var75 = null;
       var76 = CheckpointList_GetListCount(var5);
       var71 = 0;
       while (var71 < var76)
       {
           var75 = CheckpointList_GetCheckpoint(var5, var71);
           var6[var71] = mcHudMapServer_CreateElement();
           Checkpoint_GetPosition(var75, &var72);
           mcHudMapServer_SetElement(var6[var71], 0, 0, &var72, (float)0);
           var71 = var71 + 1;
       }
       var77 = null;
       if (EventOptions_IsPowerUps(L[0].v4.v790))
       {
           PRINTSTRING("Script: Powerups are on -- ");
           if (L[0].v2 == null)
           {
               PRINTSTRING("Initializing from checkpoints\n");
               var77 = PickUpManager_CreatePowerUpSourcesFromCheckPoints(var5, 0);
               PickUpManager_PowerUpSourcePostInit(var77);
           }
           else
           {
               PRINTSTRING(" Initializing from manually placed locations\n");
               PickUpManager_PowerUpSourcePostInit(L[0].v2);
           }
       }
       sub_42c(&L[0]);
       if (!L[0].v4.v780)
       {
           var78 = 0;
           Registry_GetValueInt("replaying", &var78);
           PRINTSTRING("REPLAY VALUE ");
           PRINTINT(var78);
           PRINTSTRING("\n");
           L[0].v4.v786 = var78 != 0;
           Registry_SetValueInt("replaying", 0);
           RubberBandMgr_SetupRace(L[0].v4.v775, 1, L[0].v4.v786);
       }
       SetExceptionMask(3);
       var79 = ;
       switch (var79)
       {
           case -1:
           {
               break;
           }
           case 1:
           {
               PRINTSTRING("Shutdown exception\n");
               break;
           }
           case 2:
           {
               PRINTSTRING("restart exception\n");
               break;
           }
           case 3:
           {
               PRINTSTRING("network session termination exception\n");
               break;
           }
           default:
           {
               PRINTSTRING("Unhandled exception: ");
               PRINTINT(var79);
               PRINTSTRING("\n");
               Map_SetCheckpointStrobe(0);
               if (L[0].v4.v780 && (!Net_IsCruiseMode()))
               {
                   PRINTSTRING("Script: UnOrderedCheckpointCore.sc: Disabling traffic for pre-race countdown\n");
                   if (AmbientMgr_GetTrafficEnable())
                   {
                       AmbientMgr_SetTrafficEnable(0);
                   }
               }
               Registry_SetValueInt("raceOverTrigger", 0);
               Registry_SetValueString("raceOverCommand", "");
               TriggerManager_ResetTriggers();
               PropManager_ResetProps();
               PickUpManager_OnRaceReset();
               sub_724(&(L[0].v4), var76, &var6);
               sub_7e7(&(L[0].v4));
               if (!L[0].v4.v780)
               {
                   Notify(0);
               }
               Race_SetRaceData(L[0].v3, &(L[0].v4));
               sub_939(&L[0]);
               sub_c5b(&L[0], var5);
               sub_124c(&L[0]);
               if (L[0].v4.v780)
               {
                   PRINTSTRING("Script: UnOrderedCheckpointCore.sc: Pre-race countdown ended, switching to the selected traffic level\n");
                   sub_45(&L[0]);
               }
               sub_1423(&L[0], var5, var76, &var6);
               if ((!L[0].v4.v780) && (!ReplayMgr_GetFinishedRace()))
               {
                   Form_CloseForm(Form_GetForm(72));
                   strcpy(&var80, 64, "");
                   Registry_GetValueString("raceOverCommand", &var80);
                   if (StringCaseCompare(&var80, "showRaceOverDialog"))
                   {
                       Registry_SetValueInt("raceOverTrigger", 0);
                       sub_263b();
                       ReplayMgr_End(1);
                       sub_26ba();
                       Racer_Activate(Player_FindRacerObject(0));
                   }
                   else if (StringCaseCompare(&var80, "quit"))
                   {
                       ReplayMgr_End(0);
                       Racer_Activate(Player_FindRacerObject(0));
                   }
                   else if (!L[0].v4.v786)
                   {
                       ReplayMgr_End(1);
                   }
                   Notify(1);
               }
               else if (L[0].v4.v780)
               {
                   var71 = 0;
                   while (var71 < L[0].v4.v770)
                   {
                       if (L[0].v4.v1[var71 * 48].v2 == 0)
                       {
                           Racer_Activate(L[0].v4.v1[var71 * 48].v0);
                       }
                       var71 = var71 + 1;
                   }
               }
               break;
           }
       }
       if (!L[0].v4.v780)
       {
           RubberBandMgr_ShutdownRace();
       }
       var71 = 0;
       while (var71 < L[0].v4.v770)
       {
           if (L[0].v4.v1[var71 * 48].v2 == 0)
           {
               if (L[0].v4.v780)
               {
                   Racer_Activate(L[0].v4.v1[var71 * 48].v0);
               }
               UILogic_RemoveGPSDestination(var71);
           }
           var71 = var71 + 1;
       }
       Graphics_SetShadowDisable(0);
       if (var77 != null)
       {
           PickUpManager_DeletePowerUpSources(var77);
           var77 = null;
       }
       if (L[0].v2 != null)
       {
           PickUpManager_DeletePowerUpSources(L[0].v2);
           L[0].v2 = null;
       }
       Race_UnloadAmbientPathArray(L[0].v3);
       Race_SetRaceData(L[0].v3, &(L[0].v4));
       var71 = 0;
       while (var71 < var76)
       {
           mcHudMapServer_DeleteElement(var6[var71]);
           var71 = var71 + 1;
       }
       CheckpointManager_ClearActiveCheckpointList();
       Map_SetCheckpointStrobe(1);
       if (var2 != AmbientMgr_GetTrafficEnable())
       {
           PRINTSTRING("Script: UnOrderedCheckpointCore.sc: Restoring original traffic setting (end of race)\n");
           AmbientMgr_SetTrafficEnable(var2);
       }
       SetExceptionMask(0);
       ThrowRecursive(1);
       return;
   }
}

void sub_45(var0)
{
   auto var3;

   if (*((var0 + 16) + 3160) != null)
   {
       if (EventOptions_GetTrafficLevel(*((var0 + 16) + 3160)) == 0)
       {
           PRINTSTRING("Script: UnOrderedCheckpointCore.sc: SetTrafficLevelFromOptions - Traffic is Disabled\n");
           if (AmbientMgr_GetTrafficEnable())
           {
               AmbientMgr_SetTrafficEnable(0);
           }
       }
       else if (EventOptions_GetTrafficLevel(*((var0 + 16) + 3160)) > 0)
       {
           PRINTSTRING("Script: UnOrderedCheckpointCore.sc: SetTrafficLevelFromOptions - Traffic is Enabled\n");
           if (!AmbientMgr_GetTrafficEnable())
           {
               AmbientMgr_SetTrafficEnable(1);
           }
       }
   }
   else
   {
       PRINTSTRING("Script: UnOrderedCheckpointCore.sc: SetTrafficLevelFromOptions - EventOptions is NULL (is this career?)\n");
   }
}

void sub_42c(var0)
{
   auto var3, var4;

   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       (*((var0 + 16) + 4))[var3 * 48].v7 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v6 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v41 = 0;
       var3 = var3 + 1;
   }
   if (*(var0 + 12) != null)
   {
       Race_SetRaceData(*(var0 + 12), var0 + 16);
   }
}

void sub_724(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = 0;
   while (var5 < *(var0 + 3080))
   {
       sub_745(var5, var1, var2);
       var5 = var5 + 1;
   }
}

void sub_745(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = 0;
   while (var5 < (var1 - 1))
   {
       mcHudMapServer_AddElement((*var2)[var5]);
       mcHudMapServer_SetMutExSubtype((*var2)[var5], 2);
       if (var1 > 1)
       {
           CheckpointManager_ActivateSingleCheckpoint(var0, var5, 4);
       }
       var5 = var5 + 1;
   }
   CheckpointManager_DeactivateSingleCheckpoint(var0, var1 - 1);
   mcHudMapServer_AddElement((*var2)[var1 - 1]);
   mcHudMapServer_SetMutExSubtype((*var2)[var1 - 1], 5);
}

void sub_7e7(var0)
{
   auto var3, var4;

   if (*(var0 + 3120))
   {
       PRINTSTRING("Script: NETWORKED!\n");
   }
   else
   {
       PRINTSTRING("Script: OFFLINE!\n");
   }
   var3 = 0;
   while (var3 <= (*(var0 + 3080) - 1))
   {
       PRINTSTRING("Script: Racer #");
       PRINTINT(var3);
       PRINTSTRING(": ");
       if ((*(var0 + 4))[var3 * 48].v2 == 0)
       {
           PRINTSTRING("LOCAL PLAYER\n");
       }
       else if ((*(var0 + 4))[var3 * 48].v2 == 1)
       {
           PRINTSTRING("REMOTE PLAYER\n");
       }
       else if ((*(var0 + 4))[var3 * 48].v2 == 2)
       {
           PRINTSTRING("AI\n");
       }
       var3 = var3 + 1;
   }
}

void sub_939(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61;

   PRINTSTRING("CORE INFO\n");
   PRINTSTRING("Num Racers");
   PRINTINT(*((var0 + 16) + 3080));
   PRINTSTRING("\n");
   AmbientMgr_Reset();
   var9.v9 = 15;
   var9.v9.v25 = 15;
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var9.v0 = (*((var0 + 16) + 4))[var3 * 48].v0;
       var9.v1 = (*((var0 + 16) + 4))[var3 * 48].v1;
       var9.v2 = (*((var0 + 16) + 4))[var3 * 48].v2;
       var9.v3 = (*((var0 + 16) + 4))[var3 * 48].v3;
       var9.v4 = (*((var0 + 16) + 4))[var3 * 48].v4;
       var9.v5 = (*((var0 + 16) + 4))[var3 * 48].v5;
       var9.v6 = (*((var0 + 16) + 4))[var3 * 48].v6;
       var9.v7 = (*((var0 + 16) + 4))[var3 * 48].v7;
       var9.v8 = (*((var0 + 16) + 4))[var3 * 48].v8;
       var9.v9 = (*((var0 + 16) + 4))[var3 * 48].v9;
       var9.v10 = (*((var0 + 16) + 4))[var3 * 48].v10;
       var9.v11 = (*((var0 + 16) + 4))[var3 * 48].v11;
       var9.v12 = (*((var0 + 16) + 4))[var3 * 48].v12;
       var9.v13 = (*((var0 + 16) + 4))[var3 * 48].v13;
       var9.v14 = (*((var0 + 16) + 4))[var3 * 48].v14;
       var9.v15 = (*((var0 + 16) + 4))[var3 * 48].v15;
       var9.v16 = (*((var0 + 16) + 4))[var3 * 48].v16;
       var9.v17 = (*((var0 + 16) + 4))[var3 * 48].v17;
       var9.v18 = (*((var0 + 16) + 4))[var3 * 48].v18;
       var9.v19 = (*((var0 + 16) + 4))[var3 * 48].v19;
       var9.v20 = (*((var0 + 16) + 4))[var3 * 48].v20;
       var9.v21 = (*((var0 + 16) + 4))[var3 * 48].v21;
       var9.v22 = (*((var0 + 16) + 4))[var3 * 48].v22;
       var9.v23 = (*((var0 + 16) + 4))[var3 * 48].v23;
       var9.v24 = (*((var0 + 16) + 4))[var3 * 48].v24;
       var9.v25 = (*((var0 + 16) + 4))[var3 * 48].v25;
       var9.v26 = (*((var0 + 16) + 4))[var3 * 48].v26;
       var9.v27 = (*((var0 + 16) + 4))[var3 * 48].v27;
       var9.v28 = (*((var0 + 16) + 4))[var3 * 48].v28;
       var9.v29 = (*((var0 + 16) + 4))[var3 * 48].v29;
       var9.v30 = (*((var0 + 16) + 4))[var3 * 48].v30;
       var9.v31 = (*((var0 + 16) + 4))[var3 * 48].v31;
       var9.v32 = (*((var0 + 16) + 4))[var3 * 48].v32;
       var9.v33 = (*((var0 + 16) + 4))[var3 * 48].v33;
       var9.v34 = (*((var0 + 16) + 4))[var3 * 48].v34;
       var9.v35 = (*((var0 + 16) + 4))[var3 * 48].v35;
       var9.v36 = (*((var0 + 16) + 4))[var3 * 48].v36;
       var9.v37 = (*((var0 + 16) + 4))[var3 * 48].v37;
       var9.v38 = (*((var0 + 16) + 4))[var3 * 48].v38;
       var9.v39 = (*((var0 + 16) + 4))[var3 * 48].v39;
       var9.v40 = (*((var0 + 16) + 4))[var3 * 48].v40;
       var9.v41 = (*((var0 + 16) + 4))[var3 * 48].v41;
       var9.v42 = (*((var0 + 16) + 4))[var3 * 48].v42;
       var9.v43 = (*((var0 + 16) + 4))[var3 * 48].v43;
       var9.v44 = (*((var0 + 16) + 4))[var3 * 48].v44;
       var9.v45 = (*((var0 + 16) + 4))[var3 * 48].v45;
       var9.v46 = (*((var0 + 16) + 4))[var3 * 48].v46;
       var9.v47 = (*((var0 + 16) + 4))[var3 * 48].v47;
       if (*((var0 + 16) + 3120))
       {
           var4 = Net_GetRacerGridIndex(var9.v0);
       }
       else
       {
           var4 = var3;
       }
       RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 0), var4, &var5, &var8);
       if (Racer_IsMotorcycle(var9.v0))
       {
           var57.v0 = 0.8f;
           var57.v1 = 0.0f;
           var57.v2 = 0.0f;
           Math_VecRotateY(&var57, &var57, var8);
           var5.v0 = var57.v0 + var5.v0;
           var5.v1 = var57.v1 + var5.v1;
           var5.v2 = var57.v2 + var5.v2;
       }
       PRINTSTRING("Racer ");
       PRINTINT(var3);
       PRINTSTRING(" setup - pos ");
       PRINTVECTOR(var5.v0, var5.v1, var5.v2);
       PRINTSTRING(" - rot ");
       PRINTFLOAT(var8);
       PRINTSTRING("\n");
       Racer_InitializeResetPosition(var9.v0, &var5, var8);
       if (var9.v2 == 2)
       {
           Racer_QuickFix(var9.v0);
           Racer_ResetWithDamageIntact(var9.v0);
       }
       else
       {
           if ((*((var0 + 16) + 3120) && Racer_IsLocalPlayer(var9.v0)) && Racer_IsDamagedOut(var9.v0))
           {
               PRINTSTRING("SCRIPT: QuickFixing damaged out local racer before starting race...\n");
               Racer_QuickFix(var9.v0);
           }
           else
           {
               Racer_ResetWithDamageIntact(var9.v0);
           }
           Registry_GetValueInt("revertDamage", &var60);
           if (var60 == 1)
           {
               UILogic_RevertCarDamage();
               Registry_SetValueInt("revertDamage", 0);
           }
       }
       Racer_PreRaceBurnout(var9.v0);
       var3 = var3 + 1;
   }
   PerspectiveForm_SetSlowMotion(Form_GetForm(60), 1.0f, 0.0f, 0, 0, 1.0f);
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var9.v0 = (*((var0 + 16) + 4))[var3 * 48].v0;
       var9.v1 = (*((var0 + 16) + 4))[var3 * 48].v1;
       var9.v2 = (*((var0 + 16) + 4))[var3 * 48].v2;
       var9.v3 = (*((var0 + 16) + 4))[var3 * 48].v3;
       var9.v4 = (*((var0 + 16) + 4))[var3 * 48].v4;
       var9.v5 = (*((var0 + 16) + 4))[var3 * 48].v5;
       var9.v6 = (*((var0 + 16) + 4))[var3 * 48].v6;
       var9.v7 = (*((var0 + 16) + 4))[var3 * 48].v7;
       var9.v8 = (*((var0 + 16) + 4))[var3 * 48].v8;
       var9.v9 = (*((var0 + 16) + 4))[var3 * 48].v9;
       var9.v10 = (*((var0 + 16) + 4))[var3 * 48].v10;
       var9.v11 = (*((var0 + 16) + 4))[var3 * 48].v11;
       var9.v12 = (*((var0 + 16) + 4))[var3 * 48].v12;
       var9.v13 = (*((var0 + 16) + 4))[var3 * 48].v13;
       var9.v14 = (*((var0 + 16) + 4))[var3 * 48].v14;
       var9.v15 = (*((var0 + 16) + 4))[var3 * 48].v15;
       var9.v16 = (*((var0 + 16) + 4))[var3 * 48].v16;
       var9.v17 = (*((var0 + 16) + 4))[var3 * 48].v17;
       var9.v18 = (*((var0 + 16) + 4))[var3 * 48].v18;
       var9.v19 = (*((var0 + 16) + 4))[var3 * 48].v19;
       var9.v20 = (*((var0 + 16) + 4))[var3 * 48].v20;
       var9.v21 = (*((var0 + 16) + 4))[var3 * 48].v21;
       var9.v22 = (*((var0 + 16) + 4))[var3 * 48].v22;
       var9.v23 = (*((var0 + 16) + 4))[var3 * 48].v23;
       var9.v24 = (*((var0 + 16) + 4))[var3 * 48].v24;
       var9.v25 = (*((var0 + 16) + 4))[var3 * 48].v25;
       var9.v26 = (*((var0 + 16) + 4))[var3 * 48].v26;
       var9.v27 = (*((var0 + 16) + 4))[var3 * 48].v27;
       var9.v28 = (*((var0 + 16) + 4))[var3 * 48].v28;
       var9.v29 = (*((var0 + 16) + 4))[var3 * 48].v29;
       var9.v30 = (*((var0 + 16) + 4))[var3 * 48].v30;
       var9.v31 = (*((var0 + 16) + 4))[var3 * 48].v31;
       var9.v32 = (*((var0 + 16) + 4))[var3 * 48].v32;
       var9.v33 = (*((var0 + 16) + 4))[var3 * 48].v33;
       var9.v34 = (*((var0 + 16) + 4))[var3 * 48].v34;
       var9.v35 = (*((var0 + 16) + 4))[var3 * 48].v35;
       var9.v36 = (*((var0 + 16) + 4))[var3 * 48].v36;
       var9.v37 = (*((var0 + 16) + 4))[var3 * 48].v37;
       var9.v38 = (*((var0 + 16) + 4))[var3 * 48].v38;
       var9.v39 = (*((var0 + 16) + 4))[var3 * 48].v39;
       var9.v40 = (*((var0 + 16) + 4))[var3 * 48].v40;
       var9.v41 = (*((var0 + 16) + 4))[var3 * 48].v41;
       var9.v42 = (*((var0 + 16) + 4))[var3 * 48].v42;
       var9.v43 = (*((var0 + 16) + 4))[var3 * 48].v43;
       var9.v44 = (*((var0 + 16) + 4))[var3 * 48].v44;
       var9.v45 = (*((var0 + 16) + 4))[var3 * 48].v45;
       var9.v46 = (*((var0 + 16) + 4))[var3 * 48].v46;
       var9.v47 = (*((var0 + 16) + 4))[var3 * 48].v47;
       if (var9.v2 == 2)
       {
           mcHudMapServer_AddElement(var9.v4);
       }
       Racer_SetInvincible(var9.v0, 0);
       var3 = var3 + 1;
   }
}

void sub_c5b(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79;

   Race_EnableRaceTimer(*(var0 + 12), 0);
   Race_SetTimer(*(var0 + 12), -60000);
   PRINTSTRING("Playing Starter Cutscene ");
   PRINTSTRING(*(var0 + 3196));
   PRINTSTRING("\n");
   sub_cc0(var0);
   var4 = START_NEW_SCRIPT(*(var0 + 3196), 0);
   while (!Race_IsRaceTimerEnabled(*(var0 + 12)))
   {
       WAITUNWARPED(10);
   }
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       var6.v0 = (*((var0 + 16) + 4))[var5 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var5 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var5 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var5 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var5 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var5 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var5 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var5 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var5 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var5 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var5 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var5 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var5 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var5 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var5 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var5 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var5 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var5 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var5 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var5 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var5 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var5 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var5 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var5 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var5 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var5 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var5 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var5 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var5 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var5 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var5 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var5 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var5 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var5 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var5 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var5 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var5 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var5 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var5 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var5 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var5 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var5 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var5 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var5 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var5 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var5 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var5 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var5 * 48].v47;
       if ((*((var0 + 16) + 3100) != 0) || (var6.v2 != 2))
       {
           Racer_LockFeature(var6.v0, 8, 0);
       }
       else
       {
           Racer_LockFeature(var6.v0, 8, 1);
       }
       var5 = var5 + 1;
   }
   if (!*((var0 + 16) + 3120))
   {
       ReplayMgr_Begin(*((var0 + 16) + 3144));
       RAND_RESET();
   }
   else
   {
       AmbientMgr_FullReset();
   }
   var54 = 0;
   var55 = 16;
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       DebugReplay(2000 + var5);
       var6.v0 = (*((var0 + 16) + 4))[var5 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var5 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var5 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var5 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var5 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var5 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var5 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var5 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var5 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var5 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var5 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var5 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var5 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var5 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var5 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var5 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var5 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var5 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var5 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var5 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var5 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var5 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var5 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var5 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var5 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var5 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var5 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var5 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var5 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var5 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var5 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var5 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var5 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var5 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var5 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var5 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var5 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var5 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var5 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var5 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var5 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var5 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var5 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var5 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var5 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var5 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var5 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var5 * 48].v47;
       if (var6.v2 == 2)
       {
           BrainRacing_Reset(var6.v3);
           BrainRacing_SetupRace(var6.v3, var1, var5, *((var0 + 16) + 3116), *((var0 + 16) + 3100));
           var72.v0 = (float)0;
           var72.v1 = (float)0;
           var72.v2 = (float)0;
           BrainRacing_SetFinalHeading(var6.v3, &var72);
           BrainRacing_SetFinalSpeed(var6.v3, (float)-1);
           BrainRacing_SetRevvingEnabled(var6.v3, 1);
           BrainRacing_SetHoldStill(var6.v3, 0);
           if (*((var0 + 16) + 3100) != 0)
           {
               Racer_PreRaceBurnout(var6.v0);
           }
           else
           {
               Racer_Deactivate(var6.v0);
           }
           var55[var54] = var6.v3;
           var54 = var54 + 1;
       }
       else
       {
           Racer_PreRaceBurnout(var6.v0);
       }
       var5 = var5 + 1;
   }
   var75 = var54 / 2;
   if ((var75 == 0) && (var54 > 0))
   {
       var75 = 1;
   }
   var5 = 0;
   while (var5 < var75)
   {
       var76 = RAND_INT_RANGE(0, var54 - 1);
       BrainRacing_SetRevvingHandbrake(var55[var76], 1);
       var54 = var54 - 1;
       var55[var76] = var55[var54];
       var5 = var5 + 1;
   }
   var77 = 0;
   while ((Race_GetTimer(*(var0 + 12)) < -3000) && (var77 == 0))
   {
       Registry_GetValueInt("raceOverTrigger", &var77);
       if (var77 == 1)
       {
           ThrowRecursiveScript(var4, 1);
       }
       DebugReplay(2100);
       WAITUNWARPED(10);
   }
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       var6.v0 = (*((var0 + 16) + 4))[var5 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var5 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var5 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var5 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var5 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var5 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var5 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var5 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var5 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var5 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var5 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var5 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var5 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var5 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var5 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var5 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var5 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var5 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var5 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var5 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var5 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var5 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var5 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var5 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var5 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var5 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var5 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var5 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var5 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var5 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var5 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var5 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var5 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var5 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var5 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var5 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var5 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var5 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var5 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var5 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var5 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var5 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var5 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var5 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var5 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var5 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var5 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var5 * 48].v47;
       DebugReplay(2125 + var5);
       if ((var6.v2 == 2) && (*((var0 + 16) + 3100) != 0))
       {
           BrainRacing_SetRevvingHandbrake(var6.v3, 1);
       }
       var5 = var5 + 1;
   }
   while ((Race_GetTimer(*(var0 + 12)) < -1000) && (var77 == 0))
   {
       Registry_GetValueInt("raceOverTrigger", &var77);
       if (var77 == 1)
       {
           ThrowRecursiveScript(var4, 1);
       }
       DebugReplay(2150);
       WAITUNWARPED(10);
   }
   var5 = 0;
   while (var5 < *((var0 + 16) + 3080))
   {
       var6.v0 = (*((var0 + 16) + 4))[var5 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var5 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var5 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var5 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var5 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var5 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var5 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var5 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var5 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var5 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var5 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var5 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var5 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var5 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var5 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var5 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var5 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var5 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var5 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var5 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var5 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var5 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var5 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var5 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var5 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var5 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var5 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var5 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var5 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var5 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var5 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var5 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var5 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var5 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var5 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var5 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var5 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var5 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var5 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var5 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var5 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var5 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var5 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var5 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var5 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var5 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var5 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var5 * 48].v47;
       DebugReplay(2200 + var5);
       if ((var6.v2 == 2) && (*((var0 + 16) + 3100) != 0))
       {
           BrainRacing_SetRevvingEnabled(var6.v3, 0);
       }
       var5 = var5 + 1;
   }
   while ((Race_GetTimer(*(var0 + 12)) < 0) && (var77 == 0))
   {
       Registry_GetValueInt("raceOverTrigger", &var77);
       if (var77 == 1)
       {
           ThrowRecursiveScript(var4, 1);
       }
       DebugReplay(2300);
       WAITUNWARPED(10);
   }
   if ((!*((var0 + 16) + 3120)) && *((var0 + 16) + 3144))
   {
       Form_ShowForm(Form_GetForm(-1), Form_GetForm(72));
   }
}

void sub_cc0(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9;

   RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 0), 0, &(var3.v2.v0), &(var3.v2.v3));
   CineScript_SetGameCoordSysBinding(&var3);
   sub_cf2(var0);
}

void sub_cf2(var0)
{
   auto var3, var4, var5;

   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var4 = Racer_GetUID((*((var0 + 16) + 4))[var3 * 48].v0);
       if (var4 == 0)
       {
           var4 = 5000 + var3;
           while (Racer_FindFromUID(var4) != null)
           {
               var4 = var4 + 1;
               WAITUNWARPED(10);
           }
           Racer_SetUID((*((var0 + 16) + 4))[var3 * 48].v0, var4);
       }
       CineScript_Cars_AssignIdToSlot(var4, var3);
       var3 = var3 + 1;
   }
}

void sub_124c(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54;

   var5 = LookupCity(GetCurrentCity());
   var6.v9 = 15;
   var6.v9.v25 = 15;
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       var6.v0 = (*((var0 + 16) + 4))[var3 * 48].v0;
       var6.v1 = (*((var0 + 16) + 4))[var3 * 48].v1;
       var6.v2 = (*((var0 + 16) + 4))[var3 * 48].v2;
       var6.v3 = (*((var0 + 16) + 4))[var3 * 48].v3;
       var6.v4 = (*((var0 + 16) + 4))[var3 * 48].v4;
       var6.v5 = (*((var0 + 16) + 4))[var3 * 48].v5;
       var6.v6 = (*((var0 + 16) + 4))[var3 * 48].v6;
       var6.v7 = (*((var0 + 16) + 4))[var3 * 48].v7;
       var6.v8 = (*((var0 + 16) + 4))[var3 * 48].v8;
       var6.v9 = (*((var0 + 16) + 4))[var3 * 48].v9;
       var6.v10 = (*((var0 + 16) + 4))[var3 * 48].v10;
       var6.v11 = (*((var0 + 16) + 4))[var3 * 48].v11;
       var6.v12 = (*((var0 + 16) + 4))[var3 * 48].v12;
       var6.v13 = (*((var0 + 16) + 4))[var3 * 48].v13;
       var6.v14 = (*((var0 + 16) + 4))[var3 * 48].v14;
       var6.v15 = (*((var0 + 16) + 4))[var3 * 48].v15;
       var6.v16 = (*((var0 + 16) + 4))[var3 * 48].v16;
       var6.v17 = (*((var0 + 16) + 4))[var3 * 48].v17;
       var6.v18 = (*((var0 + 16) + 4))[var3 * 48].v18;
       var6.v19 = (*((var0 + 16) + 4))[var3 * 48].v19;
       var6.v20 = (*((var0 + 16) + 4))[var3 * 48].v20;
       var6.v21 = (*((var0 + 16) + 4))[var3 * 48].v21;
       var6.v22 = (*((var0 + 16) + 4))[var3 * 48].v22;
       var6.v23 = (*((var0 + 16) + 4))[var3 * 48].v23;
       var6.v24 = (*((var0 + 16) + 4))[var3 * 48].v24;
       var6.v25 = (*((var0 + 16) + 4))[var3 * 48].v25;
       var6.v26 = (*((var0 + 16) + 4))[var3 * 48].v26;
       var6.v27 = (*((var0 + 16) + 4))[var3 * 48].v27;
       var6.v28 = (*((var0 + 16) + 4))[var3 * 48].v28;
       var6.v29 = (*((var0 + 16) + 4))[var3 * 48].v29;
       var6.v30 = (*((var0 + 16) + 4))[var3 * 48].v30;
       var6.v31 = (*((var0 + 16) + 4))[var3 * 48].v31;
       var6.v32 = (*((var0 + 16) + 4))[var3 * 48].v32;
       var6.v33 = (*((var0 + 16) + 4))[var3 * 48].v33;
       var6.v34 = (*((var0 + 16) + 4))[var3 * 48].v34;
       var6.v35 = (*((var0 + 16) + 4))[var3 * 48].v35;
       var6.v36 = (*((var0 + 16) + 4))[var3 * 48].v36;
       var6.v37 = (*((var0 + 16) + 4))[var3 * 48].v37;
       var6.v38 = (*((var0 + 16) + 4))[var3 * 48].v38;
       var6.v39 = (*((var0 + 16) + 4))[var3 * 48].v39;
       var6.v40 = (*((var0 + 16) + 4))[var3 * 48].v40;
       var6.v41 = (*((var0 + 16) + 4))[var3 * 48].v41;
       var6.v42 = (*((var0 + 16) + 4))[var3 * 48].v42;
       var6.v43 = (*((var0 + 16) + 4))[var3 * 48].v43;
       var6.v44 = (*((var0 + 16) + 4))[var3 * 48].v44;
       var6.v45 = (*((var0 + 16) + 4))[var3 * 48].v45;
       var6.v46 = (*((var0 + 16) + 4))[var3 * 48].v46;
       var6.v47 = (*((var0 + 16) + 4))[var3 * 48].v47;
       (*((var0 + 16) + 4))[var3 * 48].v6 = 0;
       (*((var0 + 16) + 4))[var3 * 48].v7 = 0;
       var4 = 0;
       while (var4 < *((var0 + 16) + 3116))
       {
           (*((var0 + 16) + 4))[var3 * 48].v25[var4] = 0;
           (*((var0 + 16) + 4))[var3 * 48].v9[var4] = 0;
           var4 = var4 + 1;
       }
       DebugReplay(2400 + var3);
       (*((var0 + 16) + 4))[var3 * 48].v8 = 0x7fffffff;
       if (var6.v2 == 2)
       {
           BrainRacing_BeginRace(var6.v3, CityDescription_GetRaceNameByIndex(var5, *((var0 + 16) + 0)));
       }
       Racer_Activate((*((var0 + 16) + 4))[var3 * 48].v0);
       if (var6.v2 == 2)
       {
           BrainRacing_SetRevvingEnabled(var6.v3, 0);
       }
       var3 = var3 + 1;
   }
}

void sub_1423(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24;

   PRINTSTRING("Script: Starting Race...\n");
   var6 = UIManager_FindMovie("HUDMOVIE");
   FlashHelper_SetGlobalString(var6, "LapTime", "");
   var7 = 0;
   var8 = 0;
   var9 = null;
   var10 = 0;
   var11 = 0;
   var12 = 0;
   Race_SetRaceData(*(var0 + 12), var0 + 16);
   while (!Race_IsFinished(*(var0 + 12)))
   {
       var9 = CheckpointManager_FindClosestOpenCheckpoint(var1, (*((var0 + 16) + 4))[0 * 48].v0, 0);
       if (var9 != null)
       {
           Checkpoint_GetPosition(var9, &var13);
           UILogic_SetGPSDestination(0, &var13);
       }
       var16 = 0;
       while (var16 < *((var0 + 16) + 3080))
       {
           var7 = (*((var0 + 16) + 4))[var16 * 48].v2 == 0;
           var8 = (*((var0 + 16) + 4))[var16 * 48].v2 == 1;
           if (Racer_IsActive((*((var0 + 16) + 4))[var16 * 48].v0))
           {
               var17 = CheckpointManager_GetWhichHitCheckpoint(var16, (*((var0 + 16) + 4))[var16 * 48].v0);
               if (var17 != -1)
               {
                   CheckpointManager_DeactivateSingleCheckpoint(var16, var17);
                   if (var7)
                   {
                       mcHudMapServer_RemoveElement((*var3)[var17]);
                   }
                   PRINTSTRING("Racer ");
                   PRINTINT(var16);
                   PRINTSTRING(" - Hit Checkpoint ");
                   PRINTINT(var17);
                   PRINTSTRING("\n");
                   if ((*((var0 + 16) + 4))[var16 * 48].v2 == 2)
                   {
                       BrainRacing_RecordTime((*((var0 + 16) + 4))[var16 * 48].v3, (*((var0 + 16) + 4))[var16 * 48].v7, var17, Race_GetTimer(*(var0 + 12)));
                   }
                   (*((var0 + 16) + 4))[var16 * 48].v6 = (*((var0 + 16) + 4))[var16 * 48].v6 + 1;
                   PRINTSTRING("Racer ");
                   PRINTINT(var16);
                   PRINTSTRING(" - Checkpoint Count ");
                   PRINTINT((*((var0 + 16) + 4))[var16 * 48].v6);
                   PRINTSTRING(" - NUM Checkpoints ");
                   PRINTINT(var2);
                   PRINTSTRING("\n");
                   sub_16e0(&((*((var0 + 16) + 4))[var16 * 48]), var16, var2);
                   if ((*((var0 + 16) + 4))[var16 * 48].v6 >= var2)
                   {
                       var18 = (*((var0 + 16) + 4))[var16 * 48].v7;
                       if (var7 || var8)
                       {
                           var19 = Race_GetTimerHuman(*(var0 + 12));
                       }
                       else
                       {
                           var19 = Race_GetTimerAI(*(var0 + 12));
                       }
                       (*((var0 + 16) + 4))[var16 * 48].v9[var18] = var19 - (*((var0 + 16) + 4))[var16 * 48].v25[var18];
                       if (var7)
                       {
                           PRINTSTRING("UNORDERED FINISH - LOCAL RACER\n");
                           Race_Finish(*(var0 + 12));
                       }
                       if (!var8)
                       {
                           PRINTSTRING("Racer ");
                           PRINTINT(var16);
                           PRINTSTRING("- Finished Race. Time ");
                           PRINTINT(var19);
                           PRINTSTRING(" seconds\n");
                           (*((var0 + 16) + 4))[var16 * 48].v8 = var19;
                           sub_1852(var0, var16, &var10, 0);
                       }
                   }
                   else if (var7)
                   {
                       AudioManager_PlayFrontendSound("HUD_CHECKPOINT_MASTER");
                   }
               }
               if (var8)
               {
                   if ((*((var0 + 16) + 4))[var16 * 48].v8 == 0x7fffffff)
                   {
                       if (Net_GetRaceFinishTime((*((var0 + 16) + 4))[var16 * 48].v0, &((*((var0 + 16) + 4))[var16 * 48].v8)))
                       {
                           if ((*((var0 + 16) + 4))[var16 * 48].v8 == -1)
                           {
                           }
                           else
                           {
                               PRINTSTRING("Racer ");
                               PRINTINT(var16);
                               PRINTSTRING("- Finished Race. Time ");
                               PRINTINT(var19);
                               PRINTSTRING(" seconds\n");
                               sub_1852(var0, var16, &var10, 0);
                           }
                       }
                   }
               }
           }
           var16 = var16 + 1;
       }
       var16 = 0;
       while (var16 < *((var0 + 16) + 3080))
       {
           var7 = (*((var0 + 16) + 4))[var16 * 48].v2 == 0;
           var8 = (*((var0 + 16) + 4))[var16 * 48].v2 == 1;
           if (((*((var0 + 16) + 4))[var16 * 48].v8 != -1) && (!Game_IsPaused()))
           {
               (*((var0 + 16) + 4))[var16 * 48].v41 = CheckpointManager_CalculateRankUnordered(Race_GetCheckpointList(*(var0 + 12)), var0 + 16, var16, *((var0 + 16) + 3080));
           }
           if (var7)
           {
               FlashHelper_SetGlobalInt(var6, "PosNumber", (*((var0 + 16) + 4))[var16 * 48].v41);
               FlashHelper_SetGlobalInt(var6, "PosMax", *((var0 + 16) + 3080));
               if (*((var0 + 16) + 3116) > 1)
               {
                   var20 = (*((var0 + 16) + 4))[var16 * 48].v7;
                   FlashHelper_SetGlobalInt(var6, "LapNumber", var20 + 1);
                   FlashHelper_SetGlobalInt(var6, "LapMax", *((var0 + 16) + 3116));
                   if (*((var0 + 16) + 3116) > 0)
                   {
                       Ctrl_SetVisible(HUD_GetHUDCtrl(16), 1);
                       Ctrl_SetVisible(HUD_GetHUDCtrl(7), 1);
                   }
                   else
                   {
                       Ctrl_SetVisible(HUD_GetHUDCtrl(16), 0);
                       Ctrl_SetVisible(HUD_GetHUDCtrl(7), 0);
                   }
               }
               if (*((var0 + 16) + 3120))
               {
                   if ((Net_IsRankedMode() || Net_IsCruiseMode()) && (*((var0 + 16) + 3080) > 1))
                   {
                       if (sub_220b(var0))
                       {
                           PRINTSTRING("Script: Everyone disconnected, local player wins by default\n");
                           (*((var0 + 16) + 4))[var16 * 48].v41 = 1;
                           sub_1852(var0, var16, &var10, 0);
                           Race_Finish(*(var0 + 12));
                       }
                   }
               }
           }
           var16 = var16 + 1;
       }
       Race_SetRaceData(*(var0 + 12), var0 + 16);
       Registry_GetValueInt("raceOverTrigger", &var11);
       if (var11 == 1)
       {
           PRINTSTRING("UNORDERED FINISH - RACER DECISION\n");
           Race_Finish(*(var0 + 12));
       }
       if ((*((var0 + 16) + 3120) && (*((var0 + 16) + 3148) > 0)) && (Race_GetTimerHuman(*(var0 + 12)) >= *((var0 + 16) + 3148)))
       {
           PRINTSTRING("Script: Race timeout! nTimeout = ");
           PRINTINT(*((var0 + 16) + 3148));
           PRINTSTRING("\n");
           Race_Finish(*(var0 + 12));
           var12 = 1;
           Notify(3);
       }
       else
       {
           WAITUNWARPED(30);
       }
   }
   if (*((var0 + 16) + 3120))
   {
       var16 = 0;
       var16 = 0;
       while (var16 < *((var0 + 16) + 3080))
       {
           var7 = (*((var0 + 16) + 4))[var16 * 48].v2 == 0;
           if (var7 && ((*((var0 + 16) + 4))[var16 * 48].v8 == 0x7fffffff))
           {
               (*((var0 + 16) + 4))[var16 * 48].v8 = -1;
               (*((var0 + 16) + 4))[var16 * 48].v41 = *((var0 + 16) + 3080);
               if (var12)
               {
                   PRINTSTRING("Script: Local racer timed out\n");
                   Net_SetRacerTimeout((*((var0 + 16) + 4))[var16 * 48].v0);
                   sub_199d(var0, var16);
               }
               else if (var11 == 1)
               {
                   PRINTSTRING("Script: Local racer quit\n");
                   Net_SetRacerDisconnect((*((var0 + 16) + 4))[var16 * 48].v0);
               }
           }
           var16 = var16 + 1;
       }
   }
   FlashHelper_SetGlobalString(var6, "LapTime", "");
   Ctrl_SetVisible(HUD_GetHUDCtrl(16), 0);
   Ctrl_SetVisible(HUD_GetHUDCtrl(7), 0);
}

void sub_16e0(var0, var1, var2)
{
   auto var5, var6, var7;

   if (*(var0 + 24) == (var2 - 1))
   {
       CheckpointManager_ActivateSingleCheckpoint(var1, var2 - 1, 17);
   }
}

void sub_1852(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13, var14;

   var6 = (*((var0 + 16) + 4))[var1 * 48].v0;
   var7 = (*((var0 + 16) + 4))[var1 * 48].v8;
   var8 = (*((var0 + 16) + 4))[var1 * 48].v2;
   if (*((var0 + 16) + 3120) && (var8 == 0))
   {
       Net_SetRaceFinishTime(var6, var7);
       (*((var0 + 16) + 4))[var1 * 48].v41 = sub_18b6(var0, var1, var7);
       PRINTSTRING("SCRIPT: Before SkidToStop, my finish time rank is ");
       PRINTINT((*((var0 + 16) + 4))[var1 * 48].v41);
       PRINTSTRING("\n");
       sub_199d(var0, var1);
   }
   var9 = (*((var0 + 16) + 4))[var1 * 48].v41;
   PRINTSTRING("RACER ");
   PRINTINT(var1);
   PRINTSTRING(" Finished in - ");
   PRINTINT(var9);
   PRINTSTRING(" Place\n");
   var10 = EventOptions_IsLastManOut(*((var0 + 16) + 3160));
   *var2 = *(var2) + 1;
   if (var9 == 1)
   {
       Race_SetWinningTime(*(var0 + 12), var7);
   }
   if (var8 == 0)
   {
       if (var3)
       {
           SplashManager_SplashDynamicString(0, 3, Racer_GetName(var6), "PLAYER_ELEMINATED", "LMO_ELEMINATED", 0x40000000, 0);
       }
       Racer_SetPreviousRaceTime(var6, var7);
       if (!*((var0 + 16) + 3120))
       {
           if (Racer_IsDamagedOut(var6))
           {
               Race_ToggleDamagedOut(*(var0 + 12), 0);
               Racer_SetDamagePercent(var6, 0.95f);
           }
           ReplayMgr_SetFinishedRace();
           ReplayMgr_End(1);
           if (*((var0 + 16) + 3144))
           {
               Form_CloseForm(Form_GetForm(72));
           }
       }
   }
   else if (var10)
   {
       if (var3)
       {
           SplashManager_SplashDynamicString(0, 3, Racer_GetName(var6), "PLAYER_ELEMINATED", "LMO_ELEMINATED", 0x40000000, 0);
       }
   }
   else
   {
       StringTable_SetString("PLAYER_FINISHED_NAME", Racer_GetName(var6));
       SplashManager_SplashRaw(0, 3, StringTable_GetString("PLAYER_FINISHED"), 1.0f, 1, 0);
   }
   if (var8 == 2)
   {
       BrainRacing_EndRace((*((var0 + 16) + 4))[var1 * 48].v3, var7);
       mcHudMapServer_RemoveElement((*((var0 + 16) + 4))[var1 * 48].v4);
   }
   if (*((var0 + 16) + 3120) && (*((var0 + 16) + 3148) <= 0))
   {
       if ((!(var7 == 0x7fffffff)) && (!(var7 == -1)))
       {
           *((var0 + 16) + 3148) = var7 + 60000;
           PRINTSTRING("Script: Timeout scheduled for ");
           PRINTINT(*((var0 + 16) + 3148));
           PRINTSTRING("\n");
       }
   }
}

function sub_18b6(var0, var1, var2)
{
   auto var5, var6, var7, var8, var9, var10;

   var5 = 1;
   var6 = 0;
   var6 = 0;
   while (var6 < *((var0 + 16) + 3080))
   {
       var7 = (*((var0 + 16) + 4))[var6 * 48].v8;
       if (((var1 != var6) && (var7 != 0x7fffffff)) && (var7 != -1))
       {
           if (var7 < var2)
           {
               var5 = var5 + 1;
           }
       }
       var6 = var6 + 1;
   }
   return var5;
}

void sub_199d(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10;

   PRINTSTRING("Script: Skidding to a stop...\n");
   var4 = (*((var0 + 16) + 4))[var1 * 48].v0;
   Racer_SetCarDrivableState(var4, 8);
   var5 = (*((var0 + 16) + 4))[var1 * 48].v8;
   var6 = Race_GetTimerHuman(*(var0 + 12)) + 2500;
   while (Race_GetTimerHuman(*(var0 + 12)) < var6)
   {
       var7 = 0;
       while (var7 < *((var0 + 16) + 3080))
       {
           if ((*((var0 + 16) + 4))[var7 * 48].v8 == 0x7fffffff)
           {
               if (Net_GetRaceFinishTime((*((var0 + 16) + 4))[var7 * 48].v0, &((*((var0 + 16) + 4))[var7 * 48].v8)))
               {
                   var8 = (*((var0 + 16) + 4))[var7 * 48].v8;
                   if (var8 != -1)
                   {
                       PRINTSTRING("During SkidToStop: Racer ");
                       PRINTINT(var7);
                       PRINTSTRING(" - Finished Race. Time ");
                       PRINTINT(var8);
                       PRINTSTRING(" seconds\n");
                       if ((var5 != -1) && (var5 != 0x7fffffff))
                       {
                           if (var8 < var5)
                           {
                               (*((var0 + 16) + 4))[var1 * 48].v41 = (*((var0 + 16) + 4))[var1 * 48].v41 + 1;
                               PRINTSTRING("Racer ");
                               PRINTINT(var7);
                               PRINTSTRING(" - Finished before me. My new rank is ");
                               PRINTINT((*((var0 + 16) + 4))[var1 * 48].v41);
                               PRINTSTRING("\n");
                           }
                       }
                   }
               }
           }
           var7 = var7 + 1;
       }
       Race_SetRaceData(*(var0 + 12), var0 + 16);
       WAITUNWARPED(30);
   }
   PRINTSTRING("Script: I finished skidding out...\n");
   if (Racer_IsDamagedOut(var4))
   {
       PRINTSTRING("SCRIPT: RaceOver.sch: QuickFixing damaged out local racer since he finished the race...\n");
       Racer_QuickFix(var4);
   }
}

function sub_220b(var0)
{
   auto var3, var4;

   if (*((var0 + 16) + 3120))
   {
       var3 = 0;
       while (var3 < *((var0 + 16) + 3080))
       {
           if ((*((var0 + 16) + 4))[var3 * 48].v2 == 1)
           {
               if (Net_IsPlayerDisconnected((*((var0 + 16) + 4))[var3 * 48].v0))
               {
               }
               else
               {
                   return 0;
               }
           }
           else
           {
               var3 = var3 + 1;
           }
       }
       PRINTSTRING("Script: Net.sch: WE ARE ALONE\n");
   }
   return 1;
}

void sub_263b()
{
   Warper_Warp("USER_WAIT_NO_CUT_UP");
   while (!Warper_IsReadyToLoadStuff())
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting\n");
   }
   PRINTSTRING("Finished waiting\n");
}

void sub_26ba()
{
   WAITUNWARPED(10);
   Warper_Warp("USER_WAIT_NO_CUT_DOWN");
   while (Warper_IsWarping())
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting\n");
   }
   PRINTSTRING("Finished waiting\n");
}

