void main()
{
    int iVar2;
    int iVar3;
    int iVar4;
    unknown uVar5;
    unknown uVar6;
    unknown uVar7;
    unknown uVar8;
    unknown uVar9;
    int I;
    int iVar11;
    unknown uVar12;
    unknown uVar13;
    int iVar14;

    if (NOT (l_U76._fU0 == 3))
    {
        l_U76._fU0 = 2;
        sub_32();
        iVar2 = 2;
        iVar3 = 8;
        l_U0[0] = {-193.70000000, 18.70000000, -758.80000000};
        l_U0[1] = {-178.00000000, 18.27000000, -759.20000000};
        l_U0[2] = {-188.90000000, 18.60000000, -764.80000000};
        l_U0[3] = {-183.14000000, 18.29000000, -755.85000000};
        l_U0[4] = {-172.70000000, 20.00000000, -762.80000000};
        l_U0[5] = {-174.70000000, 20.00000000, -762.80000000};
        l_U0[6] = {-176.70000000, 20.00000000, -762.80000000};
        l_U0[7] = {-178.70000000, 20.00000000, -762.80000000};
        iVar4 = 8;
        uVar5 = RAND_INT_RANGE( 0, iVar3 - 1 );
        uVar6 = {l_U0[uVar5]};
        l_U0[uVar5] = {l_U0[iVar3 - 1]};
        iVar3--;
        uVar9 = Player_FindRacerObject( 0 );
        Racer_InitializeResetPosition( uVar9, ref uVar6, 0 );
        Racer_Reset( uVar9 );
        iVar11 = 1;
        for ( I = 0; I < iVar11; I++ )
        {
            uVar12 = l_U25[RAND_INT_RANGE( 0, iVar2 - 1 )];
            uVar5 = RAND_INT_RANGE( 0, iVar3 - 1 );
            uVar6 = {l_U0[uVar5]};
            l_U0[uVar5] = {l_U0[iVar3 - 1]};
            iVar3--;
            uVar13 = OpponentManager_CreateOpponent();
            OpponentManager_LoadOpponent( uVar13, uVar12, ref uVar6, 0 );
            Racer_InitializeResetPosition( Opponent_GetRacer( uVar13 ), ref uVar6, 0 );
            OpponentManager_AddOpponentToWorld( uVar13 );
        }
        while (true)
        {
            iVar14 = RAND_INT_RANGE( 0, 20 );
            if (iVar14 <= 10)
            {
                iVar14 *= 30;
            }
            else
            {
                iVar14 = (iVar14 - 10) * 200;
            }
            if (iVar14 > 0)
            {
                WAIT( iVar14 );
            }
            Racer_ChangeCar( Racer_FindObject( RAND_INT_RANGE( 0, iVar11 ) ), l_U25[RAND_INT_RANGE( 0, iVar2 - 1 )] );
        }
    }
    return;
}

void sub_32()
{
    int Result;

    Result = 0;
    l_U25[Result] = "vp_am_vantage_07";
    Result++;
    l_U25[Result] = "vp_aud_r8_08";
    Result++;
    l_U25[Result] = "vp_aud_rs4_07";
    Result++;
    l_U25[Result] = "vp_buk_grandnational_87";
    Result++;
    l_U25[Result] = "vp_chv_camaro_06";
    Result++;
    l_U25[Result] = "vp_chv_camaross_69";
    Result++;
    l_U25[Result] = "vp_chv_cobalt_05";
    Result++;
    l_U25[Result] = "vp_chv_corvettez06_07";
    Result++;
    l_U25[Result] = "vp_chv_impala_96";
    Result++;
    l_U25[Result] = "vp_chv_police_96";
    Result++;
    l_U25[Result] = "vp_citybus_07";
    Result++;
    l_U25[Result] = "vp_cry_300c_06";
    Result++;
    l_U25[Result] = "vp_dge_challenger_06";
    Result++;
    l_U25[Result] = "vp_dge_challenger_70";
    Result++;
    l_U25[Result] = "vp_dge_charger_06";
    Result++;
    l_U25[Result] = "vp_dsn_280z_75";
    Result++;
    l_U25[Result] = "vp_duc_999r_06";
    Result++;
    l_U25[Result] = "vp_duc_monster_s4r_07";
    Result++;
    l_U25[Result] = "vp_frd_boss302_69";
    Result++;
    l_U25[Result] = "vp_frd_cobra_04";
    Result++;
    l_U25[Result] = "vp_frd_focus_04";
    Result++;
    l_U25[Result] = "vp_frd_gt_06";
    Result++;
    l_U25[Result] = "vp_frd_mustang_06";
    Result++;
    l_U25[Result] = "vp_kaw_ninja_zx14_06";
    Result++;
    l_U25[Result] = "vp_lam_gallardo_06";
    Result++;
    l_U25[Result] = "vp_lam_miura_71";
    Result++;
    l_U25[Result] = "vp_lam_murcielago_06";
    Result++;
    l_U25[Result] = "vp_mbz_s600_07";
    Result++;
    l_U25[Result] = "vp_mbz_sl65_07";
    Result++;
    l_U25[Result] = "vp_mit_3000gt_99";
    Result++;
    l_U25[Result] = "vp_mit_eclipse_99";
    Result++;
    l_U25[Result] = "vp_mit_evo_06";
    Result++;
    l_U25[Result] = "vp_mzd_rx7_95";
    Result++;
    l_U25[Result] = "vp_mzd_rx8_06";
    Result++;
    l_U25[Result] = "vp_nsn_240sx_98";
    Result++;
    l_U25[Result] = "vp_nsn_350z_06";
    Result++;
    l_U25[Result] = "vp_nsn_skyline_99";
    Result++;
    l_U25[Result] = "vp_pon_solstice_06";
    Result++;
    l_U25[Result] = "vp_pon_transam_79";
    Result++;
    l_U25[Result] = "vp_sln_s281_06";
    Result++;
    l_U25[Result] = "vp_sln_s7_06";
    Result++;
    l_U25[Result] = "vp_vw_golf_07";
    Result++;
    l_U25[Result] = "vp_vw_golf_83";
    Result++;
    l_U25[Result] = "vp_vw_scirocco_88";
    Result++;
    return Result;
}
