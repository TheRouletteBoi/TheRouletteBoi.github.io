﻿void main()
{
   auto var2, var3, var4, var5, var6, var7;

   var2 = Form_GetForm(-1);
   var3 = Form_GetForm(70);
   var4 = UIManager_FindMovie("HUDMOVIE");
   var5 = 0;
   WAITUNWARPED(100);
   Warper_Warp("EXIT_TO_COUNTDOWN");
   PRINTSTRING("Waiting for Warp to complete\n");
   while (Warper_IsWarping())
   {
       WAITUNWARPED(100);
       PRINTSTRING("Waiting\n");
   }
   PRINTSTRING("Warp is complete\n");
   sub_d2(1, 1, 0x3f800000, 0);
   var6 = Race_GetCurrentRace();
   UIManager_SendEventTo("countDown", "startCountdown");
   SetExceptionMask(3);
   var7 = ;
   switch (var7)
   {
       case 0:
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
           PRINTSTRING("restart race exception\n");
           break;
       }
       case 3:
       {
           PRINTSTRING("SCRIPT: generic_countdown: Handling NetworkTermination exception\n");
           if (var5)
           {
               PRINTSTRING("SCRIPT: generic_countdown: cancelling 321Go movie\n");
               sub_543(var4);
           }
           break;
       }
       default:
       {
           PRINTSTRING("Unhandled exception\n");
           WAIT(100);
           Form_ShowForm(var2, var3);
           Racer_SetScrambleInputFlags(Player_FindRacerObject(0), 2);
           PRINTSTRING("SCRIPT: Waiting to start countdown\n");
           Race_EnableRaceTimer(var6, 0);
           while (!Race_IsReadyForCountdown(var6, 5.0f))
           {
               PRINTSTRING("SCRIPT: Not ready to count down yet\n");
               WAITUNPAUSED(10);
           }
           PRINTSTRING("SCRIPT: Ready to start countdown\n");
           Form_CloseForm(var3);
           PRINTSTRING("Starting Countdown\n");
           Race_EnableRaceTimer(var6, 1);
           Race_SetTimer(var6, -3000);
           sub_703(var4);
           var5 = 1;
           PRINTSTRING("SCRIPT: Countdown 3 (RaceTimer=");
           PRINTINT(Race_GetTimer(var6));
           PRINTSTRING(" NetSyncedTime=");
           PRINTFLOAT(Net_GetSyncedTime());
           PRINTSTRING(")\n");
           AudioManager_PlayFrontendSound("HUD_CNTDWN_3_MASTER");
           while (Race_GetTimer(var6) < -2050)
           {
               WAITUNWARPED(10);
           }
           PRINTSTRING("SCRIPT: Countdown 2 (RaceTimer=");
           PRINTINT(Race_GetTimer(var6));
           PRINTSTRING(" NetSyncedTime=");
           PRINTFLOAT(Net_GetSyncedTime());
           PRINTSTRING(")\n");
           AudioManager_PlayFrontendSound("HUD_CNTDWN_2_MASTER");
           while (Race_GetTimer(var6) < -1050)
           {
               WAITUNWARPED(10);
           }
           PRINTSTRING("SCRIPT: Countdown 1 (RaceTimer=");
           PRINTINT(Race_GetTimer(var6));
           PRINTSTRING(" NetSyncedTime=");
           PRINTFLOAT(Net_GetSyncedTime());
           PRINTSTRING(")\n");
           AudioManager_PlayFrontendSound("HUD_CNTDWN_1_MASTER");
           while (Race_GetTimer(var6) < -50)
           {
               WAITUNWARPED(10);
           }
           PRINTSTRING("SCRIPT: Countdown Go! (RaceTimer=");
           PRINTINT(Race_GetTimer(var6));
           PRINTSTRING(" NetSyncedTime=");
           PRINTFLOAT(Net_GetSyncedTime());
           PRINTSTRING(")\n");
           AudioManager_PlayFrontendSound("HUD_CNTDWN_GO_MASTER");
           break;
       }
   }
   Racer_SetScrambleInputFlags(Player_FindRacerObject(0), 0);
   UIManager_SendEventTo("countDown", "stopCountdown");
   PRINTSTRING("SCRIPT: generic_countdown finished\n");
}

void sub_d2(var0, var1, var2, var3)
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

void sub_543(var0)
{
   auto var3;

   FlashHelper_SetGlobalIntArray(var0, "SplashVisibles", 3, 0);
   FlashHelper_SetGlobalInt(var0, "countdownCount", 0);
   FlashHelper_SetGlobalInt(var0, "countdownTimer", 0);
   FlashHelper_SetGlobalInt(var0, "countdownFrame", 9);
}

void sub_703(var0)
{
   auto var3;

   FlashHelper_SetGlobalIntArray(var0, "SplashVisibles", 3, 1);
}

