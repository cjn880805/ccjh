//dalu1.h

//Sample for room: �������д�·1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_dalu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������д�·1");
	
	add_npc("pub_daoke");
	add_npc("lingzhou_ye");   //add by zdn 2001-07-20


	add_door("����������1", "����������1", "�������д�·1");
	add_door("����������2", "����������2", "�������д�·1");
	add_door("��������С·1", "��������С·1", "�������д�·1");

	set("long", "����ɽ�����·����ǿ����ͨ��һ���󳵣�·��������������ĳ���ӡ��·��ɽ����ȫ�ǲ����ľ������ȥ�ܲ�͸�磬������ľ�������ż��������в��ܴ��Ƽž�����·����������ת�˸��䡣");  
	
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
