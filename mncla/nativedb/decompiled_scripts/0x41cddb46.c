void main()
{
    vector vVar2;
    unknown uVar5;
    unknown uVar6;
    unknown uVar7;
    unknown uVar8;
    unknown uVar9;
    unknown uVar10;
    int iVar11;
    int iVar12;
    int iVar13;
    int iVar14;
    int iVar15;
    int I;
    unknown[15] uVar17;
    int[15] iVar33;
    vector[15] vVar49;
    unknown uVar65;
    unknown uVar66;
    unknown uVar67;
    unknown uVar68;
    unknown uVar69;
    unknown uVar70;
    unknown uVar71;
    unknown uVar72;
    unknown uVar73;
    unknown uVar74;
    unknown uVar75;
    unknown uVar76;
    unknown uVar77;
    unknown uVar78;
    unknown uVar79;
    unknown uVar80;
    unknown uVar81;
    unknown uVar82;
    unknown uVar83;
    unknown uVar84;
    unknown uVar85;
    unknown uVar86;
    unknown uVar87;
    unknown uVar88;
    unknown uVar89;
    unknown uVar90;
    unknown uVar91;
    unknown uVar92;
    unknown uVar93;
    unknown uVar94;

    vVar2 = {0, 0, 0};
    Racer_InitializeResetPosition( Player_FindRacerObject( 0 ), ref vVar2, 0 );
    iVar11 = sub_37( 0 );
    if (N_3116278344())
    {
        iVar11 = 1;
        l_U0[0] = N_1010445634();
    }
    iVar12 = 0;
    iVar13 = 0;
    iVar14 = 100;
    iVar15 = iVar11 * ((100 / iVar14) + 1);
    array(ref uVar17, 15);
    array(ref iVar33, 15);
    array(ref vVar49, 15);
    vVar49[0] = {62536, 0, 62536};
    vVar49[1] = {62536, 0, 0};
    vVar49[2] = {62536, 0, 3000};
    vVar49[3] = {64036, 0, 62536};
    vVar49[4] = {64036, 0, 0};
    vVar49[5] = {64036, 0, 3000};
    vVar49[6] = {0, 0, 62536};
    vVar49[7] = {0, 0, 64036};
    vVar49[8] = {0, 0, 3000};
    vVar49[9] = {1500, 0, 62536};
    vVar49[10] = {1500, 0, 0};
    vVar49[11] = {1500, 0, 3000};
    vVar49[12] = {3000, 0, 62536};
    vVar49[13] = {3000, 0, 0};
    vVar49[14] = {3000, 0, 3000};
    for ( I = 0; I < 15; I++ )
    {
        iVar33[I] = 0;
    }
    while (iVar15 > 0)
    {
        for ( I = 0; I < 15; I++ )
        {
            if ((iVar12 < iVar11) AND (NOT iVar33[I]))
            {
                uVar5._fU4 = l_U0[iVar12];
                uVar5._fU8 = {vVar49[I]};
                if (N_649530691() > -1)
                {
                    uVar5._fU20 = N_649530691();
                }
                else
                {
                    uVar5._fU20 = iVar13;
                }
                uVar17[I] = START_NEW_SCRIPT_WITH_ARGS( "tools/PlowKing/PlowKing", ref uVar5, 6, 0 );
                iVar33[I] = 1;
                if ((iVar13 < 100) AND (N_649530691() == -1))
                {
                    iVar13 += iVar14;
                }
                else
                {
                    iVar12++;
                    iVar13 = 0;
                }
            }
            WAIT( 1000 );
            if ((iVar33[I]) AND (IsChildFinished( uVar17[I] )))
            {
                iVar33[I] = 0;
                iVar15--;
            }
            WAIT( 1000 );
        }
    }
    return;
}

void sub_37(int iParam0)
{
    int Result;

    Result = 0;
    if ((iParam0 == 0) || (iParam0 == 1))
    {
        l_U0[Result] = "vp_am_vantage_07";
        Result++;
        l_U0[Result] = "vp_aud_r8_08";
        Result++;
        l_U0[Result] = "vp_aud_rs4_07";
        Result++;
        l_U0[Result] = "vp_buk_grandnational_87";
        Result++;
        l_U0[Result] = "vp_chv_camaroSS_69";
        Result++;
        l_U0[Result] = "vp_chv_camaro_06";
        Result++;
    }
    if ((iParam0 == 0) || (iParam0 == 2))
    {
        l_U0[Result] = "vp_chv_cobalt_05";
        Result++;
        l_U0[Result] = "vp_chv_corvettez06_07";
        Result++;
        l_U0[Result] = "vp_chv_impala_96";
        Result++;
        l_U0[Result] = "vp_chv_police_96";
        Result++;
        l_U0[Result] = "vp_cry_300c_06";
        Result++;
        l_U0[Result] = "vp_dge_challenger_06";
        Result++;
    }
    if ((iParam0 == 0) || (iParam0 == 3))
    {
        l_U0[Result] = "vp_dge_challenger_70";
        Result++;
        l_U0[Result] = "vp_dge_charger_06";
        Result++;
        l_U0[Result] = "vp_dsn_280z_75";
        Result++;
        l_U0[Result] = "vp_duc_999r_06";
        Result++;
        l_U0[Result] = "vp_duc_monster_s4r_07";
        Result++;
        l_U0[Result] = "vp_frd_boss302_69";
        Result++;
    }
    if ((iParam0 == 0) || (iParam0 == 4))
    {
        l_U0[Result] = "vp_frd_cobra_04";
        Result++;
        l_U0[Result] = "vp_frd_focus_04";
        Result++;
        l_U0[Result] = "vp_frd_gt_06";
        Result++;
        l_U0[Result] = "vp_frd_mustang_06";
        Result++;
        l_U0[Result] = "vp_kaw_ninja_zx14_06";
        Result++;
        l_U0[Result] = "vp_lam_gallardo_06";
        Result++;
    }
    if ((iParam0 == 0) || (iParam0 == 5))
    {
        l_U0[Result] = "vp_lam_miura_71";
        Result++;
        l_U0[Result] = "vp_lam_murcielago_06";
        Result++;
        l_U0[Result] = "vp_mbz_s600_07";
        Result++;
        l_U0[Result] = "vp_mbz_sl65_07";
        Result++;
        l_U0[Result] = "vp_mit_3000gt_99";
        Result++;
    }
    if ((iParam0 == 0) || (iParam0 == 6))
    {
        l_U0[Result] = "vp_mit_eclipse_99";
        Result++;
        l_U0[Result] = "vp_mit_evo_06";
        Result++;
        l_U0[Result] = "vp_mzd_rx7_95";
        Result++;
        l_U0[Result] = "vp_mzd_rx8_06";
        Result++;
        l_U0[Result] = "vp_nsn_240sx_98";
        Result++;
    }
    if ((iParam0 == 0) || (iParam0 == 7))
    {
        l_U0[Result] = "vp_nsn_350z_06";
        Result++;
        l_U0[Result] = "vp_nsn_gtr_08";
        Result++;
        l_U0[Result] = "vp_nsn_skyline_99";
        Result++;
        l_U0[Result] = "vp_pon_solstice_06";
        Result++;
        l_U0[Result] = "vp_pon_transam_79";
        Result++;
    }
    if ((iParam0 == 0) || (iParam0 == 8))
    {
        l_U0[Result] = "vp_sln_s281_06";
        Result++;
        l_U0[Result] = "vp_sln_s7_06";
        Result++;
        l_U0[Result] = "vp_vw_golf_07";
        Result++;
        l_U0[Result] = "vp_vw_golf_83";
        Result++;
        l_U0[Result] = "vp_vw_scirocco_88";
        Result++;
    }
    return Result;
}
