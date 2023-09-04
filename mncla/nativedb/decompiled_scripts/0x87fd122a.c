void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17, var18, var19, var20;

   var2 = 2;
   var2[0] = "character/drv_mp_01_blendshapes_set";
   var2[1] = "character/drv_mp_01_set";
   var5 = 2;
   var5[0] = "drv_mp_01_blendshapes_set";
   var5[1] = "drv_mp_01_set";
   var8 = "anim";
   var9 = 1;
   var9[0] = "rb_1ray_a_rig_test";
   var11 = 0;
   var12 = 0;
   while (!var11)
   {
       var11 = 1;
       var12 = 0;
       while (var12 < 2)
       {
           var11 = var11 && CineScript_Characters_LoadType(var2[0 + var12], var5[0 + var12]);
           var12 = var12 + 1;
       }
       WAITUNWARPED(100);
   }
   var12 = 0;
   while (var12 < 1)
   {
       var11 = var11 && CineScript_Characters_LoadAnimation(var8, var9[var12]);
       var12 = var12 + 1;
   }
   if (!var11)
   {
       PRINTSTRING("Script 'test_blendshapes.sc' failed to load\n");
       BREAKPOINT();
   }
   var17.v0 = 464.8f;
   var17.v1 = 24.0f;
   var17.v2 = -884.1f;
   var13.v0.v0 = var17.v0;
   var13.v0.v1 = var17.v1;
   var13.v0.v2 = var17.v2;
   var13.v3 = 0.0f;
   var12 = 0;
   while (var12 < 2)
   {
       var20 = CineScript_Characters_LaunchAnimAt(var2[0 + var12], var5[0 + var12], var8, var9[(0 + var12) % 1], &var13, -1);
       var13.v0.v0 = var13.v0.v0 + 0.25f;
       var13.v3 = var13.v3 + 30.0f;
       CineScript_PushKillBuffer(var20, 0);
       var12 = var12 + 1;
   }
   sub_242(L[0]);
}

void sub_242(var0)
{
   auto var3;

   var0.v0 = 3;
}

