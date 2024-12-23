//kedian1.h

//Sample for room: �͵�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_kedian1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�͵�1");

	add_npc("shaolin_xingzhe");
	add_npc("pub_xiaoer2");
//	add_npc("wiz_teacher3");

	add_door("�����ʳ�", "�����ʳ�", "�����͵�1");

	set("long", "����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡����˵ȫ�����ض��������ķֵ꣬�������еĿ�ջ����һ�������С�������������¶�棬˭Ҳ��֪��������������һ���ˡ�" );
	set("no_fight", 1);
	set("valid_startroom", 1);
	
	set("sleep_room", 1);


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




