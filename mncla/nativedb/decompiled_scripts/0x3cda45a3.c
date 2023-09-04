void main()
{
    vector vVar2;
    char[64] cVar5;

    vVar2 = {1599.80000000, 0.00000000, 65447};
    StrCopy( ref cVar5, "la", 64 );
    PRINTSTRING( "Script: LoadCity " );
    PRINTSTRING( ref cVar5 );
    PRINTSTRING( "\n" );
    LayerCity_LoadCity( ref cVar5 );
    Graphics_WarpToTimeOfDay( 11.75000000, 100.00000000 );
    sub_128( "t:/mc4/cubemap_day_", ref vVar2 );
    Graphics_WarpToTimeOfDay( 23.00000000, 100.00000000 );
    sub_128( "t:/mc4/cubemap_night_", ref vVar2 );
    PRINTSTRING( "Script: UnloadCity LA\n" );
    LayerCity_UnloadCity();
    return;
}

void sub_128(unknown uParam0, unknown uParam1)
{
    vector[6] vVar4;
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
    int I;

    array(ref vVar4, 6);
    vVar4[0] = {1.00000000, 0.00000000, 0.00000000};
    vVar4[1] = {0.00000000, 0.00000000, 1.00000000};
    vVar4[2] = {-1.00000000, 0.00000000, 0.00000000};
    vVar4[3] = {0.00000000, 0.00000000, -1.00000000};
    vVar4[4] = {0.00000000, 1.00000000, 0.01000000};
    vVar4[5] = {0.00000000, -1.00000000, 0.01000000};
    uVar23 = {vVar4[0] + (uParam1^)};
    Game_SetCamera( uParam1, ref uVar23, 45.00000000, 1, 0, 0 );
    WAIT( 10000 );
    for ( I = 0; I < 6; I++ )
    {
        uVar23 = {vVar4[I] + (uParam1^)};
        Game_SetCamera( uParam1, ref uVar23, 45.00000000, 1, 0, 0 );
        WAIT( 200 );
        sub_379( uParam0, I );
    }
    WAIT( 1000 );
    return;
}

void sub_379(unknown uParam0, int iParam1)
{
    char[64] cVar4;
    char[64] cVar20;

    StrCopy( ref cVar4, uParam0, 64 );
    string(ref cVar20, iParam1, 64);
    StringCat( ref cVar4, ref cVar20 );
    N_2366296418( ref cVar4 );
    return;
}
