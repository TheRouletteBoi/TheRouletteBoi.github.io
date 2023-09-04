void main()
{
   auto var2;

   var2 = mcMissionManager_GetMission("BESTOF_SH_03");
   sub_41(var2, "SIDEKICK_BESTOF_SH_03", 0x41200000, 0);
   mcMission_ChangeState(var2, 3, 0);
}

void sub_41(var0, var1, var2, var3)
{
   auto var6, var7, var8, var9, var10, var11, var12;

   var6 = mcMission_GetHookmanNameId(var0);
   var7 = mcCareer_GetHookmanCharacterSet(var6);
   var8 = null;
   while (!sub_ec())
   {
       WAITUNWARPED(100);
   }
   var8 = Sidekick_AppendData(2, mcMission_GetId(var0), mcCareer_GetHookmanFlashId(var6), 0, var2, var7, "Incoming Call!", var1, "Mission_Log", 1, var3, var1, var7, "PLAYER");
   while (!Sidekick_HasDataBeenAnnounced(var8))
   {
       WAITUNWARPED(100);
   }
}

void sub_78(var0)
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

function sub_ec()
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

