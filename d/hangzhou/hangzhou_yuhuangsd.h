//yuhuangsd.h

//Sample for room: �������ɽ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yuhuangsd);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������ɽ��");
	
	add_npc("pub_youke");      // add by zdn 2001-07-14


	add_door("����ɽ·6", "����ɽ·6", "�������ɽ��");
	add_door("����ɽ·7", "����ɽ·7", "�������ɽ��");

	set("long"," �������ɽ�����ɽ�£����Կ��������������˵���ǻʵۼ���ũʱ�׸��ļ��ɽ���и��ǹۣ�����Ƴ�������������һ�غͰ�ʯ��������������ͤ���������߸���һ����ɽ��·��");

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
