void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43;

   var2 = 10;
   var2[0] = "character/drv_mp_01_set_HackedScale";
   var2[1] = "character/";
   var2[2] = "character/";
   var2[3] = "character/";
   var2[4] = "character/";
   var2[5] = "character/";
   var2[6] = "character/";
   var2[7] = "character/";
   var2[8] = "character/";
   var13 = 10;
   var13[0] = "drv_mp_01_set_HackedScale";
   var13[1] = "";
   var13[2] = "";
   var13[3] = "";
   var13[4] = "";
   var13[5] = "";
   var13[6] = "";
   var13[7] = "";
   var13[8] = "";
   var24 = 1;
   var26 = 1;
   var28 = "cutscene/story/cut_story_motorcycle_rep_B/Entity/andrew_drv01_name_drv_ma_03_set";
   var29 = "cutscene/story/cut_story_motorcycle_rep_IM/entity/andrew_drv01_name_drv_ma_03_set";
   var24[0] = "andrew_drv01_name_drv_ma_03_set";
   var26[0] = "andrew_drv01_name_drv_ma_03_set";
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
               var31 = var31 + 1;
           }
           WAITUNWARPED(100);
       }
       var31 = 0;
       while (var31 < 1)
       {
           var30 = var30 && CineScript_Characters_LoadAnimationWithFaceXX(var28, var24[var31], var29, var26[var31]);
           var31 = var31 + 1;
       }
       if (!var30)
       {
           PRINTSTRING("Script 'test_face_on_base_standing_in_place_Andrew.sc' failed to load\n");
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
       var42 = 0;
       var31 = 0;
       while (var31 < 1)
       {
           if (var31 == 0)
           {
               var43 = CineScript_Characters_LaunchAnimWithFaceAtXX(var2[0 + var31], var13[0 + var31], var28, var24[(0 + var31) % 1], var29, var26[(0 + var31) % 1], &var32, 1);
               var42 = var43;
           }
           else
           {
               var43 = CineScript_Characters_LaunchAnimAt(var2[0 + var31], var13[0 + var31], var28, var24[(0 + var31) % 1], &var32, 1);
           }
           var32.v0.v0 = var39.v0 + var32.v0.v0;
           var32.v0.v1 = var39.v1 + var32.v0.v1;
           var32.v0.v2 = var39.v2 + var32.v0.v2;
           CineScript_PushKillBuffer(var43, 0);
           var31 = var31 + 1;
       }
       while (CineScript_Characters_GetTimeRemainingForId(var42) > 0.0f)
       {
           WAITUNWARPED(100);
       }
       CineScript_PopKillBuffer(0);
   }
   sub_4ba(L[0]);
}

void sub_4ba(var0)
{
   auto var3;

   var0.v0 = 3;
}

