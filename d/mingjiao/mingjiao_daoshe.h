//daoshe.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_daoshe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���̵�������");


	add_door("�������Ź㳡", "�������Ź㳡", "���̵�������");
	add_npc("mingjiao_tuoba");

	set("long", "�߽�������ᣬһ������Ʈ����ֻ����Ϊ����ɮ�˶���������֮�ϣ�������ӽ���վ����������������ƣ���Ӱ������һ��ü��ɮ�������У��ֳ��������飬�����дʡ����ǽ��֮�ϣ�����һ����(tiao fu)��ֽ�ѷ���,�������پ���һ����֪�Ǽ����");
    
    set("sleep_room", 1);
    set("no_fight", 1);

/*****************************************************
    set("exits", ([
        "south" : __DIR__"mjfengmen1",
    ]));
    set("item_desc",(["tiao fu" : (: look_fu :),]));
********************************************/
};


ROOM_END;
