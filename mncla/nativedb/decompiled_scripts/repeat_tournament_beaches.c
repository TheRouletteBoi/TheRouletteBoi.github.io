﻿void main()
{
   auto var2;

   var2 = mcCareer_GetHookman(201);
   while (var2 != null)
   {
       WAITUNWARPED(500);
       var2 = mcCareer_GetHookman(201);
   }
   START_NEW_SCRIPT("Game/CruisingHookmen/be_tournament_hk1", 1500);
}
