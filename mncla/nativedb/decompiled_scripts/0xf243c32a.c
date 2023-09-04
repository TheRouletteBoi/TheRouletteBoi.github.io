void main()
{
    unknown uVar2;
    string[4] sVar3;
    string[3] sVar8;
    vector[4] vVar12;
    unknown uVar17;
    unknown uVar18;
    unknown uVar19;
    unknown uVar20;
    unknown uVar21;
    unknown uVar22;
    unknown uVar23;
    unknown uVar24;
    float[4] fVar25;
    vector[3] vVar30;
    unknown uVar34;
    unknown uVar35;
    unknown uVar36;
    unknown uVar37;
    unknown uVar38;
    unknown uVar39;
    vector[3] vVar40;
    unknown uVar44;
    unknown uVar45;
    unknown uVar46;
    unknown uVar47;
    unknown uVar48;
    unknown uVar49;
    int iVar50;
    unknown uVar51;
    vector vVar52;
    unknown[4] uVar55;
    unknown[4] uVar60;
    int I;
    unknown[4] uVar66;
    vector[4] vVar71;
    unknown uVar76;
    unknown uVar77;
    unknown uVar78;
    unknown uVar79;
    unknown uVar80;
    unknown uVar81;
    unknown uVar82;
    unknown uVar83;
    float[4] fVar84;
    int J;
    unknown uVar90;
    unknown uVar91;
    unknown uVar92;
    unknown uVar93;
    unknown uVar94;
    unknown uVar95;
    unknown uVar96;

    uVar2 = Graphics_GetAndSetAutoUpdateTimeOfDay( 0 );
    UILogic_UnPauseCamera();
    array(ref sVar3, 4);
    sVar3[0] = "starter_vp_vw_scirocco_88";
    sVar3[1] = "starter_vp_nsn_240sx_98";
    sVar3[2] = "starter_vp_vw_golf_83";
    sVar3[3] = "vp_citybus_07";
    array(ref sVar8, 3);
    sVar8[0] = "vp_vw_scirocco_88";
    sVar8[1] = "vp_nsn_240sx_98";
    sVar8[2] = "vp_vw_golf_83";
    array(ref vVar12, 4);
    vVar12[0] = {-173.08800000, 18.16900000, -762.76900000};
    vVar12[1] = {-176.35500000, 18.19900000, -761.17800000};
    vVar12[2] = {-179.10400000, 18.20300000, -759.11900000};
    vVar12[3] = {-160.10400000, 18.20300000, -759.11900000};
    array(ref fVar25, 4);
    fVar25[0] = 34.02500000;
    fVar25[1] = 35.09100000;
    fVar25[2] = 36.12000000;
    fVar25[3] = 36.12000000;
    array(ref vVar30, 3);
    array(ref vVar40, 3);
    vVar30[0] = {-174.15400000, 19.60900000, -769.26300000};
    vVar40[0] = {-172.35300000, 16.67300000, -751.90400000};
    vVar30[1] = {-181.70900000, 19.57700000, -764.57200000};
    vVar40[1] = {-165.48900000, 16.82500000, -755.18300000};
    vVar30[2] = {-179.07700000, 19.06500000, -765.56200000};
    vVar40[2] = {-179.63400000, 18.41500000, -749.72500000};
    iVar50 = Player_FindObject( 0 );
    if (iVar50 != nil)
    {
        uVar51 = Player_GetRacer( iVar50 );
        vVar52 = {-183.10000000, 18.20000000, -722.70000000};
        Racer_InitializeResetPosition( uVar51, ref vVar52, 349.00000000 );
        Racer_Reset( uVar51 );
    }
    array(ref uVar55, 4);
    array(ref uVar60, 4);
    for ( I = 0; I < 4; I++ )
    {
        uVar55[I] = OpponentManager_CreateOpponent();
        uVar60[I] = Opponent_GetRacer( uVar55[I] );
        Racer_SetForceHiresTextures( uVar60[I], 1 );
        OpponentManager_LoadOpponent( uVar55[I], sVar3[I], ref vVar12[I], fVar25[I] );
        OpponentManager_AddOpponentToWorld( uVar55[I] );
        Racer_SetStreamingLockedIn( uVar60[I] );
        Racer_SetUID( uVar60[I], 205 + I );
        Racer_SetVehicleDriverEnable( uVar60[I], 0 );
        if (I < 3)
        {
            Racer_Deactivate( uVar60[I] );
            Racer_SetHeadlights( uVar60[I], 0 );
            Racer_SetExhaust( uVar60[I], 0 );
        }
        Racer_HideIcon( uVar60[I], 1 );
    }
    array(ref uVar66, 4);
    array(ref vVar71, 4);
    array(ref fVar84, 4);
    vVar71[0] = {-192.15100000, 18.76500000, -766.67900000};
    fVar84[0] = 28.18900000;
    vVar71[1] = {-188.55600000, 18.73300000, -768.17400000};
    fVar84[1] = 28.18900000;
    vVar71[2] = {-185.18300000, 18.58300000, -769.89200000};
    fVar84[2] = 28.18900000;
    vVar71[3] = {-181.23800000, 18.49400000, -771.32400000};
    fVar84[3] = 28.18900000;
    mcGame_ThrowEvent( "loadSuccess" );
    Graphics_WarpToTimeOfDay( 3.00000000, 100.00000000 );
    SETTIMERA( 0 );
    for ( J = 0; J < 4; J++ )
    {
        uVar66[J] = AmbientMgr_AddRandomCarToLayout( 0, ref vVar71[J], fVar84[J] );
    }
    while (true)
    {
        AmbientMgr_SetParkedCarsEnable( 0 );
        AmbientMgr_Reset();
        uVar90._fU8._fU0 = {0.00000000, 0.00000000, 0.00000000};
        uVar90._fU8._fU12 = 0.00000000;
        CineScript_SetGameCoordSysBinding( ref uVar90 );
        sub_1356( uVar60[3], 0 );
        PostProcessing_SetCutsceneDof();
        uVar96 = nil;
        uVar96 = START_NEW_SCRIPT_WITH_ARGS( "Game/CineScripts/generated/story/cut_intro_generated", ref nil, 0, 0 );
        while (NOT (IsChildFinished( uVar96 )))
        {
            WAITUNWARPED( 30 );
        }
        PostProcessing_SetGameDof();
        sub_1589( 1, 1, 1065353216, 0 );
    }
    for ( J = 0; J < 4; J++ )
    {
        AmbientMgr_RemoveAmbientFromLayout( uVar66[J] );
    }
    for ( I = 0; I < 4; I++ )
    {
        Racer_SetStreamingUnlocked( uVar60[I] );
        Opponent_ToggleDeleteOnEviction( uVar55[I], 1 );
    }
    OpponentManager_RemoveOpponentFromWorld( uVar55[3] );
    OpponentManager_DeleteOpponent( uVar55[3] );
    Graphics_GetAndSetAutoUpdateTimeOfDay( 1 );
    AmbientMgr_SetParkedCarsEnable( 1 );
    AmbientMgr_Reset();
    return;
}

void sub_1356(unknown uParam0, int iParam1)
{
    int iVar4;

    iVar4 = Racer_GetUID( uParam0 );
    if (iVar4 == 0)
    {
        iVar4 = 5000 + iParam1;
        while ((Racer_FindFromUID( iVar4 )) != nil)
        {
            iVar4++;
            WAITUNWARPED( 10 );
        }
        Racer_SetUID( uParam0, iVar4 );
    }
    CineScript_Cars_AssignIdToSlot( iVar4, iParam1 );
    return;
}

void sub_1589(boolean bParam0, boolean bParam1, unknown uParam2, unknown uParam3)
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
