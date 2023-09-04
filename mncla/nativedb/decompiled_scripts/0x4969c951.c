void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40;

   var2 = 10;
   var2[0] = "character/pol_mb_01_set";
   var2[1] = "character/pol_mc_01_set";
   var2[2] = "character/pol_mc_02_set";
   var2[3] = "character/pol_mc_03_set";
   var2[4] = "character/pol_mc_04_set";
   var2[5] = "character/drv_fa_001_set";
   var2[6] = "character/drv_fh_001_set";
   var2[7] = "character/drv_fc_003_set";
   var2[8] = "character/mec_mc_002_set";
   var2[9] = "character/mec_mh_001_set";
   var13 = 10;
   var13[0] = "pol_mb_01_set";
   var13[1] = "pol_mc_01_set";
   var13[2] = "pol_mc_02_set";
   var13[3] = "pol_mc_03_set";
   var13[4] = "pol_mc_04_set";
   var13[5] = "drv_fa_001_set";
   var13[6] = "drv_fh_001_set";
   var13[7] = "drv_fc_003_set";
   var13[8] = "mec_mc_002_set";
   var13[9] = "mec_mh_001_set";
   var24 = "anim/Extras/female";
   var25 = "anim/Extras/male";
   var26 = "Fped_Idle";
   var27 = "Mped_Idle";
   var28 = 0;
   var29 = 0;
   while (!var28)
   {
       var28 = 1;
       var29 = 0;
       while (var29 < 10)
       {
           var28 = var28 && CineScript_Characters_LoadType(var2[0 + var29], var13[0 + var29]);
           var29 = var29 + 1;
       }
       WAITUNWARPED(100);
   }
   var28 = var28 && CineScript_Characters_LoadAnimation(var25, var27);
   var28 = var28 && CineScript_Characters_LoadAnimation(var24, var26);
   if (!var28)
   {
       PRINTSTRING("Script 'test_lineup.sc' failed to load\n");
       BREAKPOINT();
   }
   var34.v0 = 464.8f;
   var34.v1 = 24.0f;
   var34.v2 = -884.1f;
   var37.v0 = 1.0f;
   var37.v1 = 0.0f;
   var37.v2 = 0.0f;
   Math_VecRotateY(&var37, &var37, -140.0f * 0.01745329f);
   var30.v0.v0 = var34.v0;
   var30.v0.v1 = var34.v1;
   var30.v0.v2 = var34.v2;
   var30.v3 = -140.0f;
   var29 = 0;
   while (var29 < 10)
   {
       var40 = 0;
       if (((var29 == 5) || (var29 == 6)) || (var29 == 7))
       {
           var40 = CineScript_Characters_LaunchAnimAt(var2[0 + var29], var13[0 + var29], var24, var26, &var30, -1);
       }
       else
       {
           var40 = CineScript_Characters_LaunchAnimAt(var2[0 + var29], var13[0 + var29], var25, var27, &var30, -1);
       }
       var30.v0.v0 = var37.v0 + var30.v0.v0;
       var30.v0.v1 = var37.v1 + var30.v0.v1;
       var30.v0.v2 = var37.v2 + var30.v0.v2;
       CineScript_PushKillBuffer(var40, 0);
       var29 = var29 + 1;
   }
   sub_45c(L[0]);
}

void sub_45c(var0)
{
   auto var3;

   var0.v0 = 3;
}

