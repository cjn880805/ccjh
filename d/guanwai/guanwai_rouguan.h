//rouguan.h

//Sample for room: �����
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_rouguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	set("monster_chance", 1);

	//add npcs into the room
	add_npc("pub_laoban");
	add_npc("pub_fengwanzhan");
	add_npc("pub_situshashou");
	
	add_door("������Զ", "������Զ", "������Զ�����");

    set("long","����һ���С�Ĺ���ݣ�������һ���ܴ������������ռȥ�˷����һ�롣������һ������ϼ�һ�ڴ�������������������ӹ��в���ð�������ݵ��ϰ����ڹ��ԣ����ϵĸ�����ʢ��һ���������ڵ�������" );


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
