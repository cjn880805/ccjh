//anfugate.h

//Sample for room: ����ʹ����
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_anfugate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ʹ����");

	add_npc("pub_xiexunfu"); 
	add_npc("pub_yuguangqi");
	add_npc("pub_xyqinbing");

	add_door("��������", "��������", "��������ʹ����");

	set("long", "���ǰ���ʹ���ŵĴ��ţ�ͭƤ�����ƺ���Ϊ���أ��������������λε�ͭ�������Ž��գ�����ȴ����һ������Ц�������ſڵ���ɱ�ܲ�Э���������������ʹ���˵����ӻ��ǹ���������ġ�" );
	set("outdoors", "xiangyang");
	
/*****************************************************
	set("exits", ([
		"south" : __DIR__"anfupailou",
	]));
********************************************/
};


ROOM_END;
