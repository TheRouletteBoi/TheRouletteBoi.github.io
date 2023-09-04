void main()
{
    string[5] sVar2;
    vector[5] vVar8;
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
    float[5] fVar24;
    unknown[5] uVar30;
    unknown uVar36;
    int I;
    vector vVar38;
    vector vVar41;

    array(ref sVar2, 5);
    sVar2[0] = "starter_vp_vw_scirocco_88";
    sVar2[1] = "starter_vp_nsn_240sx_98";
    sVar2[2] = "starter_vp_vw_golf_83";
    sVar2[3] = "vp_nsn_240sx_98";
    sVar2[4] = "vp_chv_camaroSS_69";
    array(ref vVar8, 5);
    vVar8[0] = {-183.14000000, 18.29000000, -755.85000000};
    vVar8[1] = {-180.64000000, 18.29000000, -757.25000000};
    vVar8[2] = {-178.00000000, 18.27000000, -759.20000000};
    vVar8[3] = {-188.90000000, 18.60000000, -764.80000000};
    vVar8[4] = {-193.70000000, 18.70000000, -758.80000000};
    array(ref fVar24, 5);
    fVar24[0] = 210.00000000;
    fVar24[1] = 210.00000000;
    fVar24[2] = 209.13000000;
    fVar24[3] = 284.00000000;
    fVar24[4] = 284.00000000;
    array(ref uVar30, 5);
    for ( I = 0; I < 5; I++ )
    {
        uVar30[I] = OpponentManager_CreateOpponent();
        OpponentManager_LoadOpponent( uVar30[I], sVar2[I], ref vVar8[I], fVar24[I] );
        OpponentManager_AddOpponentToWorld( uVar30[I] );
        uVar36 = Opponent_GetRacer( uVar30[I] );
        Racer_SetStreamingLockedIn( uVar36 );
        Racer_SetUID( uVar36, 201 + I );
        Racer_SetVehicleDriverEnable( uVar36, 0 );
    }
    sub_527();
    vVar38 = {65363, 21.90000000, -738.20000000};
    vVar41 = {-183.14000000, 18.29000000, -755.85000000};
    sub_1294( 1, 1, 1065353216, 0 );
    Game_SetCamera( ref vVar38, ref vVar41, 25.00000000, 0, 0, 0 );
    WAIT( 30000 );
    return;
}

void sub_527()
{
    string[3] sVar2;
    string[3] sVar6;
    string sVar10;
    string[1] sVar11;
    string sVar13;
    string sVar14;
    boolean bVar15;
    int I;
    unknown uVar17;
    unknown uVar18;
    unknown uVar19;
    unknown uVar20;
    vector vVar21;
    vector vVar24;
    unknown uVar27;

    array(ref sVar2, 3);
    sVar2[0] = "character/drv_mb_04_set";
    sVar2[1] = "character/drv_mb_008_set";
    sVar2[2] = "character/drv_mc_003_set";
    array(ref sVar6, 3);
    sVar6[0] = "drv_mb_04_set";
    sVar6[1] = "drv_mb_008_set";
    sVar6[2] = "drv_mc_003_set";
    sVar10 = "anim/Extras/male";
    array(ref sVar11, 1);
    sVar11[0] = "Mped_Idle";
    sVar13 = "anim/Extras/female";
    sVar14 = "FPed_Idle";
    bVar15 = false;
    I = 0;
    while (NOT bVar15)
    {
        bVar15 = true;
        for ( I = 0; I < 3; I++ )
        {
            bVar15 = (bVar15) AND (CineScript_Characters_LoadType( sVar2[I], sVar6[I] ));
        }
        WAITUNWARPED( 30 );
    }
    for ( I = 0; I < 1; I++ )
    {
        bVar15 = (bVar15) AND (CineScript_Characters_LoadAnimation( sVar10, sVar11[I] ));
    }
    bVar15 = (bVar15) AND (CineScript_Characters_LoadAnimation( sVar13, sVar14 ));
    if (NOT bVar15)
    {
        PRINTSTRING( "Script 'WorseCaseCharacterTest.sc' failed to load character(s) or anim\n" );
        BREAKPOINT();
    }
    vVar21 = {-190.14000000, 18.29000000, -755.85000000};
    vVar24 = {1.00000000, 0.00000000, 0.00000000};
    Math_VecRotateY( ref vVar24, ref vVar24, -140.00000000 * 0.01745329 );
    uVar17._fU0 = {vVar21.x, vVar21.y, vVar21.z};
    uVar17._fU12 = -140.00000000;
    for ( I = 0; I < 3; I++ )
    {
        uVar27 = CineScript_Characters_LaunchAnimAt( sVar2[I], sVar6[I], sVar10, sVar11[I mod 1], ref uVar17, -1 );
        uVar17._fU0 = {uVar17._fU0 + vVar24};
        CineScript_PushKillBuffer( uVar27, 0 );
    }
    return;
}

void sub_1294(boolean bParam0, boolean bParam1, unknown uParam2, unknown uParam3)
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
