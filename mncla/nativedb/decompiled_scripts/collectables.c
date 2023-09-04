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

    array(ref uVar2._fU12, 60);
    ref uVar2;
    array(ref uVar66, 60);
    uVar127 = sub_35( ref uVar66, ref uVar2._fU12 );
    WAIT( 10000 );
    iVar128 = 0;
    iVar129 = 0;
    while (iVar128 == 0)
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
                    PropManager_RemoveRaceProp( uVar127, iVar130 );
                    uVar66[iVar131] = nil;
                    uVar2._fU12[iVar131] = 1;
                    bVar132 = false;
                    iVar129 = LocalOptions_SaveCollectables( iVar131 );
                    PRINTSTRING( "found collectable prop at idx " );
                    PRINTINT( iVar131 );
                    PRINTSTRING( "\n" );
                    SplashManager_Splash( 0, 1, "Collectable Found!!", 1073741824, 1, 0 );
                }
                iVar131++;
                if (iVar131 >= 60)
                {
                    PRINTSTRING( "didn't find collectable prop\n" );
                    bVar132 = false;
                }
            }
        }
        if (iVar129 > 0)
        {
            StatsManager_UpdateStatInt( "gCOL", 0, 2, iVar129 );
        }
        WAIT( 1000 );
    }
    sub_2175( uVar127, ref uVar66, ref uVar2._fU12 );
    return;
}

void sub_35(unknown uParam0, unknown uParam1)
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

    Result = PropManager_InitRaceProps( 70, 5 );
    vVar5 = {0, 0, 0};
    array(ref vVar8, 60);
    vVar8[0] = {-550.44000000, 18.83000000, -696.79000000};
    vVar8[1] = {-1768.93000000, 6.94000000, -866.89000000};
    vVar8[2] = {-2138.87000000, 1.25000000, -187.94000000};
    vVar8[3] = {-1687.47000000, 14.89000000, 575.42000000};
    vVar8[4] = {-1879.91000000, 3.41000000, 388.87000000};
    vVar8[5] = {-300.97000000, -7.57000000, 186.05000000};
    vVar8[6] = {689.86000000, -13.62000000, 254.58000000};
    vVar8[7] = {398.92000000, 7.12000000, -221.45000000};
    vVar8[8] = {-298.40000000, 17.40000000, -405.20000000};
    vVar8[9] = {-940.10000000, -0.40000000, -229.90000000};
    vVar8[10] = {-1765.70000000, -1.13000000, 99.56000000};
    vVar8[11] = {-1548.40000000, 2.13000000, -226.13000000};
    vVar8[12] = {-1266.63000000, 7.21000000, 394.22000000};
    vVar8[13] = {431.26000000, 23.04000000, -1025.88000000};
    vVar8[14] = {778.09000000, 30.29000000, -1280.96000000};
    vVar8[15] = {1024.79000000, 16.52000000, -787.00000000};
    vVar8[16] = {-2083.09000000, 2.46000000, -381.07000000};
    vVar8[17] = {224.97000000, -20.61000000, 612.63000000};
    vVar8[18] = {-503.45000000, -8.29000000, 145.34000000};
    vVar8[19] = {-257.91000000, 31.54000000, -778.71000000};
    vVar8[20] = {-3197.50000000, -19.76000000, 562.59000000};
    vVar8[21] = {-2930.10000000, -8.64000000, 610.00000000};
    vVar8[22] = {-2971.15000000, -25.86000000, -411.74000000};
    vVar8[23] = {-2669.27000000, -25.81000000, -922.25000000};
    vVar8[24] = {-2624.73000000, -19.71000000, -1093.39000000};
    vVar8[25] = {-2200.68000000, 4.16000000, -662.93000000};
    vVar8[26] = {-2951.74000000, -3.38000000, -273.47000000};
    vVar8[27] = {-2609.16000000, -3.45000000, 273.97000000};
    vVar8[28] = {-2126.11000000, 0.10000000, 320.73000000};
    vVar8[29] = {-2949.34000000, -29.23000000, 1072.44000000};
    vVar8[30] = {-2550.10000000, -10.67000000, 806.20000000};
    vVar8[31] = {-2296.64000000, -4.36000000, 316.01000000};
    vVar8[32] = {-2120.52000000, 10.92000000, -1216.81000000};
    vVar8[33] = {-2496.71000000, 0.68000000, -476.80000000};
    vVar8[34] = {-2644.81000000, -4.20000000, 673.13000000};
    vVar8[35] = {2638.50000000, -15.80000000, -631.50000000};
    vVar8[36] = {2327.95000000, -15.56000000, 345.34000000};
    vVar8[37] = {2045.90000000, -20.00000000, 1051.10000000};
    vVar8[38] = {1183.38000000, -8.21000000, 719.95000000};
    vVar8[39] = {1460.30000000, -5.60000000, 1021.30000000};
    vVar8[40] = {1408.36000000, -3.16000000, 10.69000000};
    vVar8[41] = {1622.39000000, 3.51000000, -526.63000000};
    vVar8[42] = {1817.88000000, -0.02000000, -674.90000000};
    vVar8[43] = {1758.86000000, 4.05000000, -907.04000000};
    vVar8[44] = {2122.52000000, 3.97000000, -220.08000000};
    vVar8[45] = {2353.50000000, -10.00000000, 92.20000000};
    vVar8[46] = {2522.18000000, -10.09000000, -122.02000000};
    vVar8[47] = {1849.67000000, -3.50000000, 252.25000000};
    vVar8[48] = {2191.49000000, 4.01000000, -57.03000000};
    vVar8[49] = {2004.04000000, 6.50000000, -1180.63000000};
    vVar8[50] = {-598.06000000, 30.76000000, -1902.41000000};
    vVar8[51] = {-1887.59000000, 20.54000000, -2074.37000000};
    vVar8[52] = {-1707.23000000, 69.90000000, -1561.80000000};
    vVar8[53] = {-1081.42000000, 69.69000000, -1636.98000000};
    vVar8[54] = {-989.55000000, 64.11000000, -1446.82000000};
    vVar8[55] = {-572.63000000, 84.10000000, -1324.42000000};
    vVar8[56] = {432.89000000, 99.77000000, -1655.29000000};
    vVar8[57] = {82.90000000, 28.74000000, -1933.15000000};
    vVar8[58] = {-645.74000000, 37.67000000, -1814.02000000};
    vVar8[59] = {455.71000000, 23.15000000, -2268.27000000};
    for ( I = 0; I < 60; I++ )
    {
        (uParam1^)[I] = LocalOptions_IsCollected( I );
        if ((uParam1^)[I] == 0)
        {
            (uParam0^)[I] = PropManager_AddRaceProp( Result, ref vVar8[I], ref vVar5, "city/la/props", "l_prop_barrel_01x" );
        }
    }
    PRINTSTRING( " I AM FREE\n" );
    return Result;
}

void sub_2175(unknown uParam0, unknown uParam1, unknown uParam2)
{
    int I;

    for ( I = 0; I < 60; I++ )
    {
        if ((uParam2^)[I] == 0)
        {
            PropManager_RemoveRaceProp( uParam0, (uParam1^)[I] );
        }
    }
    PropManager_ShutdownRaceProps( uParam0 );
    return;
}
