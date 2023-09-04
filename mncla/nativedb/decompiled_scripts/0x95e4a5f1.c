void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63;

   var2 = 21;
   var2[0] = "character/ped_fa_001_set";
   var2[1] = "character/ped_fa_002_set";
   var2[2] = "character/ped_fb_001_set";
   var2[3] = "character/ped_fb_002_set";
   var2[4] = "character/ped_fb_003_set";
   var2[5] = "character/ped_fb_004_set";
   var2[6] = "character/ped_fb_005_set";
   var2[7] = "character/ped_fc_001_set";
   var2[8] = "character/ped_fc_002_set";
   var2[9] = "character/ped_fc_003_set";
   var2[10] = "character/ped_fc_004_set";
   var2[11] = "character/ped_fc_005_set";
   var2[12] = "character/ped_fc_006_set";
   var2[13] = "character/ped_fc_007_set";
   var2[14] = "character/ped_fc_008_set";
   var2[15] = "character/ped_fh_001_set";
   var2[16] = "character/ped_fh_002_set";
   var2[17] = "character/ped_fh_003_set";
   var2[18] = "character/ped_fh_004_set";
   var2[19] = "character/ped_fh_005_set";
   var2[20] = "character/ped_fh_006_set";
   var24 = 21;
   var24[0] = "ped_fa_001_set";
   var24[1] = "ped_fa_002_set";
   var24[2] = "ped_fb_001_set";
   var24[3] = "ped_fb_002_set";
   var24[4] = "ped_fb_003_set";
   var24[5] = "ped_fb_004_set";
   var24[6] = "ped_fb_005_set";
   var24[7] = "ped_fc_001_set";
   var24[8] = "ped_fc_002_set";
   var24[9] = "ped_fc_003_set";
   var24[10] = "ped_fc_004_set";
   var24[11] = "ped_fc_005_set";
   var24[12] = "ped_fc_006_set";
   var24[13] = "ped_fc_007_set";
   var24[14] = "ped_fc_008_set";
   var24[15] = "ped_fh_001_set";
   var24[16] = "ped_fh_002_set";
   var24[17] = "ped_fh_003_set";
   var24[18] = "ped_fh_004_set";
   var24[19] = "ped_fh_005_set";
   var24[20] = "ped_fh_006_set";
   var46 = "anim/Extras/male";
   var47 = 1;
   var47[0] = "Mped_Idle";
   var49 = "anim/Extras/female";
   var50 = "FPed_Idle";
   var51 = 0;
   var52 = 0;
   while (!var51)
   {
       var51 = 1;
       var52 = 0;
       while (var52 < 21)
       {
           var51 = var51 && CineScript_Characters_LoadType(var2[0 + var52], var24[0 + var52]);
           var52 = var52 + 1;
       }
       WAITUNWARPED(100);
   }
   var52 = 0;
   while (var52 < 1)
   {
       var51 = var51 && CineScript_Characters_LoadAnimation(var46, var47[var52]);
       var52 = var52 + 1;
   }
   var51 = var51 && CineScript_Characters_LoadAnimation(var49, var50);
   if (!var51)
   {
       PRINTSTRING("Script 'test_lineup.sc' failed to load\n");
       BREAKPOINT();
   }
   var57.v0 = 464.8f;
   var57.v1 = 24.0f;
   var57.v2 = -884.1f;
   var60.v0 = 1.0f;
   var60.v1 = 0.0f;
   var60.v2 = 0.0f;
   Math_VecRotateY(&var60, &var60, -140.0f * 0.01745329f);
   var53.v0.v0 = var57.v0;
   var53.v0.v1 = var57.v1;
   var53.v0.v2 = var57.v2;
   var53.v3 = -140.0f;
   var52 = 0;
   while (var52 < 21)
   {
       var63 = CineScript_Characters_LaunchAnimAt(var2[0 + var52], var24[0 + var52], var46, var47[(0 + var52) % 1], &var53, -1);
       var53.v0.v0 = var60.v0 + var53.v0.v0;
       var53.v0.v1 = var60.v1 + var53.v0.v1;
       var53.v0.v2 = var60.v2 + var53.v0.v2;
       CineScript_PushKillBuffer(var63, 0);
       var52 = var52 + 1;
   }
   sub_705(L[0]);
}

void sub_705(var0)
{
   auto var3;

   var0.v0 = 3;
}

