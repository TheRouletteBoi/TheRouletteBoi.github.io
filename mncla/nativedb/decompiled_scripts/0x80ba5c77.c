void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17;

   if (!(L[0].v0 == 3))
   {
       L[0].v0 = 2;
       var2 = OpponentManager_CreateOpponent();
       OpponentManager_LoadOpponent(var2, L[0].v1, &(L[0].v2), 0);
       OpponentManager_AddOpponentToWorld(var2);
       var3 = Opponent_GetRacer(var2);
       Racer_SetStreamingLockedIn(var3);
       while (!Racer_IsSimStreamed(var3))
       {
           WAIT(100);
       }
       Racer_InitializeResetPosition(var3, &(L[0].v2), (float)0);
       Racer_Reset(var3);
       var4 = 0x309c65dc(var3);
       0xbe9ab967(var4, (float)0);
       0x11945fc1(var4, (float)1);
       0x50e803f(var4, (float)0);
       0xb0c3a954(var4, (float)0);
       0xf0954f1c(var4, L[0].v5);
       WAIT(1000);
       var12 = 0x12fe7341(var4);
       0x79159bfc(var4, "EngineAccel");
       0xd4f9658c(var4, 0);
       var11 = 2;
       while (var11 <= (var12 - 1))
       {
           Racer_Reset(var3);
           0x16084ee8(var4, 0);
           0x42a88171(var4, var11);
           0xbe9ab967(var4, 0.5f);
           0x11945fc1(var4, (float)0);
           0xb0c3a954(var4, (float)0);
           WAIT(10000);
           0xbe9ab967(var4, (float)1);
           0xd4f9658c(var4, 1);
           var13 = 0x90058bb7(var4);
           WAIT(1000);
           while ((0x90058bb7(var4) - var13) > 0.01f)
           {
               var13 = 0x90058bb7(var4);
               WAIT(1000);
           }
           WAIT(1000);
           0xd4f9658c(var4, 0);
           var11 = var11 + 1;
       }
       0xedc8181c(var4);
       0x79159bfc(var4, "EngineDecel");
       0xd4f9658c(var4, 0);
       var11 = 2;
       while (var11 <= (var12 - 1))
       {
           Racer_Reset(var3);
           0x16084ee8(var4, 0);
           0x7c09edb2(var4, 0xb73c3ea0(var4, var11));
           0x42a88171(var4, var11);
           0xbe9ab967(var4, (float)1);
           0x11945fc1(var4, (float)0);
           0xb0c3a954(var4, (float)0);
           WAIT(1000);
           0xbe9ab967(var4, (float)0);
           0xd4f9658c(var4, 1);
           var13 = 0x90058bb7(var4);
           WAIT(1000);
           while ((var13 - 0x90058bb7(var4)) > 0.01f)
           {
               var13 = 0x90058bb7(var4);
               WAIT(1000);
           }
           WAIT(1000);
           0xd4f9658c(var4, 0);
           var11 = var11 + 1;
       }
       0xedc8181c(var4);
       var10 = 10;
       0x79159bfc(var4, "BrakeDecel");
       0xd4f9658c(var4, 0);
       var9 = 1;
       while (var9 <= var10)
       {
           Racer_Reset(var3);
           0x7c09edb2(var4, 0x101434d(var4));
           0xbe9ab967(var4, (float)1);
           0x11945fc1(var4, (float)0);
           0xb0c3a954(var4, (float)0);
           WAIT(1000);
           0xbe9ab967(var4, (float)0);
           0x11945fc1(var4, (1.0f * ((float)var9)) / ((float)var10));
           0x42a88171(var4, 1);
           0xd4f9658c(var4, 1);
           while (0x90058bb7(var4) > 0.01f)
           {
               WAIT(1000);
           }
           WAIT(1000);
           0xd4f9658c(var4, 0);
           var9 = var9 + 1;
       }
       0xedc8181c(var4);
       0x79159bfc(var4, "Drag");
       0xd4f9658c(var4, 0);
       var14 = 0x101434d(var4);
       var6 = 50;
       var5 = 0;
       while (var5 <= var6)
       {
           Racer_Reset(var3);
           0x7c09edb2(var4, var14);
           0x42a88171(var4, 1);
           0xbe9ab967(var4, (float)0);
           0x11945fc1(var4, (float)0);
           0xb0c3a954(var4, (1.0f * ((float)var5)) / ((float)var6));
           WAIT(1000);
           0xd4f9658c(var4, 1);
           var13 = 0x90058bb7(var4);
           WAIT(1000);
           while (0xc8d20327(var4) && ((var13 - 0x90058bb7(var4)) > 0.05f))
           {
               var13 = 0x90058bb7(var4);
               WAIT(1000);
           }
           if (!0xc8d20327(var4))
           {
               var5 = var5 - 1;
               var14 = var14 - 1.0f;
           }
           0xd4f9658c(var4, 0);
           var5 = var5 + 1;
       }
       0xedc8181c(var4);
       0x79159bfc(var4, "Steering");
       0xd4f9658c(var4, 0);
       var6 = 20;
       var5 = 1;
       while (var5 <= (var6 - 1))
       {
           Racer_Reset(var3);
           0x16084ee8(var4, 0);
           0x42a88171(var4, var12 - 1);
           0xbe9ab967(var4, 0.5f);
           0x11945fc1(var4, (float)0);
           if (var5 <= 10)
           {
               0xb0c3a954(var4, (0.2f * ((float)var5)) / ((float)var6));
           }
           else
           {
               0xb0c3a954(var4, (2.0f * ((float)(var5 - 9))) / ((float)var6));
           }
           WAIT(1000);
           0xd4f9658c(var4, 1);
           var13 = 0x90058bb7(var4);
           var15 = 0.5f;
           while (0xc8d20327(var4) && (var15 < ((float)1)))
           {
               WAIT(1000);
               while (0xc8d20327(var4) && ((0x90058bb7(var4) - var13) > 0.1f))
               {
                   var13 = 0x90058bb7(var4);
                   WAIT(1000);
               }
               var15 = var15 + 0.01f;
               if (var15 > ((float)1))
               {
                   var15 = (float)1;
               }
               0xbe9ab967(var4, var15);
           }
           var13 = 0x90058bb7(var4);
           WAIT(1000);
           while (0xc8d20327(var4) && ((0x90058bb7(var4) - var13) > 0.01f))
           {
               var13 = 0x90058bb7(var4);
               WAIT(1000);
           }
           0xd4f9658c(var4, 0);
           var5 = var5 + 1;
       }
       0xedc8181c(var4);
       0x79159bfc(var4, "Handling");
       0xd4f9658c(var4, 0);
       var8 = 200;
       var16 = ((float)2) * 0x101434d(var4);
       if (var16 > 134.1f)
       {
           var16 = 134.1f;
       }
       var7 = 0;
       while (var7 <= var8)
       {
           Racer_Reset(var3);
           0x7c09edb2(var4, (var16 * ((float)var7)) / ((float)var8));
           0x42a88171(var4, 1);
           0xbe9ab967(var4, (float)0);
           0x11945fc1(var4, (float)0);
           0xb0c3a954(var4, (float)0);
           WAIT(1000);
           0xd4f9658c(var4, 1);
           var17 = (float)0;
           while (0xc8d20327(var4) && (var17 < ((float)1)))
           {
               var17 = var17 + 0.0025f;
               if (var17 > ((float)1))
               {
                   var17 = (float)1;
               }
               0xb0c3a954(var4, var17);
               WAIT(1);
           }
           if (0xc8d20327(var4))
           {
               WAIT(1000);
           }
           0xd4f9658c(var4, 0);
           var7 = var7 + 1;
       }
       0xedc8181c(var4);
       Racer_SetStreamingUnlocked(var3);
       OpponentManager_RemoveOpponentFromWorld(var2);
       OpponentManager_DeleteOpponent(var2);
       WAIT(1000);
   }
   sub_859(L[0].v0, L[0].v1, L[0].v2, L[0].v3, L[0].v4, L[0].v5);
}

void sub_859(var0, var1, var2, var3, var4, var5)
{
   auto var8, var9, var10, var11, var12, var13;

   var0.v0 = 3;
   PRINTSTRING("Script: finished section\n");
}

