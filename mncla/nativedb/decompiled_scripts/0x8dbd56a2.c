void main()
{
    string[16] sVar2;
    unknown uVar19;
    unknown uVar20;
    unknown uVar21;
    float fVar22;
    unknown[16] uVar23;
    unknown[16] uVar40;
    unknown[16] uVar57;
    unknown uVar74;
    int I;

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
    array(ref sVar2, 16);
    sVar2[0] = "vp_nsn_240sx_98";
    sVar2[1] = "vp_vw_golf_83";
    sVar2[2] = "vp_mit_evo_06";
    sVar2[3] = "vp_chv_camaroSS_69";
    sVar2[4] = "vp_buk_grandnational_87";
    sVar2[5] = "vp_chv_camaro_06";
    sVar2[6] = "vp_chv_cobalt_05";
    sVar2[7] = "vp_chv_corvettez06_07";
    sVar2[8] = "vp_cry_300c_06";
    sVar2[9] = "vp_dge_challenger_06";
    sVar2[10] = "vp_dge_charger_06";
    sVar2[11] = "vp_frd_focus_04";
    sVar2[12] = "vp_frd_gt_06";
    sVar2[13] = "vp_lam_miura_71";
    sVar2[14] = "vp_mit_3000gt_99";
    sVar2[15] = "vp_sln_s281_06";
    fVar22 = 0;
    array(ref uVar23, 16);
    array(ref uVar40, 16);
    array(ref uVar57, 16);
    for ( I = 0; I < 16; I++ )
    {
        PropManager_GetRandomBreakablePropLocation( ref uVar19 );
        if (I > 0)
        {
            uVar57[I] = mcCarConfig_Create( sVar2[I] );
            LayerPlayer_LoadRemotePlayer( I, uVar57[I], ref uVar19, fVar22, -1, 1 );
        }
        uVar23[I] = Player_FindObject( I );
        uVar40[I] = Player_GetRacer( uVar23[I] );
        Racer_InitializeResetPosition( uVar40[I], ref uVar19, fVar22 );
        if (I == 0)
        {
            ;
        }
        else
        {
            Racer_SetUIDAndCharacterName( uVar40[I], 50 + I, l_U0 );
        }
        Racer_Reset( uVar40[I] );
    }
    I = 0;
    while (true)
    {
        if ((RAND_INT_RANGE( 0, 1 )) == 0)
        {
            WAIT( 0 );
        }
        PropManager_GetRandomBreakablePropLocation( ref uVar19 );
        Racer_Teleport( uVar40[I], ref uVar19, fVar22, 5 );
        I++;
        if (I >= 16)
        {
            I = 0;
        }
    }
    return;
}
