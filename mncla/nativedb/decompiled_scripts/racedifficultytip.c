void main()
{
   sub_29("SIDEKICK_RACE_DIFFICULTY_TIP", 5);
}

void sub_29(var0, var1)
{
   auto var4, var5, var6, var7;

   var4 = mcMissionManager_GetMission("GARAGE_HOLLYWOOD");
   while (mcMission_GetState(var4) != 5)
   {
       WAITUNWARPED(100);
   }
   var5 = null;
   while (!sub_f8())
   {
       WAITUNWARPED(100);
   }
   var5 = Sidekick_AppendData(5, "SIDEKICK_TITLE_TIP", 1, var1, 10.0f, "mec_mc_01_set", "Incoming Call!", var0, "Prompt_NavigateToTutorialLog", 3, 0, var0, "mec_mc_01_set", "PLAYER");
   while (!Sidekick_HasDataBeenAnnounced(var5))
   {
       WAITUNWARPED(100);
   }
}

void sub_84(var0)
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

int sub_f8()
{
   if (Sidekick_GetTypeCount(3) > 4)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}

