void main()
{
    string[4] sVar2;
    vector[4] vVar7;
    unknown uVar12;
    unknown uVar13;
    unknown uVar14;
    unknown uVar15;
    unknown uVar16;
    unknown uVar17;
    unknown uVar18;
    unknown uVar19;
    float[4] fVar20;
    unknown[4] uVar25;
    unknown[4] uVar30;
    unknown[4] uVar35;
    unknown uVar40;
    int I;
    vector vVar42;
    vector vVar45;

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
    Graphics_WarpToTimeOfDay( 1.00000000, 50.00000000 );
    array(ref sVar2, 4);
    sVar2[0] = "";
    sVar2[1] = "vp_vw_golf_83";
    sVar2[2] = "vp_mit_evo_06";
    sVar2[3] = "vp_chv_camaroSS_69";
    array(ref vVar7, 4);
    vVar7[0] = {-193.70000000, 18.70000000, -758.80000000};
    vVar7[1] = {-178.00000000, 18.27000000, -759.20000000};
    vVar7[2] = {-188.90000000, 18.60000000, -764.80000000};
    vVar7[3] = {-183.14000000, 18.29000000, -755.85000000};
    array(ref fVar20, 4);
    fVar20[0] = 284.00000000;
    fVar20[1] = 209.13000000;
    fVar20[2] = 284.00000000;
    fVar20[3] = 210.00000000;
    array(ref uVar25, 4);
    array(ref uVar30, 4);
    array(ref uVar35, 4);
    for ( I = 0; I < 4; I++ )
    {
        if (I > 0)
        {
            uVar35[I] = mcCarConfig_Create( sVar2[I] );
            LayerPlayer_LoadPlayer( I, uVar35[I], ref vVar7[I], fVar20[I] );
        }
        uVar25[I] = Player_FindObject( I );
        uVar30[I] = Player_GetRacer( uVar25[I] );
        Racer_InitializeResetPosition( uVar30[I], ref vVar7[I], fVar20[I] );
        if (I == 0)
        {
            ;
        }
        else
        {
            Racer_SetUIDAndCharacterName( uVar30[I], 50 + I, l_U0 );
        }
        Racer_Reset( uVar30[I] );
    }
    vVar42 = {65363, 21.90000000, -738.20000000};
    vVar45 = {-183.14000000, 18.29000000, -755.85000000};
    sub_1321( 1, 1, 1065353216, 0 );
    Game_SetCamera( ref vVar42, ref vVar45, 25.00000000, 0, 0, 0 );
    WAIT( 30000 );
    return;
}

void sub_1321(boolean bParam0, boolean bParam1, unknown uParam2, unknown uParam3)
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
