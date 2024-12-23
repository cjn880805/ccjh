//yangcanfang.h

//Sample for room: ���Ϸ�
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaliEast_yangcanfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ϸ�");

	//add npcs into the room
	add_npc("pub_yangcannu");
	
	add_door("����ǲ��۲�", "����ǲ��۲�", "��������Ϸ�");

	set("long", "����һ�������ĸ�����ӣ��˼��²�ȴû��ţ����������ϯΧס����һ�����ݣ���������������̣�������һЩɣ�ϡ�һλ���Ĺ������������ʵ�ɣҶι��ɣ�ϡ�" );

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
