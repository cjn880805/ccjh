//zahuopu.h

//Sample for room: �ӻ���
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_zahuopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ӻ���");
	
	add_npc("pub_xiaoer2");         //add by zdn 2001-07-16


	add_door("���ݳ�", "���ݳ�", "�����ӻ���");

	set("long", "����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ�����ƹ������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�����̯������һ������(zhaopai)��" );
/*****************************************************
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"north" : __DIR__"dongdajie1",
		"up"    : __DIR__"garments",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));
********************************************/
};


ROOM_END;
