//qunxianguan.h

//Sample for room: Ⱥ�ɹ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHuaShan_qunxianguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ⱥ�ɹ�");

	add_npc("huashan_yue_buqun");

	add_door("��ɽ���䳡", "��ɽ���䳡", "��ɽȺ�ɹ�");
    add_door("��ɽ������Ϊ��", "��ɽ������Ϊ��", "��ɽȺ�ɹ�");



    set("long","�����ǻ�ɽ������֮�����صأ�ǽ�Ϲ��Ż�ɽ�����������˵Ļ��񣬻�ɽ��һ���ش����Ƕ���������С�����Ҳ�ǻ�ɽ���ӽ���ϰ��֮�ء����߾��ǻ�ɽ��������Ⱥ�ľ�����������Ϊ������");

/*****************************************************
        set("exits", ([ 
             "south": __DIR__"square",
             "north": __DIR__"buwei1",
        ]));
        set("objects", ([
             CLASS_D("huashan") + "/yue-buqun": 1,
        ]));
//        
********************************************/
};


ROOM_END;
