//shuiliandong.h

//Sample for room: ��ɽˮ����
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shuiliandong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽˮ����");
	
	add_npc("pub_daoke");         ///add by zdn 2001-07-20

	add_door("��ɽɽ·12", "��ɽɽ·12", "��ɽˮ����");

    set("long","ˮ�������ϸǷ��£����������¯����֮�䡣�ϸǷ�֮ˮ��ɽ�������ϸ��ɶ��У���ɲ⣬ˮ�����磬���ٸ߶�ʮ���ɣ�����������Ʈй���£�εΪ׳�ۡ����ž���ʫԻ:  '����孺�������Ī�����ӵ�����������������������ˮ����������ͷ��' ����̾���ɽ���ľ�֮һ��'ˮ����֮��' ��" );
    

/*****************************************************
        set("exits", ([  
           "westdown"    : __DIR__"shanlu12",
        ]));
********************************************/
};


ROOM_END;
