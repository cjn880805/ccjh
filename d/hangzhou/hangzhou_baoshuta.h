//baoshuta.h

//Sample for room: ���ݱ�����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_baoshuta);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݱ�����");
	
	add_npc("pub_guest");          // add by zdn 2001-07-14

	add_door("���ݱ�ʯɽ", "���ݱ�ʯɽ", "���ݱ�����");

	set("long"," ��������̬����ͦ�Σ�������С��ȴ�����˼��ߵ�������˵��Խ��Ǯ��������뾩������δ������������ˬΪףԭ��ƽ��������������������������������������ɽ��·��");

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
