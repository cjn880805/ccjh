//shishi1.h

//Sample for room: ʯ��1
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_shishi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ʯ��1");



	add_door("������ʯ��", "������ʯ��", "������ʯ��1");

	set("long","����һ��ʯͷ���ɵķ��䣬��Ϊ�þ�û����������ɢ����һЩ�����ŵ���ζ�������е������Կ�����˿�ͳ漣��");

/*****************************************************
	set("exits", ([
		"east" : __DIR__"shiji1",
	]));
	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));
//	
*****************************************************/
};


ROOM_END;
