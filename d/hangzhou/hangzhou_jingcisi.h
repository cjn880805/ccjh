//jingcisi.h

//Sample for room: ���ݾ�����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_jingcisi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݾ�����");
	
	add_npc("pub_guest");
	add_npc("pub_youke");          // add by zdn 2001-07-14


	add_door("������ʯ���16", "������ʯ���16", "���ݾ�����");


	set("long"," �����£�ԭ����������Ժ���ֽ��˽��¡�������������������ӵ��Ȼͦ�������ɽ�������ͻص�����ϡ�");
 
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
