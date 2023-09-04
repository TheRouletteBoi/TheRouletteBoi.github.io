void main()
{
    int iVar2;

    UIManager_StreamMovie( "REWARDMOVIE", "reward/reward.swf", 1000, 1000, 10000, 0, 0 );
    iVar2 = nil;
    while (iVar2 == nil)
    {
        iVar2 = UIManager_FindMovie( "REWARDMOVIE" );
        PRINTSTRING( "SCRIPT: waiting for reward movie to stream in...\n" );
        WAIT( 10 );
    }
    FlashHelper_SetGlobalInt( iVar2, "cur_visibility", 1 );
    Graphics_PictureInPictureGrabImageSequence( 100, 3 );
    WAIT( 8000 );
    UIManager_UnloadMovie( "REWARDMOVIE" );
    return;
}
