void main()
{
    unknown uVar2;
    vector vVar3;
    float fVar6;
    boolean bVar7;

    Registry_SetValueInt( "hw_garage_state", 1 );
    uVar2 = Player_FindRacerObject( 0 );
    vVar3 = {837.00000000, 17.60000000, -826.60000000};
    fVar6 = 0;
    bVar7 = false;
    while (NOT bVar7)
    {
        fVar6 = Racer_DistanceToPoint( uVar2, ref vVar3 );
        if (fVar6 < 8.00000000)
        {
            bVar7 = true;
        }
        WAITUNWARPED( 100 );
    }
    mcCareer_StartNewScript( "Game/Garages/hw_garage_setup", 1500 );
    return;
}
