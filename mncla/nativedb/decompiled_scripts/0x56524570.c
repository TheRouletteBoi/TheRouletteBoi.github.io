void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31;

   var2 = 5;
   var2[0] = "character/drv_sc_mh_007_set";
   var2[1] = "character/drv_sc_mh_008_set";
   var2[2] = "character/drv_sc_mb_011_set";
   var2[3] = "character/drv_sc_mb_012_set";
   var2[4] = "character/drv_sc_mb_013_set";
   var8 = 5;
   var8[0] = "drv_sc_mh_007_set";
   var8[1] = "drv_sc_mh_008_set";
   var8[2] = "drv_sc_mb_011_set";
   var8[3] = "drv_sc_mb_012_set";
   var8[4] = "drv_sc_mb_013_set";
   CineScript_Characters_RegisterDriverMappings("drv_sc_mh_007_set", "drv_sc_mh_007_set_h", "character/drv_sc_mh_007_set_h", "drv_sc_mh_007_set_h", "character/drv_sc_mh_007_set_h", "drv_sc_mh_007_set", "character/drv_sc_mh_007_set", "drv_sc_mh_007_set", "character/drv_sc_mh_007_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mh_008_set", "drv_sc_mh_007_set_h", "character/drv_sc_mh_008_set_h", "drv_sc_mh_007_set_h", "character/drv_sc_mh_008_set_h", "drv_sc_mh_007_set", "character/drv_sc_mh_008_set", "drv_sc_mh_007_set", "character/drv_sc_mh_008_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mb_011_set", "drv_sc_mb_011_set_h", "character/drv_sc_mb_011_set_h", "drv_sc_mb_011_set_h", "character/drv_sc_mb_011_set_h", "drv_sc_mb_011_set", "character/drv_sc_mb_011_set", "drv_sc_mb_011_set", "character/drv_sc_mb_011_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mb_012_set", "drv_sc_mb_012_set_h", "character/drv_sc_mb_012_set_h", "drv_sc_mb_012_set_h", "character/drv_sc_mb_012_set_h", "drv_sc_mb_012_set", "character/drv_sc_mb_012_set", "drv_sc_mb_012_set", "character/drv_sc_mb_012_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set");
   CineScript_Characters_RegisterDriverMappings("drv_sc_mb_013_set", "drv_sc_mb_013_set_h", "character/drv_sc_mb_013_set_h", "drv_sc_mb_013_set_h", "character/drv_sc_mb_013_set_h", "drv_sc_mb_013_set", "character/drv_sc_mb_013_set", "drv_sc_mb_013_set", "character/drv_sc_mb_013_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set");
   var14 = "anim/Extras/male";
   var15 = 1;
   var15[0] = "Mped_Idle";
   var17 = "anim/Extras/female";
   var18 = "FPed_Idle";
   var19 = 0;
   var20 = 0;
   while (!var19)
   {
       var19 = 1;
       var20 = 0;
       while (var20 < 4)
       {
           var19 = var19 && CineScript_Characters_LoadType(var2[0 + var20], var8[0 + var20]);
           var20 = var20 + 1;
       }
       WAITUNWARPED(100);
   }
   var20 = 0;
   while (var20 < 1)
   {
       var19 = var19 && CineScript_Characters_LoadAnimation(var14, var15[var20]);
       var20 = var20 + 1;
   }
   var19 = var19 && CineScript_Characters_LoadAnimation(var17, var18);
   if (!var19)
   {
       PRINTSTRING("Script 'test_lineup.sc' failed to load\n");
       BREAKPOINT();
   }
   var25.v0 = 464.8f;
   var25.v1 = 24.0f;
   var25.v2 = -884.1f;
   var28.v0 = 1.0f;
   var28.v1 = 0.0f;
   var28.v2 = 0.0f;
   Math_VecRotateY(&var28, &var28, -140.0f * 0.01745329f);
   var21.v0.v0 = var25.v0;
   var21.v0.v1 = var25.v1;
   var21.v0.v2 = var25.v2;
   var21.v3 = -140.0f;
   var20 = 0;
   while (var20 < 4)
   {
       var31 = CineScript_Characters_LaunchAnimAt(var2[0 + var20], var8[0 + var20], var14, var15[(0 + var20) % 1], &var21, -1);
       var21.v0.v0 = var28.v0 + var21.v0.v0;
       var21.v0.v1 = var28.v1 + var21.v0.v1;
       var21.v0.v2 = var28.v2 + var21.v0.v2;
       CineScript_PushKillBuffer(var31, 0);
       var20 = var20 + 1;
   }
}

