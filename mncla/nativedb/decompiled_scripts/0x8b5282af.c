void main()
{
   auto var2, var3, var4, var5, var6, var7, var8, var9;

   var2.v2.v0.v0 = 0.0f;
   var2.v2.v0.v1 = 0.0f;
   var2.v2.v0.v2 = 0.0f;
   var2.v2.v3 = 0.0f;
   CineScript_SetGameCoordSysBinding(&var2);
   PostProcessing_SetCutsceneDof();
   var8 = START_NEW_SCRIPT_WITH_ARGS("Game/CineScripts/generated/story/cut_story_hangout_series_hollywoodc_generated", &null, 0, 1500);
   while (!IsChildFinished(var8))
   {
       WAITUNWARPED(100);
   }
   PostProcessing_SetGameDof();
   var9 = mcMissionManager_GetMission("HANGOUT_SERIES_HOLLYWOODC");
   mcMission_ChangeState(var9, 3, 0);
   mcEvent_PostEventStr("CAREER_AUTOSAVE", "");
}

