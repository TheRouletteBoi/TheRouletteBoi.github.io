void main()
{
    sub_14( "la" );
    return;
}

void sub_14(unknown uParam0)
{
    unknown uVar3;
    vector vVar4;
    vector vVar7;
    vector vVar10;
    vector vVar13;
    vector vVar16;
    vector vVar19;
    vector vVar22;
    vector vVar25;
    vector vVar28;
    vector vVar31;
    vector vVar34;
    vector vVar37;
    vector vVar40;
    unknown uVar43;

    uVar3 = PropManager_InitRaceProps( 10, 5 );
    vVar4 = {0, 0, 0};
    if (StringCaseCompare( uParam0, "la" ))
    {
        vVar7 = {519.11100000, 23.89500000, 64655};
        vVar10 = {520.11100000, 23.89500000, 64654};
        vVar13 = {521.11100000, 23.89500000, 64653};
        vVar16 = {522.11100000, 23.89500000, 64652};
        vVar19 = {523.11100000, 23.89500000, 64651};
        PropManager_AddRaceProp( uVar3, ref vVar7, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
        PropManager_AddRaceProp( uVar3, ref vVar10, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
        PropManager_AddRaceProp( uVar3, ref vVar13, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
        PropManager_AddRaceProp( uVar3, ref vVar16, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
        PropManager_AddRaceProp( uVar3, ref vVar19, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
    }
    else if (StringCaseCompare( uParam0, "test_cityblock" ))
    {
        vVar22 = {100, 0, 55};
        vVar25 = {90, 0, 27};
        vVar28 = {95, 0, 27};
        vVar31 = {100, 0, 27};
        vVar34 = {80, 0, 27};
        vVar37 = {60, 0, 27};
        vVar40 = {40, 0, 0};
        PropManager_AddRaceProp( uVar3, ref vVar22, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
        PropManager_AddRaceProp( uVar3, ref vVar25, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
        PropManager_AddRaceProp( uVar3, ref vVar28, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
        uVar43 = PropManager_AddRaceProp( uVar3, ref vVar31, ref vVar4, "city/la/props", "l_prop_barrel_01x" );
        PropManager_AddRaceProp( uVar3, ref vVar34, ref vVar4, "city/la/props", "l_prop_boxSet_04x" );
        PropManager_AddRaceProp( uVar3, ref vVar37, ref vVar4, "city/la/props", "l_prop_boxSet_05x" );
        PropManager_AddRaceProp( uVar3, ref vVar40, ref vVar4, "city/la/props", "l_prop_trafltsngl_01x" );
        PropManager_RemoveRaceProp( uVar3, uVar43 );
    }
    return;
}
