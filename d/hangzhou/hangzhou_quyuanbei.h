//quyuanbei.h

//Sample for room: ������Ժ���
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_quyuanbei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������Ժ���");
	
	add_npc("pub_youke");          //add by zdn 2001-07-14
	add_npc("pub_gongzijun");

	add_door("�����յ�2", "�����յ�2", "������Ժ���");

	set("long"," ���С���ţ�ӭ����һͤԺ���Ա�����ʯ�������⡰��Ժ��ɡ��������ǻ��յ̡�");

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
