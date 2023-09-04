void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55;

   var2 = 17;
   var2[0] = "character/Drv_mp_01_set";
   var2[1] = "character/Drv_mp_01_lod02_set";
   var2[2] = "character/Mec_mc_01_set";
   var2[3] = "character/Mec_mc_01_lod02_set";
   var2[4] = "character/Drv_ma_03_set";
   var2[5] = "character/Drv_ma_03_lod02_set";
   var2[6] = "character/Drv_mb_02_set";
   var2[7] = "character/drv_mb_02_lod02_set";
   var2[8] = "character/drv_mh_02_set";
   var2[9] = "character/drv_mh_02_lod02_set";
   var2[10] = "character/drv_mb_04_set";
   var2[11] = "character/drv_mb_04_lod02_set";
   var2[12] = "character/drv_mb_008_set";
   var2[13] = "character/drv_mb_008_lod02_set";
   var2[14] = "character/Drv_mb_010_set";
   var2[15] = "character/drv_mb_010_lod02_set";
   var2[16] = "character/drv_fc_002_set";
   var20 = 17;
   var20[0] = "Drv_mp_01_set";
   var20[1] = "Drv_mp_01_lod02_set";
   var20[2] = "Mec_mc_01_set";
   var20[3] = "Mec_mc_01_lod02_set";
   var20[4] = "Drv_ma_03_set";
   var20[5] = "Drv_ma_03_lod02_set";
   var20[6] = "Drv_mb_02_set";
   var20[7] = "drv_mb_02_lod02_set";
   var20[8] = "drv_mh_02_set";
   var20[9] = "drv_mh_02_lod02_set";
   var20[10] = "drv_mb_04_set";
   var20[11] = "drv_mb_04_lod02_set";
   var20[12] = "drv_mb_008_set";
   var20[13] = "drv_mb_008_lod02_set";
   var20[14] = "Drv_mb_010_set";
   var20[15] = "drv_mb_010_lod02_set";
   var20[16] = "drv_fc_002_set";
   var38 = "anim/Extras/male";
   var39 = 1;
   var39[0] = "Mped_Idle";
   var41 = "anim/Extras/female";
   var42 = "FPed_Idle";
   var43 = 0;
   var44 = 0;
   while (!var43)
   {
       var43 = 1;
       var44 = 0;
       while (var44 < 17)
       {
           var43 = var43 && CineScript_Characters_LoadType(var2[0 + var44], var20[0 + var44]);
           var44 = var44 + 1;
       }
       WAITUNWARPED(100);
   }
   var44 = 0;
   while (var44 < 1)
   {
       var43 = var43 && CineScript_Characters_LoadAnimation(var38, var39[var44]);
       var44 = var44 + 1;
   }
   var43 = var43 && CineScript_Characters_LoadAnimation(var41, var42);
   if (!var43)
   {
       PRINTSTRING("Script 'test_lineup.sc' failed to load\n");
       BREAKPOINT();
   }
   var49.v0 = 464.8f;
   var49.v1 = 24.0f;
   var49.v2 = -884.1f;
   var52.v0 = 1.0f;
   var52.v1 = 0.0f;
   var52.v2 = 0.0f;
   Math_VecRotateY(&var52, &var52, -140.0f * 0.01745329f);
   var45.v0.v0 = var49.v0;
   var45.v0.v1 = var49.v1;
   var45.v0.v2 = var49.v2;
   var45.v3 = -140.0f;
   var44 = 0;
   while (var44 < 17)
   {
       var55 = CineScript_Characters_LaunchAnimAt(var2[0 + var44], var20[0 + var44], var38, var39[(0 + var44) % 1], &var45, -1);
       var45.v0.v0 = var52.v0 + var45.v0.v0;
       var45.v0.v1 = var52.v1 + var45.v0.v1;
       var45.v0.v2 = var52.v2 + var45.v0.v2;
       CineScript_PushKillBuffer(var55, 0);
       var44 = var44 + 1;
   }
   sub_671(L[0]);
}

void sub_671(var0)
{
   auto var3;

   var0.v0 = 3;
}

