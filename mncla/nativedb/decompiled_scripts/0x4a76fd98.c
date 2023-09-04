void main()
{
   auto var2, var3, var4, var5, var6, var7, var8;

   Registry_SetValueInt(L[0].v1.v26, 2);
   mcTargetManager_HideTarget(L[0].v1.v1, 0);
   var2 = UIManager_GetState("Cruising_Offline");
   var3 = 0;
   var4 = 0;
   var5 = 0;
   var6 = 0;
   var7 = 0;
   while (!var7)
   {
       Registry_GetValueInt("Script_SuspendAllOpponents", &var3);
       if (var3 == 1)
       {
           PRINTSTRING("Rate My Ride ");
           PRINTSTRING(L[0].v1.v0);
           PRINTSTRING(" was suspended (Script_SuspendAllOpponents was set)\n");
           SetExceptionMask(0);
           while (var3 == 1)
           {
               Registry_GetValueInt("Script_SuspendAllOpponents", &var3);
               WAITUNWARPED(100);
           }
           PRINTSTRING("Rate My Ride ");
           PRINTSTRING(L[0].v1.v0);
           PRINTSTRING(" was un-suspended (Script_SuspendAllOpponents was reset)\n");
           SetExceptionMask(2);
       }
       if (vhsmState_IsListener(var2))
       {
           if (var6 > 0)
           {
               var6 = var6 - 1;
           }
           Registry_GetValueInt(L[0].v1.v26, &var4);
           if (var4 == 4)
           {
               PRINTSTRING("Rate My Ride TRIGGERED\n");
               Registry_SetValueInt("EXITRMR_TRIG", 0);
               Registry_SetValueInt(L[0].v1.v26, 3);
               mcEvent_PostEventStr("LOCATION_EVENT", L[0].v1.v0);
               mcEvent_PostEventStr("MISSION_EVENT", L[0].v1.v27);
               WAITUNWARPED(1000);
               while (CineScript_IsScenePlaying())
               {
                   WAITUNWARPED(100);
               }
               WAITUNWARPED(1000);
               Registry_GetValueInt(L[0].v1.v26, &var4);
               while (var4 == 3)
               {
                   PRINTSTRING("enum to int reserved\n");
                   Registry_GetValueInt(L[0].v1.v26, &var4);
                   WAITUNWARPED(1000);
               }
               if (var4 == 5)
               {
                   PRINTSTRING("SCRIPT: streaming RMR movie\n");
                   UIManager_StreamMovie("GARAGEMOVIE", "garage/garage.swf", 5200, 5100, 10000, 0, 0);
                   var8 = null;
                   while (var8 == null)
                   {
                       var8 = UIManager_FindMovie("GARAGEMOVIE");
                       PRINTSTRING("SCRIPT: waiting for RMR movie to stream in...\n");
                       WAITUNWARPED(100);
                   }
                   PRINTSTRING("SCRIPT: RMR movie streamed successfully\n");
                   UIManager_SendEvent("ratemyrideTransition");
                   Garage_TransitionIntoRateMyRide();
                   var5 = 0;
                   while (var5 == 0)
                   {
                       Registry_GetValueInt("EXITRMR_TRIG", &var5);
                       WAITUNWARPED(100);
                   }
                   UIManager_UnloadMovie("GARAGEMOVIE");
                   var8 = null;
                   Garage_TransitionOutOfRateMyRide();
                   mcEvent_PostEventStr("MISSION_EVENT", L[0].v1.v28);
                   WAITUNWARPED(1000);
                   while (CineScript_IsScenePlaying())
                   {
                       WAITUNWARPED(100);
                   }
                   WAITUNWARPED(1000);
                   mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
                   mcGame_ThrowEvent("cruising");
               }
               Registry_SetValueInt(L[0].v1.v26, 2);
           }
       }
       WAITUNWARPED(100);
   }
   Registry_SetValueInt(L[0].v1.v26, 0);
   mcTargetManager_HideTarget(L[0].v1.v1, 1);
}

