void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42;

   var2 = 10;
   var2[0] = "character/drv_mp_01_set";
   var2[1] = "character/drv_mp_01_set.bak";
   var2[2] = "character/";
   var2[3] = "character/";
   var2[4] = "character/";
   var2[5] = "character/";
   var2[6] = "character/";
   var2[7] = "character/";
   var2[8] = "character/";
   var13 = 10;
   var13[0] = "drv_mp_01_set";
   var13[1] = "drv_mp_01_set";
   var13[2] = "";
   var13[3] = "";
   var13[4] = "";
   var13[5] = "";
   var13[6] = "";
   var13[7] = "";
   var13[8] = "";
   var24 = "anim/test";
   var25 = 1;
   var25[0] = "rb_ray_1_body";
   var27 = 1;
   var27[0] = "rb_ray_1_head";
   var29 = "IM_RIG_FACIAL_TEST";
   while (1)
   {
       var30 = 0;
       var31 = 0;
       while (!var30)
       {
           var30 = 1;
           var31 = 0;
           while (var31 < 1)
           {
               var30 = var30 && CineScript_Characters_LoadType(var2[0 + var31], var13[0 + var31]);
               var30 = var30 && CineScript_Audio_PrepareStream(var29);
               var31 = var31 + 1;
           }
           WAITUNWARPED(100);
       }
       var31 = 0;
       while (var31 < 1)
       {
           var30 = var30 && CineScript_Characters_LoadAnimation(var24, var25[var31]);
           var31 = var31 + 1;
       }
       var31 = 0;
       while (var31 < 1)
       {
           var30 = var30 && CineScript_Characters_LoadAnimation(var24, var27[var31]);
           var31 = var31 + 1;
       }
       if (!var30)
       {
           PRINTSTRING("Script 'test_lineup10.sc' failed to load\n");
           BREAKPOINT();
       }
       var36.v0 = 464.8f;
       var36.v1 = 24.0f;
       var36.v2 = -884.1f;
       var39.v0 = 1.0f;
       var39.v1 = 0.0f;
       var39.v2 = 0.0f;
       Math_VecRotateY(&var39, &var39, -140.0f * 0.01745329f);
       var32.v0.v0 = var36.v0;
       var32.v0.v1 = var36.v1;
       var32.v0.v2 = var36.v2;
       var32.v3 = -140.0f;
       var31 = 0;
       while (var31 < 1)
       {
           if (var31 == 0)
           {
               var42 = CineScript_Characters_LaunchAnimWithFaceAt(var2[0 + var31], var13[0 + var31], var24, var25[(0 + var31) % 1], var27[(0 + var31) % 1], &var32, 1);
           }
           else
           {
               var42 = CineScript_Characters_LaunchAnimAt(var2[0 + var31], var13[0 + var31], var24, var25[(0 + var31) % 1], &var32, 1);
           }
           var32.v0.v0 = var39.v0 + var32.v0.v0;
           var32.v0.v1 = var39.v1 + var32.v0.v1;
           var32.v0.v2 = var39.v2 + var32.v0.v2;
           CineScript_PushKillBuffer(var42, 0);
           var31 = var31 + 1;
       }
       CineScript_Audio_PlayStream();
       WAITUNWARPED(13000);
       CineScript_PopKillBuffer(0);
   }
   sub_40c(L[0]);
}

void sub_40c(var0)
{
   auto var3;

   var0.v0 = 3;
}

