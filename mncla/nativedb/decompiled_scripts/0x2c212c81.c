void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43;

   var2 = 11;
   var2[0] = "character/ped_fh_001_set";
   var2[1] = "character/ped_ma_001_set";
   var2[2] = "character/ped_mb_001_set";
   var2[3] = "character/ped_mc_001_set";
   var2[4] = "character/ped_mc_002_set";
   var2[5] = "character/ped_mc_003_set";
   var2[6] = "character/ped_mc_004_set";
   var2[7] = "character/ped_mc_005_set";
   var2[8] = "character/ped_mh_001_set";
   var2[9] = "character/ped_fb_001_set";
   var2[10] = "character/ped_fc_001_set";
   var14 = 11;
   var14[0] = "ped_fh_001_set";
   var14[1] = "ped_ma_001_set";
   var14[2] = "ped_mb_001_set";
   var14[3] = "ped_mc_001_set";
   var14[4] = "ped_mc_002_set";
   var14[5] = "ped_mc_003_set";
   var14[6] = "ped_mc_004_set";
   var14[7] = "ped_mc_005_set";
   var14[8] = "ped_mh_001_set";
   var14[9] = "ped_fb_001_set";
   var14[10] = "ped_fc_001_set";
   var26 = "anim";
   var27 = 4;
   var27[0] = "Ped_male_Idle";
   var27[1] = "Ped_male_Idle2";
   var27[2] = "Ped_male_Idle3";
   var27[3] = "Ped_male_Idle4";
   var32 = 0;
   var33 = 0;
   while (!var32)
   {
       var32 = 1;
       var33 = 0;
       while (var33 < 11)
       {
           var32 = var32 && CineScript_Characters_LoadType(var2[0 + var33], var14[0 + var33]);
           var33 = var33 + 1;
       }
       WAITUNWARPED(100);
   }
   var33 = 0;
   while (var33 < 4)
   {
       var32 = var32 && CineScript_Characters_LoadAnimation(var26, var27[var33]);
       var33 = var33 + 1;
   }
   if (!var32)
   {
       PRINTSTRING("Script 'test_peds.sc' failed to load\n");
       BREAKPOINT();
   }
   var38.v0 = 464.8f;
   var38.v1 = 24.0f;
   var38.v2 = -884.1f;
   var34.v0.v0 = var38.v0;
   var34.v0.v1 = var38.v1;
   var34.v0.v2 = var38.v2;
   var34.v3 = 0.0f;
   var33 = 0;
   while (var33 < 11)
   {
       var42 = 1;
       var41 = 0;
       while (var41 < var42)
       {
           var43 = CineScript_Characters_LaunchAnimAt(var2[0 + var33], var14[0 + var33], var26, var27[(0 + var33) % 4], &var34, -1);
           var34.v0.v2 = var34.v0.v2 + 1.0f;
           var41 = var41 + 1;
       }
       var34.v0.v2 = var34.v0.v2 - ((float)var42);
       var34.v0.v0 = var34.v0.v0 + 1.0f;
       CineScript_PushKillBuffer(var43, 0);
       var33 = var33 + 1;
   }
   sub_4f5(L[0]);
}

void sub_4f5(var0)
{
   auto var3;

   var0.v0 = 3;
}

