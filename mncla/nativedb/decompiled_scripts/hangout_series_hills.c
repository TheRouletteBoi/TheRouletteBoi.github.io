﻿void main()
{
   auto var2;

   var2 = 0;
   Registry_GetValueInt("hl_local_hangout1_state", &var2);
   if (var2 == 0)
   {
       mcCareer_StartNewScript("Game/Hangouts/hl_local_hangout1_setup", 1500);
   }
}

