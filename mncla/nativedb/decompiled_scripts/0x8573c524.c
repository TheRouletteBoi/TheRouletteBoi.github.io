void main()
{
    string[3] sVar2;
    vector[3] vVar6;
    unknown uVar10;
    unknown uVar11;
    unknown uVar12;
    unknown uVar13;
    unknown uVar14;
    unknown uVar15;
    float[3] fVar16;
    vector[3] vVar20;
    unknown uVar24;
    unknown uVar25;
    unknown uVar26;
    unknown uVar27;
    unknown uVar28;
    unknown uVar29;
    unknown[3] uVar30;
    int I;

    array(ref sVar2, 3);
    array(ref vVar6, 3);
    array(ref fVar16, 3);
    array(ref vVar20, 3);
    sVar2[0] = "vp_chv_police_96";
    vVar6[0] = {2030.10000000, 6.80000000, -813.70000000};
    fVar16[0] = 90;
    vVar20[0] = {-510.00000000, 9.50000000, -400.00000000};
    sVar2[1] = "vp_chv_police_96";
    vVar6[1] = {-646.80000000, 18.50000000, -643.80000000};
    fVar16[1] = 90;
    vVar20[1] = {-500.00000000, 9.50000000, -400.00000000};
    sVar2[2] = "vp_chv_police_96";
    vVar6[2] = {-2434.40000000, 1.90000000, -577.90000000};
    fVar16[2] = 84.90000000;
    vVar20[2] = {-490.00000000, 9.50000000, -400.00000000};
    array(ref uVar30, 3);
    for ( I = 0; I < 3; I++ )
    {
        uVar30[I] = PoliceManager_CreatePolice( sVar2[I], 1, ref vVar6[I], fVar16[I], ref vVar20[I], 400 + I );
    }
    return;
}
