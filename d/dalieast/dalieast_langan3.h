//langan3.h

//Sample for room: ����Ǹ���3
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_langan3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǹ���3");

	//add npcs into the room
	add_npc("pub_yangcannu");
	
	add_door("�����ũ��5", "�����ũ��5", "����Ǹ���3");
	add_door("����ǲ��۲�", "����ǲ��۲�", "����Ǹ���3");

	set("long", "һ�������ĸ�����ӣ��˼��²�û��ţ��ȴ����ϯΧ��һ����ɣ�ϵ�С���ݣ���������̡�¥�ϴ��������ɴ�����������" );
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
