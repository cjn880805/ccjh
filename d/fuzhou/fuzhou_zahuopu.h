//zahuopu.h

//Sample for room: �ӻ���
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_zahuopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ӻ���");

	//add npcs into the room
	add_npc("pub_chen");
	
	add_door("������", "������", "�����ӻ���");

    set("long", "������һ��ר��Ů���õĶ�����С���ӡ�" );

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
