void main()
{
    int iVar2;
    string sVar3;
    char[64] cVar4;
    unknown uVar20;
    unknown uVar21;
    unknown uVar22;
    unknown uVar23;
    unknown uVar24;
    unknown uVar25;
    unknown uVar26;
    unknown uVar27;
    vector vVar28;
    unknown uVar31;
    float fVar32;
    char[64] cVar33;
    int iVar49;
    int I;

    l_U0._fU0 = 2;
    iVar2 = 0;
    sVar3 = GetCarCommandLine( ref iVar2 );
    if (iVar2 == 0)
    {
        sVar3 = "vp_mit_3000gt_99";
    }
    StrCopy( ref cVar4, "la", 64 );
    PRINTSTRING( "Script: LoadCity LA\n" );
    uVar20 = LookupCity( ref cVar4 );
    LayerCity_LoadCity( ref cVar4 );
    CityDescription_GetDefaultStartPosition( uVar20, ref uVar21, ref uVar24 );
    uVar25 = LocalOptions_GetShowroomProfile( N_3899682874( sVar3 ) );
    LayerPlayer_LoadPlayer( 0, uVar25, ref uVar21, uVar24 );
    uVar26 = Player_FindObject( 0 );
    uVar27 = Player_GetRacer( uVar26 );
    Racer_SetStreamLockState( uVar27, 1 );
    Racer_InitializeResetPosition( uVar27, ref uVar21, uVar24 );
    Racer_Reset( uVar27 );
    Graphics_WarpToTimeOfDay( 16.00000000, 100.00000000 );
    WAIT( 8000 );
    vVar28 = {-612.38000000, 17.88000000, -632.66000000};
    uVar31 = BrainFactory_CreateBrainRacing( uVar27 );
    BrainRacing_Reset( uVar31 );
    BrainRacing_AppendGoal( uVar31, ref vVar28, 2.00000000 );
    BrainRacing_SetAllowNitro( uVar31, 0 );
    Racer_Activate( uVar27 );
    fVar32 = 27.50000000;
    iVar49 = 0;
    StrCopy( ref cVar33, "t:/mc4/aimovie-", 64 );
    for ( I = 0; I < 1000; I++ )
    {
        WAIT( 10 );
        sub_409( ref cVar33, ref iVar49 );
    }
    Graphics_WarpToTimeOfDay( 16.00000000, 100.00000000 );
    WAIT( 100 );
    WAIT( 300 );
    BrainFactory_DeleteBrain( uVar27 );
    LayerPlayer_KillPlayer( 0 );
    PRINTSTRING( "Script: UnloadCity LA\n" );
    LayerCity_UnloadCity();
    return;
}

void sub_409(unknown uParam0, unknown uParam1)
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
