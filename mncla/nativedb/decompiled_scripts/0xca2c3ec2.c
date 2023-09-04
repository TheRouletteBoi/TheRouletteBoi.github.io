void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19;

   Registry_SetValueInt(L[0].v820.v21, 2);
   mcTargetManager_RegisterLocation(L[0].v820.v2, &(L[0].v820.v4));
   mcTargetManager_HideTarget(L[0].v820.v2, 0);
   mcHudMapServer_AddElement(L[0].v820.v3);
   AudioManager_InitHangout(L[0].v820.v0, L[0].v820.v21, &(L[0].v820.v10));
   var2.v0 = 0.0f;
   var2.v1 = 0.0f;
   var2.v2 = 0.0f;
   var5 = PropManager_InitRaceProps(1, 1);
   var6 = PropManager_CreateRaceProp(var5, &(L[0].v820.v18), &var2, "city/la/props", L[0].v820.v17);
   var7 = TriggerManager_CreateTriggerArray(1);
   var8 = TriggerArray_AddTriggerLine(var7);
   Trigger_SetValueVector(var8, "oPosStart", &(L[0].v820.v7));
   Trigger_SetValueVector(var8, "oPosEnd", &(L[0].v820.v10));
   Trigger_SetValueFloat(var8, "rHeight", (float)20);
   Trigger_SetValueInt(var8, "lapActive", -1);
   Trigger_SetValueFloat(var8, "fRandomness", 1.0f);
   var9 = Player_FindRacerObject(0);
   var10 = UIManager_GetState("Cruising_Offline");
   var11 = (float)0;
   var12 = 1;
   var13 = 0;
   var14 = 0;
   var15 = 0;
   var16 = null;
   var17 = 0;
   var18 = 0;
   var13 = 0;
   while (var13 < L[0].v0.v803)
   {
       mcCareer_UnlockRace(L[0].v0.v804[var13]);
       var13 = var13 + 1;
   }
   var19 = 0;
   while (!var19)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var14);
       if (var14 == 1)
       {
           PRINTSTRING("Hangout ");
           PRINTSTRING(L[0].v820.v0);
           PRINTSTRING(" was nSuspended (Script_SuspendAllOpponents was set)\n");
           sub_288(&L[0], var6);
           while (var14 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var14);
               WAITUNWARPED(100);
           }
           PRINTSTRING("Hangout ");
           PRINTSTRING(L[0].v820.v0);
           PRINTSTRING(" was un-nSuspended (Script_SuspendAllOpponents was reset)\n");
           sub_3e4(&L[0], var6);
       }
       if (vhsmState_IsListener(var10))
       {
           var18 = PoliceManager_CheckPoliceActivity(1) > 1;
           if (var18 && (!var17))
           {
               var17 = 1;
               PropManager_AttachRaceProp(var6);
           }
           else if ((!var18) && var17)
           {
               var17 = 0;
               PropManager_DetachRaceProp(var6);
           }
           if (Trigger_CheckTrigger(var8, var9))
           {
               if (var18)
               {
                   WAITUNWARPED(100);
               }
               else
               {
                   sub_525(0.0f, 0.2f, 108);
                   mcGame_ThrowEvent("localHangout");
                   Registry_SetValueInt(L[0].v820.v21, 3);
                   mcHudMapServer_RemoveElement(L[0].v820.v3);
                   Racer_Deactivate(var9);
                   PRINTSTRING("Hangout entered.  Animating to start position\n");
                   Warper_TransitionTo("STORY_LOCATION_CUT_SIMPLE", L[0].v820.v2, &(L[0].v820.v24), &(L[0].v820.v27), &(L[0].v820.v30), "WarpFromCarToWaitPosition_CarneySign");
                   AudioManager_SetActiveSlowMotionForm(1);
                   while (!Warper_IsReadyToLoadStuff())
                   {
                       WAITUNWARPED(30);
                       PRINTSTRING("Waiting for cutscene to load\n");
                   }
                   PRINTSTRING("Warper is in place\n");
                   AmbientMgr_SetHangoutMode(1);
                   sub_6e2(&(L[0].v820));
                   mcEvent_PostEventStr("LOCATION_EVENT", L[0].v820.v0);
                   mcEvent_PostEventStr("MISSION_EVENT", L[0].v820.v22);
                   PRINTSTRING("Sent off the hangout entry event ( this will trigger the cinematic based off of a priority )\n");
                   sub_8f2(108, 0x3f000000);
                   AudioManager_EnterHangoutState(L[0].v820.v0);
                   AudioManager_SetActiveSlowMotionForm(0);
                   Registry_GetValueInt(L[0].v820.v21, &var15);
                   while (var15 == 3)
                   {
                       Registry_GetValueInt(L[0].v820.v21, &var15);
                       WAITUNWARPED(100);
                   }
                   PRINTSTRING("Ready to display UI\n");
                   if (var15 == 4)
                   {
                       PropManager_AttachRaceProp(var6);
                       var12 = sub_a03(&L[0]);
                       PropManager_DetachRaceProp(var6);
                       if (var12 == 0)
                       {
                           PRINTSTRING("Player opted to return to hangout\n");
                           PRINTSTRING("THIS IS NO LONGER SUPPORTED/n");
                           BREAKPOINT();
                       }
                       else if (var12 == 3)
                       {
                           PRINTSTRING("Player opted to ignore exit event\n");
                       }
                       else
                       {
                           Registry_SetValueInt(L[0].v820.v21, 3);
                           mcEvent_PostEventStr("MISSION_EVENT", L[0].v820.v23);
                           Registry_GetValueInt(L[0].v820.v21, &var15);
                           while (var15 == 3)
                           {
                               Registry_GetValueInt(L[0].v820.v21, &var15);
                               WAITUNWARPED(100);
                           }
                           sub_bd0(&(L[0].v820));
                       }
                   }
                   else if (var15 == 1)
                   {
                       sub_288(&L[0], var6);
                       AmbientMgr_SetHangoutMode(1);
                       while (var15 == 1)
                       {
                           Registry_GetValueInt(L[0].v820.v21, &var15);
                           WAITUNWARPED(100);
                       }
                       AmbientMgr_SetHangoutMode(0);
                       sub_3e4(&L[0], var6);
                   }
                   mcGame_ThrowEvent("cruising");
                   Registry_SetValueInt(L[0].v820.v21, 2);
                   var13 = 0;
                   while (var13 < L[0].v820.v33)
                   {
                       var16 = Opponent_GetRacer(L[0].v820.v34[var13]);
                       Racer_InitializeResetPosition(var16, &(L[0].v820.v52[var13 * 3]), L[0].v820.v77[var13]);
                       Racer_Reset(var16);
                       var13 = var13 + 1;
                   }
                   mcHudMapServer_AddElement(L[0].v820.v3);
                   AmbientMgr_SetHangoutMode(0);
               }
           }
       }
       WAITUNWARPED(10);
   }
   TriggerManager_DestroyTriggerArray(var7);
   PropManager_ShutdownRaceProps(var5);
   Registry_SetValueInt(L[0].v820.v21, 0);
   mcTargetManager_HideTarget(L[0].v820.v2, 1);
   AudioManager_DestroyHangout(L[0].v820.v0);
}

void sub_288(var0, var1)
{
   auto var4, var5, var6, var7;

   PRINTSTRING("Hangout ");
   PRINTSTRING(*((var0 + 3280) + 0));
   PRINTSTRING(" was suspended\n");
   SetExceptionMask(0);
   mcHudMapServer_RemoveElement(*((var0 + 3280) + 12));
   PropManager_AttachRaceProp(var1);
   var5 = null;
   var4 = 0;
   while (var4 < *((var0 + 3280) + 132))
   {
       var5 = Opponent_GetRacer((*((var0 + 3280) + 136))[var4]);
       Racer_SetStreamingLockedOut(var5);
       var4 = var4 + 1;
   }
}

void sub_3e4(var0, var1)
{
   auto var4, var5, var6, var7;

   var5 = null;
   var4 = 0;
   while (var4 < *((var0 + 3280) + 132))
   {
       var5 = Opponent_GetRacer((*((var0 + 3280) + 136))[var4]);
       Racer_SetStreamingUnlocked(var5);
       var4 = var4 + 1;
   }
   PropManager_DetachRaceProp(var1);
   mcHudMapServer_AddElement(*((var0 + 3280) + 12));
   SetExceptionMask(2);
   PRINTSTRING("Hangout ");
   PRINTSTRING(*((var0 + 3280) + 0));
   PRINTSTRING(" was un-suspended\n");
}

void sub_525(var0, var1, var2)
{
   auto var5, var6, var7, var8;

   var5 = Form_GetForm(var2);
   Ctrl_SetVisible(Form_ToCtrl(var5), 1);
   PerspectiveForm_SetSlowMotion(var5, var0, 1.0f / var1, 0, 1, 1.0f);
   WAITUNWARPED(FLOOR(var1 * 1000.0f));
}

void sub_6e2(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10;

   var4 = 0;
   while (!var4)
   {
       var4 = 1;
       var3 = 0;
       while (var3 < (*(var0 + 384) - *(var0 + 392)))
       {
           var4 = var4 && CineScript_Characters_LoadType((*(var0 + 1000))[var3], (*(var0 + 1068))[var3]);
           var3 = var3 + 1;
       }
       WAITUNWARPED(100);
       PRINTSTRING("LoadHangoutCharacters : Streaming characters\n");
   }
   var4 = 1;
   var3 = 0;
   while (var3 < (*(var0 + 384) - *(var0 + 392)))
   {
       var4 = var4 && CineScript_Characters_LoadAnimation((*(var0 + 1136))[var3], (*(var0 + 1204))[var3]);
       var3 = var3 + 1;
   }
   var3 = 0;
   while (var3 < (*(var0 + 384) - *(var0 + 392)))
   {
       var9 = CineScript_Characters_LaunchAnimAt((*(var0 + 1000))[var3], (*(var0 + 1068))[var3], (*(var0 + 1136))[var3], (*(var0 + 1204))[var3], &var5, -1);
       CineScript_PushKillBuffer(var9, 0);
       var3 = var3 + 1;
   }
}

void sub_8f2(var0, var1)
{
   auto var4, var5, var6;

   PRINTSTRING("EASE FROM PAUSE YO1\n");
   var4 = Form_GetForm(var0);
   PerspectiveForm_SetSlowMotion(var4, 1.0f, 1.0f / var1, 0, 1, 1.0f);
   Ctrl_SetVisible(Form_ToCtrl(var4), 0);
   PRINTSTRING("EASE FROM PAUSE YO\n");
}

function sub_a03(var0)
{
   auto var3, var4, var5, var6, var7;

   var3 = Form_GetForm(64);
   Form_SetText(var3, *((var0 + 3280) + 0));
   Registry_SetValueString("szEventName", *((var0 + 0) + 3208));
   StringTable_SetInt("DYN_RACES_NEEDED_8", *((var0 + 0) + 3252));
   UILogic_DisableCarInput();
   UILogic_DisableCameraInput();
   var4 = sub_a83(-1, 64, 0, 0, 0);
   if (var4 == 3)
   {
       AudioManager_ExitHangoutState();
       var5 = null;
       var6 = 0;
       var5 = SimpleListForm_GetItem(var3, 0);
       var6 = ComboBoxItem_GetSelectedIndex(var5);
       Warper_Warp("DEFAULT_WITH_CUT");
       WAITUNWARPED(100);
       Form_CloseForm(var3);
       PRINTSTRING("Start Waiting\n");
       while (!Warper_IsReadyToLoadStuff())
       {
           WAITUNWARPED(100);
           PRINTSTRING("Waiting\n");
       }
       sub_bd0(var0 + 3280);
       return sub_bed(var0, var6);
   }
   else
   {
       UILogic_EnableCarInput();
       PRINTSTRING("Player decided to exit hangout\n");
       return 1;
   }
}

function sub_a83(var0, var1, var2, var3, var4)
{
   auto var7, var8, var9, var10, var11, var12, var13, var14, var15;

   var7 = 1;
   var8 = Form_GetForm(var0);
   var9 = Form_GetForm(var1);
   Form_ShowForm(var8, var9);
   if (!StringCompare(var2, ""))
   {
       var10 = mcCareerSpeech_FindScenario(var2);
       if (var10 != null)
       {
           mcCareerSpeech_Stop();
           mcCareerSpeech_PlayScenario(var10, var3, var4);
       }
   }
   while (var7)
   {
       var7 = Form_GetFormVisible(var9);
       WAITUNWARPED(100);
   }
   return Form_GetFormResult(var9);
}

void sub_bd0(var0)
{
   auto var3;

   CineScript_PopKillBuffer(0);
}

function sub_bed(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24;

   var20 = null;
   var22 = null;
   var21 = 0;
   while (var21 < *((var0 + 3280) + 132))
   {
       var22 = Opponent_GetRacer((*((var0 + 3280) + 136))[var21]);
       Racer_SetStreamingLockedOut(var22);
       var21 = var21 + 1;
   }
   *((((var0 + 0) + 0) + 16) + 3080) = 4;
   *((((var0 + 0) + 0) + 16) + 3084) = 3;
   (*((((var0 + 0) + 0) + 16) + 4))[0 * 48].v0 = Player_FindRacerObject(0);
   (*((((var0 + 0) + 0) + 16) + 4))[0 * 48].v2 = 0;
   (*((((var0 + 0) + 0) + 16) + 4))[0 * 48].v5 = 1;
   *((((var0 + 0) + 0) + 16) + 3120) = 0;
   *((((var0 + 0) + 0) + 16) + 3100) = var1;
   var20 = START_NEW_SCRIPT_WITH_ARGS("Game/Race/OrderedSeriesCore", var0 + 0, 820, 1500);
   while (!IsChildFinished(var20))
   {
       WAITUNWARPED(100);
   }
   var21 = 0;
   while (var21 < *((var0 + 3280) + 132))
   {
       var22 = Opponent_GetRacer((*((var0 + 3280) + 136))[var21]);
       Racer_SetStreamingUnlocked(var22);
       var21 = var21 + 1;
   }
   Registry_GetValueString("raceOverCommand", &var4);
   if (StringCompare(&var4, "returnToHangout"))
   {
       return 0;
   }
   else
   {
       return 3;
   }
}

