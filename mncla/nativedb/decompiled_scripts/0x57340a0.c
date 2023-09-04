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

    uVar2 = Player_FindRacerObject( 0 );
    Racer_GetPosition( uVar2, ref uVar3 );
    while (true)
    {
        uVar6 = {uVar3};
        uVar6._fU4 += 2.00000000;
        uVar9 = Particles_CreateParticleEffect( "muzzle_flash_03", ref uVar6 );
        uVar6._fU4 += 2.30000000;
        uVar10 = Particles_CreateParticleEffect( "qub_merge_blue", ref uVar6 );
        WAIT( 2000 );
        Particles_DestroyParticleEffect( uVar9 );
        Particles_DestroyParticleEffect( uVar10 );
        WAIT( 100 );
    }
    return;
}
