//shuzhuangtai.h

//Sample for room: ��ɽ��ױ̨
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shuzhuangtai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��ױ̨");

	add_npc("hengshan1_liuhong");
	add_door("��ɽ�ؾ���", "��ɽ�ؾ���", "��ɽ��ױ̨");

    set("long","�ؾ�����һ����Ȫ�羵���������Ȫ���ഫΪ�ϳº������ڴ˱���ʱ���Ա�ˮ��������ױ���ĵط�����ǰʤ�������գ���ʱҹ�䳣���ɹ⣬���緱�ǵ�㣬������ө�ҷɣ�ɷ��׳�ۡ�" );
    

/*****************************************************
        set("exits", ([ 
           "north"   : __DIR__"cangjingdian",
        ]));
********************************************/
};


ROOM_END;
