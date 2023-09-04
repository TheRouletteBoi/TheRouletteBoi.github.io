void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39;

   var2 = 10;
   var2[0] = "character/ped_fb_001_set";
   var2[1] = "character/ped_fc_001_set";
   var2[2] = "character/ped_fc_002_set";
   var2[3] = "character/ped_fc_003_set";
   var2[4] = "character/ped_fc_004_set";
   var2[5] = "character/ped_fc_005_set";
   var2[6] = "character/ped_fh_001_set";
   var2[7] = "character/ped_ma_001_set";
   var2[8] = "character/ped_ma_002_set";
   var2[9] = "character/ped_mb_001_set";
   var13 = 10;
   var13[0] = "ped_fb_001_set";
   var13[1] = "ped_fc_001_set";
   var13[2] = "ped_fc_002_set";
   var13[3] = "ped_fc_003_set";
   var13[4] = "ped_fc_004_set";
   var13[5] = "ped_fc_005_set";
   var13[6] = "ped_fh_001_set";
   var13[7] = "ped_ma_001_set";
   var13[8] = "ped_ma_002_set";
   var13[9] = "ped_mb_001_set";
   var24 = "anim/Extras/male";
   var25 = 1;
   var25[0] = "Mped_Idle";
   var27 = 0;
   var28 = 0;
   while (!var27)
   {
       var27 = 1;
       var28 = 0;
       while (var28 < 10)
       {
           var27 = var27 && CineScript_Characters_LoadType(var2[0 + var28], var13[0 + var28]);
           var28 = var28 + 1;
       }
       WAITUNWARPED(100);
   }
   var28 = 0;
   while (var28 < 1)
   {
       var27 = var27 && CineScript_Characters_LoadAnimation(var24, var25[var28]);
       var28 = var28 + 1;
   }
   if (!var27)
   {
       PRINTSTRING("Script 'test_lineup.sc' failed to load\n");
       BREAKPOINT();
   }
   var33.v0 = 464.8f;
   var33.v1 = 24.0f;
   var33.v2 = -884.1f;
   var36.v0 = 1.0f;
   var36.v1 = 0.0f;
   var36.v2 = 0.0f;
   Math_VecRotateY(&var36, &var36, -140.0f * 0.01745329f);
   var29.v0.v0 = var33.v0;
   var29.v0.v1 = var33.v1;
   var29.v0.v2 = var33.v2;
   var29.v3 = -140.0f;
   var28 = 0;
   while (var28 < 10)
   {
       var39 = CineScript_Characters_LaunchAnimAt(var2[0 + var28], var13[0 + var28], var24, var25[(0 + var28) % 1], &var29, -1);
       var29.v0.v0 = var36.v0 + var29.v0.v0;
       var29.v0.v1 = var36.v1 + var29.v0.v1;
       var29.v0.v2 = var36.v2 + var29.v0.v2;
       CineScript_PushKillBuffer(var39, 0);
       var28 = var28 + 1;
   }
   sub_413(L[0]);
}

void sub_413(var0)
{
   auto var3;

   var0.v0 = 3;
}

