//xuankong.h

//Sample for room: ��ɽ������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_xuankong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������");

	//add npcs into the room
	add_npc("pub_yafu");

	add_door("��ɽ���̵�", "��ɽ���̵�", "��ɽ������");
	add_door("��ɽ��ʽջ��", "��ɽ��ʽջ��", "��ɽ������");
	add_door("��ɽ����ɽ��2", "��ɽ����ɽ��2", "��ɽ������");

    set("long","�����������µı���¥��Ҳ�Ǳ���ͤ����¥���ӣ�������Ԩ���ȵ���������ڼ䵤�����������ջ��ͨ����¥��"   );
    

/*****************************************************
	set("exits", ([
		"south"    : __DIR__"zhanqiao",
		"up"       : __DIR__"sanjiaodian",
		"westdown" : __DIR__"cuiping2",
	]));
	set("objects", ([
		__DIR__"npc/yafu" : 1,
	]));
********************************************/
};


ROOM_END;
