//dixiashishi1.h

//Sample for room: ����ʯ��1
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_dixiashishi1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����µ���ʯ��1");


	add_door("�����·���2", "�����·���2", "�����µ���ʯ��1");
	add_door("�����µ���ʯ��2", "�����µ���ʯ��2", "�����µ���ʯ��1");

	set("long","����һ�����µ�����ʯ�ң�������Ըо��õ���ֻ��ǿ�ҵ�ɱ�����Լ�����ص׵�һЩ���ŵ���ζ����΢���ĵƹ��£��㾹Ȼ�����и���վ������������º�����·��");

/*****************************************************
	set("exits", ([
		"up" : __DIR__"fangjian2",
		"down" : __DIR__"shishi5",
	]));
	set("objects",([
		__DIR__"npc/qingyun" : 1,
	]));
//	
*****************************************************/
};


ROOM_END;
