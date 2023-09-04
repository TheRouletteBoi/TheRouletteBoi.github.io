void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51;

   var2 = 16;
   var2[0] = "character/ped_mb_002_set";
   var2[1] = "character/ped_mc_001_set";
   var2[2] = "character/ped_mc_002_set";
   var2[3] = "character/ped_mc_003_set";
   var2[4] = "character/ped_mc_004_set";
   var2[5] = "character/ped_mc_005_set";
   var2[6] = "character/ped_mh_001_set";
   var2[7] = "character/ped_mh_002_set";
   var2[8] = "character/ped_fa_002_set";
   var2[9] = "character/ped_fb_004_set";
   var2[10] = "character/ped_fb_005_set";
   var2[11] = "character/ped_fc_008_set";
   var2[12] = "character/ped_fh_004_set";
   var2[13] = "character/ped_fh_005_set";
   var2[14] = "character/ped_fh_006_set";
   var2[15] = "character/ped_mc_008_set";
   var19 = 16;
   var19[0] = "ped_mb_002_set";
   var19[1] = "ped_mc_001_set";
   var19[2] = "ped_mc_002_set";
   var19[3] = "ped_mc_003_set";
   var19[4] = "ped_mc_004_set";
   var19[5] = "ped_mc_005_set";
   var19[6] = "ped_mh_001_set";
   var19[7] = "ped_mh_002_set";
   var19[8] = "ped_fa_002_set";
   var19[9] = "ped_fb_004_set";
   var19[10] = "ped_fb_005_set";
   var19[11] = "ped_fc_008_set";
   var19[12] = "ped_fh_004_set";
   var19[13] = "ped_fh_005_set";
   var19[14] = "ped_fh_006_set";
   var19[15] = "ped_mc_008_set";
   var36 = "anim/Extras/male";
   var37 = 1;
   var37[0] = "Mped_Idle";
   var39 = 0;
   var40 = 0;
   while (!var39)
   {
       var39 = 1;
       var40 = 0;
       while (var40 < 16)
       {
           var39 = var39 && CineScript_Characters_LoadType(var2[0 + var40], var19[0 + var40]);
           var40 = var40 + 1;
       }
       WAITUNWARPED(100);
   }
   var40 = 0;
   while (var40 < 1)
   {
       var39 = var39 && CineScript_Characters_LoadAnimation(var36, var37[var40]);
       var40 = var40 + 1;
   }
   if (!var39)
   {
       PRINTSTRING("Script 'test_lineup5.sc' failed to load\n");
       BREAKPOINT();
   }
   var45.v0 = 464.8f;
   var45.v1 = 24.0f;
   var45.v2 = -884.1f;
   var48.v0 = 1.0f;
   var48.v1 = 0.0f;
   var48.v2 = 0.0f;
   Math_VecRotateY(&var48, &var48, -140.0f * 0.01745329f);
   var41.v0.v0 = var45.v0;
   var41.v0.v1 = var45.v1;
   var41.v0.v2 = var45.v2;
   var41.v3 = -140.0f;
   var40 = 0;
   while (var40 < 16)
   {
       var51 = CineScript_Characters_LaunchAnimAt(var2[0 + var40], var19[0 + var40], var36, var37[(0 + var40) % 1], &var41, -1);
       var41.v0.v0 = var48.v0 + var41.v0.v0;
       var41.v0.v1 = var48.v1 + var41.v0.v1;
       var41.v0.v2 = var48.v2 + var41.v0.v2;
       CineScript_PushKillBuffer(var51, 0);
       var40 = var40 + 1;
   }
   sub_5ac(L[0]);
}

void sub_5ac(var0)
{
   auto var3;

   var0.v0 = 3;
}

