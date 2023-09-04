void main()
{
    unknown uVar2;
    unknown uVar3;
    unknown uVar4;
    unknown uVar5;
    unknown uVar6;
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
    unknown uVar19;
    unknown uVar20;
    unknown uVar21;
    unknown uVar22;
    unknown uVar23;
    unknown uVar24;
    unknown uVar25;
    unknown uVar26;
    unknown uVar27;
    unknown uVar28;
    unknown uVar29;
    unknown uVar30;
    unknown uVar31;
    unknown uVar32;
    unknown uVar33;
    unknown uVar34;
    unknown uVar35;
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
    unknown uVar50;
    unknown uVar51;
    unknown uVar52;
    unknown uVar53;
    unknown uVar54;
    unknown uVar55;
    unknown uVar56;
    unknown uVar57;
    unknown uVar58;
    unknown uVar59;
    unknown uVar60;
    unknown uVar61;
    unknown uVar62;
    unknown uVar63;
    unknown uVar64;
    unknown uVar65;
    unknown[60] uVar66;
    unknown uVar127;
    int iVar128;
    int iVar129;
    int iVar130;
    int iVar131;
    boolean bVar132;
    int iVar133;

    if (NOT GetNoPropCommandLine())
    {
        array(ref uVar2._fU12, 60);
        ref uVar2;
        array(ref uVar66, 60);
        uVar127 = sub_48( ref uVar66, ref uVar2._fU12 );
        WAIT( 1000 );
        iVar128 = 0;
        iVar129 = 0;
        while (true)
        {
            iVar130 = PropManager_GetFirstBrokenRaceProp( uVar127 );
            if (iVar130 != nil)
            {
                PRINTSTRING( "BrokenProp is not null!! \n" );
                iVar131 = 0;
                bVar132 = true;
                while (bVar132)
                {
                    if (uVar66[iVar131] == iVar130)
                    {
                        bVar132 = false;
                        PropManager_DetachRaceProp( iVar130 );
                        PRINTSTRING( "found collectable prop at idx " );
                        PRINTINT( iVar131 );
                        PRINTSTRING( "\n" );
                        if (uVar2._fU12[iVar131] == 0)
                        {
                            AudioManager_PlayFrontendSound( "COLLECTIBLES_PICKUP_MASTER" );
                            StatsManager_UpdateStatInt( "gCOL", 0, 0, 1 );
                            iVar129 = LocalOptions_SaveCollectables( iVar131 );
                            PRINTSTRING( "WORKING!!!!11!!!" );
                            PRINTSTRING( "TOTAL COLLECTED IS :" );
                            PRINTINT( iVar129 );
                            if (((NOT Net_IsNetworked()) AND (NOT Net_IsConnecting())) AND (NOT InGameEditor_InEditorMode()))
                            {
                                if (((StatsManager_GetIntValue( "xTCO", 0 )) == 0) AND (NOT GetNoTutorialCommandLine()))
                                {
                                    sub_2232( -1, 94, 0, 0, 0 );
                                    StatsManager_UpdateStatInt( "xTCO", 0, 3, 1 );
                                }
                                mcEvent_PostEventStr( "CAREER_AUTOSAVE", "" );
                            }
                            SplashManager_SplashDynamicInt( 0, 3, "NUM_COLLECTABLE_COLLECTED", "COLLECTABLE_FOUND_MSG", iVar129, 4.00000000, 0 );
                            uVar2._fU12[iVar131] = 1;
                            iVar133 = StatsManager_GetIntValue( "gCOL", 0 );
                            if ((iVar133 mod 10) == 0)
                            {
                                SplashManager_Splash( 0, 3, "CHEAT_UNLOCKED", 1073741824, 1, 0 );
                            }
                        }
                    }
                    iVar131++;
                    if (iVar131 >= 60)
                    {
                        PRINTSTRING( "didn't find collectable prop\n" );
                        bVar132 = false;
                    }
                }
            }
            if (iVar129 > iVar128)
            {
                iVar128 = iVar129;
            }
            WAIT( 10 );
        }
    }
    return;
}

void sub_48(unknown uParam0, unknown uParam1)
{
    unknown Result;
    vector vVar5;
    vector[60] vVar8;
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
    unknown uVar95;
    unknown uVar96;
    unknown uVar97;
    unknown uVar98;
    unknown uVar99;
    unknown uVar100;
    unknown uVar101;
    unknown uVar102;
    unknown uVar103;
    unknown uVar104;
    unknown uVar105;
    unknown uVar106;
    unknown uVar107;
    unknown uVar108;
    unknown uVar109;
    unknown uVar110;
    unknown uVar111;
    unknown uVar112;
    unknown uVar113;
    unknown uVar114;
    unknown uVar115;
    unknown uVar116;
    unknown uVar117;
    unknown uVar118;
    unknown uVar119;
    unknown uVar120;
    unknown uVar121;
    unknown uVar122;
    unknown uVar123;
    unknown uVar124;
    unknown uVar125;
    unknown uVar126;
    unknown uVar127;
    unknown uVar128;
    unknown uVar129;
    unknown uVar130;
    unknown uVar131;
    unknown uVar132;
    unknown uVar133;
    unknown uVar134;
    unknown uVar135;
    unknown uVar136;
    unknown uVar137;
    unknown uVar138;
    unknown uVar139;
    unknown uVar140;
    unknown uVar141;
    unknown uVar142;
    unknown uVar143;
    unknown uVar144;
    unknown uVar145;
    unknown uVar146;
    unknown uVar147;
    unknown uVar148;
    unknown uVar149;
    unknown uVar150;
    unknown uVar151;
    unknown uVar152;
    unknown uVar153;
    unknown uVar154;
    unknown uVar155;
    unknown uVar156;
    unknown uVar157;
    unknown uVar158;
    unknown uVar159;
    unknown uVar160;
    unknown uVar161;
    unknown uVar162;
    unknown uVar163;
    unknown uVar164;
    unknown uVar165;
    unknown uVar166;
    unknown uVar167;
    unknown uVar168;
    unknown uVar169;
    unknown uVar170;
    unknown uVar171;
    unknown uVar172;
    unknown uVar173;
    unknown uVar174;
    unknown uVar175;
    unknown uVar176;
    unknown uVar177;
    unknown uVar178;
    unknown uVar179;
    unknown uVar180;
    unknown uVar181;
    unknown uVar182;
    unknown uVar183;
    unknown uVar184;
    unknown uVar185;
    unknown uVar186;
    unknown uVar187;
    unknown uVar188;
    int I;

    Result = PropManager_InitRaceProps( 60, 5 );
    vVar5 = {0, 0, 0};
    array(ref vVar8, 60);
    vVar8[0] = {1024.79000000, 16.52000000, -787.00000000};
    vVar8[1] = {588.67000000, 31.03000000, -1199.74000000};
    vVar8[2] = {170.58000000, 23.91000000, -977.95000000};
    vVar8[3] = {-257.91000000, 31.73000000, -778.71000000};
    vVar8[4] = {-494.86000000, 18.82000000, -692.85000000};
    vVar8[5] = {-1768.93000000, 6.94000000, -866.89000000};
    vVar8[6] = {-2083.09000000, 2.41000000, -381.07000000};
    vVar8[7] = {-2138.87000000, 1.25000000, -187.94000000};
    vVar8[8] = {-940.10000000, -0.40000000, -229.90000000};
    vVar8[9] = {-298.40000000, 17.49000000, -405.20000000};
    vVar8[10] = {398.92000000, 7.12000000, -221.45000000};
    vVar8[11] = {689.86000000, -13.62000000, 254.58000000};
    vVar8[12] = {-1507.28000000, 8.01000000, -514.87000000};
    vVar8[13] = {-300.97000000, -7.57000000, 186.05000000};
    vVar8[14] = {-715.26000000, 2.84000000, 24.02000000};
    vVar8[15] = {-1477.10000000, 1.99000000, 389.30000000};
    vVar8[16] = {-1633.34000000, 6.85000000, 83.11000000};
    vVar8[17] = {-1538.48000000, 2.12000000, -238.57000000};
    vVar8[18] = {-1882.16000000, 3.46000000, 388.18000000};
    vVar8[19] = {-1580.55000000, 18.37000000, 573.68000000};
    vVar8[20] = {-1979.71000000, 0.08000000, 360.60000000};
    vVar8[21] = {-2609.16000000, -3.62000000, 273.72000000};
    vVar8[22] = {-2644.81000000, -4.15000000, 673.13000000};
    vVar8[23] = {-2550.10000000, -10.67000000, 806.20000000};
    vVar8[24] = {-2949.34000000, -29.23000000, 1072.44000000};
    vVar8[25] = {-3197.50000000, -19.76000000, 562.59000000};
    vVar8[26] = {-2926.36000000, -7.22000000, 610.77000000};
    vVar8[27] = {-2617.49000000, -4.69000000, -38.54000000};
    vVar8[28] = {-2944.99000000, -1.54000000, -289.59000000};
    vVar8[29] = {-3073.67000000, -30.74000000, -443.60000000};
    vVar8[30] = {-2677.51000000, -24.45000000, -983.29000000};
    vVar8[31] = {-2496.71000000, 0.68000000, -476.80000000};
    vVar8[32] = {-2346.30000000, 1.40000000, -449.06000000};
    vVar8[33] = {-2257.89000000, 4.26000000, -763.06000000};
    vVar8[34] = {-2108.99000000, 9.24000000, -1235.97000000};
    vVar8[35] = {2068.77000000, 5.47000000, -1159.27000000};
    vVar8[36] = {1771.25000000, 3.42000000, -890.07000000};
    vVar8[37] = {1817.88000000, -0.02000000, -674.90000000};
    vVar8[38] = {2143.03000000, 6.99000000, -665.34000000};
    vVar8[39] = {2638.50000000, -15.80000000, -629.01000000};
    vVar8[40] = {2522.18000000, -10.09000000, -122.02000000};
    vVar8[41] = {2371.54000000, -5.86000000, 181.39000000};
    vVar8[42] = {2353.40000000, -22.05000000, 379.50000000};
    vVar8[43] = {2111.48000000, -19.99000000, 1007.94000000};
    vVar8[44] = {1183.38000000, -8.21000000, 719.95000000};
    vVar8[45] = {1461.78000000, -5.44000000, 1020.38000000};
    vVar8[46] = {1408.36000000, -3.16000000, 10.69000000};
    vVar8[47] = {1724.53000000, -2.99000000, 179.87000000};
    vVar8[48] = {2080.74000000, -3.00000000, -84.05000000};
    vVar8[49] = {2122.52000000, 3.97000000, -220.08000000};
    vVar8[50] = {-65.10000000, 29.87000000, -2229.00000000};
    vVar8[51] = {379.77000000, 19.98000000, -2153.96000000};
    vVar8[52] = {-598.06000000, 30.76000000, -1902.41000000};
    vVar8[53] = {-645.74000000, 37.67000000, -1814.02000000};
    vVar8[54] = {-1518.91000000, 29.99000000, -2137.94000000};
    vVar8[55] = {-1923.10000000, 21.10000000, -2034.40000000};
    vVar8[56] = {-1090.05000000, 82.92000000, -1562.53000000};
    vVar8[57] = {-993.70000000, 64.18000000, -1449.96000000};
    vVar8[58] = {-572.63000000, 84.10000000, -1324.42000000};
    vVar8[59] = {432.89000000, 99.77000000, -1655.29000000};
    for ( I = 0; I < 60; I++ )
    {
        InGameEditor_AddCollectablePosition( ref vVar8[I], I );
        (uParam1^)[I] = LocalOptions_IsCollected( I );
        if ((uParam1^)[I] == 0)
        {
            (uParam0^)[I] = PropManager_AddRaceProp( Result, ref vVar8[I], ref vVar5, "city/la/props", "la_prop_col_barrel_01x" );
            PropManager_SetPropPhysicsTypeFlags( (uParam0^)[I], 16384 );
        }
    }
    PRINTSTRING( " I AM FREE\n" );
    return Result;
}

int sub_2232(unknown uParam0, unknown uParam1, unknown uParam2, unknown uParam3, unknown uParam4)
{
    boolean bVar7;
    unknown uVar8;
    unknown uVar9;
    int iVar10;

    bVar7 = true;
    uVar8 = Form_GetForm( uParam0 );
    uVar9 = Form_GetForm( uParam1 );
    Form_ShowForm( uVar8, uVar9 );
    if (NOT (StringCompare( uParam2, "" )))
    {
        iVar10 = mcCareerSpeech_FindScenario( uParam2 );
        if (iVar10 != nil)
        {
            mcCareerSpeech_Stop();
            mcCareerSpeech_PlayScenario( iVar10, uParam3, uParam4 );
        }
    }
    while (bVar7)
    {
        bVar7 = Form_GetFormVisible( uVar9 );
        WAITUNWARPED( 100 );
    }
    return Form_GetFormResult( uVar9 );
}
