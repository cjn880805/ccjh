//fangjian2.h

//Sample for room: ����2
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRSheShenYa_fangjian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����·���2");


	add_door("������ʯ��", "������ʯ��", "�����·���2");
	add_door("�����µ���ʯ��1", "�����µ���ʯ��1", "�����·���2");

	set("long","����һ�䲼�ó�����ģ����С���䣬����ʯ�������ϰ��Ÿ�СС��ľͷ�Ƴɵ�ҡ����ǽ��������һ�������٣����߶��Ѿ����ˡ�");
	

/*****************************************************
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));
*****************************************************/
};


ROOM_END;
