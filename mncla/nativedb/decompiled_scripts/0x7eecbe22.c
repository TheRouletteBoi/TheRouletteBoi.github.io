void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41;

   var2 = 10;
   var2[0] = "character/Drv_mp_01_set";
   var2[1] = "character/Mec_mc_01_set";
   var2[2] = "character/Drv_ma_03_set";
   var2[3] = "character/Drv_mb_02_set";
   var2[4] = "character/drv_mh_02_set";
   var2[5] = "character/drv_mb_04_set";
   var2[6] = "character/drv_mb_008_set";
   var2[7] = "character/Drv_mb_010_set";
   var2[8] = "character/drv_fc_002_set";
   var2[9] = "character/";
   var13 = 10;
   var13[0] = "Drv_mp_01_set";
   var13[1] = "Mec_mc_01_set";
   var13[2] = "Drv_ma_03_set";
   var13[3] = "Drv_mb_02_set";
   var13[4] = "drv_mh_02_set";
   var13[5] = "drv_mb_04_set";
   var13[6] = "drv_mb_008_set";
   var13[7] = "Drv_mb_010_set";
   var13[8] = "drv_fc_002_set";
   var13[9] = "";
   var24 = "anim/Extras/male";
   var25 = 1;
   var25[0] = "Mped_Idle";
   var27 = "anim/Extras/female";
   var28 = "FPed_Idle";
   var29 = 0;
   var30 = 0;
   while (!var29)
   {
       var29 = 1;
       var30 = 0;
       while (var30 < 9)
       {
           var29 = var29 && CineScript_Characters_LoadType(var2[0 + var30], var13[0 + var30]);
           var30 = var30 + 1;
       }
       WAITUNWARPED(100);
   }
   var30 = 0;
   while (var30 < 1)
   {
       var29 = var29 && CineScript_Characters_LoadAnimation(var24, var25[var30]);
       var30 = var30 + 1;
   }
   var29 = var29 && CineScript_Characters_LoadAnimation(var27, var28);
   if (!var29)
   {
       PRINTSTRING("Script 'test_lineup.sc' failed to load\n");
       BREAKPOINT();
   }
   var35.v0 = 464.8f;
   var35.v1 = 24.0f;
   var35.v2 = -884.1f;
   var38.v0 = 1.0f;
   var38.v1 = 0.0f;
   var38.v2 = 0.0f;
   Math_VecRotateY(&var38, &var38, -140.0f * 0.01745329f);
   var31.v0.v0 = var35.v0;
   var31.v0.v1 = var35.v1;
   var31.v0.v2 = var35.v2;
   var31.v3 = -140.0f;
   var30 = 0;
   while (var30 < 9)
   {
       var41 = CineScript_Characters_LaunchAnimAt(var2[0 + var30], var13[0 + var30], var24, var25[(0 + var30) % 1], &var31, -1);
       var31.v0.v0 = var38.v0 + var31.v0.v0;
       var31.v0.v1 = var38.v1 + var31.v0.v1;
       var31.v0.v2 = var38.v2 + var31.v0.v2;
       CineScript_PushKillBuffer(var41, 0);
       var30 = var30 + 1;
   }
   sub_426(L[0]);
}

void sub_426(var0)
{
   auto var3;

   var0.v0 = 3;
}

