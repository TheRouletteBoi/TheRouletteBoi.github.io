void main()
{
    char[64] cVar2;
    unknown uVar18;
    vector vVar19;
    char[64] cVar22;
    int iVar38;
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

    StrCopy( ref cVar2, "la", 64 );
    uVar18 = LookupCity( ref cVar2 );
    LayerCity_LoadCity( ref cVar2 );
    vVar19 = {-286.50000000, 23.20000000, -741.80000000};
    Graphics_WarpToTimeOfDay( 11.75000000, 100.00000000 );
    Graphics_SetMainShadowedRenderPass( 0 );
    iVar38 = 1;
    StrCopy( ref cVar22, "t:/mc4/particleshot-", 64 );
    uVar45 = {vVar19};
    uVar45._fU4 += 2.00000000;
    uVar39 = {uVar45};
    uVar39._fU0 -= 25.00000000;
    uVar39._fU4 += 5.00000000;
    uVar42 = {uVar45};
    uVar42._fU4 += 5.00000000;
    Game_SetCamera( ref uVar39, ref uVar42, 40.00000000, 0, 0, 0 );
    uVar48 = Particles_CreateParticleEffect( "checkpoint_night", ref uVar45 );
    WAIT( 5000 );
    while (iVar38 < 100)
    {
        sub_317( ref cVar22, ref iVar38 );
        WAIT( 20 );
    }
    WAIT( 100 );
    LayerCity_UnloadCity();
    return;
}

void sub_317(unknown uParam0, unknown uParam1)
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
