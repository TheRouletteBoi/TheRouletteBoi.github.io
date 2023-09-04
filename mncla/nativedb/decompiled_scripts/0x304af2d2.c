void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53;

   var2 = 16;
   var2[0] = "character/drv_mp_01_set_h";
   var2[1] = "character/drv_ma_03_set_h";
   var2[2] = "character/drv_mb_001_set_h";
   var2[3] = "character/drv_mb_009_set_h";
   var2[4] = "character/drv_mc_001_set_h";
   var2[5] = "character/drv_mc_07_set_h";
   var2[6] = "character/drv_mh_005_set_h";
   var2[7] = "character/drv_fh_001_set_h";
   var2[8] = "character/drv_mp_01_lod02_set";
   var2[9] = "character/drv_ma_03_lod02_set";
   var2[10] = "character/drv_mb_001_lod02_set";
   var2[11] = "character/drv_mb_009_lod02_set";
   var2[12] = "character/drv_mc_001_lod02_set";
   var2[13] = "character/drv_mc_07_lod02_set";
   var2[14] = "character/drv_mh_005_lod02_set";
   var2[15] = "character/drv_fh_001_lod02_set";
   var19 = 16;
   var19[0] = "drv_mp_01_set_h";
   var19[1] = "drv_ma_03_set_h";
   var19[2] = "drv_mb_001_set_h";
   var19[3] = "drv_mb_009_set_h";
   var19[4] = "drv_mc_001_set_h";
   var19[5] = "drv_mc_07_set_h";
   var19[6] = "drv_mh_005_set_h";
   var19[7] = "drv_fh_001_set_h";
   var19[8] = "drv_mp_01_lod02_set";
   var19[9] = "drv_ma_03_lod02_set";
   var19[10] = "drv_mb_001_lod02_set";
   var19[11] = "drv_mb_009_lod02_set";
   var19[12] = "drv_mc_001_lod02_set";
   var19[13] = "drv_mc_07_lod02_set";
   var19[14] = "drv_mh_005_lod02_set";
   var19[15] = "drv_fh_001_lod02_set";
   var36 = "anim/Extras/male";
   var37 = 1;
   var37[0] = "Mped_Idle";
   var39 = "anim/Extras/female";
   var40 = "FPed_Idle";
   var41 = 0;
   var42 = 0;
   while (!var41)
   {
       var41 = 1;
       var42 = 0;
       while (var42 < 16)
       {
           var41 = var41 && CineScript_Characters_LoadType(var2[0 + var42], var19[0 + var42]);
           var42 = var42 + 1;
       }
       WAITUNWARPED(100);
   }
   var42 = 0;
   while (var42 < 1)
   {
       var41 = var41 && CineScript_Characters_LoadAnimation(var36, var37[var42]);
       var42 = var42 + 1;
   }
   var41 = var41 && CineScript_Characters_LoadAnimation(var39, var40);
   if (!var41)
   {
       PRINTSTRING("Script 'test_lineup1.sc' failed to load\n");
       BREAKPOINT();
   }
   var47.v0 = 464.8f;
   var47.v1 = 24.0f;
   var47.v2 = -884.1f;
   var50.v0 = 1.0f;
   var50.v1 = 0.0f;
   var50.v2 = 0.0f;
   Math_VecRotateY(&var50, &var50, -140.0f * 0.01745329f);
   var43.v0.v0 = var47.v0;
   var43.v0.v1 = var47.v1;
   var43.v0.v2 = var47.v2;
   var43.v3 = -140.0f;
   var42 = 0;
   while (var42 < 16)
   {
       var53 = CineScript_Characters_LaunchAnimAt(var2[0 + var42], var19[0 + var42], var36, var37[(0 + var42) % 1], &var43, -1);
       var43.v0.v0 = var50.v0 + var43.v0.v0;
       var43.v0.v1 = var50.v1 + var43.v0.v1;
       var43.v0.v2 = var50.v2 + var43.v0.v2;
       CineScript_PushKillBuffer(var53, 0);
       var42 = var42 + 1;
   }
   sub_667(L[0]);
}

void sub_667(var0)
{
   auto var3;

   var0.v0 = 3;
}

