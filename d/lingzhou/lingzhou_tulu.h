//tulu.h

//Sample for room: ����������·
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_tulu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������·");
	
	add_npc("pub_xixiabing");   //add by zdn 2001-07-14


	add_door("����������2", "����������2", "����������·");
	add_door("�������пյ�", "�������пյ�", "����������·");

	set("long", "����ɽ�����·����ǿ����ͨ��һ���󳵣�·��������������ĳ���ӡ��·��ɽ����ȫ�ǲ����ľ������ȥ�ܲ�͸�磬������ľ�������ż��������в��ܴ��Ƽž�����·�򶫱���������ת�˸��䣬��������Լ���Կ�������һ����ݶ��ϵ����ġ�");  

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
