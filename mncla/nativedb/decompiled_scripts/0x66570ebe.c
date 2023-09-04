void main()
{
   auto var2, var3;

   L[0] = "drv_mp_01_set";
   L[1] = "drv_mp_01_lod02_set";
   L[2] = "drv_ma_03_set";
   L[3] = "drv_ma_02_set";
   L[4] = "drv_ma_001_set";
   L[5] = "drv_fa_001_set";
   L[6] = "drv_mb_02_set";
   L[7] = "drv_mb_03_set";
   L[8] = "drv_mb_04_set";
   L[9] = "drv_mb_05_set";
   L[10] = "drv_mb_007_set";
   L[11] = "drv_mb_008_set";
   L[12] = "drv_mb_010_set";
   L[13] = "drv_mb_001_set";
   L[14] = "drv_mb_009_set";
   L[15] = "drv_mb_06_set";
   L[16] = "drv_fb_01_set";
   L[17] = "drv_mc_02_set";
   L[18] = "drv_mc_06_set";
   L[19] = "drv_mc_07_set";
   L[20] = "drv_mc_003_set";
   L[21] = "drv_mc_05_set";
   L[22] = "drv_mc_001_set";
   L[23] = "drv_fc_002_set";
   L[24] = "drv_mh_01_set";
   L[25] = "drv_mh_02_set";
   L[26] = "drv_mh_003_set";
   L[27] = "drv_mh_005_set";
   L[28] = "drv_mh_04_set";
   L[29] = "drv_mh_006_set";
   L[30] = "drv_fh_001_set";
   L[31] = "mec_mc_01_set";
   L[32] = "ped_ma_001_set";
   L[33] = "ped_mb_001_set";
   L[34] = "ped_mc_001_set";
   L[35] = "ped_mh_001_set";
   L[36] = "pol_mc_01_set";
   var2 = Race_GetCurrentRace();
   UIManager_SendEventTo("countDown", "startCountdown");
   Race_SetTimer(var2, -3000);
   Race_EnableRaceTimer(var2, 0);
   PRINTSTRING(L[37].v799);
   sub_34a(L[37].v799, &L[37]);
   var3 = UIManager_FindMovie("HUDMOVIE");
   sub_529(var3);
   AudioManager_PlayFrontendSound("HUD_CNTDWN_GO_MASTER");
   Race_SetTimer(var2, 0);
   Race_EnableRaceTimer(var2, 1);
   UIManager_SendEventTo("countDown", "stopCountdown");
   PRINTSTRING("Countdown script finished\n");
}

function sub_34a(var0, var1)
{
   auto var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15;

   var4 = 2.0f;
   CineScript_Characters_AssignNameToSlot(L[0], 0);
   CineScript_Characters_AssignNameToSlot("drv_mp_01_set", 1);
   var0 = "game/cinescripts/generated/RaceStart/cut_racestarter01_generated";
   if (!StringCompare(var0, ""))
   {
       var11 = Player_FindRacerObject(0);
       Racer_GetPosition(var11, &(var5.v2.v0));
       var5.v2.v3 = Racer_GetAngleY(var11);
       CineScript_SetGameCoordSysBinding(&var5);
       var13 = START_NEW_SCRIPT_WITH_ARGS(var0, &var12, 1, 0);
       while (!CineScript_IsScenePlaying())
       {
           WAIT(10);
       }
       while (CineScript_Camera_GetTimeRemaining() > (3.0f + var4))
       {
           WAIT(10);
       }
       AudioManager_PlayFrontendSound("HUD_CNTDWN_3_MASTER");
       while (CineScript_Camera_GetTimeRemaining() > (2.0f + var4))
       {
           WAIT(10);
       }
       AudioManager_PlayFrontendSound("HUD_CNTDWN_2_MASTER");
       while (CineScript_Camera_GetTimeRemaining() > (1.0f + var4))
       {
           WAIT(10);
       }
       AudioManager_PlayFrontendSound("HUD_CNTDWN_1_MASTER");
       while (CineScript_Camera_GetTimeRemaining() > var4)
       {
           WAIT(10);
       }
   }
   return 1;
}

void sub_529(var0)
{
   auto var3;

   FlashHelper_SetGlobalIntArray(var0, "SplashVisibles", 3, 2);
}

