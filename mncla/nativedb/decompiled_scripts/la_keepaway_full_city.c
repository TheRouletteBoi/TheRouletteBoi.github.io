void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20, var21, var22, var23, var24, var25, var26, var27, var28, var29, var30, var31, var32, var33, var34, var35, var36, var37, var38, var39, var40, var41, var42, var43, var44, var45, var46, var47, var48, var49, var50, var51, var52, var53, var54, var55, var56, var57, var58, var59, var60, var61, var62, var63, var64, var65, var66, var67, var68, var69, var70, var71, var72, var73, var74, var75, var76, var77, var78, var79;

   var2 = 16;
   var2[0 * 3].v0 = -127.737f;
   var2[0 * 3].v1 = 17.8414f;
   var2[0 * 3].v2 = -749.949f;
   var2[1 * 3].v0 = -122.737f;
   var2[1 * 3].v1 = 17.8414f;
   var2[1 * 3].v2 = -750.032f;
   var2[2 * 3].v0 = -132.236f;
   var2[2 * 3].v1 = 17.8414f;
   var2[2 * 3].v2 = -749.874f;
   var2[3 * 3].v0 = -118.238f;
   var2[3 * 3].v1 = 17.8414f;
   var2[3 * 3].v2 = -750.106f;
   var2[4 * 3].v0 = -122.878f;
   var2[4 * 3].v1 = 17.8414f;
   var2[4 * 3].v2 = -758.531f;
   var2[5 * 3].v0 = -132.377f;
   var2[5 * 3].v1 = 17.8414f;
   var2[5 * 3].v2 = -758.373f;
   var2[6 * 3].v0 = -118.379f;
   var2[6 * 3].v1 = 17.8414f;
   var2[6 * 3].v2 = -758.605f;
   var2[7 * 3].v0 = -127.878f;
   var2[7 * 3].v1 = 17.8414f;
   var2[7 * 3].v2 = -758.448f;
   var2[8 * 3].v0 = -123.019f;
   var2[8 * 3].v1 = 17.8414f;
   var2[8 * 3].v2 = -767.029f;
   var2[9 * 3].v0 = -132.518f;
   var2[9 * 3].v1 = 17.8414f;
   var2[9 * 3].v2 = -766.872f;
   var2[10 * 3].v0 = -128.019f;
   var2[10 * 3].v1 = 17.8414f;
   var2[10 * 3].v2 = -766.947f;
   var2[11 * 3].v0 = -118.52f;
   var2[11 * 3].v1 = 17.8414f;
   var2[11 * 3].v2 = -767.104f;
   var2[12 * 3].v0 = -123.16f;
   var2[12 * 3].v1 = 17.8414f;
   var2[12 * 3].v2 = -775.528f;
   var2[13 * 3].v0 = -132.659f;
   var2[13 * 3].v1 = 17.8414f;
   var2[13 * 3].v2 = -775.371f;
   var2[14 * 3].v0 = -118.661f;
   var2[14 * 3].v1 = 17.8414f;
   var2[14 * 3].v2 = -775.603f;
   var2[15 * 3].v0 = -128.16f;
   var2[15 * 3].v1 = 17.8414f;
   var2[15 * 3].v2 = -775.445f;
   var51 = 16;
   var51[0] = -179.049f;
   var51[1] = -179.049f;
   var51[2] = -179.049f;
   var51[3] = -179.049f;
   var51[4] = -179.049f;
   var51[5] = -179.049f;
   var51[6] = -179.049f;
   var51[7] = -179.049f;
   var51[8] = -179.049f;
   var51[9] = -179.049f;
   var51[10] = -179.049f;
   var51[11] = -179.049f;
   var51[12] = -179.049f;
   var51[13] = -179.049f;
   var51[14] = -179.049f;
   var51[15] = -179.049f;
   var68 = 1;
   var68[0 * 3].v0 = -124.576f;
   var68[0 * 3].v1 = 7.84717f;
   var68[0 * 3].v2 = -568.163f;
   var72 = 1;
   var72[0] = "PickUp";
   var74 = 1;
   var74[0] = 0;
   var76 = 0;
   var77 = Ctf_GetMap(L[0].v801);
   CtfMap_Init(var77, 1, 0);
   var76 = 0;
   while (var76 < 1)
   {
       CtfMap_AddItem(var77, var72[var76], &(var68[var76 * 3]), var74[var76]);
       var76 = var76 + 1;
   }
   var78 = 0;
   var79 = Race_GetRaceGrid(L[0].v3, 0);
   var78 = 0;
   while (var78 < 16)
   {
       RaceGrid_SetPosition(var79, var78, &(var2[var78 * 3]), var51[var78]);
       var78 = var78 + 1;
   }
   sub_388(&L[0]);
}

void sub_388(var0)
{
   auto var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16;

   var8.v0 = (float)0;
   var8.v1 = (float)1;
   var8.v2 = (float)0;
   var11.v0 = (float)0;
   var11.v1 = (float)0;
   var11.v2 = (float)-1;
   RaceGrid_GetPosition(Race_GetRaceGrid(*(var0 + 12), 0), 0, &var4, &var7);
   Math_VecRotateY(&var11, &var11, var7);
   var11.v0 = var4.v0 + var11.v0;
   var11.v1 = var4.v1 + var11.v1;
   var11.v2 = var4.v2 + var11.v2;
   var8.v0 = var4.v0 + var8.v0;
   var8.v1 = var4.v1 + var8.v1;
   var8.v2 = var4.v2 + var8.v2;
   UILogic_LockStreaming(&var4, &var8, &var11);
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       Racer_SetStreamingLockedIn((*((var0 + 16) + 4))[var3 * 48].v0);
       var3 = var3 + 1;
   }
   var14 = 1;
   while (var14 > 0)
   {
       var14 = *((var0 + 16) + 3080);
       var3 = 0;
       while (var3 < *((var0 + 16) + 3080))
       {
           if (Racer_IsSimStreamed((*((var0 + 16) + 4))[var3 * 48].v0))
           {
               var14 = var14 - 1;
           }
           var3 = var3 + 1;
       }
       if (var14 > 0)
       {
           if (!*((var0 + 16) + 3132))
           {
               sub_49f(1, 0, 0x3f800000, 0);
           }
           WAIT(100);
       }
   }
   while (OpponentManager_StillStreamingOut())
   {
       WAIT(30);
   }
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       if ((*((var0 + 16) + 4))[var3 * 48].v2 == 2)
       {
           PRINTSTRING(" BRAIN CREATED!");
           (*((var0 + 16) + 4))[var3 * 48].v3 = BrainFactory_CreateBrainRacing((*((var0 + 16) + 4))[var3 * 48].v0);
       }
       var3 = var3 + 1;
   }
   var15 = START_NEW_SCRIPT_WITH_ARGS("game/racetypes/BaseWarCore", var0, 802, 1500);
   while (!IsChildFinished(var15))
   {
       WAIT(30);
   }
   var3 = 0;
   while (var3 < *((var0 + 16) + 3080))
   {
       if ((*((var0 + 16) + 4))[var3 * 48].v2 == 2)
       {
           BrainFactory_DeleteBrain((*((var0 + 16) + 4))[var3 * 48].v0);
       }
       var3 = var3 + 1;
   }
}

void sub_49f(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12, var13;

   var6 = null;
   while (var6 == null)
   {
       var6 = UIManager_FindMovie("TRANSITIONMOVIE");
       if (var6 == null)
       {
           PRINTSTRING("SCRIPT: waiting for transition movie to stream in...\n");
           WAITUNWARPED(10);
       }
   }
   var7 = 0;
   var8 = 0;
   var9 = 0;
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionout", &var7);
   FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
   FlashHelper_GetGlobalInt(var6, "TransitionOutisReady", &var9);
   PRINTSTRING("FADE DOWN REPORT\n");
   PRINTSTRING("================\n");
   PRINTSTRING("TransitionOut: ");
   PRINTINT(var7);
   PRINTSTRING("\nTransitionIn: ");
   PRINTINT(var8);
   PRINTSTRING("\nnTransitionReady: ");
   PRINTINT(var9);
   PRINTSTRING("\n");
   if ((var8 == 0) && ((var9 == 0) || ((var7 == 1) && (var9 == 2))))
   {
       FlashHelper_SetMovieEnabled(var6, 1);
       FlashHelper_SetGlobalInt(var6, "cur_visibility", 1);
       FlashHelper_SetGlobalInt(var6, "mask_color", var3);
       if (var1)
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 0);
       }
       else
       {
           FlashHelper_SetGlobalInt(var6, "transition_type", 1);
       }
       FlashHelper_SetGlobalFloat(var6, "fade_speed_in", var2);
       FlashHelper_SetGlobalFloat(var6, "fade_speed_out", 0.01f);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionout", 0);
       FlashHelper_SetGlobalInt(var6, "TransitionOutisReady", 0);
       FlashHelper_SetGlobalInt(var6, "StartOfTransitionin", 1);
       if (var0)
       {
           var8 = 1;
           while (var8 == 1)
           {
               FlashHelper_GetGlobalInt(var6, "StartOfTransitionin", &var8);
               if (var8 == 1)
               {
                   WAITUNWARPED(10);
               }
           }
       }
   }
}

