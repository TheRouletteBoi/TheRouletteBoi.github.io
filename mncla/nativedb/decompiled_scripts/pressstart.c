void main()
{
    unknown uVar2;
    int iVar3;
    unknown uVar4;
    unknown uVar5;
    unknown uVar6;
    unknown uVar7;

    uVar2 = Graphics_GetAndSetAutoUpdateTimeOfDay( 0 );
    iVar3 = -1;
    if (GetDemoCommandLine())
    {
        iVar3 = 0;
    }
    else
    {
        iVar3 = sub_42();
    }
    SetPlayerPadIndex( 0, iVar3 );
    PRINTSTRING( "Startpad " );
    PRINTINT( iVar3 );
    PRINTSTRING( "\n" );
    sub_2459();
    MoviePlayer_StopMovie();
    Game_FadeLoadscreenLogo( 1 );
    Game_LoadScreenShutdown();
    Graphics_SetMovieRenderingMode( 0 );
    Graphics_GetAndSetAutoUpdateTimeOfDay( uVar2 );
    AmbientMgr_SetFrontEnd( 0, 0, 0, 0, 0, 0 );
    Warper_SetUseCinematicWarp( 0 );
    Warper_SetPauseCameraAtEndOfWarp();
    Warper_Warp( "MAXHEIGHT" );
    while (NOT Warper_IsReadyToLoadStuff())
    {
        WAITUNWARPED( 10 );
        PRINTSTRING( "Waiting for gps transition to finish\n" );
    }
    CityDescription_GetDefaultStartPosition( LookupCity( GetCurrentCity() ), ref uVar4, ref uVar7 );
    UILogic_LockStreamingPosHeading( ref uVar4, uVar7 );
    mcEvent_PostEventStr( "EVENT_START_SCREEN_EXIT", "" );
    return;
}

void sub_42()
{
    int Result;
    int iVar3;
    int iVar4;
    boolean bVar5;
    vector[7] vVar6;
    unknown uVar14;
    unknown uVar15;
    unknown uVar16;
    unknown uVar17;
    unknown uVar18;
    unknown uVar19;
    unknown uVar20;
    unknown uVar21;
    unknown uVar22;
    unknown uVar23;
    unknown uVar24;
    unknown uVar25;
    unknown uVar26;
    unknown uVar27;
    vector[7] vVar28;
    unknown uVar36;
    unknown uVar37;
    unknown uVar38;
    unknown uVar39;
    unknown uVar40;
    unknown uVar41;
    unknown uVar42;
    unknown uVar43;
    unknown uVar44;
    unknown uVar45;
    unknown uVar46;
    unknown uVar47;
    unknown uVar48;
    unknown uVar49;
    float[7] fVar50;
    float[7] fVar58;
    int[7] iVar66;
    float[7] fVar74;
    float[7] fVar82;
    float[7] fVar90;
    float[7] fVar98;
    float[7] fVar106;
    float[7] fVar114;
    float[7] fVar122;
    float[7] fVar130;
    int[7] iVar138;
    int iVar146;
    int iVar147;
    boolean bVar148;
    boolean bVar149;
    boolean bVar150;
    int I;

    Result = -1;
    iVar3 = -1;
    iVar4 = -1;
    bVar5 = false;
    array(ref vVar6, 7);
    array(ref vVar28, 7);
    array(ref fVar50, 7);
    array(ref fVar58, 7);
    array(ref iVar66, 7);
    array(ref fVar74, 7);
    array(ref fVar82, 7);
    array(ref fVar90, 7);
    array(ref fVar98, 7);
    array(ref fVar106, 7);
    array(ref fVar114, 7);
    array(ref fVar122, 7);
    array(ref fVar130, 7);
    array(ref iVar138, 7);
    vVar6[0] = {2903.00000000, 83.00000000, 22.60000000};
    vVar28[0] = {-0.99300000, -0.10600000, 0.04400000};
    fVar50[0] = 39.20000000;
    fVar58[0] = 5.77600000;
    iVar66[0] = 1;
    fVar74[0] = 2000;
    fVar82[0] = 3000;
    fVar106[0] = 0.06000000;
    fVar114[0] = 0;
    fVar122[0] = 0.10000000;
    fVar130[0] = 425;
    iVar138[0] = 4;
    vVar6[1] = {-2932.90000000, -14.30000000, 368.40000000};
    vVar28[1] = {-0.85400000, 0.16500000, 0.49400000};
    fVar50[1] = 40.40000000;
    fVar58[1] = 17.81900000;
    fVar106[1] = 0;
    fVar114[1] = 0;
    fVar122[1] = 0.10000000;
    fVar130[1] = 200;
    iVar138[1] = 4;
    vVar6[2] = {-339.00000000, 44.10000000, -753.20000000};
    vVar28[2] = {0.96300000, -0.15000000, 0.22500000};
    fVar50[2] = 34.80000000;
    fVar58[2] = 6.49800000;
    fVar106[2] = 0;
    fVar114[2] = 0.05000000;
    fVar122[2] = 0.10000000;
    fVar130[2] = 162;
    iVar138[2] = 4;
    vVar6[3] = {2531.00000000, 9.00000000, 141.80000000};
    vVar28[3] = {-0.99600000, 0.08800000, 0.01000000};
    fVar50[3] = 41.00000000;
    fVar58[3] = 16.75200000;
    fVar74[3] = 800;
    fVar82[3] = 3000;
    fVar90[3] = 100;
    fVar98[3] = 1500;
    fVar106[3] = 0;
    fVar114[3] = 0.16500000;
    fVar122[3] = 0.10000000;
    fVar130[3] = 131;
    iVar138[3] = 5;
    vVar6[4] = {864.90000000, 39.80000000, -1415.10000000};
    vVar28[4] = {0.63300000, 0.13500000, -0.76200000};
    fVar50[4] = 32.90000000;
    fVar58[4] = 14.81000000;
    fVar74[4] = 800;
    fVar82[4] = 3000;
    fVar90[4] = 100;
    fVar98[4] = 1500;
    fVar106[4] = 0.00000000;
    fVar114[4] = 0.03700000;
    fVar122[4] = 0.10000000;
    fVar130[4] = 265;
    iVar138[4] = 4;
    vVar6[5] = {-2603.60000000, 2.80000000, 239.30000000};
    vVar28[5] = {-0.37100000, -0.00400000, -0.92900000};
    fVar50[5] = 33.30000000;
    fVar58[5] = 10.40000000;
    fVar74[5] = 900;
    fVar82[5] = 3000;
    fVar106[5] = 0;
    fVar114[5] = 0;
    fVar122[5] = 0.10000000;
    fVar130[5] = 226;
    iVar138[5] = 4;
    vVar6[6] = {939.20000000, 59.60000000, 739.70000000};
    vVar28[6] = {0.50800000, -0.21000000, -0.83500000};
    fVar50[6] = 50.50000000;
    fVar58[6] = 18.00000000;
    iVar66[6] = 1;
    fVar74[6] = 3500;
    fVar82[6] = 4000;
    fVar106[6] = 0.05500000;
    fVar114[6] = 0;
    fVar122[6] = 0.10000000;
    fVar130[6] = 270;
    iVar138[6] = 4;
    RAND_RESET();
    RAND_RESET();
    iVar146 = RAND_INT_RANGE( 0, 6 );
    UILogic_SetPrompt( 0 );
    AmbientMgr_SetFrontEnd( 1, fVar106[iVar146], fVar114[iVar146], fVar122[iVar146], fVar130[iVar146], iVar138[iVar146] );
    sub_1448( vVar6[iVar146], vVar28[iVar146], fVar50[iVar146], fVar58[iVar146], iVar66[iVar146], fVar74[iVar146], fVar82[iVar146], fVar90[iVar146], fVar98[iVar146], 1 );
    iVar147 = Net_GetAchievementSetupStatus();
    if (iVar147 == 4)
    {
        UIManager_TransitionTo( "AchievementDataCorrupt" );
    }
    else if (iVar147 == 5)
    {
        UIManager_TransitionTo( "AchievementRequiresUpdate" );
    }
    else if (iVar147 == 2)
    {
        UIManager_TransitionTo( "AchievementInitFailed" );
    };;;
    bVar148 = UILogic_IsShowingDialog();
    if (NOT bVar148)
    {
        UILogic_SetPrompt( 27 );
    }
    SETTIMERA( 0 );
    bVar149 = false;
    bVar150 = false;
    if (bVar5)
    {
        MoviePlayer_StopMovie();
        bVar149 = MoviePlayer_StartMovie( "game:/attract", 0 );
        if (bVar149)
        {
            AudioManager_StopLoadingMusic();
        }
    }
    else
    {
        MoviePlayer_StopMovie();
        bVar149 = false;
    }
    while (Result == -1)
    {
        bVar148 = UILogic_IsShowingDialog();
        if (bVar148)
        {
            Game_FadeLoadscreenLogo( 1 );
            for ( I = 0; I < 4; I++ )
            {
                if (IS_PAD_BUTTON_DOWN( I, 6 ))
                {
                    UILogic_FireButtonPressedEvent( 52 );
                    UILogic_SetPrompt( 27 );
                }
            }
        }
        else
        {
            Game_FadeLoadscreenLogo( bVar149 );
            for ( I = 0; I < 4; I++ )
            {
                if (IS_PAD_BUTTON_DOWN( I, 11 ))
                {
                    Result = I;
                    AudioManager_PlayFrontendSound( "UI_MENU_SELECT" );
                }
                if (IS_PAD_BUTTON_DOWN( I, 6 ))
                {
                    iVar4 = I;
                }
            }
        }
        if (Result == -1)
        {
            Result = Net_GetJoinWishPad();
        }
        if (NOT bVar149)
        {
            if (iVar3 == Result)
            {
                Result = -1;
            }
            else
            {
                iVar3 = -1;
            }
            if ((bVar148) AND (NOT bVar150))
            {
                sub_2459();
                bVar150 = true;
            }
            else if ((NOT bVar148) AND (bVar150))
            {
                sub_2579();
                bVar150 = false;
            }
            if ((TIMERA() > 110000) AND (NOT bVar148))
            {
                sub_2710( 1, 1, 1065353216, 0 );
                sub_2459();
                MoviePlayer_StopMovie();
                WAIT( 0 );
                WAIT( 0 );
                WAIT( 0 );
                bVar149 = MoviePlayer_StartMovie( "game:/attract", 0 );
                if (bVar149)
                {
                    AudioManager_StopLoadingMusic();
                    Graphics_SetMovieRenderingMode( 1 );
                    WAIT( 0 );
                }
                SETTIMERA( 0 );
            }
            else
            {
                UILogic_SetPrompt( 27 );
            }
        }
        else
        {
            UILogic_SetPrompt( 0 );
            if (NOT MoviePlayer_IsMoviePlaying())
            {
                MoviePlayer_StopMovie();
                bVar149 = false;
                WAIT( 0 );
                WAIT( 0 );
                WAIT( 0 );
                Graphics_SetMovieRenderingMode( 0 );
                iVar146++;
                if (iVar146 >= 7)
                {
                    iVar146 = 0;
                }
                AmbientMgr_SetFrontEnd( 1, fVar106[iVar146], fVar114[iVar146], fVar122[iVar146], fVar130[iVar146], iVar138[iVar146] );
                sub_1448( vVar6[iVar146], vVar28[iVar146], fVar50[iVar146], fVar58[iVar146], iVar66[iVar146], fVar74[iVar146], fVar82[iVar146], fVar90[iVar146], fVar98[iVar146], 0 );
                sub_3938( 1, 1, 1065353216, 0 );
                UILogic_SetPrompt( 27 );
                if (bVar148)
                {
                    bVar150 = true;
                }
                else
                {
                    sub_2579();
                }
                SETTIMERA( 0 );
                AudioManager_StartLoadingMusic();
            }
            else if ((Result != -1) || (iVar4 != -1))
            {
                Graphics_SetMovieRenderingMode( 0 );
                sub_2459();
                MoviePlayer_StopMovie();
                WAIT( 0 );
                WAIT( 0 );
                WAIT( 0 );
                sub_3938( 1, 1, 1065353216, 0 );
                sub_2579();
                bVar149 = false;
                if (Result != -1)
                {
                    if (IS_PAD_BUTTON_DOWN( Result, 11 ))
                    {
                        iVar3 = Result;
                    }
                }
                Result = -1;
                UILogic_SetPrompt( 27 );
                AudioManager_StartLoadingMusic();
                SETTIMERA( 0 );
            }
        }
        iVar4 = -1;
        WAIT( 20 );
    }
    UILogic_SetPrompt( 0 );
    MoviePlayer_StopMovie();
    sub_2579();
    return Result;
}

void sub_1448(vector vParam0, vector vParam3, unknown uParam6, unknown uParam7, unknown uParam8, float fParam9, float fParam10, float fParam11, float fParam12, boolean bParam13)
{
    unknown uVar16;
    unknown uVar17;
    unknown uVar18;

    Graphics_WarpToTimeOfDay( uParam7, 100.00000000 );
    Weather_SetCurrentWeather( uParam8, 1 );
    if (fParam9 > 0.10000000)
    {
        PostProcessing_SetCutsceneDofNear( fParam9 );
    }
    if (fParam10 > 0.10000000)
    {
        PostProcessing_SetCutsceneDofFar( fParam10 );
        PostProcessing_SetCutsceneDof();
    }
    else
    {
        PostProcessing_SetGameDof();
    }
    if (fParam11 > 0.10000000)
    {
        ;
    }
    if (fParam12 > 0.10000000)
    {
        ;
    }
    uVar16 = {vParam0 + vParam3};
    sub_1597( vParam0, uVar16, uParam6 );
    if (bParam13)
    {
        sub_1748( vParam0, uVar16, uParam6 );
    }
    Game_SetCamera( ref vParam0, ref uVar16, uParam6, 0, 5.00000000, 10000.00000000 );
    return;
}

void sub_1597(unknown uParam0, unknown uParam1, unknown uParam2, unknown uParam3, unknown uParam4, unknown uParam5, unknown uParam6)
{
    Game_SetCamera( ref uParam0, ref uParam3, uParam6, 0, 5.00000000, 10000.00000000 );
    WAIT( 0 );
    WAIT( 0 );
    WAIT( 0 );
    PRINTSTRING( "About to wait for city\n" );
    while (NOT (City_DoneStreaming( 250 )))
    {
        WAIT( 10 );
    }
    City_SetSnapLODFade();
    return;
}

void sub_1748(unknown uParam0, unknown uParam1, unknown uParam2, unknown uParam3, unknown uParam4, unknown uParam5, unknown uParam6)
{
    Game_SetCamera( ref uParam0, ref uParam3, uParam6, 0, 5.00000000, 10000.00000000 );
    Game_SetLoadingDone();
    while (NOT Game_GetLoadingDone())
    {
        WAIT( 10 );
    }
    if (UILogic_IsShowingDialog())
    {
        Game_FadeLoadscreenLogo( 1 );
    }
    return;
}

void sub_2459()
{
    float fVar2;

    fVar2 = 1.00000000;
    while (fVar2 > 0.00000000)
    {
        fVar2 -= 0.10000000;
        MoviePlayer_SetTintColor( 1, 1, 1, fVar2 );
        WAIT( 30 );
    }
    MoviePlayer_SetTintColor( 1, 1, 1, 0 );
    return;
}

void sub_2579()
{
    float fVar2;

    fVar2 = 0.00000000;
    while (fVar2 < 1.00000000)
    {
        fVar2 += 0.10000000;
        MoviePlayer_SetTintColor( 1, 1, 1, fVar2 );
        WAIT( 30 );
    }
    MoviePlayer_SetTintColor( 1, 1, 1, 1 );
    return;
}

void sub_2710(boolean bParam0, boolean bParam1, unknown uParam2, unknown uParam3)
{
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;

    iVar6 = nil;
    while (iVar6 == nil)
    {
        iVar6 = UIManager_FindMovie( "TRANSITIONMOVIE" );
        if (iVar6 == nil)
        {
            PRINTSTRING( "SCRIPT: waiting for transition movie to stream in...\n" );
            WAITUNWARPED( 10 );
        }
    }
    iVar7 = 0;
    iVar8 = 0;
    iVar9 = 0;
    FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionout", ref iVar7 );
    FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionin", ref iVar8 );
    FlashHelper_GetGlobalInt( iVar6, "TransitionOutisReady", ref iVar9 );
    PRINTSTRING( "FADE DOWN REPORT\n" );
    PRINTSTRING( "================\n" );
    PRINTSTRING( "TransitionOut: " );
    PRINTINT( iVar7 );
    PRINTSTRING( "\nTransitionIn: " );
    PRINTINT( iVar8 );
    PRINTSTRING( "\nnTransitionReady: " );
    PRINTINT( iVar9 );
    PRINTSTRING( "\n" );
    if ((iVar8 == 0) AND ((iVar9 == 0) || ((iVar7 == 1) AND (iVar9 == 2))))
    {
        FlashHelper_SetMovieEnabled( iVar6, 1 );
        FlashHelper_SetGlobalInt( iVar6, "cur_visibility", 1 );
        FlashHelper_SetGlobalInt( iVar6, "mask_color", uParam3 );
        if (bParam1)
        {
            FlashHelper_SetGlobalInt( iVar6, "transition_type", 0 );
        }
        else
        {
            FlashHelper_SetGlobalInt( iVar6, "transition_type", 1 );
        }
        FlashHelper_SetGlobalFloat( iVar6, "fade_speed_in", uParam2 );
        FlashHelper_SetGlobalFloat( iVar6, "fade_speed_out", 0.01000000 );
        FlashHelper_SetGlobalInt( iVar6, "StartOfTransitionout", 0 );
        FlashHelper_SetGlobalInt( iVar6, "TransitionOutisReady", 0 );
        FlashHelper_SetGlobalInt( iVar6, "StartOfTransitionin", 1 );
        if (bParam0)
        {
            iVar8 = 1;
            while (iVar8 == 1)
            {
                FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionin", ref iVar8 );
                if (iVar8 == 1)
                {
                    WAITUNWARPED( 10 );
                }
            }
        }
    }
    return;
}

void sub_3938(boolean bParam0, boolean bParam1, unknown uParam2, unknown uParam3)
{
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;

    iVar6 = nil;
    while (iVar6 == nil)
    {
        iVar6 = UIManager_FindMovie( "TRANSITIONMOVIE" );
        if (iVar6 == nil)
        {
            WAITUNWARPED( 10 );
        }
    }
    iVar7 = 0;
    iVar8 = 0;
    iVar9 = 0;
    FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionout", ref iVar7 );
    FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionin", ref iVar8 );
    FlashHelper_GetGlobalInt( iVar6, "TransitionOutisReady", ref iVar9 );
    PRINTSTRING( "FADE UP REPORT\n" );
    PRINTSTRING( "==============\n" );
    PRINTSTRING( "TransitionOut: " );
    PRINTINT( iVar7 );
    PRINTSTRING( "\nTransitionIn: " );
    PRINTINT( iVar8 );
    PRINTSTRING( "\nnTransitionReady: " );
    PRINTINT( iVar9 );
    PRINTSTRING( "\n" );
    if ((iVar7 == 0) AND ((iVar8 != 0) || (iVar9 != 0)))
    {
        FlashHelper_SetMovieEnabled( iVar6, 1 );
        FlashHelper_SetGlobalInt( iVar6, "cur_visibility", 1 );
        FlashHelper_SetGlobalInt( iVar6, "mask_color", uParam3 );
        if (bParam1)
        {
            FlashHelper_SetGlobalInt( iVar6, "transition_type", 0 );
        }
        else
        {
            FlashHelper_SetGlobalInt( iVar6, "transition_type", 1 );
        }
        FlashHelper_SetGlobalFloat( iVar6, "fade_speed_in", 0.01000000 );
        FlashHelper_SetGlobalFloat( iVar6, "fade_speed_out", uParam2 );
        FlashHelper_SetGlobalInt( iVar6, "StartOfTransitionin", 0 );
        FlashHelper_SetGlobalInt( iVar6, "TransitionOutisReady", 2 );
        FlashHelper_SetGlobalInt( iVar6, "StartOfTransitionout", 1 );
        if (bParam0)
        {
            iVar7 = 1;
            while (iVar7 == 1)
            {
                FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionout", ref iVar7 );
                if (iVar7 == 1)
                {
                    PRINTSTRING( "SCRIPT: waiting for transition movie transition up...\n" );
                    WAITUNWARPED( 10 );
                }
            }
        }
    }
    return;
}
