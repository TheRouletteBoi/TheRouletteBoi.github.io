void main()
{
    l_U0 = "drv_mp_01_set";
    l_U1 = "drv_mp_01_lod02_set";
    l_U2 = "drv_ma_03_set";
    l_U3 = "drv_ma_02_set";
    l_U4 = "drv_ma_001_set";
    l_U5 = "drv_fa_001_set";
    l_U6 = "drv_mb_02_set";
    l_U7 = "drv_mb_03_set";
    l_U8 = "drv_mb_04_set";
    l_U9 = "drv_mb_05_set";
    l_U10 = "drv_mb_007_set";
    l_U11 = "drv_mb_008_set";
    l_U12 = "drv_mb_010_set";
    l_U13 = "drv_mb_001_set";
    l_U14 = "drv_mb_009_set";
    l_U15 = "drv_mb_06_set";
    l_U16 = "drv_fb_01_set";
    l_U17 = "drv_mc_02_set";
    l_U18 = "drv_mc_06_set";
    l_U19 = "drv_mc_07_set";
    l_U20 = "drv_mc_003_set";
    l_U21 = "drv_mc_05_set";
    l_U22 = "drv_mc_001_set";
    l_U23 = "drv_fc_002_set";
    l_U24 = "drv_mh_01_set";
    l_U25 = "drv_mh_02_set";
    l_U26 = "drv_mh_003_set";
    l_U27 = "drv_mh_005_set";
    l_U28 = "drv_mh_04_set";
    l_U29 = "drv_mh_006_set";
    l_U30 = "drv_fh_001_set";
    l_U31 = "mec_mc_01_set";
    l_U32 = "ped_ma_001_set";
    l_U33 = "ped_mb_001_set";
    l_U34 = "ped_mc_001_set";
    l_U35 = "ped_mh_001_set";
    l_U36 = "pol_mc_01_set";
    l_U87 = 0;
    l_U88 = -1;
    l_U89 = 1;
    if (NOT (l_U122._fU0 == 3))
    {
        l_U122._fU0 = 2;
        PRINTSTRING( "Script: Play Logo here?\n" );
        PRINTSTRING( "Script: Play Intro movie here?\n" );
        StrCopy( ref l_U90, "LA", 64 );
        StrCopy( ref l_U106, "vp_mit_3000gt_99", 64 );
        Registry_SetValueString( "raceOverCommand", "" );
        l_U69 = 2;
        while (NOT (l_U69 == 0))
        {
            l_U86 = l_U69;
            l_U69 = 0;
            switch (l_U86)
            {
                case 1:
                PRINTSTRING( "Script: Going into a Movie!\n" );
                sub_1034( l_U70 );
                break;
                case 2:
                PRINTSTRING( "Script: Going into a Game!\n" );
                sub_1449();
                break;
            }
        }
    }
    WAIT( 1000 );
    PRINTSTRING( "Script: Play splash?\n" );
    while (true)
    {
        WAIT( 100 );
    }
    return;
}

void sub_1034(unknown uParam0, unknown uParam1, unknown uParam2, unknown uParam3, unknown uParam4, unknown uParam5, unknown uParam6, unknown uParam7, unknown uParam8, unknown uParam9, unknown uParam10, unknown uParam11, unknown uParam12, unknown uParam13, unknown uParam14, unknown uParam15)
{
    unknown uVar18;
    int iVar19;

    uVar18 = UIManager_LoadMovie( "Menu", ref uParam0, 500, 100, 10000, 0 );
    StrCopy( ref l_U37, "C_SWITCHMODULE_TRIG", 64 );
    iVar19 = 0;
    while (iVar19 == 0)
    {
        FlashHelper_GetGlobalInt( uVar18, ref l_U37, ref iVar19 );
        WAIT( 100 );
    }
    StrCopy( ref l_U37, "C_NEXTMODULE_NAME", 64 );
    FlashHelper_GetGlobalString( uVar18, ref l_U37, ref l_U53 );
    l_U69 = sub_1196( l_U53 );
    StrCopy( ref l_U37, "C_NEXTMODULE_DESC", 64 );
    FlashHelper_GetGlobalString( uVar18, ref l_U37, ref l_U70 );
    if (l_U69 == 2)
    {
        StrCopy( ref l_U90, "LA", 64 );
        FlashHelper_GetGlobalInt( uVar18, "d_careermode_id", ref l_U89 );
    }
    UIManager_UnloadMovie( "Menu" );
    return;
}

int sub_1196(unknown uParam0, unknown uParam1, unknown uParam2, unknown uParam3, unknown uParam4, unknown uParam5, unknown uParam6, unknown uParam7, unknown uParam8, unknown uParam9, unknown uParam10, unknown uParam11, unknown uParam12, unknown uParam13, unknown uParam14, unknown uParam15)
{
    if (StringCaseCompare( ref uParam0, "INGAME" ))
    {
        return 2;
        break;
    }
    if (StringCaseCompare( ref uParam0, "PUSHMOVIE" ))
    {
        return 1;
        break;
    }
    return 0;
}

void sub_1449()
{
    boolean bVar2;
    int iVar3;
    unknown uVar4;
    unknown uVar5;
    int iVar6;
    unknown uVar7;
    unknown uVar8;
    unknown uVar9;
    unknown uVar10;
    unknown uVar11;
    unknown uVar12;
    unknown uVar13;
    unknown uVar14;
    unknown uVar15;
    unknown uVar16;
    unknown uVar17;
    unknown uVar18;
    int iVar19;
    unknown uVar20;
    unknown uVar21;
    unknown uVar22;
    unknown uVar23;
    unknown uVar24;
    int iVar25;
    unknown uVar26;
    unknown uVar27;
    unknown uVar28;
    int iVar29;
    unknown uVar30;

    bVar2 = NOT GetNoCareerCommandLine();
    PRINTSTRING( "Playing Game\n" );
    iVar3 = 0;
    uVar4 = GetCityCommandLine( ref iVar3 );
    if (NOT (iVar3 == 0))
    {
        StrCopy( ref l_U90, uVar4, 64 );
    }
    uVar5 = LookupCity( ref l_U90 );
    LayerCity_LoadCity( ref l_U90 );
    LayerAmbients_LoadAmbients( ref l_U90 );
    iVar6 = 0;
    uVar7 = GetCarCommandLine( ref iVar6 );
    if ((bVar2) || (iVar6 != 0))
    {
        uVar8 = UIManager_LoadMovie( "HUDMAPMOVIE", "hudmap/hudmap.swf", 150, 200, 10000, 0 );
        uVar9 = UIManager_LoadMovie( "SIDEKICKMOVIE", "sidekick/sidekick.swf", 50, 50, 10000, 0 );
        uVar10 = UIManager_LoadMovie( "PHOTOALBUMMOVIE", "photoalbum/photoalbum.swf", 300, 500, 10000, 0 );
        uVar11 = UIManager_LoadMovie( "NAVSYS2DMOVIE", "navsys2d/navsys2d.swf", 400, 200, 10000, 0 );
        UIManager_LoadHUD();
        UILogic_PreLoad();
        uVar12 = UIManager_LoadMovie( "PAUSEMOVIE", "pause/pause.swf", 2400, 1500, 10000, 1 );
        uVar13 = UIManager_LoadMovie( "NAVSYSMOVIE", "navsys/navsys.swf", 3100, 1600, 10000, 0 );
        uVar14 = UIManager_LoadMovie( "NAVSYSTARGETICONMOVIE", "navsys_target/navsys_target.swf", 20, 20, 10000, 0 );
        uVar15 = UIManager_LoadMovie( "PROMPTMOVIE", "prompt/prompt.swf", 300, 100, 10000, 1 );
        uVar16 = UIManager_LoadMovie( "TRANSITIONMOVIE", "transition/transition.swf", 50, 50, 10000, 0 );
        uVar17 = UIManager_LoadMovie( "POPUPMOVIE", "popup/popup.swf", 1700, 1500, 10000, 1 );
        UILogic_PostLoad();
        UIManager_LoadStates();
        sub_2200();
    }
    if (bVar2)
    {
        uVar18 = START_NEW_SCRIPT( "Game/Flow/PressStart", 1500 );
        while (NOT (IsChildFinished( uVar18 )))
        {
            WAITUNWARPED( 30 );
        }
    }
    else
    {
        Game_SetLoadingDone();
        AudioManager_StopLoadingMusic();
        WAIT( 1500 );
        Game_FadeLoadscreenLogo( 1 );
        Game_LoadScreenShutdown();
        mcEvent_PostEventStr( "EVENT_START_SCREEN_EXIT", "" );
    }
    iVar19 = nil;
    uVar20 = nil;
    if ((NOT bVar2) AND (iVar6 != 0))
    {
        CityDescription_GetDefaultStartPosition( uVar5, ref uVar21, ref uVar24 );
        if (GetNetDemoCommandLine())
        {
            LocalOptions_AddVehicleToPlayer( "DEMO_vp_mzd_rx7_95" );
            LocalOptions_AddVehicleToPlayer( "DEMO_vp_mit_evo_06" );
            LocalOptions_AddVehicleToPlayer( "DEMO_vp_nsn_skyline_99" );
            LocalOptions_AddVehicleToPlayer( "DEMO_vp_mit_3000gt_99" );
            LocalOptions_AddVehicleToPlayer( "DEMO_vp_aud_rs4_07" );
            LocalOptions_AddVehicleToPlayer( "DEMO_vp_sln_s281_06" );
            LocalOptions_AddVehicleToPlayer( "DEMO_vp_nsn_350z_06" );
            LocalOptions_AddVehicleToPlayer( "DEMO_vp_dge_charger_06" );
            iVar25 = RAND_INT_RANGE( 0, 7 );
        }
        else
        {
            iVar25 = LocalOptions_AddVehicleToPlayer( uVar7 );
            if (iVar25 == -1)
            {
                PRINTSTRING( "BOOT - Attempt to load a default car config\n" );
                uVar26 = mcCarConfig_Create( uVar7 );
                iVar25 = LocalOptions_AddConfigToPlayer( uVar26 );
                mcCarConfig_Destroy( uVar26 );
            }
        }
        LocalOptions_SetCurrentVehicleProfileIndex( iVar25 );
        uVar27 = LocalOptions_GetVehicleProfile( iVar25 );
        LayerPlayer_LoadPlayer( 0, uVar27, ref uVar21, uVar24 );
        iVar19 = Player_FindObject( 0 );
        uVar20 = Player_GetRacer( iVar19 );
        Racer_SetStreamLockState( uVar20, 1 );
        Racer_InitializeResetPosition( uVar20, ref uVar21, uVar24 );
        Racer_SetUIDAndCharacterName( uVar20, 50, l_U0 );
        Racer_Reset( uVar20 );
        mcTargetManager_RegisterPlayer( 50, iVar19 );
        uVar28 = mcHudMapServer_CreateElement();
        mcHudMapServer_SetVehicleElement( uVar28, 0, uVar20 );
        mcHudMapServer_AddElement( uVar28 );
        mcEvent_PostEventStr( "EVENT_PRE_PLAYER_LOAD", "" );
        while (NOT (Racer_IsCarStreamed( uVar20 )))
        {
            WAITUNWARPED( 100 );
        }
        if (NOT (l_U88 == -1))
        {
            Racer_SetModValue( uVar20, l_U88 );
        }
        PRINTSTRING( "PLAYER HAS BEEN LOADED\n" );
        START_NEW_SCRIPT_WITH_ARGS( "Game/Flow/BootDebug", ref nil, 0, 1500 );
        mcEvent_PostEventStr( "EVENT_POST_PLAYER_LOAD", "" );
        mcGame_ThrowEvent( "cruising" );
        mcCareer_StartNewScript( "Game/MiscTasks/SoundTriggers", 1500 );
    }
    else if (bVar2)
    {
        WAIT( 30 );
        while (iVar19 == nil)
        {
            iVar19 = Player_FindObject( 0 );
            WAITUNWARPED( 30 );
        }
        uVar20 = Player_GetRacer( iVar19 );
        while (NOT (Racer_IsCarStreamed( uVar20 )))
        {
            WAITUNWARPED( 30 );
        }
        mcEvent_PostEventStr( "EVENT_POST_PLAYER_LOAD", "" );
    }
    iVar29 = 0;
    uVar30 = GetExtraCarCommandLine( ref iVar29 );
    if (iVar29 != 0)
    {
        if ((LocalOptions_LookupVehicleProfile( uVar30 )) == -1)
        {
            LocalOptions_AddVehicleToPlayer( uVar30 );
        }
    }
    sub_14247();
    WAIT( 10000 );
    return;
}

void sub_2200()
{
    CineScript_Characters_RegisterDriverMappings( "drv_mp_01_set", "drv_mp_01_set_h", "character/drv_mp_01_set_h/", "drv_mp_01_mot_set_h", "character/drv_mp_01_mot_set_h/", "drv_mp_01_set_HackedScale", "character/drv_mp_01_set_HackedScale/", "drv_mp_jacket_01_set_hackedscale", "character/drv_mp_jacket_01_set_hackedscale/", "drv_mp_01_lod02_set", "character/drv_mp_01_lod02_set/", "drv_mp_01_mot_lod02_set", "character/drv_mp_01_mot_lod02_set/" );
    CineScript_Characters_RegisterDriverMappings( "drv_ma_03_set", "drv_ma_03_set_h", "character/drv_ma_03_set_h", "drv_ma_03_mot_set_h", "character/drv_ma_03_mot_set_h", "drv_ma_03_set_HackedScale", "character/drv_ma_03_set_HackedScale", "drv_ma_03_set_HackedScale", "character/drv_ma_03_set_HackedScale", "drv_ma_03_lod02_set", "character/drv_ma_03_lod02_set", "drv_ma_03_mot_lod02_set", "character/drv_ma_03_mot_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_001_set", "drv_mb_001_set_h", "character/drv_mb_001_set_h", "drv_mb_001_mot_set_h", "character/drv_mb_001_mot_set_h", "drv_mb_001_set_HackedScale", "character/drv_mb_001_set_HackedScale", "drv_mb_001_set_HackedScale", "character/drv_mb_001_set_HackedScale", "drv_mb_001_lod02_set", "character/drv_mb_001_lod02_set", "drv_mb_001_mot_lod02_set", "character/drv_mb_001_mot_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_009_set", "drv_mb_009_set_h", "character/drv_mb_009_set_h", "drv_mb_009_mot_set_h", "character/drv_mb_009_mot_set_h", "drv_mb_009_set", "character/drv_mb_009_set", "drv_mb_009_set", "character/drv_mb_009_set", "drv_mb_009_lod02_set", "character/drv_mb_009_lod02_set", "drv_mb_009_mot_lod02_set", "character/drv_mb_009_mot_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mc_001_set", "drv_mc_001_set_h", "character/drv_mc_001_set_h", "drv_mc_001_mot_set_h", "character/drv_mc_001_mot_set_h", "drv_mc_001_set_HackedScale", "character/drv_mc_001_set_HackedScale", "drv_mc_001_set_HackedScale", "character/drv_mc_001_set_HackedScale", "drv_mc_001_lod02_set", "character/drv_mc_001_lod02_set", "drv_mc_001_mot_lod02_set", "character/drv_mc_001_mot_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mc_07_set", "drv_mc_07_set_h", "character/drv_mc_07_set_h", "drv_mc_07_mot_set_h", "character/drv_mc_07_mot_set_h", "drv_mc_07_set", "character/drv_mc_07_set", "drv_mc_07_set", "character/drv_mc_07_set", "drv_mc_07_lod02_set", "character/drv_mc_07_lod02_set", "drv_mc_07_mot_lod02_set", "character/drv_mc_07_mot_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mh_005_set", "drv_mh_005_set_h", "character/drv_mh_005_set_h", "drv_mh_005_mot_set_h", "character/drv_mh_005_mot_set_h", "drv_mh_005_set", "character/drv_mh_005_set", "drv_mh_005_set", "character/drv_mh_005_set", "drv_mh_005_lod02_set", "character/drv_mh_005_lod02_set", "drv_mh_005_mot_lod2_set", "character/drv_mh_005_mot_lod2_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_fh_001_set", "drv_fh_001_set_h", "character/drv_fh_001_set_h", "drv_fh_001_mot_set_h", "character/drv_fh_001_mot_set_h", "drv_fh_001_set", "character/drv_fh_001_set", "drv_fh_001_set", "character/drv_fh_001_set", "drv_fh_001_lod02_set", "character/drv_fh_001_lod02_set", "drv_fh_001_mot_lod02_set", "character/drv_fh_001_mot_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_ma_001_set", "drv_ma_001_set_h", "character/drv_ma_001_set_h", "drv_ma_001_mot_set_h", "character/drv_ma_001_mot_set_h", "drv_ma_001_set_HackedScale", "character/drv_ma_001_set_HackedScale", "drv_ma_001_set_HackedScale", "character/drv_ma_001_set_HackedScale", "drv_ma_001_lod02_set", "character/drv_ma_001_lod02_set", "drv_ma_001_lod02_set", "character/drv_ma_001_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_ma_02_set", "drv_ma_02_set_h", "character/drv_ma_02_set_h", "drv_ma_02_mot_set_h", "character/drv_ma_02_mot_set_h", "drv_ma_02_set", "character/drv_ma_02_set", "drv_ma_02_set", "character/drv_ma_02_set", "drv_ma_02_lod02_set", "character/drv_ma_02_lod02_set", "drv_ma_02_lod02_set", "character/drv_ma_02_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_02_set", "drv_mb_02_set_h", "character/drv_mb_02_set_h", "drv_mb_02_set_h", "character/drv_mb_02_set_h", "drv_mb_02_set", "character/drv_mb_02_set", "drv_mb_02_set", "character/drv_mb_02_set", "drv_mb_02_lod02_set", "character/drv_mb_02_lod02_set", "drv_mb_02_lod02_set", "character/drv_mb_02_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_03_set", "drv_mb_03_set_h", "character/drv_mb_03_set_h", "drv_mb_03_set_h", "character/drv_mb_03_set_h", "drv_mb_03_set", "character/drv_mb_03_set", "drv_mb_03_set", "character/drv_mb_03_set", "drv_mb_03_lod02_set", "character/drv_mb_03_lod02_set", "drv_mb_03_lod02_set", "character/drv_mb_03_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_04_set", "drv_mb_04_set_h", "character/drv_mb_04_set_h", "drv_mb_04_set_h", "character/drv_mb_04_set_h", "drv_mb_04_set_HackedScale", "character/drv_mb_04_set_HackedScale", "drv_mb_04_set_HackedScale", "character/drv_mb_04_set_HackedScale", "drv_mb_04_lod02_set", "character/drv_mb_04_lod02_set", "drv_mb_04_lod02_set", "character/drv_mb_04_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_05_set", "drv_mb_05_set_h", "character/drv_mb_05_set_h", "drv_mb_05_set_h", "character/drv_mb_05_set_h", "drv_mb_05_set", "character/drv_mb_05_set", "drv_mb_05_set", "character/drv_mb_05_set", "drv_mb_05_lod02_set", "character/drv_mb_05_lod02_set", "drv_mb_05_lod02_set", "character/drv_mb_05_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_06_set", "drv_mb_06_set_h", "character/drv_mb_06_set_h", "drv_mb_06_set_h", "character/drv_mb_06_set_h", "drv_mb_06_set", "character/drv_mb_06_set", "drv_mb_06_set", "character/drv_mb_06_set", "drv_mb_06_lod02_set", "character/drv_mb_06_lod02_set", "drv_mb_06_lod02_set", "character/drv_mb_06_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_007_set", "drv_mb_007_set_h", "character/drv_mb_007_set_h", "drv_mb_007_set_h", "character/drv_mb_007_set_h", "drv_mb_007_set", "character/drv_mb_007_set", "drv_mb_007_set", "character/drv_mb_007_set", "drv_mb_007_lod02_set", "character/drv_mb_007_lod02_set", "drv_mb_007_lod02_set", "character/drv_mb_007_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_008_set", "drv_mb_008_set_h", "character/drv_mb_008_set_h", "drv_mb_008_set_h", "character/drv_mb_008_set_h", "drv_mb_008_set_HackedScale", "character/drv_mb_008_set_HackedScale", "drv_mb_008_set_HackedScale", "character/drv_mb_008_set_HackedScale", "drv_mb_008_lod02_set", "character/drv_mb_008_lod02_set", "drv_mb_008_lod02_set", "character/drv_mb_008_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mb_010_set", "drv_mb_010_set_h", "character/drv_mb_010_set_h", "drv_mb_010_set_h", "character/drv_mb_010_set_h", "drv_mb_010_set", "character/drv_mb_010_set", "drv_mb_010_set", "character/drv_mb_010_set", "drv_mb_010_lod02_set", "character/drv_mb_010_lod02_set", "drv_mb_010_lod02_set", "character/drv_mb_010_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mc_02_set", "drv_mc_02_set_h", "character/drv_mc_02_set_h", "drv_mc_02_set_h", "character/drv_mc_02_set_h", "drv_mc_02_set_HackedScale", "character/drv_mc_02_set_HackedScale", "drv_mc_02_set_HackedScale", "character/drv_mc_02_set_HackedScale", "drv_mc_02_lod02_set", "character/drv_mc_02_lod02_set", "drv_mc_02_lod02_set", "character/drv_mc_02_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mc_003_set", "drv_mc_003_set_h", "character/drv_mc_003_set_h", "drv_mc_003_set_h", "character/drv_mc_003_set_h", "drv_mc_003_set_HackedScale", "character/drv_mc_003_set_HackedScale", "drv_mc_003_set_HackedScale", "character/drv_mc_003_set_HackedScale", "drv_mc_003_lod02_set", "character/drv_mc_003_lod02_set", "drv_mc_003_lod02_set", "character/drv_mc_003_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mc_05_set", "drv_mc_05_set_h", "character/drv_mc_05_set_h", "drv_mc_05_set_h", "character/drv_mc_05_set_h", "drv_mc_05_set", "character/drv_mc_05_set", "drv_mc_05_set", "character/drv_mc_05_set", "drv_mc_05_lod02_set", "character/drv_mc_05_lod02_set", "drv_mc_05_lod02_set", "character/drv_mc_05_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mc_06_set", "drv_mc_06_set_h", "character/drv_mc_06_set_h", "drv_mc_06_set_h", "character/drv_mc_06_set_h", "drv_mc_06_set", "character/drv_mc_06_set", "drv_mc_06_set", "character/drv_mc_06_set", "drv_mc_06_lod02_set", "character/drv_mc_06_lod02_set", "drv_mc_06_lod02_set", "character/drv_mc_06_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mh_01_set", "drv_mh_01_set_h", "character/drv_mh_01_set_h", "drv_mh_01_set_h", "character/drv_mh_01_set_h", "drv_mh_01_set", "character/drv_mh_01_set", "drv_mh_01_set", "character/drv_mh_01_set", "drv_mh_01_lod02_set", "character/drv_mh_01_lod02_set", "drv_mh_01_lod02_set", "character/drv_mh_01_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mh_02_set", "drv_mh_02_set_h", "character/drv_mh_02_set_h", "drv_mh_02_set_h", "character/drv_mh_02_set_h", "drv_mh_02_set_HackedScale", "character/drv_mh_02_set_HackedScale", "drv_mh_02_set_HackedScale", "character/drv_mh_02_set_HackedScale", "drv_mh_02_lod02_set", "character/drv_mh_02_lod02_set", "drv_mh_02_lod02_set", "character/drv_mh_02_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mh_003_set", "drv_mh_003_set_h", "character/drv_mh_003_set_h", "drv_mh_003_set_h", "character/drv_mh_003_set_h", "drv_mh_003_set", "character/drv_mh_003_set", "drv_mh_003_set", "character/drv_mh_003_set", "drv_mh_003_lod02_set", "character/drv_mh_003_lod02_set", "drv_mh_003_lod02_set", "character/drv_mh_003_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mh_04_set", "drv_mh_04_set_h", "character/drv_mh_04_set_h", "drv_mh_04_mot_set_h", "character/drv_mh_04_mot_set_h", "drv_mh_04_set", "character/drv_mh_04_set", "drv_mh_04_set", "character/drv_mh_04_set", "drv_mh_04_lod02_set", "character/drv_mh_04_lod02_set", "drv_mh_04_lod02_set", "character/drv_mh_04_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_mh_006_set", "drv_mh_006_set_h", "character/drv_mh_006_set_h", "drv_mh_006_set_h", "character/drv_mh_006_set_h", "drv_mh_006_set_HackedScale", "character/drv_mh_006_set_HackedScale", "drv_mh_006_set_HackedScale", "character/drv_mh_006_set_HackedScale", "drv_mh_006_lod02_set", "character/drv_mh_006_lod02_set", "drv_mh_006_lod02_set", "character/drv_mh_006_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_fb_01_set", "drv_fb_01_set_h", "character/drv_fb_01_set_h", "drv_fb_01_set_h", "character/drv_fb_01_set_h", "drv_fb_01_set", "character/drv_fb_01_set", "drv_fb_01_set", "character/drv_fb_01_set", "drv_fb_01_lod02_set", "character/drv_fb_01_lod02_set", "drv_fb_01_lod02_set", "character/drv_fb_01_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_fc_002_set", "drv_fc_002_set_h", "character/drv_fc_002_set_h", "drv_fc_002_set_h", "character/drv_fc_002_set_h", "drv_fc_002_set_HackedScale", "character/drv_fc_002_set_HackedScale", "drv_fc_002_set_HackedScale", "character/drv_fc_002_set_HackedScale", "drv_fc_002_lod02_set", "character/drv_fc_002_lod02_set", "drv_fc_002_lod02_set", "character/drv_fc_002_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_fa_001_set", "drv_fa_001_set_h", "character/drv_fa_001_set_h", "drv_fa_001_set_h", "character/drv_fa_001_set_h", "drv_fa_001_set", "character/drv_fa_001_set", "drv_fa_001_set", "character/drv_fa_001_set", "drv_fa_001_lod02_set", "character/drv_fa_001_lod02_set", "drv_fa_001_lod02_set", "character/drv_fa_001_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "drv_fc_003_set", "drv_fc_003_set_h", "character/drv_fc_003_set_h", "drv_fc_003_set_h", "character/drv_fc_003_set_h", "drv_fc_003_set_HackedScale", "character/drv_fc_003_set_HackedScale", "drv_fc_003_set_HackedScale", "character/drv_fc_003_set_HackedScale", "drv_fc_003_lod02_set", "character/drv_fc_003_lod02_set", "drv_fc_003_lod02_set", "character/drv_fc_003_lod02_set" );
    CineScript_Characters_RegisterDriverMappings( "mec_mc_01_set", "mec_mc_01_set", "character/mec_mc_01_set", "mec_mc_01_set", "character/mec_mc_01_set", "mec_mc_01_set_HackedScale", "character/mec_mc_01_set_HackedScale", "mec_mc_01_set_HackedScale", "character/mec_mc_01_set_HackedScale", "mec_mc_01_lod02_set", "character/mec_mc_01_lod02_set", "mec_mc_01_lod02_set", "character/mec_mc_01_lod02_set" );
    return;
}

void sub_14247()
{
    string[3] sVar2;
    vector[3] vVar6;
    unknown uVar10;
    unknown uVar11;
    unknown uVar12;
    unknown uVar13;
    unknown uVar14;
    unknown uVar15;
    float[3] fVar16;
    vector[3] vVar20;
    unknown uVar24;
    unknown uVar25;
    unknown uVar26;
    unknown uVar27;
    unknown uVar28;
    unknown uVar29;
    unknown[3] uVar30;
    int I;

    array(ref sVar2, 3);
    array(ref vVar6, 3);
    array(ref fVar16, 3);
    array(ref vVar20, 3);
    sVar2[0] = "vp_chv_police_96";
    vVar6[0] = {2030.10000000, 6.80000000, -813.70000000};
    fVar16[0] = 90;
    vVar20[0] = {-510.00000000, 9.50000000, -400.00000000};
    sVar2[1] = "vp_chv_police_96";
    vVar6[1] = {-646.80000000, 18.50000000, -643.80000000};
    fVar16[1] = 90;
    vVar20[1] = {-500.00000000, 9.50000000, -400.00000000};
    sVar2[2] = "vp_chv_police_96";
    vVar6[2] = {-2434.40000000, 1.90000000, -577.90000000};
    fVar16[2] = 84.90000000;
    vVar20[2] = {-490.00000000, 9.50000000, -400.00000000};
    array(ref uVar30, 3);
    for ( I = 0; I < 3; I++ )
    {
        uVar30[I] = PoliceManager_CreatePolice( sVar2[I], 1, ref vVar6[I], fVar16[I], ref vVar20[I], 400 + I );
    }
    return;
}
