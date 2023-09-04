void main()
{
   auto var2, var3, var4, var5;

   var2 = "GH_25";
   var3 = mcCareer_GetHookmanCharacterSet(var2);
   sub_31("Cruising_Offline");
   var4 = null;
   var4 = Sidekick_AppendData(1, "SIDEKICK_TIMETRIAL_DOWNTOWN_POST_TITLE", mcCareer_GetHookmanFlashId(var2), 21, 10.0f, var3, "Incoming Call!", "SIDEKICK_TIMETRIAL_DOWNTOWN_POST", "", 3, 0, "SIDEKICK_TIMETRIAL_DOWNTOWN_POST", var3, "PLAYER");
   while (!Sidekick_HasDataBeenAnnounced(var4))
   {
       WAITUNWARPED(200);
   }
   var5 = mcCareer_GetHookman(253);
   while (var5 != null)
   {
       WAITUNWARPED(500);
       var5 = mcCareer_GetHookman(253);
   }
   mcCareer_UnlockTimeTrial(3);
   mcCareer_StartNewScript("Game/CruisingHookmen/dt_time_trial_hk1", 1500);
}

void sub_31(var0)
{
   auto var3, var4;

   var3 = UIManager_GetState(var0);
   while (!vhsmState_IsListener(var3))
   {
       WAITUNWARPED(100);
   }
   while (FlashNavigator_IsTransitioning() && (PoliceManager_CheckPoliceActivity(1) > 1))
   {
       WAITUNWARPED(100);
   }
   if (!vhsmState_IsListener(var3))
   {
   }
}


