void main()
{
    int iVar2;
    int iVar3;
    unknown uVar4;
    string[35] sVar5;
    char[64] cVar41;
    unknown uVar57;
    vector vVar58;
    float fVar61;
    int I;

    l_U0._fU0 = 2;
    iVar2 = 0;
    iVar3 = 1;
    uVar4 = GetCarCommandLine( ref iVar2 );
    if (iVar2 == 0)
    {
        iVar3 = 0;
    }
    array(ref sVar5, 35);
    sVar5[0] = "vp_chv_cobalt_05";
    sVar5[1] = "vp_dsn_280z_75";
    sVar5[2] = "vp_mit_eclipse_99";
    sVar5[3] = "vp_mit_evo_06";
    sVar5[4] = "vp_nsn_240sx_98";
    sVar5[5] = "vp_vw_scirocco_88";
    sVar5[6] = "vp_pon_transam_79";
    sVar5[7] = "vp_pon_solstice_06";
    sVar5[8] = "vp_mit_3000gt_99";
    sVar5[9] = "vp_dge_challenger_70";
    sVar5[10] = "vp_buk_grandnational_87";
    sVar5[11] = "vp_chv_camaross_69";
    sVar5[12] = "vp_chv_impala_64";
    sVar5[13] = "vp_chv_impala_96";
    sVar5[14] = "vp_cry_300c_06";
    sVar5[15] = "vp_dge_charger_06";
    sVar5[16] = "vp_gem_gtrgullwing_06";
    sVar5[17] = "vp_lam_gallardo_06";
    sVar5[18] = "vp_lam_murcielago_06";
    sVar5[19] = "vp_vw_golf_85";
    sVar5[20] = "vp_sln_s281_06";
    sVar5[21] = "vp_mit_eclipsespyder_99";
    sVar5[22] = "vp_mbz_cl65_06";
    sVar5[23] = "vp_mbz_sl65_06";
    sVar5[24] = "vp_nsn_350z_06";
    sVar5[25] = "vp_nsn_skyline_02";
    sVar5[26] = "vp_pon_gto_66";
    sVar5[27] = "vp_frd_focus_04";
    sVar5[28] = "vp_mzd_rx8_06";
    sVar5[29] = "vp_chv_police_96";
    sVar5[30] = "vp_cad_escalade_07";
    sVar5[31] = "vp_sln_s7_06";
    sVar5[32] = "vp_duc_999r_06";
    sVar5[33] = "vp_duc_monster_06";
    sVar5[34] = "vp_kaw_ninja_06";
    Graphics_WarpToTimeOfDay( 11.75000000, 100 );
    StrCopy( ref cVar41, "la", 64 );
    PRINTSTRING( "Script: LoadCity LA\n" );
    uVar57 = LookupCity( ref cVar41 );
    LayerCity_LoadCity( ref cVar41 );
    vVar58 = {-286.50000000, 23.20000000, -741.80000000};
    fVar61 = 267.70000000;
    if (iVar3 == 1)
    {
        sub_1041( uVar4, ref vVar58, fVar61, 0 );
    }
    else
    {
        for ( I = 0; I < sVar5; I++ )
        {
            sub_1041( sVar5[I], ref vVar58, fVar61, 0 );
        }
    }
    return;
}

void sub_1041(unknown uParam0, unknown uParam1, unknown uParam2, boolean bParam3)
{
    unknown uVar6;
    unknown uVar7;
    unknown uVar8;
    char[64] cVar9;
    int I;
    float fVar26;
    char[64] cVar27;
    char[64] cVar43;
    float fVar59;

    uVar6 = LocalOptions_AddVehicleToPlayer( uParam0 );
    uVar7 = LocalOptions_GetVehicleProfile( uVar6 );
    LayerPlayer_LoadPlayer( 0, uVar7, uParam1, uParam2 );
    uVar8 = Player_FindRacerObject( 0 );
    Racer_InitializeResetPosition( uVar8, uParam1, uParam2 );
    Racer_Reset( uVar8 );
    Racer_SetVehicleDriverEnable( uVar8, 0 );
    Graphics_WarpToTimeOfDay( 11.75000000, 100.00000000 );
    Graphics_SetMainShadowedRenderPass( 0 );
    while (NOT (Racer_IsSimStreamed( uVar8 )))
    {
        WAIT( 100 );
    }
    WAIT( 10000 );
    I = 1;
    StrCopy( ref cVar9, "t:/mc4/carshot-", 64 );
    StringCat( ref cVar9, uParam0 );
    StringCat( ref cVar9, "-" );
    fVar26 = 27.50000000;
    Garage_SetDebugPlayerRelativeCamera( 0, 0.60000000, 7.00000000, 180.00000000 - 50.00000000, 5.00000000, fVar26 );
    WAIT( 200 );
    sub_1307( ref cVar9, ref I );
    Garage_SetDebugPlayerRelativeCamera( 0, 0.60000000, 7.30000000, 0.00000000 - 50.00000000, 5.00000000, fVar26 );
    WAIT( 200 );
    sub_1307( ref cVar9, ref I );
    Garage_SetDebugPlayerRelativeCamera( 0, 0.60000000, 7.00000000, 180.00000000 - 3.00000000, 5.00000000, fVar26 );
    WAIT( 200 );
    sub_1307( ref cVar9, ref I );
    Garage_SetDebugPlayerRelativeCamera( 0, 0.60000000, 7.30000000, 90.00000000 - 5.00000000, 8.00000000, fVar26 );
    WAIT( 200 );
    sub_1307( ref cVar9, ref I );
    Garage_SetDebugPlayerRelativeCamera( 0, 0.60000000, 7.30000000, -90.00000000 - 5.00000000, 8.00000000, fVar26 );
    WAIT( 200 );
    sub_1307( ref cVar9, ref I );
    Garage_SetDebugPlayerRelativeCamera( 0, 0.60000000, 7.00000000, 0.00000000 + 1.00000000, 3.00000000, fVar26 );
    WAIT( 200 );
    sub_1307( ref cVar9, ref I );
    Garage_SetDebugPlayerRelativeCamera( 0, 0.50000000, 8.00000000, -90.00000000 + 20.00000000, 89.00000000 - 5.00000000, fVar26 );
    WAIT( 200 );
    sub_1307( ref cVar9, ref I );
    if (bParam3)
    {
        I = 0;
        fVar59 = -179.00000000;
        for ( I = 0; I < 180; I++ )
        {
            Garage_SetDebugPlayerRelativeCamera( 0, 0.60000000, 6.50000000, fVar59, 10.00000000, fVar26 );
            fVar59 += 2.00000000;
            WAIT( 150 );
            StrCopy( ref cVar27, "t:/mc4/carmovie-", 64 );
            string(ref cVar43, I, 64);
            StringCat( ref cVar27, uParam0 );
            StringCat( ref cVar27, "-" );
            StringCat( ref cVar27, ref cVar43 );
            N_2366296418( ref cVar27 );
        }
    }
    WAIT( 300 );
    LayerPlayer_KillPlayer( 0 );
    return;
}

void sub_1307(unknown uParam0, unknown uParam1)
{
    char[64] cVar4;
    char[64] cVar20;

    StrCopy( ref cVar4, uParam0, 64 );
    string(ref cVar20, (uParam1^), 64);
    StringCat( ref cVar4, ref cVar20 );
    (uParam1^)++;
    N_2366296418( ref cVar4 );
    return;
}
