void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9, var10, var11, var12, var13, var14, var15, var16, var17;

   var2 = Player_FindRacerObject(0);
   Racer_GetPosition(var2, &var3);
   var6 = 2;
   var6[0] = TriggerManager_CreateTriggerArray(2);
   var9 = TriggerArray_AddTriggerRadius(var6[0]);
   var11.v0 = var3.v0;
   var11.v1 = var3.v1;
   var11.v2 = var3.v2;
   var11.v0 = var11.v0 + 100.0f;
   Trigger_SetValueVector(var9, "oCenter", &var11);
   Trigger_SetValueFloat(var9, "rRadius", 90.0f);
   var10 = Trigger_AddEvent(var9, "RoadDensity");
   var14.v0 = 20.0f;
   var14.v1 = 20.0f;
   var14.v2 = 20.0f;
   TriggerEvent_SetValueVector(var10, "RoadCenter", &var14);
   TriggerEvent_SetValueFloat(var10, "Density", 0.5f);
   var9 = TriggerArray_AddTriggerTimer(var6[0]);
   Trigger_SetValueFloat(var9, "rTimer", 3.0f);
   var10 = Trigger_AddEvent(var9, "RoadDensity");
   var14.v0 = 30.0f;
   var14.v1 = 30.0f;
   var14.v2 = 30.0f;
   TriggerEvent_SetValueVector(var10, "RoadCenter", &var14);
   TriggerEvent_SetValueFloat(var10, "Density", 0.5f);
   var10 = Trigger_AddEvent(var9, "RoadDensity");
   var14.v0 = 40.0f;
   var14.v1 = 40.0f;
   var14.v2 = 40.0f;
   TriggerEvent_SetValueVector(var10, "RoadCenter", &var14);
   TriggerEvent_SetValueFloat(var10, "Density", 0.25f);
   var6[1] = TriggerManager_CreateTriggerArray(1);
   var9 = TriggerArray_AddTriggerRadius(var6[1]);
   var11.v0 = 239.06f;
   var11.v1 = 26.76f;
   var11.v2 = -923.56f;
   Trigger_SetValueVector(var9, "oCenter", &var11);
   Trigger_SetValueFloat(var9, "rRadius", 28.0f);
   Trigger_SetValueBool(var9, "bTriggerMultipleTimes", 1);
   Trigger_SetValueBool(var9, "bTriggerOnEntryOnly", 0);
   var10 = Trigger_AddEvent(var9, "NitroReplenish");
   TriggerEvent_SetValueFloat(var10, "rDelay", 2.0f);
   TriggerManager_ResetTriggers();
   var17 = Race_GetCurrentRace();
   if (var17 != null)
   {
       Race_EnableRaceTimer(var17, 1);
   }
   while (1)
   {
       WAIT(100);
   }
   TriggerManager_DestroyTriggerArray(var6[0]);
   TriggerManager_DestroyTriggerArray(var6[1]);
}

