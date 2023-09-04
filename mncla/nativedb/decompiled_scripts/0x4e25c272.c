void main()
{
   auto var2, var3;

   var2 = mcMissionManager_GetMission("TIMETRIAL_DOWNTOWNC");
   sub_4f(var2, "SIDEKICK_TIMETRIAL_DOWNTOWNC", 0x41200000, 0);
   mcMission_ChangeState(var2, 3, 0);
   var3 = mcCareer_GetHookman(253);
   while (var3 == null)
   {
       WAITUNWARPED(500);
       var3 = mcCareer_GetHookman(253);
   }
   mcCareer_EvaluateCurrentTargetTime(3, 0, 12);
}

void sub_4f(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12;

   var6 = mcMission_GetHookmanNameId(var0);
   var7 = mcCareer_GetHookmanCharacterSet(var6);
   var8 = null;
   while (!sub_fa())
   {
       WAITUNWARPED(100);
   }
   var8 = Sidekick_AppendData(2, mcMission_GetId(var0), mcCareer_GetHookmanFlashId(var6), 0, var2, var7, "Incoming Call!", var1, "Mission_Log", 1, var3, var1, var7, "PLAYER");
   while (!Sidekick_HasDataBeenAnnounced(var8))
   {
       WAITUNWARPED(100);
   }
}

void sub_86(var0)
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

function sub_fa()
{
   if (Sidekick_GetTypeCount(1) > 9)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}

