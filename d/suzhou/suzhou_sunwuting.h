//sunwuting.h

//Sample for room: ����ͤ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_sunwuting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ͤ");
	
	add_npc("pub_youke");        //add by zdn 2001-07-16


	add_door("�����Խ�ʯ", "�����Խ�ʯ", "��������ͤ");

	set("long", "������Ļ��������ϣ���һ��Сͤ�ӣ���Ϊ����ͤ���ഫ����ʱ�������������ڴ�ѵ�����ӹ�Ů���������������輧�ֱ��ζӳ������ڳ輧�빬Ů�ǲ���������������꣬���������ţ������������ն�����ھ�ǰ�������͡�����������ͤ��" );
	

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
