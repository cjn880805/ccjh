//tingyu.h

//Sample for room: ������
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_tingyu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("pub_shutong");        //add by zdn 2001-07-16


	add_door("������", "������", "����������");

	set("long", "�����������ݳ��ڵ�һ��Ψһ��һ������ˡ��������Ÿ��ָ������鼮��ʲôС˵��������������������������������书�����ȵȵȵȡ�ֻ�뻨�������ӾͿ�������Ҫ���顣 " );
 	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
