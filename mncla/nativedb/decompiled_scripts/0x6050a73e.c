void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38;

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
   var24 = "cutscene/story/cut_story_motorcycle_rep/entity/player_drv02_name_drv_mp_01_set";
   var25 = 1;
   var25[0] = "player_drv02_name_drv_mp_01_set";
   var27 = 1;
   var27[0] = "player_drv02_name_drv_mp_01_set";
   while (1)
   {
       var29 = 0;
       var30 = 0;
       while (!var29)
       {
           var29 = 1;
           var30 = 0;
           while (var30 < 1)
           {
               var29 = var29 && CineScript_Characters_LoadType(var2[0 + var30], var13[0 + var30]);
               var30 = var30 + 1;
           }
           WAITUNWARPED(100);
       }
       var30 = 0;
       while (var30 < 1)
       {
           var29 = var29 && CineScript_Characters_LoadAnimationWithFace(var24, var25[var30], var27[var30]);
           var30 = var30 + 1;
       }
       if (!var29)
       {
           PRINTSTRING("Script 'test_blendshapes_face_on_base.sc' failed to load\n");
           BREAKPOINT();
       }
       var35.v0 = 1.0f;
       var35.v1 = 0.0f;
       var35.v2 = 0.0f;
       var30 = 0;
       while (var30 < 1)
       {
           if (var30 == 0)
           {
               var38 = CineScript_Characters_LaunchAnimWithFaceAt(var2[0 + var30], var13[0 + var30], var24, var25[(0 + var30) % 1], var27[(0 + var30) % 1], &var31, 1);
           }
           else
           {
               var38 = CineScript_Characters_LaunchAnimAt(var2[0 + var30], var13[0 + var30], var24, var25[(0 + var30) % 1], &var31, 1);
           }
           var31.v0.v0 = var35.v0 + var31.v0.v0;
           var31.v0.v1 = var35.v1 + var31.v0.v1;
           var31.v0.v2 = var35.v2 + var31.v0.v2;
           CineScript_PushKillBuffer(var38, 0);
           var30 = var30 + 1;
       }
       WAITUNWARPED(47000);
       CineScript_PopKillBuffer(0);
   }
   sub_3c3(L[0]);
}

void sub_3c3(var0)
{
   auto var3;

   var0.v0 = 3;
}

