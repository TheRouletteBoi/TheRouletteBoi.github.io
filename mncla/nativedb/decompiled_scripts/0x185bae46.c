void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34;

   CineScript_Characters_AssignNameToSlot("drv_mp_01_set", 0);
   CineScript_Characters_AssignNameToSlot("Ped_fb_001_set", 1);
   CineScript_Characters_AssignNameToSlot("Ped_mc_001_set", 2);
   CineScript_Characters_AssignNameToSlot("Ped_fc_001_set", 3);
   CineScript_Characters_AssignNameToSlot("Ped_mc_004_set", 4);
   CineScript_Characters_AssignNameToSlot("Ped_fc_002_set", 5);
   CineScript_Characters_AssignNameToSlot("Ped_mc_005_set", 6);
   CineScript_Characters_AssignNameToSlot("Ped_fc_003_set", 7);
   CineScript_Characters_AssignNameToSlot("Ped_mh_001_set", 8);
   CineScript_Characters_AssignNameToSlot("Ped_fh_001_set", 9);
   CineScript_Characters_AssignNameToSlot("Ped_ma_001_set", 10);
   CineScript_Characters_AssignNameToSlot("Ped_mb_001_set", 11);
   CineScript_Characters_AssignNameToSlot("Ped_mh_002_set", 12);
   var2 = Player_FindRacerObject(0);
   Racer_GetPosition(var2, &var3);
   Racer_ResetWithDamageIntact(var2);
   Racer_Deactivate(var2);
   var12 = 4;
   var17 = 4;
   var22 = 1000;
   var23.v0 = var6.v0;
   var23.v1 = var6.v1;
   var23.v2 = var6.v2;
   var23.v3 = var6.v3;
   var23.v4 = var6.v4;
   var23.v5 = var6.v5;
   var29 = 0;
   while (var29 < 4)
   {
       var17[var29] = var22 + CineScript_Cars_GenerateId();
       var30 = 0;
       var31 = GetOpponentCarCommandLine(&var30, var29);
       if (var30 == 0)
       {
           var31 = "vp_chv_corvettez06_07";
       }
       var23.v2.v0.v2 = var23.v2.v0.v2 - 10.0f;
       sub_20f(&(var12[var29]), var17[var29], var31, &var23);
       Racer_SetVehicleDriverEnable(Opponent_GetRacer(var12[var29]), 0);
       var29 = var29 + 1;
   }
   var32 = "Game/CineScripts/generated/story/cut_story_hollywood_garage_intro_generated";
   PRINTSTRING("/\\/\\/\\/\\/ generic launcher.\n");
   PRINTSTRING("Launching ");
   PRINTSTRING(var32);
   PRINTNL();
   while (1)
   {
       var29 = 0;
       while (var29 < 4)
       {
           CineScript_Cars_AssignIdToSlot(var17[var29], var29);
           var29 = var29 + 1;
       }
       CineScript_SetGameCoordSysBinding(&var6);
       var34 = START_NEW_SCRIPT_WITH_ARGS(var32, &var33, 1, 0);
       while (!IsChildFinished(var34))
       {
           WAIT(10);
       }
       WAIT(5000);
       sub_3b4(1, 1, 0x3f800000, 0);
       Warper_TerminateWarp();
       WAIT(1000);
   }
   var29 = 0;
   while (var29 < 4)
   {
       sub_708(&(var12[var29]));
       var29 = var29 + 1;
   }
}

void sub_20f(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10;

   *var0 = OpponentManager_CreateOpponent();
   OpponentManager_LoadOpponent(*(var0), var2, (var3 + 8) + 0, *((var3 + 8) + 12));
   OpponentManager_AddOpponentToWorld(*(var0));
   var6 = Opponent_GetRacer(*(var0));
   Racer_SetStreamingLockedIn(var6);
   Racer_SetUID(var6, var1);
}

void sub_3b4(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = null;
   while (var6 == null)
   {
       var6 = UIManager_FindMovie("TRANSITIONMOVIE");
       if (var6 == null)
       {
           WAITUNWARPED(10);
       }
   }
   var7 = 0;
   var8 = 0;
   var9 = 0;
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
   FlashHelper_GetGlobalInt(var6, "TransitionOutisReady", &var9);
   PRINTSTRING("FADE UP REPORT\n");
   PRINTSTRING("==============\n");
   PRINTSTRING("TransitionOut: ");
   PRINTINT(var7);
   PRINTSTRING("\nTransitionIn: ");
   PRINTINT(var8);
   PRINTSTRING("\nnTransitionReady: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var7 == 0) && ((var8 != 0) || (var9 != 0)))
   {
       FlashHelper_SetMovieEnabled(var6, 1);
       FlashHelper_SetGlobalInt(var6, "cur_visibility", 1);
       FlashHelper_SetGlobalInt(var6, "mask_color", var3);
       if (var1)
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 0);
       }
       else
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 1);
       }
       FlashHelper_SetGlobalFloat(var6, "fade_speed_in", 0.01f);
       FlashHelper_SetGlobalFloat(var6, "fade_speed_out", var2);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionin", 0);
       FlashHelper_SetGlobalInt(var6, "TransitionOutisReady", 2);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionout", 1);
       if (var0)
       {
           var7 = 1;
           while (var7 == 1)
           {
               FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
               if (var7 == 1)
               {
                   PRINTSTRING("SCRIPT: waiting for transition movie transition up...\n");
                   WAITUNWARPED(10);
               }
           }
       }
   }
}

void sub_708(var0)
{
   auto var3;

   OpponentManager_RemoveOpponentFromWorld(*(var0));
   OpponentManager_DeleteOpponent(*(var0));
}

