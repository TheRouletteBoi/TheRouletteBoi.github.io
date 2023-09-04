void main()
{
   auto var2, var3, var4, var5, var6, var7;

   CineScript_SetGameCoordSysBinding(&var2);
   sub_11();
   sub_cc();
   sub_1b9(L[0]);
   PRINTSTRING("'SETUP_GENERIC_CUTSCENE' Finished.\n");
}

void sub_11()
{
   auto var2, var3, var4, var5;

   var3 = 4;
   var2 = 0;
   while (var2 < var3)
   {
       var4 = 1;
       var5 = Racer_FindFromUID(var4);
       while (var5 == null)
       {
           var4 = var4 + 1;
           if (var4 > 10000)
           {
               PRINTSTRING("PROC 'SlotFourAvailableRacers' Failed to slot all four racers.");
               return;
           }
           else
           {
               var5 = Racer_FindFromUID(var4);
           }
       }
       CineScript_Cars_AssignIdToSlot(var4, var2);
       var2 = var2 + 1;
   }
}

void sub_cc()
{
   CineScript_Characters_AssignNameToSlot("drv_fh_001_set", 0);
   CineScript_Characters_AssignNameToSlot("drv_mc_07_set", 1);
   CineScript_Characters_AssignNameToSlot("drv_mc_07_set", 2);
   CineScript_Characters_AssignNameToSlot("drv_mc_07_set", 3);
   CineScript_Characters_AssignNameToSlot("drv_mc_07_set", 4);
   CineScript_Characters_AssignNameToSlot("drv_mc_07_set", 5);
   CineScript_Characters_AssignNameToSlot("drv_mc_07_set", 6);
   CineScript_Characters_AssignNameToSlot("drv_mc_07_set", 7);
   CineScript_Characters_AssignNameToSlot("drv_mp_01_set", 8);
}

void sub_1b9(var0)
{
   auto var3;

   var0.v0 = 3;
}

